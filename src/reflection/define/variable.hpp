#ifndef reflection_define_variable
#define reflection_define_variable

// reflection__CLASS_MEMBER_variable( member_string_name, reader_full_symbolic_name, traitor_full_symbolic_name  )
// reflection__CLASS_SIMPLE_variable( member_string_name, type_symbolic_name, value_instance )

#define reflection__CLASS_MEMBER_variable( member_string_name, class_symbolic_name, traitor_symbolic_name, reader_symbolic_name  )\
 {                                                              \
  typedef /*decltype( member_string_name )*/ std::string identifier_type;     \
  insert                                                       \
   (                                                           \
     member_string_name                                        \
    ,item_type                                                 \
     (                                                         \
      ::memory::pointer::make                                  \
       (                                                       \
        ::reflection::content::variable::member                \
         <identifier_type>                                     \
         (                                                     \
           (class_symbolic_name*)(nullptr)                     \
          ,&class_symbolic_name::traitor_symbolic_name         \
          ,&class_symbolic_name::reader_symbolic_name          \
         )                                                     \
       )                                                       \
     )                                                         \
   );                                                          \
 }

#define reflection__CLASS_SIMPLE_variable( member_string_name, type_symbolic_name, value_instance )\
 {                                                      \
  typedef /*decltype( member_string_name )*/ std::string identifier_type;     \
  insert                                                \
   (                                                    \
     member_string_name                                 \
    ,item_type                                          \
     (                                                  \
      ::memory::pointer::make                           \
       (                                                \
        ::reflection::content::variable::simple         \
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

#endif
