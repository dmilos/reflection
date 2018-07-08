#ifndef reflection_type_add_lconst_value_reference
#define reflection_type_add_lconst_value_reference

// ::reflection::type::add_lconst_value_reference

namespace reflection
 {
  namespace type
   {

    template
     <
       typename type_name
     >
    struct add_lconst_value_reference
     {
      typedef typename std::add_const<type_name>::type                      const_type;
      typedef typename std::add_lvalue_reference<const_type>::type    type, type_type;
     };

   }
 }

#endif