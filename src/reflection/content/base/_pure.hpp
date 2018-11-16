#ifndef reflection_content_base_pure_hpp
#define reflection_content_base_pure_hpp

 // ::reflection::content::base::pure_class<identifier_name >

 #include "../../property/base/_pure.hpp"

 #include "../_pure.hpp"

namespace reflection
 {
  namespace content
   {
    namespace base
     {

      template
       <
         typename identifier_name
       >
       class pure_class
        : virtual public ::reflection::content::pure_class< identifier_name >
        , virtual public ::reflection::property::base::pure_class
        {
         public:
           typedef identifier_name identifier_type;

        };

      }
    }
  }

#endif
