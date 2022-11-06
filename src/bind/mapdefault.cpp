#include "mapdefault.hpp"

#include "util/debug.hpp"

namespace
{
    const std::vector<std::pair<std::string, std::string>>& gui_normal() {
        static std::vector<std::pair<std::string, std::string>> tmp = {
            {"<esc-left>", "<to_gui_normal>"},
            {"<esc-down>", "<to_resident>"},
            {"v", "<to_gui_visual>"},
            {":", "<to_command>"},
            {"I", "<to_edi_normal>"},
            {"<esc-right>", "<to_edi_normal>"},
            {"<ctrl-[>", "<to_edi_normal>"},
            {"i", "<to_insert>"},

            {"V", "<select_all>"},

            {"h", "<move_cursor_left>"},
            {"<bs>", "<move_cursor_left>"},
            {"<left>", "<move_cursor_left>"},
            {"l", "<move_cursor_right>"},
            {"<space>", "<move_cursor_right>"},
            {"<right>", "<move_cursor_right>"},
            {"k", "<move_cursor_up>"},
            {"-", "<move_cursor_up>"},
            {"<up>", "<move_cursor_up>"},
            {"j", "<move_cursor_down>"},
            {"+", "<move_cursor_down>"},
            {"<down>", "<move_cursor_down>"},

            {"0", "<jump_cursor_to_left>"},
            {"^", "<jump_cursor_to_left>"},
            {"<home>", "<jump_cursor_to_left>"},
            {"$", "<jump_cursor_to_right>"},
            {"<end>", "<jump_cursor_to_right>"},
            {"gg", "<jump_cursor_to_top>"},
            {"G", "<jump_cursor_to_bottom>"},
            {"gm", "<jump_cursor_to_hcenter>"},
            {"M", "<jump_cursor_to_vcenter>"},
            {"f", "<jump_cursor_with_keybrd_layout>"},
            {"t", "<jump_cursor_to_active_window>"},

            {"<c-y>", "<scroll_up>"},
            {"<c-k>", "<scroll_up>"},
            {"<c-e>", "<scroll_down>"},
            {"<c-j>", "<scroll_down>"},
            {"<c-u>", "<scroll_up_halfpage>"},
            {"<c-d>", "<scroll_down_halfpage>"},
            {"<c-b>", "<scroll_up_onepage>"},
            {"<c-f>", "<scroll_down_onepage>"},
            {"zh", "<scroll_left>"},
            {"<c-h>", "<scroll_left>"},
            {"zl", "<scroll_right>"},
            {"<c-l>", "<scroll_right>"},
            {"zh", "<scroll_left_halfpage>"},
            {"zl", "<scroll_right_halfpage>"},

            {"o", "<click_left>"},
            {"O", "<click_left>"},
            {"a", "<click_right>"},
            {"A", "<click_right>"},
            {"FF", "<easy_click_left>"},
            {"Fo", "<easy_click_left>"},
            {"Fa", "<easy_click_right>"},
            {"Fm", "<easy_click_mid>"},
            {"Fh", "<easy_click_hover>"},

            {"y", "<hotkey_copy>"},
            {"yy", "<hotkey_copy>"},
            {"Y", "<hotkey_copy>"},
            {"p", "<hotkey_paste>"},
            {"P", "<hotkey_paste>"},
            {"dd", "<hotkey_cut>"},
            {"D", "<hotkey_cut>"},
            {"x", "<hotkey_delete>"},
            {"<Del>", "<hotkey_delete>"},
            {"X", "<hotkey_backspace>"},
            {"<C-r>", "<redo>"},
            {"u", "<undo>"},
            {"U", "<undo>"},

            {"<C-v>h", "<switch_to_left_vdesktop>"},
            {"<C-v>l", "<switch_to_right_vdesktop>"},
            {"<C-v>n", "<create_new_vdesktop>"},
            {"<C-v>q", "<close_current_vdesktop>"},
            {"<C-v>s", "<taskview>"},

            {"gT", "<switch_to_left_tab>"},
            {"gt", "<switch_to_right_tab>"},

            {"/", "<search_pattern>"},
            {"?", "<search_pattern>"},

            {"<C-w>q", "<close_current_window>"},
            {"<C-w>c", "<close_current_window>"},
            {"<C-w>s", "<switch_window>"},
            {"<C-w>e", "<window_resizer>"},
            {"<C-w>h", "<select_left_window>"},
            {"<C-w>l", "<select_right_window>"},
            {"<C-w>k", "<select_upper_window>"},
            {"<C-w>j", "<select_lower_window>"},
            {"<C-w>u", "<maximize_current_window>"},
            {"<C-w>d", "<minimize_current_window>"},
            {"<C-w>H", "<snap_current_window_to_left>"},
            {"<C-w><Left>", "<snap_current_window_to_left>"},
            {"<C-w>L", "<snap_current_window_to_right>"},
            {"<C-w><Right>", "<snap_current_window_to_right>"},
            {"<C-w>K", "<snap_current_window_to_top>"},
            {"<C-w>J", "<snap_current_window_to_bottom>"},
            {"<C-w>=", "<arrange_windows>"},
            {"<C-w>r", "<rotate_windows>"},
            {"<C-w>R", "<rotate_windows_in_reverse>"},
            {"<C-w>x", "<exchange_window_with_nearest>"},
            {"<C-w><gt>", "<increase_window_width>"},
            {"<C-w><lt>", "<decrease_window_width>"},
            {"<C-w>+", "<increase_window_height>"},
            {"<C-w>-", "<decrease_window_height>"},
            {"<C-w>n", "<open_new_window>"},

            {"<gt>", "<goto_next_page>"},
            {"<lt>", "<goto_prev_page>"},

            {"<win>", "<open_startmenu>"},
        } ;
        return tmp ;
    }

