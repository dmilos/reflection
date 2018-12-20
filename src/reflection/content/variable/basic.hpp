#ifndef reflection_content_variable_basic_hpp
#define reflection_content_variable_basic_hpp
 // ::reflection::content::variable::basic_class<data_name,original_name,image_name,storage_name,extractor_name,retriever_name >

#include "../../property/variable/basic.hpp"

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
        ,typename        data_name
        ,typename    original_name
        ,typename       image_name
        ,typename     storage_name
        ,typename   extractor_name
        ,typename   retriever_name
       >
       class basic_class
        :virtual public ::reflection::content::variable::pure_class<identifier_name, data_name,original_name,image_name>
        ,        public ::reflection::property::variable::basic_class< original_name, image_name, storage_name,extractor_name, retriever_name >
        {
         public:
           typedef      data_name       data_type;
           typedef  original_name      original_type;
           typedef     image_name      image_type;
           typedef   storage_name    storage_type;
           typedef extractor_name  extractor_type;
           typedef retriever_name  retriever_type;

           typedef ::reflection::content::variable::pure_class<identifier_name, data_name,original_name,image_name> pure_type;
           typedef ::reflection::property::variable::basic_class< original_name, image_name, storage_name,extractor_name, retriever_name> base_type;

           typedef ::reflection::property::_internal::carrier_class<storage_name> carrier_type;

                    basic_class()
                     : basic_class( storage_type{}, extractor_type{}, retriever_type{} )
                     {
                     }

           explicit basic_class
                    (
                      storage_type   const& storage_param
                     ,extractor_type const& extractor_param = extractor_type()
                     ,retriever_type const& retriever_param = retriever_type()
                    )
                    :carrier_type( storage_param )
                    ,base_type( extractor_param, retriever_param )
                    {
                    }

           //using base_class::disclose;
           using base_type::extractor;

           //using base_type::present;
           using base_type::retriever;

           original_type disclose( )   { return base_type::disclose(); }
           image_type    present()const{ return base_type::present(); }
        };

      }
    }
  }

#endif
