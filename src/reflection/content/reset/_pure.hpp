#ifndef reflection_content_reset_pure_hpp
#define reflection_content_reset_pure_hpp

 // ::reflection::content::reset::pure_class<data_name,original_name >

 #include "../../property/reset/_pure.hpp"

 #include "../_pure.hpp"

namespace reflection
 {
  namespace content
   {
    namespace reset
     {

      template
       <
         typename data_name
        ,typename report_name
       >
       class pure_class
        : virtual public ::reflection::content::pure_class< data_name >
        , virtual public ::reflection::property::reset::pure_class<report_name>
        {
         public:
           typedef data_name       data_type;
           typedef report_name   report_type;

           typedef ::reflection::content::pure_class< data_name >              content_type;
           typedef ::reflection::property::reset::pure_class<report_name>     property_type;

           using property_type::process;
        };

      }
    }
  }

#endif
