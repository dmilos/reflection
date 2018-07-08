#ifndef reflection_define_mutate
#define reflection_define_mutate

// reflection__CLASS_MEMBER_mutate( member_string_name, writter_full_symbolic_name  )\



#define reflection__CLASS_MEMBER_mutate( member_string_name, class_symbolic_name, writter_symbolic_name )\
  insert                                                \
   (                                                    \
     member_string_name                                 \
    ,item_type                                          \
     (                                                  \
      ::memory::pointer::make                           \
       (                                                \
        ::reflection::content::mutate::member           \
         (                                              \
           this                                         \
          ,&class_symbolic_name::writter_symbolic_name  \
         )                                              \
       )                                                \
     )                                                  \
   );

/*
mutate\
    member.hpp
    simple.hpp
   pretend-member.hpp

   */
#endif
