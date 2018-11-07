#ifndef reflection_define_function
#define reflection_define_function





#define reflection__CLASS_FUNCTION_member( function_string_name, class_symbolic_name, function_symbolic_name ) \
 {                                                            \
  typedef /*decltype( member_string_name )*/ std::string identifier_type;     \
  insert                                                      \
   (                                                          \
     function_string_name                                     \
    ,item_type                                                \
     (                                                        \
      ::memory::pointer::make                                 \
       (                                                      \
        ::reflection::content::function::member<identifier_type>  \
         (                                                    \
            (class_symbolic_name *)(nullptr)                  \
          , &class_symbolic_name::function_symbolic_name      \
         )                                                    \
       )                                                      \
     )                                                        \
    );                                                        \
 }


#define reflection__CLASS_FUNCTION_static( function_string_name, class_symbolic_name, function_symbolic_name ) \
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
          class_symbolic_name::function_symbolic_name\
         )                                           \
       )                                             \
     )                                               \
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