    const std::vector<std::pair<std::string, std::string>>& gui_visual() {
        static std::vector<std::pair<std::string, std::string>> tmp = {
            {"<Esc-Left>", "<to_gui_normal>"},
            {"<ctrl-]>", "<to_gui_normal>"},
            {"<Esc-Down>", "<to_resident>"},
            {"h", "<move_cursor_left>"},
            {"<BS>", "<move_cursor_left>"},
            {"<Left>", "<move_cursor_left>"},
            {"l", "<move_cursor_right>"},
            {"<Space>", "<move_cursor_right>"},
            {"<Right>", "<move_cursor_right>"},
            {"k", "<move_cursor_up>"},
            {"-", "<move_cursor_up>"},
            {"<Up>", "<move_cursor_up>"},
            {"j", "<move_cursor_down>"},
            {"+", "<move_cursor_down>"},
            {"<Down>", "<move_cursor_down>"},
            {"0", "<jump_cursor_to_left>"},
            {"^", "<jump_cursor_to_left>"},
            {"<Home>", "<jump_cursor_to_left>"},
            {"$", "<jump_cursor_to_right>"},
            {"<End>", "<jump_cursor_to_right>"},
            {"gg", "<jump_cursor_to_top>"},
            {"G", "<jump_cursor_to_bottom>"},
            {"gm", "<jump_cursor_to_hcenter>"},
            {"M", "<jump_cursor_to_vcenter>"},
            {"<C-y>", "<scroll_up>"},
            {"<C-k>", "<scroll_up>"},
            {"<C-e>", "<scroll_down>"},
            {"<C-j>", "<scroll_down>"},
            {"<C-u>", "<scroll_up_halfpage>"},
            {"<C-d>", "<scroll_down_halfpage>"},
            {"<C-b>", "<scroll_up_onepage>"},
            {"<C-f>", "<scroll_down_onepage>"},
            {"zh", "<scroll_left>"},
            {"<C-h>", "<scroll_left>"},
            {"zl", "<scroll_right>"},
            {"<C-l>", "<scroll_right>"},
            {"zH", "<scroll_left_halfpage>"},
            {"zL", "<scroll_right_halfpage>"},
            {"y", "<hotkey_copy>"},
            {"yy", "<hotkey_copy>"},
            {"Y", "<hotkey_copy>"},
            {"p", "<hotkey_paste>"},
            {"P", "<hotkey_paste>"},
            {"dd", "<hotkey_cut>"},
            {"D", "<hotkey_cut>"},
            {"x", "<hotkey_delete>"},
            {"<Del>", "<hotkey_delete>"},
            {"X", "<hotkey_backspace>"},
        } ;
        return tmp ;
    }

