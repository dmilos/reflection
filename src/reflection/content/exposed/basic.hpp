#ifndef reflection_content_exposed_basic_hpp
#define reflection_content_exposed_basic_hpp

 // ::reflection::content::exposed::basic_class<data_name,original_name,model_name,storage_name,extractor_name,assigner_name,report_name >

#include "../../property/exposed/basic.hpp"

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
        ,typename        data_name
        ,typename    original_name
        ,typename       model_name
        ,typename     storage_name
        ,typename   extractor_name  //= stl_ext::identity_cast<  data_name const&, storage_name const& >
        ,typename    assigner_name  //= stl_ext::identity_cast<  data_name const&, storage_name const& >

        ,typename     report_name
       >
       class basic_class
        :virtual public ::reflection::content::exposed::pure_class<identifier_name,data_name,original_name,model_name,report_name>
        ,        public ::reflection::property::exposed::basic_class< original_name, model_name, storage_name, extractor_name, assigner_name, report_name >
        {
         public:
           typedef      data_name       data_type;
           typedef  original_name   original_type;
           typedef     model_name      model_type;
           typedef   storage_name    storage_type;
           typedef extractor_name  extractor_type;
           typedef assigner_name    assigner_type;
           typedef report_name        report_type;

           typedef ::reflection::property::_internal::carrier_class<storage_name> carrier_type;

           typedef ::reflection::content::exposed::pure_class<identifier_name,data_name,original_name,model_name,report_name> pure_type;
           typedef ::reflection::property::exposed::basic_class< original_name, model_name, storage_name, extractor_name, assigner_name, report_name > base_type;


                    basic_class()
                     :basic_class( storage_type{}, extractor_type{}, assigner_type{} )
                     {
                     }

           explicit basic_class
             (
               storage_type   const& storage_param
              ,extractor_type const&  extractor_param  =   extractor_type()
              ,assigner_type  const&  assigner_param   =    assigner_type()
             )
             :carrier_type( storage_param )
             ,base_type( extractor_param, assigner_param )
             {
             }

         public:
            using base_type::extractor;
            using base_type::assigner;

            //using base_type::disclose;
            //using base_type::process;

            original_type disclose(){ return base_type::disclose(); }
            report_name   process( model_type model_param ){ return base_type::process(model_param); }

        };

      }
    }
  }

#endif
