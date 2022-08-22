#include "close_win.hpp"

#include "core/inputgate.hpp"
#include "core/ntypelogger.hpp"
#include "util/def.hpp"

namespace vind
{
    namespace bind
    {
        //CloseCurrentWindow
        CloseCurrentWindow::CloseCurrentWindow()
        : BindedFuncVoid("close_current_window")
        {}
        void CloseCurrentWindow::sprocess(
                std::uint16_t count, const std::string& args) {
            core::InputGate::get_instance().pushup(
                    KEYCODE_LALT, KEYCODE_F4) ;
        }
    }
}
