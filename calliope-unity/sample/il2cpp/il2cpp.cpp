#include "il2cpp.hpp"

il2cpp::structures::image_t* il2cpp::structures::image_t::get_image_by_name( const char* const name ) {
	static const auto domain = functions::domain_get( );

	if ( const auto assembly = functions::domain_assembly_open( domain, name ) )
		return functions::assembly_get_image( assembly );

	return nullptr;
}

il2cpp::structures::string_t* il2cpp::structures::string_t::make( const char* const buffer ) {
	return functions::string_new( buffer );
}

il2cpp::structures::class_t* il2cpp::structures::image_t::get_class( const char* const namespace_name, const char* const class_name ) const {
	if ( !this )
		return nullptr;

	return functions::class_from_name( this, namespace_name, class_name );
}

il2cpp::structures::method_t* il2cpp::structures::class_t::get_method_from_name( const char* method_name, std::int32_t parameter_count ) const {
	if ( !this )
		return nullptr;

	return functions::class_get_method_from_name( this, method_name, parameter_count );
}

il2cpp::structures::method_t* il2cpp::structures::class_t::get_method_from_name_with_arg( const char* method_name, std::int32_t parameter_count, const char* arg_name ) const {
	if ( !this )
		return nullptr;

	void* iter{ };

	while ( auto method = functions::class_get_methods( this, &iter ) ) {
		if ( !strcmp( functions::method_get_name( method ), method_name ) ) {
			auto param_count = functions::method_get_param_count( method );
			if ( param_count == parameter_count ) {
				for ( int idx{ 0 }; idx < param_count; idx++ ) {
					auto param_name = functions::method_get_param_name( method, idx );
					if ( !strcmp( param_name, arg_name ) )
						return method;
				}
			}
		}
	}

	return nullptr;
}

il2cpp::structures::field_t* il2cpp::structures::class_t::get_field( const char* const name ) const {
	if ( !this )
		return nullptr;

	return functions::class_get_field_from_name( this, name );
}

std::size_t il2cpp::structures::field_t::get_offset( ) const {
	if ( !this )
		return 0;

	return functions::field_get_offset( this );
}

il2cpp::structures::type_t* il2cpp::structures::class_t::get_type( ) const {
	if ( !this )
		return nullptr;

	return functions::class_get_type( this );
}

void* il2cpp::structures::type_t::get_object( ) const {
	if ( !this )
		return nullptr;

	return functions::type_get_object( this );
}