    const std::vector<std::pair<std::string, std::string>>& edi_normal() {
        static std::vector<std::pair<std::string, std::string>> tmp = {
            {"<Esc-Left>", "<to_gui_normal>"},
            {"<Esc-Down>", "<to_resident>"},
            {"<ctrl-]>", "<to_gui_normal>"},
            {":", "<to_command>"},
            {"i", "<to_insert>"},
            {"v", "<to_edi_visual>"},
            {"V", "<to_edi_visual_line>"},
            {"<C-y>", "<scroll_up>"},
            {"<C-k>", "<scroll_up>"},
            {"<C-e>", "<scroll_down>"},
            {"<C-j>", "<scroll_down>"},
            {"<C-u>", "<scroll_up_halfpage>"},
            {"<C-d>", "<scroll_down_halfpage>"},
            {"<C-b>", "<scroll_up_onepage>"},
            {"<C-f>", "<scroll_down_onepage>"},
            {"zh", "<scroll_left>"},
            {"<C-h>", "<scroll_left>"},
            {"zl", "<scroll_right>"},
            {"<C-l>", "<scroll_right>"},
            {"zH", "<scroll_left_halfpage>"},
            {"zL", "<scroll_right_halfpage>"},
            {"<C-r>", "<redo>"},
            {"u", "<undo>"},
            {"U", "<undo>"},
            {"gT", "<switch_to_left_tab>"},
            {"gt", "<switch_to_right_tab>"},
            {"/", "<search_pattern>"},
            {"?", "<search_pattern>"},
            {"I", "<to_insert_BOL>"},
            {"gI", "<to_insert_BOL>"},
            {"a", "<to_insert_append>"},
            {"A", "<to_insert_EOL>"},
            {"o", "<to_insert_nlbelow>"},
            {"O", "<to_insert_nlabove>"},
            {"h", "<move_caret_left>"},
            {"<C-h>", "<move_caret_left>"},
            {"<BS>", "<move_caret_left>"},
            {"<Left>", "<move_caret_left>"},
            {"l", "<move_caret_right>"},
            {"<Space>", "<move_caret_right>"},
            {"<Right>", "<move_caret_right>"},
            {"k", "<move_caret_up>"},
            {"-", "<move_caret_up>"},
            {"gk", "<move_caret_up>"},
            {"<C-p>", "<move_caret_up>"},
            {"<Up>", "<move_caret_up>"},
            {"j", "<move_caret_down>"},
            {"+", "<move_caret_down>"},
            {"gj", "<move_caret_down>"},
            {"<C-n>", "<move_caret_down>"},
            {"<Down>", "<move_caret_down>"},
            {"<Enter>", "<move_caret_down>"},
            {"<C-m>", "<move_caret_down>"},
            {"w", "<move_fwd_word>"},
            {"b", "<move_bck_word>"},
            {"W", "<move_fwd_bigword>"},
            {"B", "<move_bck_bigword>"},
            {"e", "<move_end_word>"},
            {"E", "<move_end_bigword>"},
            {"ge", "<move_bckend_word>"},
            {"gE", "<move_bckend_bigword>"},
            {"0", "<jump_caret_to_BOL>"},
            {"<Home>", "<jump_caret_to_BOL>"},
            {"g0", "<jump_caret_to_BOL>"},
            {"$", "<jump_caret_to_EOL>"},
            {"<End>", "<jump_caret_to_EOL>"},
            {"g$", "<jump_caret_to_EOL>"},
            {"gg", "<jump_caret_to_BOF>"},
            {"G", "<jump_caret_to_EOF>"},
            {"yy", "<yank_line>"},
            {"Y", "<yank_line>"},
            {"y", "<yank_with_motion>"},
            {"p", "<put_after>"},
            {"P", "<put_before>"},
            {"dd", "<delete_line>"},
            {"D", "<delete_line_until_EOL>"},
            {"x", "<delete_after>"},
            {"<Del>", "<delete_after>"},
            {"X", "<delete_before>"},
            {"J", "<join_next_line>"},
            {"r", "<replace_char>"},
            {"R", "<replace_sequence>"},
            {"~", "<switch_char_case>"},
            {"d", "<delete_with_motion>"},
            {"c", "<change_with_motion>"},
            {"cc", "<change_line>"},
            {"S", "<change_line>"},
            {"s", "<change_char>"},
            {"C", "<change_until_EOL>"},
            {".", "<repeat_last_change>"},

        } ;
        return tmp ;
    }

