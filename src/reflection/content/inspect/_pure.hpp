#ifndef reflection_content_inspect_pure_hpp
 #define reflection_content_inspect_pure_hpp
 // ::reflection::content::inspect::pure_class<data_name,image_name >

 #include "../../property/inspect/_pure.hpp"

 #include "../_pure.hpp"

namespace reflection
 {
  namespace content
   {
    namespace inspect
     {

      template
       <
         typename data_name
        ,typename image_name
       >
       class pure_class
        : virtual public ::reflection::content::pure_class< data_name >
        , virtual public ::reflection::property::inspect::pure_class<image_name>
        {
         public:
           typedef data_name   data_type;
           typedef image_name  image_type;

           typedef ::reflection::content::pure_class< data_name >              content_pure_type;
           typedef ::reflection::property::inspect::pure_class<image_name>   property_pure_type;

           using property_pure_type::present;
        };

      }
    }
  }

#endif
