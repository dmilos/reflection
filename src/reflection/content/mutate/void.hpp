#ifndef reflection_content_mutate_void_hpp
#define reflection_content_mutate_void_hpp

 // ::reflection::content::mutate::void_class<identifier_name,report_name >

#include "../../property/mutate/void.hpp"

#include "../void.hpp"
#include "./_pure.hpp"

namespace reflection
 {
  namespace content
   {
    namespace mutate
     {

      template
       <
         typename identifier_name
        ,typename report_name
       >
       class void_class
        :virtual public ::reflection::content::void_class< identifier_name >
        ,virtual public ::reflection::content::mutate::pure_class<identifier_name,void,void,report_name>
        ,        public ::reflection::property::mutate::void_class<report_name>
        {
         public:
           typedef identifier_name      identifier_type;
           typedef void                       data_type;
           typedef void                      model_type;
           typedef report_name              report_type;

           typedef ::reflection::content::mutate::pure_class<identifier_name,data_type,model_type, report_type > pure_type;

           typedef::reflection::property::mutate::void_class<report_name> property_type;

                     void_class()
                      {
                      }

           using property_type::process;
        };

      }
    }
  }

#endif
