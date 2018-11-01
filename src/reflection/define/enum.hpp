#ifndef reflection_define_enum
#define reflection_define_enum

#define reflection__CLASS_ENUM_begin(  enumerator_string_name, class_symbolic_name, enumerator_symbolic_name ) \
 { \
  typedef /*decltype( enumerator_string_name)*/ std::string identifier_type;     \
  typedef enumerator_symbolic_name enumarator_type; \
  typedef std::string name_type; \
  typedef std::size_t value_type; \
  typedef   ::reflection::content::enumeration::pure_class<identifier_type,enumarator_type, name_type, value_type> enumeration_type; \
  auto                         enumeration_instance = ::memory::pointer::make( enumeration_type() );  \
  auto                            property_instance = item_type( enumeration_instance );  \
  insert( enumerator_string_name, property_instance );

#define reflection__CLASS_ENUM_value(  enumerant_string_name, enumerant_symbolic_name ) \
 { \
  enumeration_instance->push( enumerant_string_name, enumerant_symbolic_name ); \
 }

#define reflection__CLASS_ENUM_end( enumerator_symbolic_name ) \
 }


#endif
