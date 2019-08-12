#ifndef reflection_define_friend
#define reflection_define_friend

// reflection__CLASS_friend( friend_string_name, class_symbolic_name, friend_symbolic_name )


#define reflection__CLASS_friend( friend_string_name, class_symbolic_name, friend_symbolic_name ) \
 { \
  typedef /*decltype( friend_string_name)*/ std::string identifier_type;     \
  typedef  ::reflection::content::frienddeclaration::pure_class<identifier_type,friend_symbolic_name> friend_type; \
  auto                                  friend_instance = ::memory::pointer::make( friend_type( #friend_symbolic_name ) );  \
  auto   property_instance = item_type( friend_instance );  \
  insert( friend_string_name, property_instance );  \
 }

#endif


