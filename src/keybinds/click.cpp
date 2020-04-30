#include "click.hpp"
#include "mouse_eventer.hpp"
#include "system.hpp"
#include <windows.h>
#include <iostream>

using namespace std ;

//ClickLeft
const string ClickLeft::sname() noexcept
{
    return "click_left" ;
}

bool ClickLeft::sprocess(const bool first_call)
{
    if(!first_call) return true ;
    using namespace System ;
    if(get_mode() == Mode::Visual) {
        change_mode(Mode::Normal) ;
    }

    if(!MouseEventer::is_click(MouseEventer::Button::LEFT)) {
        return false ;
    }
    return true ;
}


//ClickRight
const string ClickRight::sname() noexcept
{
    return "click_right" ;
}

bool ClickRight::sprocess(const bool first_call)
{
    if(!first_call) return true ;
    using namespace System ;
    if(get_mode() == Mode::Visual) {
        change_mode(Mode::Normal) ;
    }

    if(!MouseEventer::is_click(MouseEventer::Button::RIGHT)) {
        return false ;
    }
    return true ;
}