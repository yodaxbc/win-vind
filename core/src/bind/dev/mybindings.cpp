#include "bind/dev/mybindings.hpp"

#include "bind/base/binded_func_with_creator.hpp"
#include "opt/virtual_cmd_line.hpp"
#include "io/mouse.hpp"
#include "io/keybrd.hpp"
#include "util/def.hpp"

#include "bind/base/ntype_logger.hpp"

namespace vind
{
    MyBinding::MyBinding()
    : BindedFuncCreator("my_binding") //Give the unique identifier.
    {}
    void MyBinding::sprocess() {
        mouse::click(KEYCODE_MOUSE_LEFT) ; //left click

        keybrd::pushup(KEYCODE_LWIN, KEYCODE_D) ; //minimize all window

        VirtualCmdLine::msgout("Hello World !") ;
    }
    void MyBinding::sprocess(NTypeLogger& parent_lgr) {
        if(!parent_lgr.is_long_pressing()) {
            sprocess() ;
        }
    }
    void MyBinding::sprocess(const CharLogger& UNUSED(parent_lgr)) {
        sprocess() ;
    }
}
