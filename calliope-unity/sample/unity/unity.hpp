#pragma once
#include "../il2cpp/il2cpp.hpp"

namespace UnityEngine {
	class Rect {
	public:
		float left, top, right, bottom;
	public:
		explicit Rect( float l, float t, float r, float b ) : left( l ), top( t ), right( r ), bottom( b ) { }
	};

	class Color {
	public:
		float R, G, B, A;
	public:
		explicit Color( float r, float g, float b, float a ) : R( r ), G( g ), B( b ), A( a ) { }
	};

	class Vector2 {
	public:
		float x, y;
	public:
		Vector2(  ) : x( 0.f ), y( 0.f ) { }
		explicit Vector2( float x, float y ) : x( x ), y( y ) { }
	};

	class Vector4 {
	public:
		float x, y, z, w;
	public:
		Vector4( ) : x( 0.f ), y( 0.f ), z( 0.f ), w( 0.f ) { }
		explicit Vector4( float x, float y, float z, float w ) : x( x ), y( y ), z( z ), w( w ) { }
	};

	class Object {
	public:
		static void DontDestroyOnLoad( void* object ) {
			static const auto dont_destroy_on_load = il2cpp::structures::image_t::get_image_by_name( "UnityEngine.CoreModule" )
				->get_class( "UnityEngine", "Object" )->get_method_from_name( __func__, 1 )->get_function_pointer< void( * )( void* )>( );

			return dont_destroy_on_load( object );
		}
	};

	class GameObject : public Object {
	public:
		static void Internal_CreateGameObject( void* il2cppObject, il2cpp::structures::string_t* name ) {
			static const auto internal_create_game_object = il2cpp::structures::image_t::get_image_by_name( "UnityEngine.CoreModule" )
				->get_class( "UnityEngine", "GameObject" )->get_method_from_name( __func__, 2 )->get_function_pointer<void( * )( void*, il2cpp::structures::string_t* )>( );

			return internal_create_game_object( il2cppObject, name );
		}

		class Component* AddComponent( il2cpp::structures::type_t* classType ) {
			static const auto add_component = il2cpp::structures::image_t::get_image_by_name( "UnityEngine.CoreModule" )
				->get_class( "UnityEngine", "GameObject" )->get_method_from_name( __func__, 1 )->get_function_pointer<class Component*( * )( void*, void* )>( );

			return add_component( this, classType->get_object( ) );
		}
	};


	class AssetBundle {
	public:
		static AssetBundle* LoadFromFile( il2cpp::structures::string_t* path ) {
			static const auto load_from_file = reinterpret_cast< AssetBundle * ( * )( il2cpp::structures::string_t*, std::uint32_t, std::uint64_t ) >( il2cpp::functions::resolve_icall( "UnityEngine.AssetBundle::LoadFromFile_Internal(System.String,System.UInt32,System.UInt64)" ) );
			return load_from_file( path, 0u, 0llu );
		}

		template<typename T>
		T LoadAsset( il2cpp::structures::string_t* name, il2cpp::structures::type_t* type ) {
			static const auto load_asset = reinterpret_cast< T( * )( void*, il2cpp::structures::string_t*, void* ) >( il2cpp::functions::resolve_icall( "UnityEngine.AssetBundle::LoadAsset_Internal(System.String,System.Type)" ) );
			return load_asset( this, name, type->get_object( ) );
		}
	};

	class Shader {
	public:
		static Shader* Find( il2cpp::structures::string_t* name ) {
			static const auto find = il2cpp::structures::image_t::get_image_by_name( "UnityEngine.CoreModule" )
				->get_class( "UnityEngine", "Shader" )->get_method_from_name( __func__, 1 )->get_function_pointer<Shader* ( * )( il2cpp::structures::string_t* )>( );

			return find( name );
		}
	};

	class Material {
	public:
		static void CreateWithShader( Material* self, Shader* shader ) {
			static const auto create_with_shader = il2cpp::structures::image_t::get_image_by_name( "UnityEngine.CoreModule" )
				->get_class( "UnityEngine", "Material" )->get_method_from_name( __func__, 2 )->get_function_pointer<void( * )( Material*, Shader* )>( );

			return create_with_shader( self, shader );
		}

