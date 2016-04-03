#ifndef reflection_type_ptr_ptr
#define reflection_type_ptr_ptr

#include "./base.hpp"
#include "./polymorph.hpp"
#include "./pure.hpp"

namespace reflection
 {
  namespace type
   {
    namespace ptr
     {

      template< typename type_type>
        using clone = ::memory::pointer::polymorph<type_type>;

     }

   }
 }

#endif