#ifndef reflection_define_idspec
#define reflection_define_idspec

#define reflection__IDSPEC( identificator_symbolic_name, class_string_name, class_symbolic_name )     \
namespace reflection                                                                                  \
 {                                                                                                    \
  namespace type                                                                                      \
   {                                                                                                  \
    namespace name                                                                                    \
     {                                                                                                \
                                                                                                      \
       template <>                                                                                    \
       typename identificatorX<identificator_symbolic_name>::identifier_type const&                   \
       identificatorX<identificator_symbolic_name>::template get< class_symbolic_name   >()           \
        {                                                                                             \
         static identificatorX<identificator_symbolic_name>::identifier_type id( class_string_name ); \
         return id;                                                                                   \
        }                                                                                             \
                                                                                                      \
    }                                                                                                 \
   }                                                                                                  \
 }

#endif

