#ifndef reflection_content_guarded_basic_hpp
#define reflection_content_guarded_basic_hpp
 // ::reflection::content::guarded::basic_class<data_name,image_name,storage_name,extractor_name >

#include "../../property/guarded/base.hpp"

#include "../mutate/basic.hpp"
#include "../inspect/basic.hpp"

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
           typedef ::reflection::property::guarded::base_class< model_name, image_name,  storage_name,assigner_name, retriever_name, report_name > base_type;

           typedef ::reflection::property::_internal::carrier_class<storage_name> carrier_type;

                     basic_class()
                      {
                      }

            explicit basic_class
                     (
                       storage_type   const& storage_param
                      ,assigner_type  const&  assigner_param =  assigner_type()
                      ,retriever_type const& retriever_param = retriever_type()
                     )
                     :carrier_type( storage_param )
                     ,base_type( assigner_param, retriever_param )
                     {
                     }

           //using base_type::process;
           using base_type::assigner;

           //using base_type::present;
           using base_type::retriever;

           image_type present()const{ return base_type::present(); }
           report_name process( model_type model_param ){ return base_type::process(model_param); }
        };

      }
    }
  }

#endif
