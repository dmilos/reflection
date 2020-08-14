#ifndef reflection_define_function
#define reflection_define_function





#define reflection__CLASS_FUNCTION_member( function_string_name, class_symbolic_name, accessibility_name, function_symbolic_name ) \
 {                                                             \
  typedef /*decltype( member_string_name )*/ std::string identifier_type;     \
  auto instance = ::reflection::content::function::member<identifier_type>  \
         (                                                    \
            (pointer_type)(nullptr)                  \
          , &class_symbolic_name::function_symbolic_name      \
         );  \
  instance.accessibility( ::reflection::ornament::accessibility_class::from_string( #accessibility_name ) ); \
  instance.linkage(    ::reflection::ornament::linkage_class::default_index   ); \
  instance.qualification( ::reflection::ornament::qualification_class::get< decltype(&class_symbolic_name::function_symbolic_name) >( ) ); \
  insert                                                      \
   (                                                          \
     function_string_name                                     \
    ,item_type( ::memory::pointer::make( instance ) )                \
   );                                                        \
 }


#define reflection__CLASS_FUNCTION_static( function_string_name, class_symbolic_name, accessibility_name, function_symbolic_name ) \
 {                                                      \
  typedef /*decltype( member_string_name )*/ std::string identifier_type;     \
  auto instance = ::reflection::content::function::static_function<identifier_type>  \
         (                                                    \
           &class_symbolic_name::function_symbolic_name      \
         );  \
  instance.accessibility( ::reflection::ornament::accessibility_class::from_string( #accessibility_name ) );  \
  instance.linkage(    ::reflection::ornament::linkage_class::static_index   ); \
  /*instance.relation( ::reflection::ornament::relation_class::member_index );*/ \
  insert                                             \
   (                                                 \
     function_string_name                            \
    ,item_type( ::memory::pointer::make( instance ) )       \
    );                                               \
 }


#define reflection__CLASS_FUNCTION_free(      function_string_name,   function_symbolic_name   ) \
 {                                                      \
  typedef /*decltype( member_string_name )*/ std::string identifier_type;     \
  insert                                             \
   (                                                 \
     function_string_name                            \
    ,item_type                                       \
     (                                               \
      ::memory::pointer::make                        \
       (                                             \
        ::reflection::content::function::free<identifier_type>       \
         (                                           \
          function_symbolic_name                     \
         )                                           \
       )                                             \
     )                                               \
    );                                               \
 }



#endif
