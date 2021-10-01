#ifndef reflection_property_exposed_type_base
#define reflection_property_exposed_type_base

#include "../direct/basic.hpp"
#include "../mutate/basic.hpp"
#include "./_pure.hpp"

namespace reflection
 {
  namespace property
   {
    namespace exposed
     {

      template
       <
         typename original_name
        ,typename model_name
        ,typename storage_name
        ,typename extractor_name  //= stl_ext::identity_cast<  type_name const&, storage_name const& >
        ,typename assigner_name   //= stl_ext::identity_cast<  type_name const&, storage_name const& >
        ,typename report_name
       >
       class basic_class
        :  virtual public ::reflection::property::exposed::pure_class<original_name,model_name,report_name>
        ,          public ::reflection::property::direct::basic_class< original_name, storage_name, extractor_name >
        ,          public ::reflection::property::mutate::basic_class< model_name, storage_name, assigner_name, report_name >
        {
         public:
           typedef original_name    original_type;
           typedef model_name          model_type;
           typedef storage_name      storage_type;
           typedef extractor_name  extractor_type;
           typedef assigner_name    assigner_type;
           typedef report_name        report_type;

           typedef ::reflection::property::_internal::carrier_class<storage_name> carrier_type;

           typedef ::reflection::property::exposed::pure_class< original_name, model_name, report_name>      pure_type;

           typedef ::reflection::property::direct::basic_class< original_name,storage_name, extractor_name > direct_type;
           typedef ::reflection::property::mutate::basic_class< model_name, storage_name, assigner_name, report_name > mutate_type;

                    basic_class()
                     {
                     }

           explicit basic_class
            (
              extractor_type const& extractor_param // =   extractor_type()
             ,assigner_type  const& assigner_param  // =    assigner_type()
            )
            :direct_type( extractor_param )
            ,mutate_type( assigner_param )
            {
            }

           explicit basic_class
            (
              storage_type   const& storage_param
             ,extractor_type const& extractor_param = extractor_type()
             ,assigner_type  const& assigner_param  = assigner_type()
            )
            : direct_type( extractor_param )
            ,mutate_type( assigner_param )
              {
               this->storage( storage_param );
              }

         public:
           using direct_type::disclose;
           using direct_type::extractor;

           using mutate_type::process;
           using mutate_type::assigner;
        };

      }
    }
  }

#endif
