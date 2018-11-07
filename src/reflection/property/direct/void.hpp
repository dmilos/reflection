#ifndef reflection_property_direct_void
#define reflection_property_direct_void

// ::reflection::property::direct::void_class


#include "./_pure.hpp"

namespace reflection
 {
  namespace property
   {
    namespace direct
     {

      class void_class
       : virtual public ::reflection::property::direct::pure_class< void >
       {
        public:
          typedef void   original_type;

          typedef  ::reflection::property::direct::pure_class< original_type > pure_type;

                    void_class(){ }

        public:
          void disclose( void )
           {
            return;
           }

       };
      // TODO check
      }
    }
  }

#endif
