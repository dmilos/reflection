#ifndef reflection_content_variable_basic_hpp
#define reflection_content_variable_basic_hpp
 // ::reflection::content::variable::basic_class<data_name,image_name,storage_name,extractor_name >

#include "../../property/variable/base.hpp"

#include "./_pure.hpp"

namespace reflection
 {
  namespace content
   {
    namespace variable
     {

      template
       <
         typename      data_name
        ,typename     image_name
        ,typename     model_name
        ,typename   storage_name
        ,typename  extractor_name
        ,typename retriever_name
        ,typename    report_name
       >
       class basic_class
        :virtual public ::reflection::content::variable::pure_class<data_name,model_name,image_name,report_name>
        ,        public ::reflection::property::variable::base_class< model_name, image_name, storage_name,extractor_name, retriever_name, report_name >
        {
         public:
           typedef      data_name       data_type;
           typedef     model_name      model_type;
           typedef     image_name      image_type;
           typedef   storage_name    storage_type;
           typedef  extractor_name extractor_type;
           typedef retriever_name  retriever_type;
           typedef    report_name     report_type;

           typedef ::reflection::content::variable::pure_class<data_name,model_name,image_name,report_name> pure_type;
           typedef ::reflection::property::_internal::carrier_class<storage_name> carrier_type;

           typedef ::reflection::property::variable::base_class< model_name, image_name,  storage_name,extractor_name, retriever_name, report_name > base_class;

                     basic_class()
                      {
                      }

            explicit basic_class
                     (
                       storage_type   const& carrier_param
                      ,extractor_type  const& extractor_param  =  extractor_type()
                      ,retriever_type const& retriever_param = retriever_type()
                     )
                     :base_class( carrier_param, extractor_param, retriever_param )
                     {
                     }

           //using base_class::disclose;
           using base_class::extractor;

           //using base_class::present;
           using base_class::retriever;

           image_type present()const{ return base_class::present(); }
           report_name disclose( model_type model_param ){ return base_class::disclose(model_param); }
        };

      }
    }
  }

#endif
