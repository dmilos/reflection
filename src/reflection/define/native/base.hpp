#ifndef reflection_define_base
#define reflection_define_base


#define reflection__CLASS_BASE_direct( member_string_name, class_symbolic_name, accessibility_name, derivation_name, base_symbolic_name ) \
 {                                                                                                   \
  typedef /*decltype( member_string_name )*/ std::string identifier_type;                            \
  auto instance =  ::reflection::content::direct::base                                               \
         <identifier_type,base_symbolic_name,class_symbolic_name >                                   \
         (                                                                                           \
          (pointer_type)nullptr                                                              \
         );                                                                                          \
  instance.accessibility( ::reflection::ornament::accessibility_class::from_string( #accessibility_name ) );     \
  instance.derivation(    ::reflection::ornament::derivation_class::from_string( #derivation_name ) );           \
  instance.relation(      ::reflection::ornament::relation_class::base_index );                                  \
  insert                                                                                             \
   (                                                                                                 \
     member_string_name                                                                              \
    ,item_type( ::memory::pointer::make( instance ) )                                                \
   );                                                                                                \
 }

#define reflection__CLASS_BASE_inspect( member_string_name, class_symbolic_name, accessibility_name, derivation_name, base_symbolic_name ) \
 {                                                                                                   \
  typedef /*decltype( member_string_name )*/ std::string identifier_type;                            \
  auto instance =  ::reflection::content::inspect::base                                              \
         <identifier_type,base_symbolic_name,class_symbolic_name >                                   \
         (                                                                                           \
          (pointer_type)nullptr                                                              \
         );                                                                                          \
  instance.accessibility( ::reflection::ornament::accessibility_class::from_string( #accessibility_name ) );     \
  instance.derivation(    ::reflection::ornament::derivation_class::from_string( #derivation_name ) );           \
  instance.relation(      ::reflection::ornament::relation_class::base_index );                                  \
  insert                                                                                             \
   (                                                                                                 \
     member_string_name                                                                              \
    ,item_type( ::memory::pointer::make( instance ) )                                                \
   );                                                                                                \
 }

#define reflection__CLASS_BASE_mutate( member_string_name, class_symbolic_name, accessibility_name, derivation_name, base_symbolic_name ) \
 {                                                                                                   \
  typedef /*decltype( member_string_name )*/ std::string identifier_type;                            \
  auto instance =  ::reflection::content::mutate::base                                               \
         <identifier_type,base_symbolic_name,class_symbolic_name >                                   \
         (                                                                                           \
          (pointer_type)nullptr                                                              \
         );                                                                                          \
  instance.accessibility( ::reflection::ornament::accessibility_class::from_string( #accessibility_name ) );     \
  instance.derivation(    ::reflection::ornament::derivation_class::from_string( #derivation_name ) );           \
  instance.relation(      ::reflection::ornament::relation_class::base_index );                                  \
  insert                                                                                             \
   (                                                                                                 \
     member_string_name                                                                              \
    ,item_type( ::memory::pointer::make( instance ) )                                                \
   );                                                                                                \
 }

#define reflection__CLASS_BASE_variable( member_string_name, class_symbolic_name, accessibility_name, derivation_name, base_symbolic_name ) \
 {                                                                                                   \
  typedef /*decltype( member_string_name )*/ std::string identifier_type;                            \
  auto instance =  ::reflection::content::variable::base                                               \
         <identifier_type,base_symbolic_name, class_symbolic_name >                                                       \
         (                                                                                           \
          (pointer_type)nullptr                                                              \
         );                                                                                          \
  instance.accessibility( ::reflection::ornament::accessibility_class::from_string( #accessibility_name ) );     \
  instance.derivation(    ::reflection::ornament::derivation_class::from_string( #derivation_name ) );           \
  instance.relation(      ::reflection::ornament::relation_class::base_index );                                  \
  insert                                                                                             \
   (                                                                                                 \
     member_string_name                                                                              \
    ,item_type( ::memory::pointer::make( instance ) )                                                \
   );                                                                                                \
 }

#define reflection__CLASS_BASE_guarded( member_string_name, class_symbolic_name, accessibility_name, derivation_name, base_symbolic_name ) \
 {                                                                                                   \
  typedef /*decltype( member_string_name )*/ std::string identifier_type;                            \
  auto instance =  ::reflection::content::guarded::base                                              \
         <identifier_type,base_symbolic_name, class_symbolic_name >                                                       \
         (                                                                                           \
          (pointer_type)nullptr                                                              \
         );                                                                                          \
  instance.accessibility( ::reflection::ornament::accessibility_class::from_string( #accessibility_name ) );     \
  instance.derivation(    ::reflection::ornament::derivation_class::from_string( #derivation_name ) );           \
  instance.relation(      ::reflection::ornament::relation_class::base_index );                                  \
  insert                                                                                             \
   (                                                                                                 \
     member_string_name                                                                              \
    ,item_type( ::memory::pointer::make( instance ) )                                                \
   );                                                                                                \
 }

#define reflection__CLASS_BASE_exposed( member_string_name, class_symbolic_name, accessibility_name, derivation_name, base_symbolic_name ) \
 {                                                                                                   \
  typedef /*decltype( member_string_name )*/ std::string identifier_type;                            \
  auto instance =  ::reflection::content::exposed::base                                              \
         <identifier_type,base_symbolic_name, class_symbolic_name >                                  \
         (                                                                                           \
          (pointer_type)nullptr                                                              \
         );                                                                                          \
  instance.accessibility( ::reflection::ornament::accessibility_class::from_string( #accessibility_name ) );     \
  instance.derivation(    ::reflection::ornament::derivation_class::from_string( #derivation_name ) );           \
  instance.relation(      ::reflection::ornament::relation_class::base_index );                                  \
  insert                                                                                             \
   (                                                                                                 \
     member_string_name                                                                              \
    ,item_type( ::memory::pointer::make( instance ) )                                                \
   );                                                                                                \
 }

#define reflection__CLASS_BASE_trinity( member_string_name, class_symbolic_name, accessibility_name, derivation_name, base_symbolic_name ) \
 {                                                                                                   \
  typedef /*decltype( member_string_name )*/ std::string identifier_type;                            \
  auto instance =  ::reflection::content::trinity::base                                               \
         <identifier_type,base_symbolic_name, class_symbolic_name >                                                       \
         (                                                                                           \
          (pointer_type)nullptr                                                              \
         );                                                                                          \
  instance.accessibility( ::reflection::ornament::accessibility_class::from_string( #accessibility_name ) );     \
  instance.derivation(    ::reflection::ornament::derivation_class::from_string( #derivation_name ) );           \
  instance.relation(      ::reflection::ornament::relation_class::base_index );                                  \
  insert                                                                                             \
   (                                                                                                 \
     member_string_name                                                                              \
    ,item_type( ::memory::pointer::make( instance ) )                                                \
   );                                                                                                \
 }

#endif


