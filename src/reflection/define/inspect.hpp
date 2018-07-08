#ifndef reflection_define_insert
#define reflection_define_insert

//#define reflection__CLASS_MEMBER_inspect(    member_string_name,   reader_full_symbolic_name   )\



#define reflection__CLASS_MEMBER_inspect(    member_string_name, class_symbolic_name,  reader_symbolic_name   )\
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

/*
inspect\
    member.hpp
    simple.hpp
    pretend-member.hpp

*/

#endif
