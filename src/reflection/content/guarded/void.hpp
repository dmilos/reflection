#ifndef reflection_content_guarded_void_hpp
#define reflection_content_guarded_void_hpp

 // ::reflection::content::guarded::void_class<identifier_name,report_name >

#include "../../property/guarded/void.hpp"

#include "../void.hpp"
#include "./_pure.hpp"

namespace reflection
 {
  namespace content
   {
    namespace guarded
     {

      template
       <
         typename     identifier_name
        ,typename         report_name
       >
       class void_class
        :virtual public ::reflection::content::void_class< identifier_name >
        ,virtual public ::reflection::content::guarded::pure_class<identifier_name,void,void,void,report_name>
        ,        public ::reflection::property::guarded::void_class< report_name >
        {
         public:
           typedef     void       data_type;
           typedef     void      model_type;
           typedef     void      image_type;
           typedef    report_name     report_type;

           typedef ::reflection::content::guarded::pure_class<identifier_name,data_type,model_type,image_type,report_name> pure_type;
           typedef ::reflection::property::guarded::void_class< report_name > property_type;

                     void_class()
                      {
                      }

           using property_type::process;
           using property_type::present;

           //image_type present()const{ return property_type::present(); }
           //report_name process( model_type model_param ){ return property_type::process(model_param); }
        };

      }
    }
  }

#endif
