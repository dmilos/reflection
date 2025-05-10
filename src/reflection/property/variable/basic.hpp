#ifndef reflection_property_variable_basic
#define reflection_property_variable_basic

#include "../direct/basic.hpp"
#include "../inspect/basic.hpp"
#include "./_pure.hpp"

namespace reflection
 {
  namespace property
   {
    namespace variable
     {

      template
       <
         typename original_name
        ,typename image_name
        ,typename storage_name    //= type_name
        ,typename extractor_name  //= stl_ext::identity_cast<  type_name const&, storage_name const& >
        ,typename retriever_name  //= stl_ext::identity_cast<  type_name const&, storage_name const& >
       >
       class basic_class
        :  virtual public ::reflection::property::variable::pure_class<original_name,image_name>
        ,          public ::reflection::property::direct::basic_class< original_name,storage_name, extractor_name >
        ,          public ::reflection::property::inspect::basic_class< image_name, storage_name, retriever_name >
        {
         public:
           typedef original_name    original_type;
           typedef storage_name      storage_type;
           typedef extractor_name  extractor_type;
           typedef retriever_name  retriever_type;

           typedef ::reflection::property::_internal::proxy_class<storage_name> carrier_type;

           typedef ::reflection::property::direct::basic_class< original_name,storage_name, extractor_name > direct_type;
           typedef ::reflection::property::inspect::basic_class< image_name, storage_name, retriever_name > inspect_type;

                    basic_class()
                     {
                     }

           explicit basic_class
            (
              extractor_type const& extractor_param
             ,retriever_type const& retriever_param
            )
            :direct_type( extractor_param )
            ,inspect_type( retriever_param )
            {
            }

           explicit basic_class
            (
              storage_type   const& storage_param
             ,extractor_type const& extractor_param = extractor_type()
             ,retriever_type const& retriever_param = retriever_type()
            )
            : direct_type( extractor_param )
            ,inspect_type( retriever_param )
              {
               this->storage( storage_param );
              }

         public:
           using direct_type::disclose;
           using direct_type::extractor;

           using inspect_type::present;
           using inspect_type::retriever;
        };

      }
    }
  }

#endif
