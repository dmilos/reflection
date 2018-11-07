#ifndef reflection_content_exposed_void_hpp
#define reflection_content_exposed_void_hpp

 // ::reflection::content::exposed::void_class<identifier_name,report_name >

#include "../../property/exposed/void.hpp"

#include "./_pure.hpp"

namespace reflection
 {
  namespace content
   {
    namespace exposed
     {

      template
       <
         typename  identifier_name
        ,typename     report_name
       >
       class void_class
        :virtual public ::reflection::content::exposed::pure_class<identifier_name,void,void,void,report_name>
        ,        public ::reflection::property::exposed::void_class< report_name >
        {
         public:
           typedef  void                data_type;
           typedef  void            original_type;
           typedef  void               model_type;
           typedef report_name        report_type;

           typedef ::reflection::content::exposed::pure_class<identifier_name,data_type,original_type,model_type,report_name> pure_type;
           typedef ::reflection::property::exposed::void_class< report_name > property_type;

         public:
                    void_class()
                     {
                     }

         public:
            using property_type::disclose;
            using property_type::process;

            //original_type disclose(){ return property_type::disclose(); }
            //report_name   process( model_type model_param ){ return property_type::process(model_param); }

        };

      }
    }
  }

#endif 