#ifndef reflection_define_variable
#define reflection_define_variable

// reflection__CLASS_MEMBER_variable( member_string_name, reader_full_symbolic_name, traitor_full_symbolic_name  )


#define reflection__CLASS_MEMBER_variable( member_string_name, class_symbolic_name, traitor_symbolic_name, reader_symbolic_name  )\
  insert                                                       \
   (                                                           \
     member_string_name                                        \
    ,item_type                                                 \
     (                                                         \
      ::memory::pointer::make                                  \
       (                                                       \
        ::reflection::content::variable::member                \
         <std::string>                                         \
         (                                                     \
           this                                                \
          ,&class_symbolic_name::traitor_symbolic_name         \
          ,&class_symbolic_name::reader_symbolic_name          \
         )                                                     \
       )                                                       \
     )                                                         \
   );

#define reflection__CLASS_SIMPLE_variable( member_string_name, type_symbolic_name, value_instance )\
  insert                                                \
   (                                                    \
     member_string_name                                 \
    ,item_type                                          \
     (                                                  \
      ::memory::pointer::make                           \
       (                                                \
        ::reflection::content::variable::simple         \
          <                                             \
           std::string, type_symbolic_name              \
          >                                             \
          (                                             \
           value_instance                               \
          )                                             \
       )                                                \
     )                                                  \
   );  


#endif
