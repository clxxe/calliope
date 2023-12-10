#include "unity/unity.hpp"
#include "../calliope/calliope.hpp"

class swap_ptr_c
{
private:
	std::uintptr_t m_original{ 0 };
public:
	auto setup( std::pair<uintptr_t, void*> functions ) -> void {
		const auto [to_hook, replacement] = functions;

		m_original = *reinterpret_cast< std::uintptr_t* >( to_hook );
		*reinterpret_cast< void** >( to_hook ) = replacement;
	}

	template<typename T>
	T get_original( ) {
		return reinterpret_cast< T > ( m_original );
	}
};

UnityEngine::Material* DrawMaterial;
UnityEngine::AssetBundle* MainBundle;

calliope::color_t calliope::globals::menu_accent( 156, 129, 238, 255 );
int calliope::globals::menu_alpha = 255;

void FilledRect( calliope::vec2_t position, calliope::vec2_t size, calliope::color_t color, float rounding = 0.f ) {
	if ( const auto whiteTexture = UnityEngine::Texture2D::get_whiteTexture( ) ) {
		UnityEngine::GUI::DrawTexture3( UnityEngine::Rect( position.x, position.y, size.x, size.y ), whiteTexture, 0, false, 0.f, *( UnityEngine::Color* ) ( &color ), UnityEngine::Vector4( 0.f, 0.f, 0.f, 0.f ), UnityEngine::Vector4( rounding, rounding, rounding, rounding ), true );
	}
}

void Rect( calliope::vec2_t position, calliope::vec2_t size, calliope::color_t color, float rounding = 0.f ) {
	if ( const auto whiteTexture = UnityEngine::Texture2D::get_whiteTexture( ) ) {
		UnityEngine::GUI::DrawTexture2( UnityEngine::Rect( position.x, position.y, size.x, size.y ), whiteTexture, 0, false, 0.f, *( UnityEngine::Color* ) ( &color ), 1.f, rounding );
	}
}

void MultiColorFilledRect( calliope::vec2_t position, calliope::vec2_t size, std::array<calliope::color_t, 4> colors ) {

	DrawMaterial->SetPass( 0 );

	UnityEngine::GL::PushMatrix( );
	UnityEngine::GL::Begin( UnityEngine::GL::Mode::Quads );

	UnityEngine::GL::Color( UnityEngine::Color( colors[ 0 ].r, colors[ 0 ].g, colors[ 0 ].b, colors[ 0 ].a ) );
	UnityEngine::GL::Vertex3( position.x, position.y, 0 );

	UnityEngine::GL::Color( UnityEngine::Color( colors[ 1 ].r, colors[ 1 ].g, colors[ 1 ].b, colors[ 1 ].a ) );
	UnityEngine::GL::Vertex3( position.x + size.x, position.y, 0 );

	UnityEngine::GL::Color( UnityEngine::Color( colors[ 2 ].r, colors[ 2 ].g, colors[ 2 ].b, colors[ 2 ].a ) );
	UnityEngine::GL::Vertex3( position.x + size.x, position.y + size.y, 0 );

	UnityEngine::GL::Color( UnityEngine::Color( colors[ 3 ].r, colors[ 3 ].g, colors[ 3 ].b, colors[ 3 ].a ) );
	UnityEngine::GL::Vertex3( position.x, position.y + size.y, 0 );

	UnityEngine::GL::Color( UnityEngine::Color( colors[ 0 ].r, colors[ 0 ].g, colors[ 0 ].b, colors[ 0 ].a ) );
	UnityEngine::GL::Vertex3( position.x, position.y, 0 );

	UnityEngine::GL::End( );
	UnityEngine::GL::PopMatrix( );
}

calliope::vec2_t CalcTextSize( const char* text ) {
	const auto il2cppStr = il2cpp::structures::string_t::make( text );

	const auto skin = UnityEngine::GUI::get_skin( );

	if ( !skin )
		return calliope::vec2_t( );

	const auto labelStyle = skin->label;
	if ( !labelStyle )
		return calliope::vec2_t( );

	auto result = labelStyle->CalcSize( il2cppStr );

	return calliope::vec2_t( result.x, result.y );
}

