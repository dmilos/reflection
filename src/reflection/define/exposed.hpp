#ifndef reflection_define_exposed
#define reflection_define_exposed

// reflection__CLASS_MEMBER_exposed( member_string_name, writer_full_symbolic_name  reader_full_symbolic_name   )\





#define reflection__CLASS_FIELD_exposed( field_string_name, class_symbolic_name, field_symbolic_name )\
 {                                                      \
  typedef /*decltype( field_string_name )*/ std::string identifier_type;     \
  insert                                                \
   (                                                    \
     field_string_name                                  \
    ,item_type                                          \
     (                                                  \
      ::memory::pointer::make                           \
       (                                                \
        ::reflection::content::exposed::field            \
         <identifier_type>                              \
         (                                              \
           (class_symbolic_name*)(nullptr)              \
          ,&class_symbolic_name::field_symbolic_name    \
         )                                              \
       )                                                \
     )                                                  \
   );                                                   \
 }


#define reflection__CLASS_STATIC_exposed( common_string_name, class_symbolic_name, common_symbolic_name ) \
 {                                                                                                        \
  typedef /*decltype( common_string_name )*/ std::string identifier_type;                                 \
  insert                                                                                                  \
   (                                                                                                      \
    common_string_name                                                                                    \
    ,item_type                                                                                            \
     (                                                                                                    \
      ::memory::pointer::make                                                                             \
       (                                                                                                  \
        ::reflection::content::exposed::common                                                            \
        <identifier_type,class_symbolic_name>                                                             \
         (                                                                                                \
          &class_symbolic_name::common_symbolic_name                                                      \
         )                                                                                                \
       )                                                                                                  \
     )                                                                                                    \
   );                                                                                                     \
  }


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
