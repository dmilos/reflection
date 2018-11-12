#ifndef reflection_property_base_pure
#define reflection_property_base_pure

// ::reflection::property::base::pure_class<name_name>

#include "../_pure.hpp"

namespace reflection
 {
  namespace property
   {
    namespace base
     {

       class pure_class
        : virtual public ::reflection::property::pure_class
        ,         public ::reflection::ornament::visibility_class

        {
         public:
           typedef int           visibility_type;

         public:
           explicit pure_class(){}
           virtual ~pure_class(){}
        };

     }
   }
 }

#endif
