#ifndef reflection_define_guarded
#define reflection_define_guarded

// reflection__CLASS_FIELD_guarded(   member_string_name, class_symbolic_name, field_symbolic_name )
// reflection__CLASS_STATIC_guarded( member_string_name, class_symbolic_name, accessibility_name, common_symbolic_name )
// reflection__CLASS_MEMBER_guarded( member_string_name, class_symbolic_name, writer_symbolic_name, reader_symbolic_name )
// reflection__CLASS_SIMPLE_guarded( member_string_name, type_symbolic_name, value_instance )


#define reflection__CLASS_FIELD_guarded( member_string_name, class_symbolic_name, accessibility_name, field_symbolic_name )\
 {                                                      \
  typedef /*decltype( member_string_name )*/ std::string identifier_type;     \
  auto instance =                                              \
        ::reflection::content::guarded::field           \
         <identifier_type>                              \
         (                                              \
           (class_symbolic_name*)(nullptr)              \
          ,&class_symbolic_name::field_symbolic_name    \
         );                                                                                                     \
    instance.accessibility                                                                    \
     ( ::reflection::ornament::accessibility_class::accessibility_enum(                       \
        ::reflection::ornament::accessibility_class::guarded_index                            \
      | ::reflection::ornament::accessibility_class::from_string( #accessibility_name  )      \
     ));                                                        \
  instance.qualification( ::reflection::ornament::qualification_class::get< decltype(class_symbolic_name::field_symbolic_name) >( ) ); \
  instance.relation(      ::reflection::ornament::relation_class::field_index );                     \
  insert                                                       \
   (                                                           \
     member_string_name                                        \
    ,item_type( ::memory::pointer::make( instance ) )          \
   );                                                          \
  }


#define reflection__CLASS_STATIC_guarded( member_string_name, class_symbolic_name, accessibility_name, common_symbolic_name ) \
 {                                                                                                        \
  typedef /*decltype( member_string_name )*/ std::string identifier_type;                                 \
  auto instance =                                              \
        ::reflection::content::guarded::common                                                             \
        <identifier_type,class_symbolic_name>                                                             \
         (                                                                                                \
          &class_symbolic_name::common_symbolic_name                                                      \
         );                                                                                                     \
    instance.accessibility                                                                    \
     ( ::reflection::ornament::accessibility_class::accessibility_enum(                       \
        ::reflection::ornament::accessibility_class::guarded_index                            \
      | ::reflection::ornament::accessibility_class::from_string( #accessibility_name  )      \
     ));                                                        \
  instance.linkage(    ::reflection::ornament::linkage_class::static_index   );  \
  insert                                                       \
   (                                                           \
     member_string_name                                        \
    ,item_type( ::memory::pointer::make( instance ) )          \
   );                                                          \
  }


#define reflection__CLASS_MEMBER_guarded( member_string_name, class_symbolic_name, writer_symbolic_name, reader_symbolic_name )\
 {                                                      \
  typedef /*decltype( member_string_name )*/ std::string identifier_type;     \
  auto instance =                                              \
       ::reflection::content::guarded::member          \
         <identifier_type>                              \
         (                                              \
           (class_symbolic_name*)(nullptr)              \
          ,&class_symbolic_name::writer_symbolic_name   \
          ,&class_symbolic_name::reader_symbolic_name   \
         );                                                  \
   instance.accessibility(    ::reflection::ornament::accessibility_class::public_index   );   \
  insert                                                       \
   (                                                           \
     member_string_name                                        \
    ,item_type( ::memory::pointer::make( instance ) )          \
   );                                                          \
 }


#define reflection__CLASS_SIMPLE_guarded( member_string_name, type_symbolic_name, value_instance )\
 {                                                      \
  typedef /*decltype( member_string_name )*/ std::string identifier_type;     \
  insert                                                \
   (                                                    \
     member_string_name                                 \
    ,item_type                                          \
     (                                                  \
      ::memory::pointer::make                           \
       (                                                \
        ::reflection::content::guarded::simple          \
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
