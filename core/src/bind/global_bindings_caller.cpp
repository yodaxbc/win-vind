#include "bind/global_bindings_caller.hpp"

#include <iostream>

#include "bind/base/key_logger_base.hpp"
#include "key/keycode_def.hpp"
#include "bind/base/ntype_logger.hpp"
#include "opt/virtual_cmd_line.hpp"

#include "bind/bind.hpp"
#include "bind/base/binded_func.hpp"

#include "bind/logger_parser.hpp"
#include "bind/mode/change_mode.hpp"

//internal linkage
namespace
{
    vind::NTypeLogger g_ntlgr{} ;
    vind::LoggerParser::SPtr g_active_parser = nullptr ;
}

namespace vind
{
    namespace gbindcaller {

        void initialize() {
            g_ntlgr.clear() ;
            g_active_parser = nullptr ;
        }

        void call_matched_func() {
            auto result = g_ntlgr.logging_state() ;
            if(NTYPE_EMPTY(result)) {
                return ;
            }
            if(NTYPE_HEAD_NUM(result)) {
                VirtualCmdLine::cout(std::to_string(g_ntlgr.get_head_num())) ;
                return ;
            }

            if(g_ntlgr.is_long_pressing()) {
                if(g_active_parser) {
                    g_active_parser->get_func()->process(!g_ntlgr.is_long_pressing(), g_ntlgr.get_head_num(), nullptr, nullptr) ;
                }
                return ;
            }

            auto parser = keybind::find_parser(g_ntlgr.latest(), g_active_parser) ;
            g_active_parser = nullptr ;

            if(parser) {
                if(parser->is_accepted()) {
                    VirtualCmdLine::reset() ;

                    g_active_parser = parser ;
                    g_active_parser->get_func()->process(!g_ntlgr.is_long_pressing(), g_ntlgr.get_head_num(), nullptr, nullptr) ;

                    g_ntlgr.accept() ;
                    keybind::reset_parsers() ;
                }
                else if(parser->is_rejected_with_ready()) {
                    keybind::undo_parsers(1) ;
                    g_ntlgr.remove_from_back(1) ;
                }
            }
            else {
                g_ntlgr.ignore() ;
                keybind::reset_parsers() ;

                if(g_ntlgr.get_head_num() == 0) {
                    VirtualCmdLine::refresh() ;
                }
            }
        }
    }
}
