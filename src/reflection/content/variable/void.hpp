#ifndef reflection_content_variable_void_hpp
#define reflection_content_variable_void_hpp
 // ::reflection::content::variable::void_class<data_name,original_name,image_name,storage_name,extractor_name,retriever_name >

#include "../../property/variable/void.hpp"

#include "./_pure.hpp"

namespace reflection
 {
  namespace content
   {
    namespace variable
     {

      template
       <
         typename  identifier_name
       >
       class void_class
        :virtual public ::reflection::content::variable::pure_class<identifier_name, void,void,void>
        ,        public ::reflection::property::variable::void_class
        {
         public:
           typedef  void       data_type;
           typedef  void      original_type;
           typedef  void      image_type;

           typedef ::reflection::content::variable::pure_class<identifier_name, data_type,original_type,image_type> pure_type;
           typedef ::reflection::property::variable::void_class  property_type;

                     void_class()
                      {
                      }

           using property_type::disclose;
           using property_type::present;

           //original_type disclose( )   { return property_type::disclose(); }
           //image_type    present()const{ return property_type::present(); }
        };

      }
    }
  }

#endif