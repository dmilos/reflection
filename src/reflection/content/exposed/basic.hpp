#ifndef reflection_content_exposed_basic_hpp
#define reflection_content_exposed_basic_hpp
 // ::reflection::content::exposed::basic_class<data_name,original_name,model_name,storage_name,extractor_name,assigner_name,report_name >

#include "../../property/exposed/base.hpp"

#include "./_pure.hpp"

namespace reflection
 {
  namespace content
   {
    namespace exposed
     {

      template
       <
         typename       data_name
        ,typename   original_name
        ,typename      model_name
        ,typename    storage_name
        ,typename  extractor_name
        ,typename   assigner_name
        ,typename     report_name
       >
       class basic_class
        :virtual public ::reflection::content::exposed::pure_class<data_name,original_name,model_name,report_name>
        ,        public ::reflection::property::exposed::base_class< original_name, model_name, storage_name,extractor_name, assigner_name,report_name >
        {
         public:
           typedef      data_name       data_type;
           typedef  original_name   original_type;
           typedef     model_name      image_type;
           typedef   storage_name    storage_type;
           typedef extractor_name  extractor_type;
           typedef assigner_name    assigner_type;

           typedef ::reflection::content::exposed::pure_class<data_name,original_name,model_name,report_name> pure_type;
           typedef ::reflection::property::exposed::base_class< original_name, model_name, storage_name,extractor_name, assigner_name,report_name> base_type;

           typedef ::reflection::property::_internal::carrier_class<storage_name> carrier_type;

                     basic_class()
                      {
                      }

            explicit basic_class
                     (
                       storage_type   const& storage_param
                      ,extractor_type const& extractor_param = extractor_type()
                      ,assigner_type  const& assigner_param  = assigner_type()
                     )
                     :carrier_type( storage_param )
                     ,base_type( extractor_param, assigner_param )
                     {
                     }

           //using base_class::disclose;
           using base_type::extractor;

           //using base_type::present;
           using base_type::assigner;

           original_type disclose( )   { return base_type::disclose(); }
           image_type    present()const{ return base_type::present(); }
        };

      }
    }
  }

#endif
