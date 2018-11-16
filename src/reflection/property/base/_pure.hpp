#ifndef reflection_property_base_pure
#define reflection_property_base_pure

// ::reflection::property::base::pure_class

#include "../_pure.hpp"
#include "../../ornament/accessibility.hpp"
#include "../../ornament/derivation.hpp"
#include "../../ornament/relation.hpp"

namespace reflection
 {
  namespace property
   {
    namespace base
     {

      class pure_class
       : virtual public ::reflection::property::pure_class
       ,         public ::reflection::ornament::accessibility_class
       ,         public ::reflection::ornament::derivation_class
       ,         public ::reflection::ornament::relation_class
      {
        public:
          explicit pure_class(){}
          virtual ~pure_class(){}
       };

     }
   }
 }

#endif
