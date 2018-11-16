#ifndef reflection_define_base
#define reflection_define_base


#define reflection__CLASS_BASE_direct( member_string_name, class_symbolic_name, accessibility_name, base_symbolic_name ) \
 {                                                                                                   \
  typedef /*decltype( member_string_name )*/ std::string identifier_type;                            \
  auto instance =  ::reflection::content::direct::base                                               \
         <identifier_type,base_symbolic_name,class_symbolic_name >                                   \
         (                                                                                           \
          nullptr                                                                                    \
         );                                                                                          \
  instance.accessibility( ::reflection::ornament::accessibility_class::from_string( #accessibility_name ) );     \
  instance.derivation( ::reflection::ornament::derivation_class::default_index );                    \
  instance.relation( ::reflection::ornament::relation_class::base_index );                           \
  insert                                                                                             \
   (                                                                                                 \
     member_string_name                                                                              \
    ,item_type( ::memory::pointer::make( instance ) )                                                \
   );                                                                                                \
 }

#define reflection__CLASS_BASE_inspect( string_name, class_symbolic_name, accessibility_name, base_symbolic_name ) \
 {                                                                                                   \
  typedef /*decltype( member_string_name )*/ std::string identifier_type;                            \
  auto instance =  ::reflection::content::base::inspect                                              \
         <identifier_type,base_symbolic_name >                                                       \
         (                                                                                           \
         );                                                                                          \
  instance.accessibility( ::reflection::ornament::accessibility_class::from_string( #accessibility_name ) );                     \
/*instance.derivation( ::reflection::ornament::derivation_class::normal_index );*/                   \
  insert                                                                                             \
   (                                                                                                 \
     member_string_name                                                                              \
    ,item_type( ::memory::pointer::make( instance ) )                                                \
   );                                                                                                \
 }

#define reflection__CLASS_BASE_mutate( string_name, class_symbolic_name, accessibility_name, base_symbolic_name ) \
 {                                                                                                   \
  typedef /*decltype( member_string_name )*/ std::string identifier_type;                            \
  auto instance =  ::reflection::content::base::mutate                                               \
         <identifier_type,base_symbolic_name >                                                       \
         (                                                                                           \
         );                                                                                          \
  instance.accessibility( ::reflection::ornament::accessibility_class::from_string( #accessibility_name ) );                     \
/*instance.derivation( ::reflection::ornament::derivation_class::normal_index );*/                   \
  insert                                                                                             \
   (                                                                                                 \
     member_string_name                                                                              \
    ,item_type( ::memory::pointer::make( instance ) )                                                \
   );                                                                                                \
 }

#define reflection__CLASS_BASE_variable( string_name, class_symbolic_name, accessibility_name, base_symbolic_name ) \
 {                                                                                                   \
  typedef /*decltype( member_string_name )*/ std::string identifier_type;                            \
  auto instance =  ::reflection::content::base::variable                                               \
         <identifier_type,base_symbolic_name >                                                       \
         (                                                                                           \
         );                                                                                          \
  instance.accessibility( ::reflection::ornament::accessibility_class::from_string( #accessibility_name ) );                     \
/*instance.derivation( ::reflection::ornament::derivation_class::normal_index );*/                   \
  insert                                                                                             \
   (                                                                                                 \
     member_string_name                                                                              \
    ,item_type( ::memory::pointer::make( instance ) )                                                \
   );                                                                                                \
 }

#define reflection__CLASS_BASE_guarded( string_name, class_symbolic_name, accessibility_name, base_symbolic_name ) \
 {                                                                                                   \
  typedef /*decltype( member_string_name )*/ std::string identifier_type;                            \
  auto instance =  ::reflection::content::base::guarded                                               \
         <identifier_type,base_symbolic_name >                                                       \
         (                                                                                           \
         );                                                                                          \
  instance.accessibility( ::reflection::ornament::accessibility_class::from_string( #accessibility_name ) );                     \
/*instance.derivation( ::reflection::ornament::derivation_class::normal_index );*/                   \
  insert                                                                                             \
   (                                                                                                 \
     member_string_name                                                                              \
    ,item_type( ::memory::pointer::make( instance ) )                                                \
   );                                                                                                \
 }

#define reflection__CLASS_BASE_exposed( string_name, class_symbolic_name, accessibility_name, base_symbolic_name ) \
 {                                                                                                   \
  typedef /*decltype( member_string_name )*/ std::string identifier_type;                            \
  auto instance =  ::reflection::content::base::exposed                                               \
         <identifier_type,base_symbolic_name >                                                       \
         (                                                                                           \
         );                                                                                          \
  instance.accessibility( ::reflection::ornament::accessibility_class::from_string( #accessibility_name ) );                     \
/*instance.derivation( ::reflection::ornament::derivation_class::normal_index );*/                   \
  insert                                                                                             \
   (                                                                                                 \
     member_string_name                                                                              \
    ,item_type( ::memory::pointer::make( instance ) )                                                \
   );                                                                                                \
 }

#define reflection__CLASS_BASE_trinity( string_name, class_symbolic_name, accessibility_name, base_symbolic_name ) \
 {                                                                                                   \
  typedef /*decltype( member_string_name )*/ std::string identifier_type;                            \
  auto instance =  ::reflection::content::base::trinity                                               \
         <identifier_type,base_symbolic_name >                                                       \
         (                                                                                           \
         );                                                                                          \
  instance.accessibility( ::reflection::ornament::accessibility_class::from_string( #accessibility_name ) );                     \
/*instance.derivation( ::reflection::ornament::derivation_class::normal_index );*/                   \
  insert                                                                                             \
   (                                                                                                 \
     member_string_name                                                                              \
    ,item_type( ::memory::pointer::make( instance ) )                                                \
   );                                                                                                \
 }

#endif


