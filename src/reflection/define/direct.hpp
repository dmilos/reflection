#ifndef reflection_define_direct
#define reflection_define_direct

// reflection__CLASS_FIELD_direct( member_string_name, traitor_full_symbolic_name )
// reflection__CLASS_MEMBER_direct( member_string_name, traitor_full_symbolic_name )
// reflection__CLASS_SIMPLE_direct( member_string_name, traitor_full_symbolic_name )



#define reflection__CLASS_FIELD_direct( field_string_name, class_symbolic_name, field_symbolic_name )\
 {                                                                                                   \
  typedef /*decltype( field_string_name )*/ std::string identifier_type;                             \
  insert                                                                                             \
   (                                                                                                 \
    field_string_name                                                                                \
    ,item_type                                                                                       \
     (                                                                                               \
      ::memory::pointer::make                                                                        \
       (                                                                                             \
        ::reflection::content::direct::field                                                         \
        <identifier_type>                                                                            \
         (                                                                                           \
           (class_symbolic_name*)(nullptr)                                                           \
          ,&class_symbolic_name::field_symbolic_name                                                 \
         )                                                                                           \
       )                                                                                             \
     )                                                                                               \
   );                                                                                                \
  }


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


#define reflection__CLASS_SUBSIDER_direct( member_string_name, class_symbolic_name, subsider_symbolic_name, subsider_reflection_name, traitor_symbolic_name ) \
 reflection__CLASS_SIMPLE_directX(   member_string_name, MyFirstClassReflectionView, ::reflection::property::structure_class<>& )  \
 {     \
   typedef  ::reflection::property::direct::pure_class<structure_type &>         direct_type; \
   auto &subsder_reflection = dynamic_cast< direct_type &>( this->get(member_string_name) );  \
   subsder_reflection.disclose();            \
   if( nullptr != this->pointer() )          \
    {                                        \
     ::reflection::operation::reroute< subsider_symbolic_name* >  \
      (                                                                 \
       subsder_reflection.disclose(), &this->pointer()->traitor_symbolic_name()   \
      );                                                                     \
    }                  \
  }

// TODO #define reflection__CLASS_MEMBER_direct_reference( type_symbolic_name, value_instance )\

#endif
