#ifndef reflection_define_insert
#define reflection_define_insert

//#define reflection__CLASS_MEMBER_inspect(    member_string_name,   reader_full_symbolic_name   )\



#define reflection__CLASS_MEMBER_inspect(    member_string_name, class_symbolic_name, reader_symbolic_name  )\
  insert                                                 \
   (                                                     \
     member_string_name                                  \
    ,item_type                                           \
     (                                                   \
      ::memory::pointer::make                            \
       (                                                 \
        ::reflection::content::inspect::member           \
         (                                               \
           this                                          \
          ,&class_symbolic_name::reader_symbolic_name    \
         )                                               \
       )                                                 \
     )                                                   \
   );                                                    \

#define reflection__CLASS_SIMPLE_inspect(   member_string_name, type_symbolic_name, value_instance )\
  insert                                                \
   (                                                    \
     member_string_name                                 \
    ,item_type                                          \
     (                                                  \
      ::memory::pointer::make                           \
       (                                                \
        ::reflection::content::inspect::simple          \
          <                                             \
           type_symbolic_name                           \
          >                                             \
          (                                             \
           value_instance                               \
          )                                             \
       )                                                \
     )                                                  \
   );                                                   \

   
/*
inspect\
    member.hpp
    pretend-member.hpp

*/

#endif
