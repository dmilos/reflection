#ifndef reflection_content_trinity_void_hpp
#define reflection_content_trinity_void_hpp
 // ::reflection::content::trinity::void_class<identifier_name,report_name>

#include "../../property/trinity/base.hpp"

#include "../direct/basic.hpp"
#include "../mutate/basic.hpp"
#include "../inspect/basic.hpp"

#include "./_pure.hpp"

namespace reflection
 {
  namespace content
   {
    namespace trinity
     {

      template
       <
         typename      identifier_name
        ,typename          report_name
       >
       class void_class
        :virtual public ::reflection::content::trinity::pure_class<  identifier_name, void, void, void,void,report_name>
        ,        public ::reflection::property::trinity::void_class< report_name >
        {
         public:
           typedef   void                 data_type;
           typedef   void             original_type;
           typedef   void                model_type;
           typedef   void                image_type;
           typedef      report_name      report_type;

           typedef ::reflection::content::trinity::pure_class< identifier_name, data_type,original_type,model_type,image_type,report_name> pure_type;
           typedef ::reflection::property::trinity::void_class< report_name > property_type;


                     void_class()
                      {
                      }

            using property_type::disclose;
            using property_type::process;
            using property_type::present;

            //original_type disclose()
            // {
            //  return property_type::disclose();
            // }
            //report_name   process( model_type model_param )
            // {
            //  return property_type::process(model_param);
            // }
            //image_type    present()const
            // {
            //  return property_type::present();
            // }
        };

      }
    }
  }

#endif