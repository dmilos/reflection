#ifndef reflection_content_direct_basic_hpp
#define reflection_content_direct_basic_hpp
 // ::reflection::content::direct::basic_class<data_name,original_name,storage_name,extractor_name >

#include "../../property/direct/base.hpp"

#include "./_pure.hpp"

namespace reflection
 {
  namespace content
   {
    namespace direct
     {

      template
       <
         typename data_name       //!< mutablize before use!
        ,typename original_name   //!< mutablize before use!
        ,typename storage_name    //= data_name
        ,typename extractor_name  //= stl_ext::identity_cast<  data_name const&, storage_name const& >
       >
       class basic_class
        :virtual public ::reflection::content::direct::pure_class<data_name,original_name>
        ,        public ::reflection::property::direct::base_class<original_name,storage_name,extractor_name>
        {
         public:
           typedef data_name       data_type;
           typedef original_name   original_type;
           typedef storage_name    storage_type;
           typedef extractor_name  extractor_type;

           typedef ::reflection::content::direct::pure_class<data_name,original_name > pure_type;
           typedef ::reflection::property::_internal::carrier_class<storage_name> carrier_type;

           typedef::reflection::property::direct::base_class<original_name,storage_name,extractor_name> base_class;

                     basic_class()
                      {
                      }

            explicit basic_class
                     (
                       extractor_type const& extractor_param
                     )
                     :base_class( extractor_param )
                     {
                     }

            explicit basic_class
                     (
                       storage_type   const& P_carrier
                      ,extractor_type const& extractor_param = extractor_type()
                     )
                     :base_class( extractor_param )
                     ,carrier_type( P_carrier )
                     {
                     }

           using base_class::disclose;
        };

      }
    }
  }

#endif
