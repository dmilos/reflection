#ifndef reflection_content_trinity_basic_hpp
#define reflection_content_trinity_basic_hpp
 // ::reflection::content::trinity::basic_class<data_name,image_name,storage_name,extractor_name >

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
         typename      data_name
        ,typename  original_name
        ,typename     image_name
        ,typename     model_name
        ,typename   storage_name
        ,typename extractor_name
        ,typename  assigner_name
        ,typename retriever_name
        ,typename    report_name
       >
       class basic_class
        :virtual public ::reflection::content::trinity::pure_class< data_name, original_name, model_name,image_name,report_name>
        ,        public ::reflection::property::trinity::base_class< original_name, model_name, image_name, storage_name, extractor_name, assigner_name, retriever_name, report_name >
        {
         public:
           typedef        data_name        data_type;
           typedef    original_name    original_type;
           typedef       model_name       model_type;
           typedef       image_name       image_type;
           typedef     storage_name     storage_type;
           typedef   extractor_name   extractor_type;
           typedef    assigner_name    assigner_type;
           typedef   retriever_name   retriever_type;
           typedef      report_name      report_type;

           typedef ::reflection::property::_internal::carrier_class<storage_name> carrier_type;

           typedef ::reflection::content::trinity::pure_class<data_name,original_name,model_name,image_name,report_name> pure_type;
           typedef ::reflection::property::trinity::base_class< original_name,image_name, model_name, storage_name, extractor_name, assigner_name, retriever_name, report_name > base_type;


                     basic_class()
                      {
                      }

            explicit basic_class
                     (
                        storage_type   const& storage_param
                       ,extractor_type  const&  extractor_param =  extractor_type()
                       ,assigner_type  const&    assigner_param =   assigner_type()
                       ,retriever_type const&   retriever_param =  retriever_type()
                     )
                     :carrier_type( storage_param )
                     ,base_type( extractor_param, assigner_param, retriever_param )
                     {
                     }

            using base_type::extractor;
            using base_type::assigner;
            using base_type::retriever;

            //using base_type::disclose;
            //using base_type::process;
            //using base_type::present;

            original_type disclose(){ return base_type::disclose(); }
            report_name   process( model_type model_param ){ return base_type::process(model_param); }
            image_type    present()const{ return base_type::present(); }

        };

      }
    }
  }

#endif