    const std::vector<std::pair<std::string, std::string>>& edi_visual() {
        static std::vector<std::pair<std::string, std::string>> tmp = {
            {"<Esc-Left>", "<to_gui_normal>"},
            {"<ctrl-]>", "<to_gui_normal>"},
            {"<Esc-Down>", "<to_resident>"},
            {":", "<to_command>"},
            {"<Esc-Right>", "<to_edi_normal>"},
            {"<ctrl-[>", "<to_edi_normal>"},
            {"<C-y>", "<scroll_up>"},
            {"<C-k>", "<scroll_up>"},
            {"<C-e>", "<scroll_down>"},
            {"<C-j>", "<scroll_down>"},
            {"<C-u>", "<scroll_up_halfpage>"},
            {"<C-d>", "<scroll_down_halfpage>"},
            {"<C-b>", "<scroll_up_onepage>"},
            {"<C-f>", "<scroll_down_onepage>"},
            {"zh", "<scroll_left>"},
            {"<C-h>", "<scroll_left>"},
            {"zl", "<scroll_right>"},
            {"<C-l>", "<scroll_right>"},
            {"zH", "<scroll_left_halfpage>"},
            {"zL", "<scroll_right_halfpage>"},
            {"h", "<move_caret_left>"},
            {"<C-h>", "<move_caret_left>"},
            {"<BS>", "<move_caret_left>"},
            {"<Left>", "<move_caret_left>"},
            {"l", "<move_caret_right>"},
            {"<Space>", "<move_caret_right>"},
            {"<Right>", "<move_caret_right>"},
            {"k", "<move_caret_up>"},
            {"-", "<move_caret_up>"},
            {"gk", "<move_caret_up>"},
            {"<C-p>", "<move_caret_up>"},
            {"<Up>", "<move_caret_up>"},
            {"j", "<move_caret_down>"},
            {"+", "<move_caret_down>"},
            {"gj", "<move_caret_down>"},
            {"<C-n>", "<move_caret_down>"},
            {"<Down>", "<move_caret_down>"},
            {"<Enter>", "<move_caret_down>"},
            {"<C-m>", "<move_caret_down>"},
            {"w", "<move_fwd_word_simple>"},
            {"b", "<move_bck_word_simple>"},
            {"0", "<jump_caret_to_BOL>"},
            {"<Home>", "<jump_caret_to_BOL>"},
            {"g0", "<jump_caret_to_BOL>"},
            {"$", "<jump_caret_to_EOL>"},
            {"<End>", "<jump_caret_to_EOL>"},
            {"g$", "<jump_caret_to_EOL>"},
            {"gg", "<jump_caret_to_BOF>"},
            {"G", "<jump_caret_to_EOF>"},
            {"y", "<yank_highlight_text>"},
            {"d", "<delete_highlight_text>"},
            {"x", "<delete_highlight_text>"},
            {"X", "<delete_highlight_text>"},
            {"c", "<change_highlight_text>"},
            {"s", "<change_highlight_text>"},
            {"S", "<change_highlight_text>"},

        } ;
        return tmp ;
    }

    const std::vector<std::pair<std::string, std::string>>& insert() {
        static std::vector<std::pair<std::string, std::string>> tmp = {
            {"<Esc-Left>", "<to_gui_normal>"},
            {"<ctrl-]>", "<to_gui_normal>"},
            {"<F8>", "<to_instant_gui_normal>"},
            {"<Esc-Down>", "<to_resident>"},
            {"<Esc-Right>", "<to_edi_normal>"},
            {"<ctrl-[>", "<to_edi_normal>"},
        } ;
        return tmp ;
    }

    const std::vector<std::pair<std::string, std::string>>& resident() {
        static std::vector<std::pair<std::string, std::string>> tmp = {
            {"<Esc-Left>", "<to_gui_normal>"},
            {"<Esc-Down>", "<to_resident>"},
            {"<Esc-Right>", "<to_edi_normal>"},
            {"<Esc-up>", "<to_insert>"},
        } ;
        return tmp ;
    }

