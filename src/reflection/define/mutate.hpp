#ifndef reflection_define_mutate
#define reflection_define_mutate

// reflection__CLASS_MEMBER_mutate( member_string_name, writer_full_symbolic_name  )\





#define reflection__CLASS_FIELD_mutate( field_string_name, class_symbolic_name, field_symbolic_name )\
 {                                                      \
  typedef /*decltype( field_string_name )*/ std::string identifier_type;     \
  insert                                                \
   (                                                    \
     field_string_name                                  \
    ,item_type                                          \
     (                                                  \
      ::memory::pointer::make                           \
       (                                                \
        ::reflection::content::mutate::field            \
         <identifier_type>                              \
         (                                              \
            (class_symbolic_name*)(nullptr)             \
            ,&class_symbolic_name::field_symbolic_name  \
         )                                              \
       )                                                \
     )                                                  \
   );                                                   \
 }


#define reflection__CLASS_MEMBER_mutate( member_string_name, class_symbolic_name, writer_symbolic_name )\
 {                                                      \
  typedef /*decltype( member_string_name )*/ std::string identifier_type;     \
  insert                                                \
   (                                                    \
     member_string_name                                 \
    ,item_type                                          \
     (                                                  \
      ::memory::pointer::make                           \
       (                                                \
        ::reflection::content::mutate::member           \
         <identifier_type>                              \
         (                                              \
           (class_symbolic_name*)(nullptr)              \
          ,&class_symbolic_name::writer_symbolic_name   \
         )                                              \
       )                                                \
     )                                                  \
    );                                                  \
 }


#define reflection__CLASS_SIMPLE_mutate( member_string_name, type_symbolic_name, value_instance )\
 {                                                      \
  typedef /*decltype( member_string_name )*/ std::string identifier_type;     \
  insert                                                \
   (                                                    \
     member_string_name                                 \
    ,item_type                                          \
     (                                                  \
      ::memory::pointer::make                           \
       (                                                \
        ::reflection::content::mutate::simple           \
          <                                             \
           identifier_type, type_symbolic_name          \
          >                                             \
          (                                             \
           value_instance                               \
          )                                             \
       )                                                \
     )                                                  \
    );                                                  \
 }



/*
mutate\
    member.hpp
    simple.hpp
   pretend-member.hpp

   */
#endif
