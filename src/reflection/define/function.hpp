#ifndef reflection_define_function
#define reflection_define_function



#define reflection__CLASS_FUNCTION_member( function_string_name,  class_symbolic_name, function_symbolic_name ) \
  insert                                                      \
   (                                                          \
     function_string_name                                     \
    ,item_type                                                \
     (                                                        \
      ::memory::pointer::make                                 \
       (                                                      \
        ::reflection::property::function::member              \
         (                                                    \
            (class_symbolic_name *const)this                  \
          , &class_symbolic_name::function_symbolic_name      \
         )                                                    \
       )                                                      \
     )                                                        \
   );

#define reflection__CLASS_FUNCTION_free(      function_string_name,   function_symbolic_name   ) \
  insert                                             \
   (                                                 \
     function_string_name                            \
    ,item_type                                       \
     (                                               \
      ::memory::pointer::make                        \
       (                                             \
        ::reflection::property::function::free       \
         (                                           \
          function_symbolic_name                     \
         )                                           \
       )                                             \
     )                                               \
   );                                                \


#endif