void _DrawText( calliope::vec2_t position, const char* text, calliope::color_t color, int flags ) {
	const auto il2cppStr = il2cpp::structures::string_t::make( text );
	const auto content = UnityEngine::GUIContent::Temp( il2cppStr );
	const auto skin = UnityEngine::GUI::get_skin( );

	if ( !skin )
		return;

	const auto labelStyle = skin->label;
	if ( !labelStyle )
		return;
	
	labelStyle->fontSize = 10;

	auto textSize = labelStyle->CalcSize( il2cppStr );

	if ( flags & calliope::menu_t::text_flags::text_flags_style_outline ) {
		UnityEngine::GUI::set_color( UnityEngine::Color( 0.f, 0.f, 0.f, color.a ) );

		UnityEngine::GUI::Label( UnityEngine::Rect( position.x + 1, position.y + 1, textSize.x, textSize.y ), content, labelStyle );
		UnityEngine::GUI::Label( UnityEngine::Rect( position.x - 1, position.y - 1, textSize.x, textSize.y ), content, labelStyle );
		UnityEngine::GUI::Label( UnityEngine::Rect( position.x + 1, position.y - 1, textSize.x, textSize.y ), content, labelStyle );
		UnityEngine::GUI::Label( UnityEngine::Rect( position.x - 1, position.y + 1, textSize.x, textSize.y ), content, labelStyle );
		UnityEngine::GUI::Label( UnityEngine::Rect( position.x + 1, position.y, textSize.x, textSize.y ), content, labelStyle );
		UnityEngine::GUI::Label( UnityEngine::Rect( position.x - 1, position.y, textSize.x, textSize.y ), content, labelStyle );
		UnityEngine::GUI::Label( UnityEngine::Rect( position.x, position.y - 1, textSize.x, textSize.y ), content, labelStyle );
		UnityEngine::GUI::Label( UnityEngine::Rect( position.x, position.y + 1, textSize.x, textSize.y ), content, labelStyle );
	}

	if ( flags & calliope::menu_t::text_flags::text_flags_style_dropshadow ) {
		UnityEngine::GUI::set_color( UnityEngine::Color( 0.f, 0.f, 0.f, color.a ) );
		UnityEngine::GUI::Label( UnityEngine::Rect( position.x + 1, position.y + 1, textSize.x, textSize.y ), content, labelStyle );
	}

	UnityEngine::GUI::set_color( UnityEngine::Color( color.r, color.g, color.b, color.a ) );
	UnityEngine::GUI::Label( UnityEngine::Rect( position.x, position.y, textSize.x, textSize.y ), content, labelStyle );
}

void PushClipRect( calliope::vec2_t mins, calliope::vec2_t maxs, bool allow_intersections ) {
	UnityEngine::GUIClip::Push( UnityEngine::Rect( mins.x, mins.y, fabs( maxs.x - mins.x ), fabs( maxs.y - mins.y ) ), UnityEngine::Vector2( ), UnityEngine::Vector2( ), false );
}

void PopClipRect( ) {
	return UnityEngine::GUIClip::Pop( );
}

void Image( calliope::vec2_t position, calliope::vec2_t size, void* sourceTexture ) {
	UnityEngine::GUI::set_color( UnityEngine::Color( 1.f, 1.f, 1.f, 1.f ) );
	UnityEngine::GUI::DrawTexture( UnityEngine::Rect( position.x, position.y, size.x, size.y ), reinterpret_cast< UnityEngine::Texture2D* >( sourceTexture ) );
}

swap_ptr_c dev_controls_ongui_hk;
swap_ptr_c performance_ui_update_hk;

std::array<bool, 31> checkboxes{  };

int key_bind_value;
float slider_float_value;
int slider_int_value;

int active_selectable;

calliope::color_t example_color( 0, 255, 255, 255 );

std::vector<const char*> selectables = {
	"Selectable 1",
	"Selectable 2",
	"Selectable 3",
	"Selectable 4",
	"Selectable 5",
	"Selectable 6",
	"Selectable 7",
	"Selectable 8",
	"Selectable 9",
	"Selectable 10",
};

std::string test_input;
std::vector<bool> multidrop_down_values{ false, false, false, false, false };
int dropdown_value;