		void SetInt( il2cpp::structures::string_t* property, std::int32_t value ) {
			static const auto set_int = il2cpp::structures::image_t::get_image_by_name( "UnityEngine.CoreModule" )
				->get_class( "UnityEngine", "Material" )->get_method_from_name( __func__, 2 )->get_function_pointer<void( * )( void*, il2cpp::structures::string_t*, std::int32_t )>( );

			return set_int( this, property, value );
		}

		void SetPass( std::int32_t pass ) {
			static const auto set_pass = il2cpp::structures::image_t::get_image_by_name( "UnityEngine.CoreModule" )
				->get_class( "UnityEngine", "Material" )->get_method_from_name( __func__, 1 )->get_function_pointer<void( * )( void*, std::int32_t )>( );

			return set_pass( this, pass );
		}
	};

	class Texture2D {
	public:
		static UnityEngine::Texture2D* get_whiteTexture( ) {
			static const auto get_white_texture = il2cpp::structures::image_t::get_image_by_name( "UnityEngine.CoreModule" )
				->get_class( "UnityEngine", "Texture2D" )->get_method_from_name( __func__, 0 )->get_function_pointer< UnityEngine::Texture2D* ( * )( )>( );

			return get_white_texture( );
		}
	};

	class GUIContent {
	public:
		static GUIContent* Temp( il2cpp::structures::string_t* str ) {
			static const auto temp = il2cpp::structures::image_t::get_image_by_name( "UnityEngine.IMGUIModule" )->get_class( "UnityEngine", "GUIContent" )->get_method_from_name_with_arg(
				__func__, 1, "t" )->get_function_pointer< GUIContent* ( * )( il2cpp::structures::string_t* ) >( );

			return temp( str );
		}
	};

	class GUIStyle {
	public:
		int get_fontSize( ) {
			static const auto get_font_size = il2cpp::structures::image_t::get_image_by_name( "UnityEngine.IMGUIModule" )
				->get_class( "UnityEngine", "GUIStyle" )->get_method_from_name( __func__, 0 )->get_function_pointer< std::int32_t( * )( decltype( this ) )>( );

			return get_font_size( this );
		}

		void set_fontSize( std::int32_t value ) {
			static const auto set_font_size = il2cpp::structures::image_t::get_image_by_name( "UnityEngine.IMGUIModule" )
				->get_class( "UnityEngine", "GUIStyle" )->get_method_from_name( __func__, 1 )->get_function_pointer< void( * )( decltype( this ), std::int32_t )>( );

			return set_font_size( this, value );
		}

		Vector2 CalcSize( il2cpp::structures::string_t* text ) {
			static const auto calc_size = reinterpret_cast< void( * )( void*, GUIContent*, Vector2& ) >( il2cpp::functions::resolve_icall( "UnityEngine.GUIStyle::Internal_CalcSize_Injected( UnityEngine.GUIContent,UnityEngine.Vector2&)" ) );

			const auto content = GUIContent::Temp( text );

			Vector2 size{ };
			calc_size( this, content, size );

			return size;
		}

		__declspec( property( get = get_fontSize, put = set_fontSize ) ) std::int32_t fontSize;
	};

	class Input {
	public:
		static Vector2 get_mouseScrollDelta( ) {
			static const auto get_mouse_scroll_delta = il2cpp::structures::image_t::get_image_by_name( "UnityEngine.InputLegacyModule" )
				->get_class( "UnityEngine", "Input" )->get_method_from_name( "get_mouseScrollDelta_Injected", 1 )->get_function_pointer<void( * )( Vector2& )>( );

			Vector2 out;
			get_mouse_scroll_delta( out );
			return out;
		}

		static float GetAxis( il2cpp::structures::string_t* axis ) {
			static const auto get_axis = il2cpp::structures::image_t::get_image_by_name( "UnityEngine.InputLegacyModule" )
				->get_class( "UnityEngine", "Input" )->get_method_from_name( "get_mouseScrollDelta", 0 )->get_function_pointer<float( * )( il2cpp::structures::string_t* )>( );

			return get_axis( axis );
		}
	};

	class Event {
	public:
		enum class EventType : int32_t {
			MouseDown = 0,
			MouseUp = 1,
			MouseDrag = 3,
			KeyDown = 4,
			KeyUp = 5,
			Repaint = 7
		};

