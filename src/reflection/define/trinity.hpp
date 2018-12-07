#ifndef reflection_define_trinity
#define reflection_define_trinity

// reflection__CLASS_FIELD_trinity( member_string_name, class_symbolic_name, field_symbolic_name )
// reflection__CLASS_STATIC_trinity( member_string_name, class_symbolic_name, accessibility_name, common_symbolic_name )
// reflection__CLASS_MEMBER_trinity( member_string_name, traitir_full_symbolic_name, writer_symbolic_name  reader_symbolic_name   )
// reflection__CLASS_SIMPLE_trinity( member_string_name, type_symbolic_name, value_instance )


#define reflection__CLASS_FIELD_trinity( member_string_name, class_symbolic_name, accessibility_name, field_symbolic_name )\
 {                                                      \
  typedef /*decltype( member_string_name )*/ std::string identifier_type;     \
  auto instance =                                              \
        ::reflection::content::trinity::field            \
         <identifier_type>                              \
         (                                              \
           (class_symbolic_name*)(nullptr)              \
          ,&class_symbolic_name::field_symbolic_name    \
         );                                                                                   \
  /* TODO instance.linkage(    ::reflection::ornament::linkage_class::static_index   ); */    \
    instance.accessibility                                                                    \
     ( ::reflection::ornament::accessibility_class::accessibility_enum(                       \
        ::reflection::ornament::accessibility_class::trinity_index                            \
      | ::reflection::ornament::accessibility_class::from_string( #accessibility_name  )      \
     ));                                                        \
  insert                                                       \
   (                                                           \
     member_string_name                                        \
    ,item_type( ::memory::pointer::make( instance ) )          \
   );                                                          \
  }

#define reflection__CLASS_STATIC_trinity( member_string_name, class_symbolic_name, accessibility_name, common_symbolic_name )  \
 {                                                                                                        \
  typedef /*decltype( member_string_name )*/ std::string identifier_type;                                 \
  auto instance =                                              \
        ::reflection::content::trinity::common                                                             \
        <identifier_type,class_symbolic_name>                                                             \
         (                                                                                                \
          &class_symbolic_name::common_symbolic_name                                                      \
         );                                                                                                     \
   instance.linkage(    ::reflection::ornament::linkage_class::static_index   );   \
    instance.accessibility                                                                    \
     (::reflection::ornament::accessibility_class::accessibility_enum(                        \
        ::reflection::ornament::accessibility_class::trinity_index                            \
      | ::reflection::ornament::accessibility_class::from_string( #accessibility_name  )      \
     ));                                                        \
  insert                                                       \
   (                                                           \
     member_string_name                                        \
    ,item_type( ::memory::pointer::make( instance ) )          \
   );                                                          \
  }


#define reflection__CLASS_MEMBER_trinity( member_string_name, class_symbolic_name, traitir_symbolic_name, writer_symbolic_name, reader_symbolic_name   )\
 {                                                      \
  typedef /*decltype( member_string_name )*/ std::string identifier_type;     \
  auto instance =                                       \
        ::reflection::content::trinity::member          \
         <identifier_type>                              \
         (                                              \
           (class_symbolic_name*)(nullptr)              \
          ,&class_symbolic_name::traitir_symbolic_name  \
          ,&class_symbolic_name::writer_symbolic_name   \
          ,&class_symbolic_name::reader_symbolic_name   \
         );                                                  \
  instance.accessibility(    ::reflection::ornament::accessibility_class::trinity_index   );  \
  insert                                                       \
   (                                                           \
     member_string_name                                        \
    ,item_type( ::memory::pointer::make( instance ) )          \
   );                                                          \
 }


#define reflection__CLASS_SIMPLE_trinity( member_string_name, type_symbolic_name, value_instance )\
 {                                                      \
  typedef /*decltype( member_string_name )*/ std::string identifier_type;     \
  insert                                                \
   (                                                    \
     member_string_name                                 \
    ,item_type                                          \
     (                                                  \
      ::memory::pointer::make                           \
       (                                                \
        ::reflection::content::trinity::simple          \
          <                                             \
           identifier_type,type_symbolic_name           \
          >                                             \
          (                                             \
           value_instance                               \
          )                                             \
       )                                                \
     )                                                  \
    );                                                  \
 }


#endif
