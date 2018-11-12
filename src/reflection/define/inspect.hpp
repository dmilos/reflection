#ifndef reflection_define_insert
#define reflection_define_insert

// reflection__CLASS_FIELD_inspect(   member_string_name, class_symbolic_name, field_symbolic_name )
// reflection__CLASS_STATIC_inspect( member_string_name, class_symbolic_name, accessibility_name, common_symbolic_name )
// reflection__CLASS_MEMBER_inspect( member_string_name,   reader_full_symbolic_name   )
// reflection__CLASS_SIMPLE_inspect( member_string_name, type_symbolic_name, value_instance )


#define reflection__CLASS_FIELD_inspect( member_string_name, class_symbolic_name, visibility_name, field_symbolic_name )\
 {                                                      \
  typedef /*decltype( member_string_name )*/ std::string identifier_type;     \
  auto instance =                                              \
        ::reflection::content::inspect::field           \
         <identifier_type>                              \
         (                                              \
           (class_symbolic_name*)(nullptr)              \
          ,&class_symbolic_name::field_symbolic_name    \
         );                                                                                                     \
  instance.visibility(    ::reflection::ornament::visibility_class::public_index   );  \
  /* TODO instance.linkage(    ::reflection::ornament::linkage_class::static_index   ); */ \
  insert                                                       \
   (                                                           \
     member_string_name                                        \
    ,item_type( ::memory::pointer::make( instance ) )          \
   );                                                          \
  }

#define reflection__CLASS_STATIC_inspect( member_string_name, class_symbolic_name, accessibility_name, common_symbolic_name )  \
 {                                                                                                        \
  typedef /*decltype( member_string_name )*/ std::string identifier_type;                                 \
  auto instance =                                              \
        ::reflection::content::inspect::common                                                             \
        <identifier_type,class_symbolic_name>                                                             \
         (                                                                                                \
          &class_symbolic_name::common_symbolic_name                                                      \
         );                                                                                                     \
  instance.visibility(    ::reflection::ornament::visibility_class::public_index   );  \
  instance.linkage(    ::reflection::ornament::linkage_class::static_index   );  \
  insert                                                       \
   (                                                           \
     member_string_name                                        \
    ,item_type( ::memory::pointer::make( instance ) )          \
   );                                                          \
  }

#define reflection__CLASS_MEMBER_inspect(    member_string_name, class_symbolic_name, reader_symbolic_name  )\
 {                                                       \
  typedef /*decltype( member_string_name )*/ std::string identifier_type;     \
  auto instance =                                              \
       ::reflection::content::inspect::member           \
         <identifier_type>                               \
         (                                               \
           (class_symbolic_name*)(nullptr)               \
          ,&class_symbolic_name::reader_symbolic_name    \
         );                                                   \
   instance.visibility(    ::reflection::ornament::visibility_class::public_index   );   \
  insert                                                       \
   (                                                           \
     member_string_name                                        \
    ,item_type( ::memory::pointer::make( instance ) )          \
   );                                                          \
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


#endif
