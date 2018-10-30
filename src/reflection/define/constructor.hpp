#ifndef reflection_define_constructor
#define reflection_define_constructor

// TODO

#define reflection__CLASS_constructor( constructor_string_name, class_symbolic_name, constructor_symbolic_name ) \
 { \
  insert                                             \
   (                                                 \
     constructor_string_name                         \
    ,item_type                                       \
     (                                               \
      ::memory::pointer::make                        \
       (                                             \
        ::reflection::property::function::free       \
         (                                           \
          constructor_symbolic_name                  \
         )                                           \
       )                                             \
     )                                               \
   );                                                \
 }

#endif
