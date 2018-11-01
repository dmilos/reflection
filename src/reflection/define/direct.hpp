#ifndef reflection_define_direct
#define reflection_define_direct

// reflection__CLASS_MEMBER_direct( member_string_name, traitor_full_symbolic_name )

//#define reflection__CLASS_SIMPLE_direct(      member_name,     class_original::asdas   )\

#define reflection__CLASS_MEMBER_direct( member_string_name, class_symbolic_name, traitor_symbolic_name )\
 {                                                      \
  typedef /*decltype( member_string_name )*/ std::string identifier_type;     \
  insert                                                \
   (                                                    \
     member_string_name                                 \
    ,item_type                                          \
     (                                                  \
      ::memory::pointer::make                           \
       (                                                \
        ::reflection::content::direct::member           \
         <identifier_type>                              \
         (                                              \
           (class_symbolic_name*)(nullptr)              \
          ,&class_symbolic_name::traitor_symbolic_name  \
         )                                              \
       )                                                \
     )                                                  \
   );                                                   \
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


#define reflection__CLASS_SUBSIDER_direct               \
 (                                                      \
   member_string_name                                   \
  ,class_symbolic_name                                  \
  ,subsider_reflection_symbolic_name                    \
  ,traitor_symbolic_name                                \
 )                                                      \
 {                                                      \
  typedef /*decltype( member_string_name )*/ std::string identifier_type;     \
  insert                                                \
   (                                                    \
     member_string_name                                 \
    ,item_type                                          \
     (                                                  \
      ::memory::pointer::make                           \
       (                                                \
        ::reflection::content::direct::member           \
         <identifier_type>                              \
         (                                              \
           (class_symbolic_name*)(nullptr)              \
          ,&class_symbolic_name::traitor_symbolic_name  \
         )                                              \
       )                                                \
     )                                                  \
    );                                                  \
 }


// TODO #define reflection__CLASS_MEMBER_direct_reference( type_symbolic_name, value_instance )\

#endif
