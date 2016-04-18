#ifndef reflection_content_mutate_basic_hpp
#define reflection_content_mutate_basic_hpp
 // ::reflection::content::mutate::basic_class<data_name,model_name,storage_name,extractor_name >

#include "../../property/mutate/base.hpp"

#include "./_pure.hpp"

namespace reflection
 {
  namespace content
   {
    namespace mutate
     {

      template
       <
         typename data_name       //!< mutablize before use!
        ,typename model_name   //!< mutablize before use!
        ,typename storage_name    //= data_name
        ,typename extractor_name  //= stl_ext::identity_cast<  data_name const&, storage_name const& >
        ,typename report_name
       >
       class basic_class
        :virtual public ::reflection::content::mutate::pure_class<data_name,model_name,report_name>
        ,        public ::reflection::property::mutate::base_class<model_name,storage_name,extractor_name,report_name>
        {
         public:
           typedef data_name       data_type;
           typedef model_name   model_type;
           typedef storage_name    storage_type;
           typedef extractor_name  convertor_class;

           typedef ::reflection::content::mutate::pure_class<data_name,model_name, report_name > pure_type;
           typedef ::reflection::property::_internal::carrier_class<storage_name> carrier_type;

           typedef::reflection::property::mutate::base_class<model_name,storage_name,extractor_name, report_name> base_class;

                     basic_class()
                      {
                      }

            explicit basic_class
                     (
                       convertor_class const& extractor_param
                     )
                     :base_class( extractor_param )
                     {
                     }

            explicit basic_class
                     (
                       storage_type   const& P_carrier
                      ,convertor_class const& extractor_param = convertor_class()
                     )
                     :base_class( extractor_param )
                     ,carrier_type( P_carrier )
                     {
                     }

           using base_class::process;
        };

      }
    }
  }

#endif
