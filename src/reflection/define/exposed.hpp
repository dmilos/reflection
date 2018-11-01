#ifndef reflection_define_exposed
#define reflection_define_exposed

// reflection__CLASS_MEMBER_exposed( member_string_name, writter_full_symbolic_name  reader_full_symbolic_name   )\



#define reflection__CLASS_MEMBER_exposed( member_string_name, class_symbolic_name, traitor_symbolic_name, writer_symbolic_name   )\
 {                                                      \
  typedef /*decltype( member_string_name )*/ std::string identifier_type;     \
  insert                                                \
   (                                                    \
     member_string_name                                 \
    ,item_type                                          \
     (                                                  \
      ::memory::pointer::make                           \
       (                                                \
        ::reflection::content::exposed::member          \
         <identifier_type>                              \
         (                                              \
           (class_symbolic_name*)(nullptr)              \
          ,&class_symbolic_name::traitor_symbolic_name  \
          ,&class_symbolic_name::writer_symbolic_name   \
         )                                              \
       )                                                \
     )                                                  \
    );                                                  \
 }


#define reflection__CLASS_SIMPLE_exposed( member_string_name, type_symbolic_name, value_instance )\
 {                                                              \
  typedef /*decltype( member_string_name )*/ std::string identifier_type;     \
  insert                                                \
   (                                                    \
     member_string_name                                 \
    ,item_type                                          \
     (                                                  \
      ::memory::pointer::make                           \
       (                                                \
        ::reflection::content::exposed::simple          \
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