void hk_DevControls_OnGUI( void* self ) {
	if ( !DrawMaterial ) {
		static const auto material_class = il2cpp::structures::image_t::get_image_by_name( "UnityEngine.CoreModule" )
			->get_class( "UnityEngine", "Material" );

		const auto shader = UnityEngine::Shader::Find( il2cpp::structures::string_t::make( "Hidden/Internal-Colored" ) );

		DrawMaterial = reinterpret_cast< UnityEngine::Material* >( il2cpp::functions::object_new( material_class ) );

		UnityEngine::Material::CreateWithShader( DrawMaterial, shader );

		DrawMaterial->SetInt( il2cpp::structures::string_t::make( "_SrcBlend" ), 5 );
		DrawMaterial->SetInt( il2cpp::structures::string_t::make( "_DstBlend" ), 10 );
		DrawMaterial->SetInt( il2cpp::structures::string_t::make( "_Cull" ), 0 );
		DrawMaterial->SetInt( il2cpp::structures::string_t::make( "_ZWrite" ), 0 );
	}

	if ( UnityEngine::Event::get_current( )->type != UnityEngine::Event::EventType::Repaint )
		return;

	calliope::util::get_key_states( );

	if ( ( UnityEngine::Input::get_mouseScrollDelta( ).y != 0.f ) ) {
		calliope::menu.mouse_wheel_delta = UnityEngine::Input::get_mouseScrollDelta( ).y > 0 ? 1.0f : -1.0f;
	}
	
	if ( calliope::menu.components.window( "chloehack", calliope::vec2_t( 250, 250 ), calliope::vec2_t( 550, 400 ), calliope::menu_t::window_flags_none ) ) {
		switch ( auto selected_tab = calliope::menu.components.tabs( { "aimbot", "visuals", "skill", "config" } ) ) {
		case 0: {
			auto groupbox_sz_x = ( calliope::menu.window_ctx.drawable_area.second.x - 10 ) / 2;
			auto groupbox_sz_y = ( calliope::menu.window_ctx.drawable_area.second.y );

			if ( auto groupbox_ctx = calliope::menu.components.groupbox( "General", calliope::vec2_t( 0, 0 ), calliope::vec2_t( groupbox_sz_x, groupbox_sz_y ) ) ) {

				calliope::menu.components.colorpicker( "Colorpicker (Supports Right Click)", calliope::globals::menu_accent, false );
				calliope::menu.components.checkbox( "Checkbox", checkboxes[ 0 ] );
				calliope::menu.components.slider( "Middle slider", "", slider_float_value, -10.f, 10.f );
				calliope::menu.components.slider( "Int slider", "", slider_int_value, 0, 10, { "Example slider description :)" } );

				calliope::menu.components.textbox( "Input box", test_input, 32 );
				calliope::menu.components.multi_dropdown( "Multi dropdown", { "One", "Two", "Three", "Four" }, multidrop_down_values );
				calliope::menu.components.dropdown( "Dropdown", { "One", "Two", "Three" }, dropdown_value );

				// Scroll overflow test...
				calliope::menu.components.keybind( "Keybind", key_bind_value, true );
				calliope::menu.components.checkbox( "Checkbox 1", checkboxes[ 1 ], { { "Hello Everyone!, How are you. Fine, thank you." } } );
				calliope::menu.components.checkbox( "Checkbox 2", checkboxes[ 2 ] );

				calliope::menu.components.colorpicker( "Colorpicker", example_color, true );

				for ( int i = 3; i < 31; i++ ) {
					char name_buf[ 32 ]{};
					sprintf_s( name_buf, "Checkbox %d", i );

					calliope::menu.components.checkbox( name_buf, checkboxes[ i ] );
				}

				calliope::menu.components.end_groupbox( );
			}

			if ( auto groupbox_two = calliope::menu.components.groupbox	( "Other", calliope::vec2_t( groupbox_sz_x + 10, 0 ), calliope::vec2_t( groupbox_sz_x, groupbox_sz_y ) ) ) {
				calliope::menu.components.begin_listbox( "Listbox", selectables, active_selectable, 120.f );
				calliope::menu.components.end_listbox( );

				calliope::menu.components.button( "Example Button", [ ]( ) { printf( "Hello!\n" ); } );

				calliope::menu.components.end_groupbox( );
			}
			break;
		}
		}

		calliope::menu.components.end_window( );
	}

	return;
}

void hk_PerformanceUI_Update( void* self ) {
	static bool setup;

	if ( !setup ) {
		const static auto game_object_class = il2cpp::structures::image_t::get_image_by_name( "UnityEngine.CoreModule" )
			->get_class( "UnityEngine", "GameObject" );

		const static auto dev_controls_class_type = il2cpp::structures::image_t::get_image_by_name( "Assembly-CSharp" )
			->get_class( "", "DevControls" )->get_type( );

		auto game_object = reinterpret_cast< UnityEngine::GameObject* >( il2cpp::functions::object_new( game_object_class ) );

		UnityEngine::GameObject::Internal_CreateGameObject( game_object, il2cpp::structures::string_t::make( "" ) );

		game_object->AddComponent( dev_controls_class_type );

		UnityEngine::Object::DontDestroyOnLoad( game_object );

		setup = true;
	}

	return performance_ui_update_hk.get_original<decltype( &hk_PerformanceUI_Update )>( )( self );
}

bool __stdcall DllMain( void*, std::uint32_t call_reason, void* ) {
	if ( call_reason == DLL_PROCESS_ATTACH ) {
		AllocConsole( );
		freopen_s( reinterpret_cast< FILE** >( stdout ), "CONOUT$", "w", stdout );

		calliope::menu.drawing.calc_text_size = CalcTextSize;
		calliope::menu.drawing.filled_rect = FilledRect;
		calliope::menu.drawing.rect = Rect;
		calliope::menu.drawing.text = _DrawText;
		calliope::menu.drawing.multi_color_filled_rect = MultiColorFilledRect;
		calliope::menu.drawing.push_clip_rect = PushClipRect;
		calliope::menu.drawing.pop_clip_rect = PopClipRect;

		const auto dev_controls_ongui = il2cpp::structures::image_t::get_image_by_name( "Assembly-CSharp" )
			->get_class( "", "DevControls" )->get_method_from_name( "OnGUI", 0 );

		const auto performance_ui_update = il2cpp::structures::image_t::get_image_by_name( "Facepunch.Unity" )
			->get_class( "Facepunch", "PerformanceUI" )->get_method_from_name( "Update", 0 );

		dev_controls_ongui_hk.setup( { reinterpret_cast< uintptr_t >( dev_controls_ongui ), &hk_DevControls_OnGUI } );
		performance_ui_update_hk.setup( { reinterpret_cast< uintptr_t >( performance_ui_update ), &hk_PerformanceUI_Update } );

		return true;
	}

	return false;
}