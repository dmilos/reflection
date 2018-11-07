#ifndef reflection_property_inspect_void
#define reflection_property_inspect_void

#include "./_pure.hpp"
#include "../_carrier.hpp"

namespace reflection
 {
  namespace property
   {
    namespace inspect
     {

       class void_class
        : virtual public ::reflection::property::inspect::pure_class< void >
        {
         public:
           typedef void        image_type;

           typedef ::reflection::property::inspect::pure_class< void >     pure_type;

           void_class()
            {
            }

         public:
           image_type present( void )const
            {
             return ;
            }

        };

      }
    }
  }

#endif