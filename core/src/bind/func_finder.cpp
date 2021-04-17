#include "bind/func_finder.hpp"

#include "bind/base/binded_func.hpp"
#include "bind/base/key_logger_base.hpp"
#include "bind/base/mode.hpp"
#include "bind/bindings_def.hpp"
#include "bind/bindings_json_parser.hpp"
#include "bind/bindings_lists.hpp"
#include "bind/bindings_parser.hpp"
#include "bind/logger_parser.hpp"
#include "coreio/path.hpp"
#include "util/def.hpp"

#include <array>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <unordered_map>


//inner linkage
namespace
{
    using namespace vind ;
    const auto g_all_func_list = bindingslists::get() ;

    ParsedBindingLists g_parsed_bindlists ;
}

namespace vind
{
    using LoggerParserList = std::vector<LoggerParser::SPtr> ;
    struct FuncFinder::Impl {
        std::array<LoggerParserList, mode::mode_num()> parser_ar_{} ;
    } ;

    FuncFinder::FuncFinder()
    : pimpl(std::make_unique<Impl>())
    {
        reconstruct_funcset() ;
    }

    FuncFinder::~FuncFinder() noexcept = default ;
    FuncFinder::FuncFinder(const FuncFinder& rhs)
    : pimpl(rhs.pimpl ? std::make_unique<Impl>(*(rhs.pimpl)) : std::make_unique<Impl>())
    {}
    FuncFinder& FuncFinder::operator=(const FuncFinder& rhs) {
        if(rhs.pimpl) {
            *pimpl = *(rhs.pimpl) ;
        }
        return *this ;
    }
    FuncFinder::FuncFinder(FuncFinder&& rhs)        = default ;
    FuncFinder& FuncFinder::operator=(FuncFinder&&) = default ;

    void FuncFinder::reconstruct_funcset() {
        std::cout << "reconstructed\n" ;
        for(std::size_t i = 0 ; i < mode::mode_num() ; i ++) {
            for(const auto& func : g_all_func_list) {
                try {
                    auto& list = g_parsed_bindlists[i].at(func->name()) ;
                    auto p_parser = std::make_shared<LoggerParser>(func) ;
                    p_parser->share_parsed_binding_list(list) ;
                    pimpl->parser_ar_[i].push_back(std::move(p_parser)) ;
                }
                catch(const std::out_of_range&) {
                    continue ;
                }
            }
        }
    }

    const LoggerParser::SPtr FuncFinder::transition_parser_states_in_batch(
            const KeyLoggerBase& lgr,
            mode::Mode mode) {
        LoggerParser::SPtr ptr = nullptr ;
        for(const auto& log : lgr) {
            ptr = find_parser(log, 0, mode) ;
        }
        return ptr ;
    }

    const LoggerParser::SPtr FuncFinder::find_parser(
            const KeyLog& log,
            std::size_t low_priority_func_id,
            mode::Mode mode) {
        LoggerParser::SPtr ptr = nullptr ;
        LoggerParser::SPtr low_priority_ptr = nullptr ;
        unsigned char mostnum = 0 ;

        for(auto& parser : pimpl->parser_ar_[static_cast<std::size_t>(mode)]) {
            auto num = parser->validate_if_match(log) ;
            if(!parser->is_rejected() && mostnum < num) {
                if(parser->get_func()->id() == low_priority_func_id) {
                    low_priority_ptr = parser ;
                }
                else {
                    ptr = parser ;
                    mostnum = num ;
                }
            }
        }

        if(ptr) {
            return ptr ;
        }
        if(low_priority_ptr && low_priority_ptr->is_accepted()) {
            return low_priority_ptr ;
        }
        return nullptr ;
    }

    void FuncFinder::undo_parsers(std::size_t n, mode::Mode mode) {
        for(auto& parser : pimpl->parser_ar_[static_cast<std::size_t>(mode)]) {
            parser->undo_state(n) ;
        }
    }

    void FuncFinder::reset_parsers(mode::Mode mode) {
        for(auto& parser : pimpl->parser_ar_[static_cast<std::size_t>(mode)]) {
            parser->reset_state() ;
        }
    }

    namespace funcfinder {
        const BindedFunc::SPtr find_func_byname(const std::string& name) {
                for(const auto& func : g_all_func_list) {
                    if(func->name() == name) return func ;
                }
                return nullptr ;
        }

        void load_global_bindings() {
            ParsedBindingLists().swap(g_parsed_bindlists) ; //clear by empty swapping

            ParsedStringBindingLists parsed_strcmds ;
            bindjsonparser::parse_bindings_as_list(path::BINDINGS(), g_all_func_list, parsed_strcmds) ;

            if(parsed_strcmds.empty()) {
                throw RUNTIME_EXCEPT("Could not parse " + path::BINDINGS()) ;
            }

            for(const auto& [name, strcmd_modelists] : parsed_strcmds) {
                ModeArray<std::size_t> links ;
                links.fill(static_cast<std::size_t>(mode::Mode::None)) ;

                for(std::size_t i = 0 ; i < mode::mode_num() ; i ++) {
                    const auto& strcmds = strcmd_modelists[i] ;

                    if(strcmds.empty()) {
                        continue ;
                    }

                    if(strcmds.size() == 1) {
                        auto mode = bindparser::parse_string_modecode(strcmds.front()) ;
                        if(mode != mode::Mode::None) {
                            links[i] = static_cast<std::size_t>(mode) ;
                            continue ;
                        }
                    }

                    auto cmdlist_ptr = std::make_shared<CommandList>() ;
                    for(auto& strcmd : strcmds) {
                        cmdlist_ptr->push_back(bindparser::parse_string_binding(strcmd)) ;
                    }

                    g_parsed_bindlists[i][name] = std::move(cmdlist_ptr) ;
                }

                //If there are some key-bindings fields of the mode having <mode-name> (e.q. <guin>, <edin>) in bindings.json ,
                //they are copied key-bindings from the first mode in json-array to them.
                //Ex) "guin": ["<Esc>", "happy"]
                //    "edin": ["<guin>", "<guii>"]    -> same as "guin"'s key-bindings(<Esc>, "happy")
                for(std::size_t i = 0 ; i < mode::mode_num() ; i ++) {
                    try {
                        auto& linked_func_cmdlists = g_parsed_bindlists[links[i]] ;
                        if(links[i] != static_cast<std::size_t>(mode::Mode::None) \
                                && linked_func_cmdlists.at(name) != nullptr) {
                            g_parsed_bindlists[i][name] = linked_func_cmdlists[name] ;
                        }
                    }
                    catch(const std::out_of_range&) {
                        continue ;
                    }
                }
            }


            // load configs of all function and give a chance to reconstruct FuncFinder automatically.
            for(auto& func : g_all_func_list) {
                func->load_config() ;
            }
        }
    }
}
