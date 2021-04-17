#ifndef _FUNC_FINDER_HPP
#define _FUNC_FINDER_HPP

#include <memory>
#include <string>

#include "bind/base/binded_func.hpp"
#include "bind/base/key_logger_base.hpp"
#include "bind/base/mode.hpp"
#include "logger_parser.hpp"

namespace vind
{
    namespace funcfinder {
        const BindedFunc::SPtr find_func_byname(const std::string& name) ;
        void load_global_bindings() ;
    }

    class FuncFinder {
    private:
        struct Impl ;
        std::unique_ptr<Impl> pimpl ;

    public:
        explicit FuncFinder() ;
        explicit FuncFinder(const KeyLoggerBase& lgr) ;
        virtual ~FuncFinder() noexcept ;

        FuncFinder(const FuncFinder&) ;
        FuncFinder& operator=(const FuncFinder&) ;

        FuncFinder(FuncFinder&&) ;
        FuncFinder& operator=(FuncFinder&&) ;

        const LoggerParser::SPtr transition_parser_states_in_batch(
                const KeyLoggerBase& lgr,
                mode::Mode mode=mode::get_global_mode()) ;

        void reconstruct_funcset() ;

        const LoggerParser::SPtr find_parser(
                const KeyLog& log,
                std::size_t low_priority_func_id=0,
                mode::Mode mode=mode::get_global_mode()) ;

        void undo_parsers(std::size_t n, mode::Mode mode=mode::get_global_mode()) ;

        void reset_parsers(mode::Mode mode=mode::get_global_mode()) ;
    } ;
}

#endif
