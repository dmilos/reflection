#ifndef reflection_property_variable_base
#define reflection_property_variable_base

#include "../direct/base.hpp"
#include "../inspect/base.hpp"

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
        ,typename convertor_name  //= stl_ext::identity_cast<  type_name const&, storage_name const& >
       >
       class base_class
        :  public ::reflection::property::direct::base_class< original_name,storage_name, extractor_name >
        ,  public ::reflection::property::inspect::base_class< image_name, storage_name, convertor_name >
        {
         public:
           typedef original_name   original_type;
           typedef storage_name    storage_type;
           typedef extractor_name  extractor_type;
           typedef convertor_name  convertor_type;

           typedef ::reflection::property::_internal::carrier_class<storage_name> carrier_type;

           typedef ::reflection::property::direct::base_class< original_name,storage_name, extractor_name > direct_type;
           typedef ::reflection::property::inspect::base_class< image_name, storage_name, convertor_name > inspect_type;

                     base_class(){ }

            explicit base_class
             (
               storage_type   const& storage_param
              ,extractor_type const& extractor_param = extractor_type()
              ,convertor_type const& convertor_param = convertor_type()
             )
             :carrier_type(   storage_param )
             , direct_type( extractor_param )
             ,inspect_type( convertor_param )
             {
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
