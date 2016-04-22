#ifndef reflection_content_guarded_basic_hpp
#define reflection_content_guarded_basic_hpp
 // ::reflection::content::guarded::basic_class<data_name,image_name,storage_name,extractor_name >

#include "../../property/guarded/base.hpp"

#include "./_pure.hpp"

namespace reflection
 {
  namespace content
   {
    namespace guarded
     {

      template
       <
         typename      data_name
        ,typename     image_name
        ,typename     model_name
        ,typename   storage_name
        ,typename  assigner_name
        ,typename retriever_name
        ,typename    report_name
       >
       class basic_class
        :virtual public ::reflection::content::guarded::pure_class<data_name,model_name,image_name,report_name>
        ,        public ::reflection::property::guarded::base_class< model_name, image_name, storage_name,assigner_name, retriever_name, report_name >
        {
         public:
           typedef      data_name       data_type;
           typedef     model_name      model_type;
           typedef     image_name      image_type;
           typedef   storage_name    storage_type;
           typedef  assigner_name   assigner_type;
           typedef retriever_name  retriever_type;
           typedef    report_name     report_type;

           typedef ::reflection::content::guarded::pure_class<data_name,model_name,image_name,report_name> pure_type;
           typedef ::reflection::property::_internal::carrier_class<storage_name> carrier_type;

           typedef ::reflection::property::guarded::base_class< model_name, image_name,  storage_name,assigner_name, retriever_name, report_name > base_class;

                     basic_class()
                      {
                      }

            explicit basic_class
                     (
                       storage_type   const& carrier_param
                      ,assigner_type  const& assigner_param  =  assigner_type()
                      ,retriever_type const& retriever_param = retriever_type()
                     )
                     :base_class( carrier_param, assigner_param, retriever_param )
                     {
                     }

           //using base_class::process;
           using base_class::assigner;

           //using base_class::present;
           using base_class::retriever;

           image_type present()const{ return base_class::present(); }
           report_name process( model_type model_param ){ return base_class::process(model_param); }
        };

      }
    }
  }

#endif
