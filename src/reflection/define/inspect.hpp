#ifndef reflection_define_insert
#define reflection_define_insert

//#define reflection__CLASS_FIELD_inspect( field_string_name, class_symbolic_name, field_symbolic_name )\
//#define reflection__CLASS_MEMBER_inspect(    member_string_name,   reader_full_symbolic_name   )\




#define reflection__CLASS_FIELD_inspect( field_string_name, class_symbolic_name, field_symbolic_name )\
 {                                                      \
  typedef /*decltype( field_string_name )*/ std::string identifier_type;     \
  insert                                                \
   (                                                    \
     field_string_name                                  \
    ,item_type                                          \
     (                                                  \
      ::memory::pointer::make                           \
       (                                                \
        ::reflection::content::inspect::field           \
         <identifier_type>                              \
         (                                              \
           (class_symbolic_name*)(nullptr)              \
          ,&class_symbolic_name::field_symbolic_name    \
         )                                              \
       )                                                \
     )                                                  \
   );                                                   \
 }


#define reflection__CLASS_STATIC_inspect( common_string_name, class_symbolic_name, common_symbolic_name )  \
 {                                                                                                        \
  typedef /*decltype( common_string_name )*/ std::string identifier_type;                                 \
  insert                                                                                                  \
   (                                                                                                      \
    common_string_name                                                                                    \
    ,item_type                                                                                            \
     (                                                                                                    \
      ::memory::pointer::make                                                                             \
       (                                                                                                  \
        ::reflection::content::inspect::common                                                             \
        <identifier_type,class_symbolic_name>                                                             \
         (                                                                                                \
          &class_symbolic_name::common_symbolic_name                                                      \
         )                                                                                                \
       )                                                                                                  \
     )                                                                                                    \
   );                                                                                                     \
  }


#define reflection__CLASS_MEMBER_inspect(    member_string_name, class_symbolic_name, reader_symbolic_name  )\
 {                                                       \
  typedef /*decltype( member_string_name )*/ std::string identifier_type;     \
  insert                                                 \
   (                                                     \
     member_string_name                                  \
    ,item_type                                           \
     (                                                   \
      ::memory::pointer::make                            \
       (                                                 \
        ::reflection::content::inspect::member           \
         <identifier_type>                               \
         (                                               \
           (class_symbolic_name*)(nullptr)               \
          ,&class_symbolic_name::reader_symbolic_name    \
         )                                               \
       )                                                 \
     )                                                   \
    );                                                   \
 }


#define reflection__CLASS_SIMPLE_inspect(   member_string_name, type_symbolic_name, value_instance )\
 {                                                      \
  typedef /*decltype( member_string_name )*/ std::string identifier_type;     \
  insert                                                \
   (                                                    \
     member_string_name                                 \
    ,item_type                                          \
     (                                                  \
      ::memory::pointer::make                           \
       (                                                \
        ::reflection::content::inspect::simple          \
          <                                             \
           identifier_type, type_symbolic_name          \
          >                                             \
          (                                             \
           value_instance                               \
          )                                             \
       )                                                \
     )                                                  \
    );                                                          \
 }



/*
inspect\
    member.hpp
    pretend-member.hpp

*/

#endif
