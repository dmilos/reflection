#ifndef reflection_content_direct_pure_hpp
 #define reflection_content_direct_pure_hpp
 // ::reflection::content::direct::pure_class<data_name,original_name >

 #include "../../property/direct/_pure.hpp"

 #include "../_pure.hpp"

namespace reflection
 {
  namespace content
   {
    namespace direct
     {

      template
       <
         typename data_name
        ,typename original_name
       >
       class pure_class
        : virtual public ::reflection::content::pure_class< data_name >
        , virtual public ::reflection::property::direct::pure_class<original_name>
        {
         public:
           typedef data_name          data_type;
           typedef original_name  original_type;

           typedef ::reflection::content::pure_class< data_name >              content_pure_type;
           typedef ::reflection::property::direct::pure_class<original_name>   property_pure_type;

           using property_pure_type::disclose;
        };

      }
    }
  }

#endif
