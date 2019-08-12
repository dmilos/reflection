#ifndef reflection_define_direct
#define reflection_define_direct

// reflection__CLASS_FIELD_direct(  member_string_name, class_symbolic_name, accessibility_name, traitor_full_symbolic_name )
// reflection__CLASS_STATIC_direct( member_string_name, class_symbolic_name, accessibility_name, traitor_full_symbolic_name )
// reflection__CLASS_MEMBER_direct( member_string_name, class_symbolic_name, traitor_full_symbolic_name )
// reflection__CLASS_SIMPLE_direct( member_string_name, , type_symbolic_name, value_instance )


#define reflection__CLASS_FIELD_direct( member_string_name, class_symbolic_name, accessibility_name, field_symbolic_name )\
 {                                                                                                   \
  typedef /*decltype( member_string_name )*/ std::string identifier_type;                            \
  auto instance =  ::reflection::content::direct::field                                              \
         <identifier_type>                                                                           \
         (                                                                                           \
           (class_symbolic_name*)(nullptr)                                                           \
          ,&class_symbolic_name::field_symbolic_name                                                 \
         );                                                                                          \
    instance.accessibility                                                                    \
     ( ::reflection::ornament::accessibility_class::accessibility_enum(                       \
        ::reflection::ornament::accessibility_class::direct_index                             \
      | ::reflection::ornament::accessibility_class::from_string( #accessibility_name  )      \
     ));                                                        \
  instance.qualification( ::reflection::ornament::qualification_class::get< decltype(class_symbolic_name::field_symbolic_name) >( ) ); \
  instance.relation(      ::reflection::ornament::relation_class::field_index );                     \
  insert                                                                                             \
   (                                                                                                 \
     member_string_name                                                                              \
    ,item_type( ::memory::pointer::make( instance ) )                                                \
   );                                                                                                \
 }


#define reflection__CLASS_STATIC_direct( member_string_name, class_symbolic_name, accessibility_name, common_symbolic_name )  \
 {                                                                                                        \
  typedef /*decltype( member_string_name )*/ std::string identifier_type;                                 \
  auto instance =                                                                                         \
        ::reflection::content::direct::common                                                             \
        <identifier_type,class_symbolic_name>                                                             \
         (                                                                                                \
          &class_symbolic_name::common_symbolic_name                                                      \
         );                                                                                               \
    instance.accessibility                                                                    \
     ( ::reflection::ornament::accessibility_class::accessibility_enum(                       \
        ::reflection::ornament::accessibility_class::direct_index                             \
      | ::reflection::ornament::accessibility_class::from_string( #accessibility_name  )      \
     ));                                                        \
  instance.linkage(    ::reflection::ornament::linkage_class::static_index   );                           \
  insert                                                                                                  \
   (                                                                                                      \
     member_string_name                                                                                   \
    ,item_type( ::memory::pointer::make( instance ) )                                                     \
   );                                                                                                     \
  }


#define reflection__CLASS_MEMBER_direct( member_string_name, class_symbolic_name, traitor_symbolic_name )\
 {                                                      \
  typedef /*decltype( member_string_name )*/ std::string identifier_type;     \
  auto instance =                                       \
        ::reflection::content::direct::member           \
         <identifier_type>                              \
         (                                              \
           (class_symbolic_name*)(nullptr)              \
          ,&class_symbolic_name::traitor_symbolic_name  \
         );                                                   \
    instance.accessibility    \
     ( ::reflection::ornament::accessibility_class::accessibility_enum(   \
        ::reflection::ornament::accessibility_class::direct_index         \
      | ::reflection::ornament::accessibility_class::public_index         \
     ));                                                        \
  instance.relation(      ::reflection::ornament::relation_class::member_index      );   \
  insert                                                       \
   (                                                           \
     member_string_name                                        \
    ,item_type( ::memory::pointer::make( instance ) )          \
   );                                                          \
 }

#define reflection__CLASS_SIMPLE_direct0( member_string_name, type_symbolic_name )\
 {                                                      \
  typedef /*decltype( member_string_name )*/ std::string identifier_type;     \
  insert                                                \
   (                                                    \
     member_string_name                                 \
    ,item_type                                          \
     (                                                  \
      ::memory::pointer::make                           \
       (                                                \
        ::reflection::content::direct::simple           \
          <                                             \
           identifier_type, type_symbolic_name          \
          >                                             \
          (                                             \
          )                                             \
       )                                                \
     )                                                  \
    );                                                  \
 }

#define reflection__CLASS_SIMPLE_direct( member_string_name, type_symbolic_name, value_instance )\
 {                                                      \
  typedef /*decltype( member_string_name )*/ std::string identifier_type;     \
  insert                                                \
   (                                                    \
     member_string_name                                 \
    ,item_type                                          \
     (                                                  \
      ::memory::pointer::make                           \
       (                                                \
        ::reflection::content::direct::simple           \
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

#define reflection__CLASS_SIMPLE_directX( member_string_name, type_symbolic_nameDerive, type_symbolic_nameBase )\
 {                                                      \
  typedef /*decltype( member_string_name )*/ std::string identifier_type;     \
  insert                                                \
   (                                                    \
     member_string_name                                 \
    ,item_type                                          \
     (                                                  \
      ::memory::pointer::make                           \
       (                                                \
        ::reflection::content::direct::simple           \
          <                                             \
           identifier_type, type_symbolic_nameDerive, type_symbolic_nameBase          \
          >                                             \
          (                                             \
          )                                             \
       )                                                \
     )                                                  \
    );                                                  \
 }


// TODO #define reflection__CLASS_MEMBER_direct_reference( type_symbolic_name, value_instance )

#endif
