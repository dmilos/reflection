#ifndef reflection_define_guarded
#define reflection_define_guarded

// reflection__CLASS_MEMBER_guarded( member_string_name, writter_full_symbolic_name  reader_full_symbolic_name   )\


#define reflection__CLASS_MEMBER_guarded( member_string_name, class_symbolic_name, writter_symbolic_name, reader_symbolic_name   )\
  insert                                                \
   (                                                    \
     member_string_name                                 \
    ,item_type                                          \
     (                                                  \
      ::memory::pointer::make                           \
       (                                                \
        ::reflection::content::guarded::member          \
         (                                              \
           this                                         \
          ,&class_symbolic_name::writter_symbolic_name  \
          ,&class_symbolic_name::reader_symbolic_name    \
         )                                              \
       )                                                \
     )                                                  \
   );                                                   \

/*
guarded\
    member.hpp
    simple.hpp

    */

#endif
