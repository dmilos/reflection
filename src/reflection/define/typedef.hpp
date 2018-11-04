#ifndef reflection_define_typedef
#define reflection_define_typedef

#define reflection__CLASS_TYPEDEF( typedef_string_name, typedef_symbolic_name ) \
 { \
  typedef /*decltype( typedef_string_name)*/ std::string identifier_type;     \
  typedef  ::reflection::content::typedefinition::pure_class<identifier_type,typedef_symbolic_name> typedef_type; \
  auto                                  typedef_instance =                 ::memory::pointer::make( typedef_type() );  \
  auto   property_instance = item_type( typedef_instance );  \
  insert( typedef_string_name, property_instance );  \
 }


#endif


