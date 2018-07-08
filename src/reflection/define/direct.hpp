#ifndef reflection_define_direct
#define reflection_define_direct

// reflection__CLASS_MEMBER_direct( member_string_name, traitor_full_symbolic_name )

//#define reflection__CLASS_SIMPLE_direct(      member_name,     class_original::asdas   )\

#define reflection__CLASS_MEMBER_direct( member_string_name, class_symbolic_name, traitor_symbolic_name )\
  insert                                                \
   (                                                    \
     member_string_name                                 \
    ,item_type                                          \
     (                                                  \
      ::memory::pointer::make                           \
       (                                                \
        ::reflection::content::direct::member           \
         (                                              \
           this                                         \
          ,&class_symbolic_name::traitor_symbolic_name  \
         )                                              \
       )                                                \
     )                                                  \
   );                                                   \


/*
direct\

  member.hpp
  reference.hpp
  simple.hpp
*/

#endif
