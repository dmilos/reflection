#ifndef reflection_content_exposed_pure_hpp
 #define reflection_content_exposed_pure_hpp
 // ::reflection::content::exposed::pure_class<data_name,original_name >

 #include "../../property/exposed/_pure.hpp"

 #include "../_pure.hpp"

namespace reflection
 {
  namespace content
   {
    namespace exposed
     {

      template
       <
         typename     data_name
        ,typename original_name
        ,typename    model_name
        ,typename   report_name
       >
       class pure_class
        : virtual public ::reflection::content::pure_class< data_name >
        , virtual public ::reflection::property::exposed::pure_class<original_name,model_name,report_name>
        {
         public:
           typedef data_name         data_type;
           typedef original_name original_type;
           typedef model_name       image_type;

           typedef ::reflection::content::pure_class< data_name >              content_type;
           typedef ::reflection::property::exposed::pure_class<original_name,model_name,report_name>   property_type;

           using property_type::disclose;
           using property_type::present;
        };

      }
    }
  }

#endif
