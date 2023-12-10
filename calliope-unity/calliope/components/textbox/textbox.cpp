#include "../../calliope.hpp"

const calliope::color_t textbox_back_color( 18, 18, 18, 255 );

// this is basically ripped/recoded from zgui thx zxvnme 
struct key_code_info {
	int vk;

	char regular;
	char shift;
};

static key_code_info special_characters[ 22 ] = {
		{48,  '0',  ')'},
		{49,  '1',  '!'},
		{50,  '2',  '@'},
		{51,  '3',  '#'},
		{52,  '4',  '$'},
		{53,  '5',  '%'},
		{54,  '6',  '^'},
		{55,  '7',  '&'},
		{56,  '8',  '*'},
		{57,  '9',  '('},
		{32,  ' ',  ' '},
		{192, '`',  '~'},
		{189, '-',  '_'},
		{187, '=',  '+'},
		{219, '[',  '{'},
		{220, '\\', '|'},
		{221, ']',  '}'},
		{186, ';',  ':'},
		{222, '\'', '"'},
		{188, ',',  '<'},
		{190, '.',  '>'},
		{191, '/',  '?'}
};

void calliope::menu_t::components_t::textbox( const char* name, std::string& value, const int max_length ) {
	if ( !menu.m_current_groupbox )
		return;

	auto textbox_position = menu.m_current_groupbox->cursor_position + vec2_t( 15, 15 );
	auto textbox_size = vec2_t( menu.m_current_groupbox->size.x - 54, 20 );

	menu.drawing.filled_rect( textbox_position, textbox_size, textbox_back_color, 0.f );
	menu.drawing.rect( textbox_position, textbox_size, globals::palette::black, 0.f );

	const bool was_empty_last_hash = menu.window_ctx.m_last_hash == 0 && menu.window_ctx.m_active_hash == 0;

	const bool hovered = menu.mouse_in_rect(
		menu.m_current_groupbox->position + textbox_position + vec2_t( 0, calliope::globals::group_box_padding + 15 ),
		menu.m_current_groupbox->position + textbox_position + textbox_size + vec2_t( 0, calliope::globals::group_box_padding + 15 )
	);

	static int active_alpha = 0;

	if ( hovered && was_empty_last_hash && util::is_key_pressed( VK_LBUTTON ) ) {
		menu.window_ctx.m_active_hash = util::hash( name );
	}
	else if ( menu.window_ctx.m_active_hash == util::hash( name ) ) {
		menu.drawing.rect( textbox_position + vec2_t( 1, 1 ), textbox_size - vec2_t( 2, 2 ), globals::menu_accent, 0.f );

		if ( util::is_key_pressed( VK_ESCAPE ) || util::is_key_pressed( VK_RETURN ) || ( !hovered && menu.mouse_active ) ) {
			menu.window_ctx.m_active_hash = 0;
		}
		else if ( util::is_key_pressed( VK_BACK ) && !value.empty( ) ) {
			value.pop_back( );
		}
		else if ( value.size( ) < max_length ) {
			for ( int k{ }; k < VK_OEM_8; k++ ) {
				bool is_invalid_key = ( k > VK_SPACE && k < static_cast< int >( '0' ) ) ||
					( k > static_cast< int >( '9' ) && k < static_cast< int >( 'A' ) ) ||
					( k > static_cast< int >( 'Z' ) && k < VK_OEM_1 );

				if ( is_invalid_key )
					continue;

				if ( k > static_cast< int >( '9' ) && k <= static_cast< int >( 'Z' ) ) {
					if ( util::is_key_pressed( k ) )
						value += util::is_key_held( VK_SHIFT ) ? static_cast< char >( k ) : static_cast< char >( k + 32 );
				}
				else { // handle special chars...
					if ( util::is_key_pressed( k ) ) {
						for ( int j = 0; j < sizeof( special_characters ); j++ ) {
							if ( special_characters[ j ].vk == k )
								value += util::is_key_held( VK_SHIFT ) ? special_characters[ j ].shift : special_characters[ j ].regular;
						}
					}
				}
			}
		}
	}

	auto label_text_sz = menu.drawing.calc_text_size( value.c_str( ) );
	auto name_text_sz = menu.drawing.calc_text_size( name );

	menu.drawing.text( textbox_position + vec2_t( 5, ( textbox_size.y / 2 ) - ( label_text_sz.y / 2 ) ), value.c_str( ), globals::palette::white, text_flags::text_flags_none );
	menu.drawing.text( textbox_position - vec2_t( 0, name_text_sz.y ), name, globals::palette::white, text_flags::text_flags_none );

	menu.m_current_groupbox->cursor_position.y += ( textbox_size.y * 2 ) + 5;
}