		static Event* get_current( ) {
			static const auto get_current = il2cpp::structures::image_t::get_image_by_name( "UnityEngine.IMGUIModule" )
				->get_class( "UnityEngine", "Event" )->get_method_from_name( __func__, 0 )->get_function_pointer< Event* ( * )( )>( );

			return get_current( );
		}

		EventType get_type( ) {
			static const auto get_type = il2cpp::structures::image_t::get_image_by_name( "UnityEngine.IMGUIModule" )
				->get_class( "UnityEngine", "Event" )->get_method_from_name( __func__, 0 )->get_function_pointer< EventType ( * )( void* )>( );

			return get_type( this );
		}

		__declspec( property( get = get_type ) ) EventType type;
	};

	// Undocumented
	class GUIClip {
	public:
		static void Push( UnityEngine::Rect screenRect, UnityEngine::Vector2 scrollOffset, UnityEngine::Vector2 renderOffset, bool resetOffset ) {
			static const auto push = reinterpret_cast< void( * )( UnityEngine::Rect&, UnityEngine::Vector2&, UnityEngine::Vector2&, bool ) >( il2cpp::functions::resolve_icall( "UnityEngine.GUIClip::Internal_Push_Injected(UnityEngine.Rect&,UnityEngine.Vector2&,UnityEngine.Vector2&,System.Boolean)" ) );
			return push( screenRect, scrollOffset, renderOffset, resetOffset );
		}

		static void Pop( ) {
			static const auto pop = reinterpret_cast< void( * )( ) >( il2cpp::functions::resolve_icall( "UnityEngine.GUIClip::Internal_Pop()" ) );
			return pop( );
		}
	};

	class GUISkin {
	public:
		GUIStyle* get_label( ) {
			static const auto get_label = il2cpp::structures::image_t::get_image_by_name( "UnityEngine.IMGUIModule" )
				->get_class( "UnityEngine", "GUISkin" )->get_method_from_name( __func__, 0 )->get_function_pointer< GUIStyle* ( * )( decltype( this ) )>( );

			return get_label( this );
		}

		__declspec( property( get = get_label ) ) UnityEngine::GUIStyle* label;
	};

	class GUI {
	public:
		static GUISkin* get_skin( ) {
			static const auto get_skin = il2cpp::structures::image_t::get_image_by_name( "UnityEngine.IMGUIModule" )
				->get_class( "UnityEngine", "GUI" )->get_method_from_name( __func__, 0 )->get_function_pointer< UnityEngine::GUISkin* ( * )( )>( );

			return get_skin( );
		}

		static void set_color( UnityEngine::Color value ) {
			static const auto set_color = il2cpp::structures::image_t::get_image_by_name( "UnityEngine.IMGUIModule" )
				->get_class( "UnityEngine", "GUI" )->get_method_from_name( __func__, 1 )->get_function_pointer< void( * )( UnityEngine::Color )>( );

			return set_color( value );
		}

		static UnityEngine::Color get_color( ) {
			static const auto get_color = il2cpp::structures::image_t::get_image_by_name( "UnityEngine.IMGUIModule" )
				->get_class( "UnityEngine", "GUI" )->get_method_from_name( __func__, 0 )->get_function_pointer< UnityEngine::Color( * )( )>( );

			return get_color( );
		}

		static void DrawTexture( UnityEngine::Rect position, UnityEngine::Texture2D* image ) {
			static const auto draw_texture = il2cpp::structures::image_t::get_image_by_name( "UnityEngine.IMGUIModule" )
				->get_class( "UnityEngine", "GUI" )->get_method_from_name( __func__, 2 )->get_function_pointer< void( * )( UnityEngine::Rect, UnityEngine::Texture2D* )>( );

			return draw_texture( position, image );
		}

		// thanks zion
		static void DrawTexture2( UnityEngine::Rect Position, UnityEngine::Texture2D* Texture, int32_t ScaleMode, bool AlphaBlend, float ImageAspect, UnityEngine::Color Color, float BorderWidth, float BorderRadius )
		{
			static const auto draw_texture = il2cpp::structures::image_t::get_image_by_name( "UnityEngine.IMGUIModule" )
				->get_class( "UnityEngine", "GUI" )->get_method_from_name( "DrawTexture", 8 )->get_function_pointer<void ( * )( UnityEngine::Rect, UnityEngine::Texture2D*, int32_t, bool, float, UnityEngine::Color, float, float )>( );

			return draw_texture( Position, Texture, ScaleMode, AlphaBlend, ImageAspect, Color, BorderWidth, BorderRadius );
		}

