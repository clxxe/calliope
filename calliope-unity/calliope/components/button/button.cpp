#pragma once
#include "../../calliope.hpp"

const calliope::color_t button_back_color( 18, 18, 18, 255 );

void calliope::menu_t::components_t::button( const char* name, std::function<void( )> callback ) {
	if ( !menu.m_current_groupbox )
		return;

	auto button_position = menu.m_current_groupbox->cursor_position + vec2_t( 15, 5 );
	auto button_size = vec2_t( menu.m_current_groupbox->size.x - 54, 24 );

	menu.drawing.filled_rect( button_position, button_size, button_back_color, 0.f );

	const bool in_use = menu.window_ctx.m_active_hash == util::hash( name );
	const bool was_empty_last_hash = menu.window_ctx.m_last_hash == 0 && menu.window_ctx.m_active_hash == 0;

	const bool hovered = menu.mouse_in_rect(
		menu.m_current_groupbox->position + button_position + vec2_t( 0, calliope::globals::group_box_padding + 15 ),
		menu.m_current_groupbox->position + button_position + button_size + vec2_t( 0, calliope::globals::group_box_padding + 15 )
	);

	color_t text_color = color_t( 74, 74, 74, 255 );

	if ( hovered ) {
		color_t text_color = color_t( 164, 164, 164, 255 );

		menu.drawing.filled_rect( button_position, button_size, globals::palette::white.alpha( 10 ), 0.f );
	}
	if ( hovered && !in_use && was_empty_last_hash && ( menu.mouse_active && !menu.old_mouse_active ) ) {
		menu.window_ctx.m_active_hash = util::hash( name );
	}
	else if ( in_use && !menu.mouse_active ) {
		text_color = globals::palette::white;
		menu.drawing.rect( button_position + vec2_t( 1, 1 ), button_size - vec2_t( 2, 2 ), globals::menu_accent, 0.f );

		callback( );

		menu.window_ctx.m_active_hash = 0;
	}

	auto text_size = menu.drawing.calc_text_size( name );

	menu.drawing.text( vec2_t( button_position.x + ( button_size.x / 2 ) - ( text_size.x / 2 ), button_position.y + ( button_size.y / 2 ) - ( text_size.y / 2 ) ), name, text_color, text_flags::text_flags_none );
	menu.drawing.rect( button_position, button_size, globals::palette::black, 0.f );

	menu.m_current_groupbox->cursor_position.y += button_size.y + 5;
}