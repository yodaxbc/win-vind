#include "yanktext.hpp"

#include "bind/mode/change_mode.hpp"
#include "bind/saferepeat.hpp"
#include "core/inputgate.hpp"
#include "core/keycodedef.hpp"
#include "core/mode.hpp"
#include "core/ntypelogger.hpp"
#include "textreg.hpp"
#include "textutil.hpp"
#include "util/def.hpp"


namespace vind
{
    namespace bind
    {
        //YankHighlightText (EdiVisual only)
        YankHighlightText::YankHighlightText()
        : BindedFuncVoid("yank_highlight_text")
        {}
        void YankHighlightText::sprocess() {
            auto& igate = core::InputGate::get_instance() ;

            igate.pushup(KEYCODE_LCTRL, KEYCODE_C) ;

            if(core::get_global_mode_flags() == core::ModeFlags::VISUAL_LINE) {
                set_register_type(RegType::Lines) ;
            }
            else {
                set_register_type(RegType::Chars) ;
            }

            igate.pushup(KEYCODE_LEFT) ; //unselect, but this is for the time being
            ToEdiNormal::sprocess(true) ;
        }
        void YankHighlightText::sprocess(core::NTypeLogger& parent_lgr) {
            if(!parent_lgr.is_long_pressing()) {
                sprocess() ;
            }
        }
        void YankHighlightText::sprocess(const core::CharLogger& UNUSED(parent_lgr)) {
            sprocess() ;
        }


        //YankLine (EdiNormal only)
        YankLine::YankLine()
        : BindedFuncVoid("yank_line")
        {}
        void YankLine::sprocess(unsigned int count) {
            auto& igate = core::InputGate::get_instance() ;

            igate.pushup(KEYCODE_HOME) ;
            safe_for(count, [&igate] {
                igate.pushup(KEYCODE_LSHIFT, KEYCODE_DOWN) ;
            }) ;

            Sleep(24) ;

            igate.pushup(KEYCODE_LCTRL, KEYCODE_C) ;
            igate.pushup(KEYCODE_HOME) ;
            set_register_type(RegType::Lines) ;
        }
        void YankLine::sprocess(core::NTypeLogger& parent_lgr) {
            if(!parent_lgr.is_long_pressing()) {
                sprocess(parent_lgr.get_head_num()) ;
            }
        }
        void YankLine::sprocess(const core::CharLogger& UNUSED(parent_lgr)) {
            sprocess(1) ;
        }
    }
}
