#ifndef reflection_content_reset_pure_hpp
#define reflection_content_reset_pure_hpp

 // ::reflection::content::reset::pure_class<data_name,original_name >

 #include "../../property/reset/_pure.hpp"

 #include "../_base.hpp"

namespace reflection
 {
  namespace content
   {
    namespace reset
     {

      template
       <
         typename  identifier_name
        ,typename        data_name
        ,typename      report_name
       >
       class pure_class
        : virtual public ::reflection::content::base_class< identifier_name, data_name >
        , virtual public ::reflection::property::reset::pure_class<report_name>
        {
         public:
           typedef identifier_name    identifier_type;
           typedef data_name                data_type;
           typedef report_name            report_type;

           typedef ::reflection::content::pure_class< identifier_name >        content_type;
           typedef ::reflection::property::reset::pure_class<report_name>     property_type;

           typedef ::reflection::type::name::identificatorX< identifier_name  > identificator_type;

           using property_type::process;
        };

      }
    }
  }

#endif
