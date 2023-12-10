#pragma once
#include "../../shared/general_deps.hpp"

#define TO_STR( x ) #x
#define DO_API( name, fn_def ) using name##_t = fn_def; const auto name = reinterpret_cast< name##_t >( GetProcAddress( il2cpp_handle, TO_STR( ##il2cpp_##name ) ) );

namespace il2cpp {
	const auto il2cpp_handle = GetModuleHandleA( "GameAssembly.dll" );

	namespace structures {
		struct domain_t;
		struct assembly_t;

		struct image_t {
			static image_t* get_image_by_name( const char* const name );
			struct class_t* get_class( const char* const namespace_name, const char* const class_name ) const;
		};

		struct string_t {
			std::uint8_t m_pad[ 0x10 ];
			std::uint32_t m_size{ };
			wchar_t m_buffer[ 128 + 1 ];

			static string_t* make( const char* const buffer );
		};

		struct method_t {
			void* method_ptr;

			template< typename def >
			def get_function_pointer( ) const {
				return reinterpret_cast< def >( this->method_ptr );
			}
		};

		struct field_t {
			std::uintptr_t get_offset( ) const;
		};

		struct type_t {
			void* get_object( ) const;
		};

		struct class_t {
			method_t* get_method_from_name( const char* method_name, std::int32_t parameter_count ) const;
			method_t* get_method_from_name_with_arg( const char* method_name, std::int32_t parameter_count, const char* arg_name ) const;

			field_t* get_field( const char* const name ) const;

			type_t* get_type( ) const;
		};
	}

	namespace functions {
		DO_API( domain_get, structures::domain_t* ( __cdecl* )( ) );
		DO_API( thread_attach, void( __cdecl* )( structures::domain_t* ) );
		DO_API( domain_assembly_open, structures::assembly_t* ( __cdecl* )( const structures::domain_t*, const char* ) );
		DO_API( domain_get_assemblies, structures::assembly_t** ( __cdecl* )( const structures::domain_t*, size_t* ) );

		DO_API( assembly_get_image, structures::image_t* ( __cdecl* )( const structures::assembly_t* ) );
		DO_API( image_get_name, const char* ( __cdecl* )( const structures::image_t* ) );

		DO_API( image_get_class_count, std::int32_t( __cdecl* )( const structures::image_t* ) );
		DO_API( image_get_class, structures::class_t* ( __cdecl* )( const structures::image_t*, std::int32_t ) );


		DO_API( class_from_name, structures::class_t* ( __cdecl* )( const structures::image_t*, const char*, const char* ) );
		DO_API( class_get_name, const char* ( __cdecl* )( const structures::class_t* ) );
		DO_API( class_get_namespace, const char* ( __cdecl* )( const structures::class_t* ) )
		DO_API( class_get_methods, structures::method_t* ( __cdecl* )( const structures::class_t*, void** ) );
		DO_API( class_get_method_from_name, structures::method_t* ( __cdecl* )( const structures::class_t*, const char*, std::int32_t ) );
		DO_API( class_get_fields, structures::field_t* ( __cdecl* )( const structures::class_t*, void** ) );
		DO_API( class_get_field_from_name, structures::field_t* ( __cdecl* ) ( const structures::class_t*, const char* ) );
		DO_API( class_get_type, structures::type_t* ( __cdecl* )( const structures::class_t* ) );
		DO_API( class_is_valuetype, bool( __cdecl* )( const structures::class_t* ) );
		DO_API( class_is_enum, bool( __cdecl* )( const structures::class_t* ) );
		DO_API( class_get_flags, std::int32_t( __cdecl* )( const structures::class_t* ) );
		DO_API( class_get_parent, structures::class_t* ( __cdecl* )( const structures::class_t* ) );
		DO_API( class_get_interfaces, structures::class_t* ( __cdecl* )( const structures::class_t*, void** ) );

		DO_API( method_get_return_type, structures::type_t* ( __cdecl* )( const structures::method_t* ) );
		DO_API( method_get_param_count, std::uint32_t( __cdecl* ) ( const structures::method_t* ) );
		DO_API( method_get_param, structures::type_t* ( __cdecl* ) ( const structures::method_t*, std::uint32_t ) );
		DO_API( method_get_param_name, const char* ( __cdecl* )( const structures::method_t*, std::uint32_t ) );
		DO_API( method_get_name, const char* ( __cdecl* )( const structures::method_t* ) );
		DO_API( method_get_flags, std::int32_t( __cdecl* )( const structures::class_t* ) );

		DO_API( field_get_offset, std::size_t( __cdecl* )( const structures::field_t* ) );
		DO_API( field_get_type, structures::type_t* ( __cdecl* )( const structures::field_t* ) );
		DO_API( field_get_name, const char* ( __cdecl* )( const structures::field_t* ) );
		DO_API( field_get_flags, std::int32_t( __cdecl* )( const structures::field_t* ) );


		DO_API( type_get_object, void* ( __cdecl* )( const structures::type_t* ) );
		DO_API( type_get_name, const char* ( __cdecl* )( const structures::type_t* ) );

		DO_API( object_new, void* ( __cdecl* ) ( const structures::class_t* ) );

		DO_API( string_new, structures::string_t* ( __cdecl* ) ( const char* ) );
		DO_API( resolve_icall, void* ( __cdecl* )( const char* ) );
	}
}