#ifndef reflection_property_exposed_type_base
#define reflection_property_exposed_type_base

#include "../direct/base.hpp"
#include "../mutate/base.hpp"
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
        ,typename storage_name    //= type_name
        ,typename extractor_name  //= stl_ext::identity_cast<  type_name const&, storage_name const& >
        ,typename assigner_name   //= stl_ext::identity_cast<  type_name const&, storage_name const& >
        ,typename report_name
       >
       class base_class
        :  virtual public ::reflection::property::exposed::pure_class<original_name,model_name,report_name>
        ,          public ::reflection::property::direct::base_class< original_name, storage_name, extractor_name >
        ,          public ::reflection::property::mutate::base_class< model_name, storage_name, assigner_name, report_name >
        {
         public:
           typedef original_name   original_type;
           typedef storage_name    storage_type;
           typedef extractor_name  extractor_type;
           typedef assigner_name  assigner_class;

           typedef ::reflection::property::_internal::carrier_class<storage_name> carrier_type;

           typedef ::reflection::property::direct::base_class< original_name,storage_name, extractor_name > direct_type;
           typedef ::reflection::property::mutate::base_class< model_name, storage_name, assigner_name, report_name > mutate_type;

                    base_class()
                     {
                     }

           explicit base_class
            (
              extractor_type const& extractor_param
             ,assigner_class const& assigner_param
            )
            :direct_type( extractor_param )
            ,mutate_type( assigner_param )
            {
            }

           explicit base_class
            (
              storage_type   const& storage_param
             ,extractor_type const& extractor_param = extractor_type()
             ,assigner_class const& assigner_param = assigner_class()
            )
            :carrier_type(   storage_param )
            , direct_type( extractor_param )
            ,mutate_type( assigner_param )
            {
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