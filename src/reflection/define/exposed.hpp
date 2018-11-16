#ifndef reflection_define_exposed
#define reflection_define_exposed

// reflection__CLASS_FIELD_exposed(  member_string_name,   class_symbolic_name, field_symbolic_name )
// reflection__CLASS_STATIC_exposed( member_string_name, class_symbolic_name, accessibility_name, common_symbolic_name )
// reflection__CLASS_MEMBER_exposed( member_string_name, class_symbolic_name, traitor_symbolic_name, writer_symbolic_name   )
// reflection__CLASS_SIMPLE_exposed( member_string_name, type_symbolic_name, value_instance )


#define reflection__CLASS_FIELD_exposed( member_string_name, class_symbolic_name, accessibility_name, field_symbolic_name )\
 {                                                      \
  typedef /*decltype( member_string_name )*/ std::string identifier_type;     \
  auto instance =                                              \
        ::reflection::content::exposed::field            \
         <identifier_type>                              \
         (                                              \
           (class_symbolic_name*)(nullptr)              \
          ,&class_symbolic_name::field_symbolic_name    \
         );                                                                                                     \
   instance.accessibility(    ::reflection::ornament::accessibility_class::from_string( #accessibility_name )   );   \
  /* TODO instance.linkage(    ::reflection::ornament::linkage_class::static_index   ); */ \
  insert                                                       \
   (                                                           \
     member_string_name                                        \
    ,item_type( ::memory::pointer::make( instance ) )          \
   );                                                          \
  }


#define reflection__CLASS_STATIC_exposed( member_string_name, class_symbolic_name, accessibility_name, common_symbolic_name ) \
 {                                                                                                        \
  typedef /*decltype( member_string_name )*/ std::string identifier_type;                                 \
  auto instance =                                              \
        ::reflection::content::exposed::common                                                            \
        <identifier_type,class_symbolic_name>                                                             \
         (                                                                                                \
          &class_symbolic_name::common_symbolic_name                                                      \
         );                                                                                                     \
  instance.accessibility(    ::reflection::ornament::accessibility_class::from_string( #accessibility_name )   );   \
  instance.linkage(    ::reflection::ornament::linkage_class::static_index   );   \
  insert                                                       \
   (                                                           \
     member_string_name                                        \
    ,item_type( ::memory::pointer::make( instance ) )          \
   );                                                          \
  }

#define reflection__CLASS_MEMBER_exposed( member_string_name, class_symbolic_name, traitor_symbolic_name, writer_symbolic_name   )\
 {                                                      \
  typedef /*decltype( member_string_name )*/ std::string identifier_type;     \
  auto instance =                                       \
        ::reflection::content::exposed::member          \
         <identifier_type>                              \
         (                                              \
           (class_symbolic_name*)(nullptr)              \
          ,&class_symbolic_name::traitor_symbolic_name  \
          ,&class_symbolic_name::writer_symbolic_name   \
         );                                                  \
    instance.accessibility(    ::reflection::ornament::accessibility_class::public_index   );  \
  insert                                                       \
   (                                                           \
     member_string_name                                        \
    ,item_type( ::memory::pointer::make( instance ) )          \
   );                                                          \
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
