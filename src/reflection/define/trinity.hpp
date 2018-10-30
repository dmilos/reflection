#ifndef reflection_define_trinity
#define reflection_define_trinity

// reflection__CLASS_MEMBER_trinity( member_string_name, traitir_full_symbolic_name, writter_symbolic_name  reader_symbolic_name   )\


#define reflection__CLASS_MEMBER_trinity( member_string_name, class_symbolic_name, traitir_symbolic_name, writter_symbolic_name, reader_symbolic_name   )\
  insert                                                \
   (                                                    \
     member_string_name                                 \
    ,item_type                                          \
     (                                                  \
      ::memory::pointer::make                           \
       (                                                \
        ::reflection::content::trinity::member          \
         <std::string>                                  \
         (                                              \
           this                                         \
          ,&class_symbolic_name::traitir_symbolic_name  \
          ,&class_symbolic_name::writter_symbolic_name  \
          ,&class_symbolic_name::reader_symbolic_name   \
         )                                              \
       )                                                \
     )                                                  \
   );                                                   \


#define reflection__CLASS_SIMPLE_trinity( member_string_name, type_symbolic_name, value_instance )\
  insert                                                \
   (                                                    \
     member_string_name                                 \
    ,item_type                                          \
     (                                                  \
      ::memory::pointer::make                           \
       (                                                \
        ::reflection::content::trinity::simple          \
          <                                             \
           std::string,type_symbolic_name               \
          >                                             \
          (                                             \
           value_instance                               \
          )                                             \
       )                                                \
     )                                                  \
   );

#endif