		// thanks zion
		static void DrawTexture3( UnityEngine::Rect Position, UnityEngine::Texture2D* Texture, int32_t ScaleMode, bool AlphaBlend, float ImageAspect, UnityEngine::Color Color, Vector4 BorderWidths, Vector4 BorderRadiuses, bool DrawSmoothCorners )
		{
			static const auto draw_texture = il2cpp::structures::image_t::get_image_by_name( "UnityEngine.IMGUIModule" )
				->get_class( "UnityEngine", "GUI" )->get_method_from_name( "DrawTexture", 9 )->get_function_pointer<  void ( * )( UnityEngine::Rect, UnityEngine::Texture2D*, int32_t, bool, float, UnityEngine::Color, Vector4, Vector4, bool ) >( );

			return draw_texture( Position, Texture, ScaleMode, AlphaBlend, ImageAspect, Color, BorderWidths, BorderRadiuses, DrawSmoothCorners );
		}

		static void Label( UnityEngine::Rect rect, GUIContent* content, GUIStyle* style ) {
			static const auto label = il2cpp::structures::image_t::get_image_by_name( "UnityEngine.IMGUIModule" )->get_class( "UnityEngine", "GUI" )->get_method_from_name_with_arg(
				__func__, 3, "content" )->get_function_pointer< void( * )( UnityEngine::Rect, GUIContent*, GUIStyle* ) >( );

			return label( rect, content, style );
		}
	};

	class GL {
	public:
		enum Mode : std::int32_t {
			Lines = 1,
			LineStrip = 2,
			Triangles = 4,
			TriangleStrip = 5,
			Quads = 7
		};

		//static void Viewport( Rect pixelRect ) {
		//	static const auto viewport = il2cpp::structures::image_t::get_image_by_name( "UnityEngine.CoreModule" )
		//		->get_class( "UnityEngine", "GL" )->get_method_from_name( __func__, 1 )->get_function_pointer< void( * )( Rect )>( );

		//	return viewport( pixelRect );
		//}

		static void PushMatrix( ) {
			static const auto push_matrix = il2cpp::structures::image_t::get_image_by_name( "UnityEngine.CoreModule" )
				->get_class( "UnityEngine", "GL" )->get_method_from_name( __func__, 0 )->get_function_pointer< void( * )( )>( );

			return push_matrix( );
		}

		static void PopMatrix( ) {
			static const auto push_matrix = il2cpp::structures::image_t::get_image_by_name( "UnityEngine.CoreModule" )
				->get_class( "UnityEngine", "GL" )->get_method_from_name( __func__, 0 )->get_function_pointer< void( * )( )>( );

			return push_matrix( );
		}

		static void Begin( Mode mode ) {
			static const auto begin = il2cpp::structures::image_t::get_image_by_name( "UnityEngine.CoreModule" )
				->get_class( "UnityEngine", "GL" )->get_method_from_name( __func__, 1 )->get_function_pointer< void( * )( Mode )>( );

			return begin( mode );
		}

		static void End( ) {
			static const auto end = il2cpp::structures::image_t::get_image_by_name( "UnityEngine.CoreModule" )
				->get_class( "UnityEngine", "GL" )->get_method_from_name( __func__, 0 )->get_function_pointer< void( * )( )>( );

			return end( );
		}

		static void Color( UnityEngine::Color color ) {
			static const auto vertex3 = il2cpp::structures::image_t::get_image_by_name( "UnityEngine.CoreModule" )
				->get_class( "UnityEngine", "GL" )->get_method_from_name( __func__, 1 )->get_function_pointer< void( * )( UnityEngine::Color )>( );

			return vertex3( color );
		}

		static void Vertex3( float x, float y, float z ) {
			static const auto vertex3 = il2cpp::structures::image_t::get_image_by_name( "UnityEngine.CoreModule" )
				->get_class( "UnityEngine", "GL" )->get_method_from_name( __func__, 3 )->get_function_pointer< void( * )( float, float, float )>( );

			return vertex3( x, y, z );
		}
	};
}