    const std::vector<std::pair<std::string, std::string>>& command() {
        static std::vector<std::pair<std::string, std::string>> tmp = {
            {"guinormal", "<to_gui_normal>"},
            {"gn", "<to_gui_normal>"},
            {"resident", "<to_resident>"},
            {"guivisual", "<to_gui_visual>"},
            {"gv", "<to_gui_visual>"},
            {"edinormal", "<to_edi_normal>"},
            {"en", "<to_edi_normal>"},
            {"insert", "<to_insert>"},
            {"i", "<to_insert>"},
            {"edivisual", "<to_edi_visual>"},
            {"ev", "<to_edi_visual>"},
            {"edivisualline", "<to_edi_visual_line>"},
            {"evl",  "<to_edi_visual_line>"},
            {"vdprev", "<switch_to_left_vdesktop>"},
            {"vdnext", "<switch_to_right_vdesktop>"},
            {"closev", "<close_current_vdesktop>"},
            {"taskview", "<taskview>"},
            {"tv", "<taskview>"},
            {"vdesktop<space>list",  "<taskview>"},
            {"tabprevious",  "<switch_to_left_tab>"},
            {"tabnext",  "<switch_to_right_tab>"},
            {"tabnew", "<open_new_tab>"},
            {"cl", "<close_current_window>"},
            {"close", "<close_current_window>"},
            {"sw", "<switch_window>"},
            {"switch", "<switch_window>"},
            {"resizer",  "<window_resizer>"},
            {"winresizer", "<window_resizer>"},
            {"max",  "<maximize_current_window>"},
            {"on", "<maximize_current_window>"},
            {"only", "<maximize_current_window>"},
            {"min",  "<minimize_current_window>"},
            {"hi", "<minimize_current_window>"},
            {"hide", "<minimize_current_window>"},
            {"lsplit", "<snap_current_window_to_left>"},
            {"lsp",  "<snap_current_window_to_left>"},
            {"rsplit", "<snap_current_window_to_right>"},
            {"rsp",  "<snap_current_window_to_right>"},
            {"tsplit", "<snap_current_window_to_top>"},
            {"tsp",  "<snap_current_window_to_top>"},
            {"bsplit", "<snap_current_window_to_bottom>"},
            {"bsp",  "<snap_current_window_to_bottom>"},
            {"arrange",  "<arrange_windows>"},
            {"rotate", "<rotate_windows>"},
            {"rot",  "<rotate_windows>"},
            {"rerotate", "<rotate_windows_in_reverse>"},
            {"rerot", "<rotate_windows_in_reverse>"},
            {"exchange", "<exchange_window_with_nearest>"},
            {"vertical<space>resize", "<resize_window_width>"},
            {"vert<space>res", "<resize_window_width>"},
            {"vertical<space>resize<space>+", "<increase_window_width>"},
            {"vert<space>res<space>+",  "<increase_window_width>"},
            {"vertical<space>resize<space>-", "<decrease_window_width>"},
            {"vert<space>res<space>-",  "<decrease_window_width>"},
            {"resize", "<resize_window_height>"},
            {"res",  "<resize_window_height>"},
            {"resize<space>+",  "<increase_window_height>"},
            {"res<space>+", "<increase_window_height>"},
            {"resize<space>-",  "<decrease_window_height>"},
            {"res<space>-", "<decrease_window_height>"},
            {"new",  "<open_new_window>"},
            {"sp", "<open_new_window_with_hsplit>"},
            {"split", "<open_new_window_with_hsplit>"},
            {"vs", "<open_new_window_with_vsplit>"},
            {"vsplit", "<open_new_window_with_vsplit>"},
            {"w", "<save>"},
            {"q", "<close_current_tab>"},
            {"q!", "<close_current_tab>"},
            {"tabclose", "<close_current_tab>"},
            {"sh", "<start_shell>"},
            {"shell", "<start_shell>"},
            {"terminal", "<start_shell>"},
            {"term", "<start_shell>"},
            {"ex", "<start_explorer>"},
            {"explorer", "<start_explorer>"},
            {"win",  "<open_startmenu>"},
            {"start", "<open_startmenu>"},
            {"!", "<start_external>"},
            {"e", "<execute>"},
            {"edit", "<execute>"},
            {"execute",  "<execute>"},
            {"setgui", "<show_config_gui>"},
            {"exit", "<exit_config_gui>"},
            {"find", "<open>"},
            {"open", "<open>"},
            {"mkdir", "<makedir>"},
            {"md", "<makedir>"},
            {"reload", "<reload_current_window>"},
            {"target", "<enable_targeting_of_dedicate_to_window>"},
            {"untarget", "<disable_targeting_of_dedicate_to_window>"},
            {"-", "<move_caret_up>"},
            {"+", "<move_caret_down>"},
            {"<num>", "<jump_caret_to_BOF>"},
            {"forward",  "<forward_ui_navigation>"},
            {"backward", "<backward_ui_navigation>"},
            {"decide", "<decide_focused_ui_object>"},
            {"set",  "<set>"},

            {"map", "<map>"},
            {"noremap", "<noremap>"},
            {"unmap", "<unmap>"},
            {"mapclear", "<mapclear>"},
            {"gmap", "<gmap>"},
            {"gnoremap", "<gnoremap>"},
            {"gunmap", "<gunmap>"},
            {"gmapclear", "<gmapclear>"},
            {"emap", "<emap>"},
            {"enoremap", "<enoremap>"},
            {"eunmap", "<eunmap>"},
            {"emapclear", "<emapclear>"},
            {"nmap", "<nmap>"},
            {"nnoremap", "<nnoremap>"},
            {"nunmap", "<nunmap>"},
            {"nmapclear", "<nmapclear>"},
            {"vmap", "<vmap>"},
            {"vnoremap", "<vnoremap>"},
            {"vunmap", "<vunmap>"},
            {"vmapclear", "<vmapclear>"},
            {"gnmap", "<gnmap>"},
            {"gnnoremap", "<gnnoremap>"},
            {"gnunmap", "<gnunmap>"},
            {"gnmapclear", "<gnmapclear>"},
            {"gvmap", "<gvmap>"},
            {"gvnoremap", "<gvnoremap>"},
            {"gvunmap", "<gvunmap>"},
            {"gvmapclear", "<gvmapclear>"},
            {"enmap", "<enmap>"},
            {"ennoremap", "<ennoremap>"},
            {"enunmap", "<enunmap>"},
            {"enmapclear", "<enmapclear>"},
            {"evmap", "<evmap>"},
            {"evnoremap", "<evnoremap>"},
            {"evunmap", "<evunmap>"},
            {"evmapclear", "<evmapclear>"},
            {"imap", "<imap>"},
            {"inoremap", "<inoremap>"},
            {"iunmap", "<iunmap>"},
            {"imapclear", "<imapclear>"},
            {"rmap", "<rmap>"},
            {"rnoremap", "<rnoremap>"},
            {"runmap", "<runmap>"},
            {"rmapclear", "<rmapclear>"},
            {"cmap", "<cmap>"},
            {"cnoremap", "<cnoremap>"},
            {"cunmap", "<cunmap>"},
            {"cmapclear", "<cmapclear>"},

            {"com",  "<command>"},
            {"command",  "<command>"},
            {"delc", "<delcommand>"},
            {"delcommand", "<delcommand>"},
            {"comc", "<comclear>"},
            {"comclear", "<comclear>"},
            {"so", "<source>"},
            {"source", "<source>"},
        } ;
        return tmp ;
    }
}


namespace vind
{
    namespace bind
    {
        const std::vector<std::pair<std::string, std::string>>& get_default_map(core::Mode mode) {
            using core::Mode, core::ModeArray ;
            static auto tmp = [] {
                ModeArray<std::vector<std::pair<std::string, std::string>>> tmp_ ;
                tmp_[static_cast<int>(Mode::GUI_NORMAL)] = gui_normal() ;
                tmp_[static_cast<int>(Mode::GUI_VISUAL)] = gui_visual() ;
                tmp_[static_cast<int>(Mode::EDI_NORMAL)] = edi_normal() ;
                tmp_[static_cast<int>(Mode::EDI_VISUAL)] = edi_visual() ;
                tmp_[static_cast<int>(Mode::INSERT)]     = insert() ;
                tmp_[static_cast<int>(Mode::RESIDENT)]   = resident() ;
                tmp_[static_cast<int>(Mode::COMMAND)]    = command() ;
                return tmp_ ;
            }() ;
            return tmp[static_cast<int>(mode)] ;
        }
    }
}
