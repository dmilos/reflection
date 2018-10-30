#ifndef reflection_define_exposed
#define reflection_define_exposed

// reflection__CLASS_MEMBER_exposed( member_string_name, writter_full_symbolic_name  reader_full_symbolic_name   )\


#define reflection__CLASS_MEMBER_exposed( member_string_name, class_symbolic_name, traitor_symbolic_name, writer_symbolic_name   )\
  insert                                                \
   (                                                    \
     member_string_name                                 \
    ,item_type                                          \
     (                                                  \
      ::memory::pointer::make                           \
       (                                                \
        ::reflection::content::exposed::member          \
         <std::string>                                  \
         (                                              \
           this                                         \
          ,&class_symbolic_name::traitor_symbolic_name  \
          ,&class_symbolic_name::writer_symbolic_name    \
         )                                              \
       )                                                \
     )                                                  \
   );                                                   \

#define reflection__CLASS_SIMPLE_exposed( member_string_name, type_symbolic_name, value_instance )\
  insert                                                \
   (                                                    \
     member_string_name                                 \
    ,item_type                                          \
     (                                                  \
      ::memory::pointer::make                           \
       (                                                \
        ::reflection::content::exposed::simple          \
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
