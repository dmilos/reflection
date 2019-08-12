#ifndef reflection_define_variable
#define reflection_define_variable

// reflection__CLASS_FIELD_variable( field_string_name, class_symbolic_name, field_symbolic_name )
// reflection__CLASS_STATIC_variable( common_string_name, class_symbolic_name, accessibility_name, common_symbolic_name )
// reflection__CLASS_MEMBER_variable( member_string_name, reader_full_symbolic_name, traitor_full_symbolic_name  )
// reflection__CLASS_SIMPLE_variable( member_string_name, type_symbolic_name, value_instance )


#define reflection__CLASS_FIELD_variable( member_string_name, class_symbolic_name, accessibility_name, field_symbolic_name )\
 {                                                      \
  typedef /*decltype( member_string_name )*/ std::string identifier_type;     \
  auto instance =                                              \
        ::reflection::content::variable::field          \
         <identifier_type>                              \
         (                                              \
           (class_symbolic_name*)(nullptr)              \
          ,&class_symbolic_name::field_symbolic_name    \
         );                                                                                                     \
  /* TODO instance.linkage(    ::reflection::ornament::linkage_class::member_index   ); */ \
    instance.accessibility                                                                    \
     ( ::reflection::ornament::accessibility_class::accessibility_enum(                       \
        ::reflection::ornament::accessibility_class::variable_index                            \
      | ::reflection::ornament::accessibility_class::from_string( #accessibility_name  )      \
     ));                                                        \
  instance.relation(      ::reflection::ornament::relation_class::field_index );              \
  insert                                                       \
   (                                                           \
     member_string_name                                        \
    ,item_type( ::memory::pointer::make( instance ) )          \
   );                                                          \
  }

#define reflection__CLASS_STATIC_variable( member_string_name, class_symbolic_name, accessibility_name, common_symbolic_name )\
 {                                                                                                        \
  typedef /*decltype( member_string_name )*/ std::string identifier_type;                                 \
  auto instance =                                              \
        ::reflection::content::variable::common                                                           \
        <identifier_type,class_symbolic_name>                                                             \
         (                                                                                                \
          &class_symbolic_name::common_symbolic_name                                                      \
         );                                                                                                     \
  instance.linkage(    ::reflection::ornament::linkage_class::static_index   );  \
    instance.accessibility                                                                    \
     ( ::reflection::ornament::accessibility_class::accessibility_enum(                       \
        ::reflection::ornament::accessibility_class::variable_index                            \
      | ::reflection::ornament::accessibility_class::from_string( #accessibility_name  )      \
     ));                                                        \
  insert                                                       \
   (                                                           \
     member_string_name                                        \
    ,item_type( ::memory::pointer::make( instance ) )          \
   );                                                          \
  }


#define reflection__CLASS_MEMBER_variable( member_string_name, class_symbolic_name, traitor_symbolic_name, reader_symbolic_name  )\
 {                                                              \
  typedef /*decltype( member_string_name )*/ std::string identifier_type;     \
  auto instance =                                              \
        ::reflection::content::variable::member                \
         <identifier_type>                                     \
         (                                                     \
           (class_symbolic_name*)(nullptr)                     \
          ,&class_symbolic_name::traitor_symbolic_name         \
          ,&class_symbolic_name::reader_symbolic_name          \
         );                                                    \
    instance.accessibility    \
     ( ::reflection::ornament::accessibility_class::accessibility_enum(   \
        ::reflection::ornament::accessibility_class::variable_index       \
      | ::reflection::ornament::accessibility_class::public_index         \
     ));                                                        \
  instance.relation(      ::reflection::ornament::relation_class::member_index );              \
  /*instance.meta( "traitor", #traitor_symbolic_name ); */ \
  /*instance.meta( "reader",  #reader_symbolic_name  ); */ \
  insert                                                       \
   (                                                           \
     member_string_name                                        \
    ,item_type( ::memory::pointer::make( instance ) )          \
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
