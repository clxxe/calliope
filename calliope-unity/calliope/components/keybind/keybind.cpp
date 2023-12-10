#include "../../calliope.hpp"

constexpr const char* key_names[ ] = {
        "xxx", "left mouse", "right mouse", "break", "middle mouse", "mouse 4", "mouse 5",
        "xxx", "backspace", "tab", "xxx", "xxx", "xxx", "enter", "xxx", "xxx", "shift",
        "ctrl", "alt", "pause", "caps lock", "xxx", "xxx", "xxx", "xxx", "xxx", "xxx",
        "xxx", "xxx", "xxx", "xxx", "xxx", "spacebar", "page up", "page down", "end", "home", "left",
        "up", "right", "down", "xxx", "print", "xxx", "print screen", "insert", "delete", "xxx", "0", "1",
        "2", "3", "4", "5", "6", "7", "8", "9", "xxx", "xxx", "xxx", "xxx", "xxx", "xxx",
        "xxx", "a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u",
        "v", "w", "x", "y", "z", "left windows", "right windows", "xxx", "xxx", "xxx", "num 0", "num 1",
        "num 2", "num 3", "num 4", "num 5", "num 6", "num 7", "num 8", "num 9", "*", "+", "_", "-", ".", "/", "f1", "f2", "f3",
        "f4", "f5", "f6", "f7", "f8", "f9", "f10", "f11", "f12", "f13", "f14", "f15", "f16", "f17", "f18", "f19", "f20", "f21",
        "f22", "f23", "f24", "xxx", "xxx", "xxx", "xxx", "xxx", "xxx", "xxx", "xxx",
        "num lock", "scroll lock", "xxx", "xxx", "xxx", "xxx", "xxx", "xxx", "xxx",
        "xxx", "xxx", "xxx", "xxx", "xxx", "xxx", "xxx", "lshift", "rshift", "lcontrol",
        "rcontrol", "lmenu", "rmenu", "xxx", "xxx", "xxx", "xxx", "xxx", "xxx", "xxx",
        "xxx", "xxx", "xxx", "next track", "previous track", "stop", "play/pause", "xxx", "xxx",
        "xxx", "xxx", "xxx", "xxx", ";", "+", ",", "-", ".", "/?", "~", "xxx", "xxx",
        "xxx", "xxx", "xxx", "xxx", "xxx", "xxx", "xxx", "xxx", "xxx",
        "xxx", "xxx", "xxx", "xxx", "xxx", "xxx", "xxx", "xxx", "xxx",
        "xxx", "xxx", "xxx", "xxx", "xxx", "xxx", "[{", "\\|", "}]", "'\"", "xxx",
        "xxx", "xxx", "xxx", "xxx", "xxx", "xxx", "xxx", "xxx", "xxx",
        "xxx", "xxx", "xxx", "xxx", "xxx", "xxx", "xxx", "xxx", "xxx",
        "xxx", "xxx", "xxx", "xxx", "xxx", "xxx", "xxx", "xxx", "xxx",
        "xxx", "xxx"
};

// TODO: Finish non-inlined keybinds...
void calliope::menu_t::components_t::keybind( const char* name, int& key, bool inlined ) {
    if ( inlined ) {
        if ( !menu.m_current_groupbox )
            return;

        auto label_position = menu.m_current_groupbox->cursor_position + vec2_t( menu.m_current_groupbox->size.x - 24, 0 );

        const bool in_use = menu.window_ctx.m_active_hash == util::hash( name );
        const bool was_empty_last_hash = menu.window_ctx.m_last_hash == 0 && menu.window_ctx.m_active_hash == 0;

        auto label = key_names[ key ] == "xxx" ? "..." : key_names[ key ];
        auto label_size = menu.drawing.calc_text_size( label );

        auto bordered_label = "[" + std::string( label ) + "]";
        auto bordered_label_size = menu.drawing.calc_text_size( bordered_label.c_str( ) );

        label_position.x -= bordered_label_size.x;

        const bool hovered = menu.mouse_in_rect(
            menu.m_current_groupbox->position + label_position + vec2_t( 0, calliope::globals::group_box_padding + 15 ),
            menu.m_current_groupbox->position + label_position + bordered_label_size + vec2_t( 0, calliope::globals::group_box_padding + 15 )
        );

        if ( hovered && !in_use && was_empty_last_hash && util::is_key_pressed( VK_LBUTTON ) ) {
            menu.window_ctx.m_active_hash = util::hash( name );
        }
        else if ( in_use ) {
            for ( int i{ }; i < 256; i++ ) {
                if ( util::is_key_pressed( i ) ) {
                    if ( key_names[ i ] != "xxx" )
                        key = i;

                    menu.window_ctx.m_active_hash = 0;
                }

                if ( util::is_key_pressed( VK_ESCAPE ) ) {
                    key = 0;
                    menu.window_ctx.m_active_hash = 0;
                }
            }
        }

        menu.drawing.text( label_position, bordered_label.c_str( ), in_use ? globals::menu_accent : ( hovered ? ( color_t( 160, 160, 160, 255 ) ) : color_t( 50, 50, 50, 255 ) ), text_flags::text_flags_style_dropshadow );
    }
}