#ifndef reflection_content_inspect_basic_hpp
#define reflection_content_inspect_basic_hpp
 // ::reflection::content::inspect::basic_class<data_name,image_name,storage_name,extractor_name >

#include "../../property/inspect/base.hpp"

#include "./_pure.hpp"

namespace reflection
 {
  namespace content
   {
    namespace inspect
     {

      template
       <
         typename data_name       //!< mutablize before use!
        ,typename image_name   //!< mutablize before use!
        ,typename storage_name    //= data_name
        ,typename extractor_name  //= stl_ext::identity_cast<  data_name const&, storage_name const& >
       >
       class basic_class
        :virtual public ::reflection::content::inspect::pure_class<data_name,image_name>
        ,        public ::reflection::property::inspect::base_class<image_name,storage_name,extractor_name>
        {
         public:
           typedef data_name       data_type;
           typedef image_name   image_type;
           typedef storage_name    storage_type;
           typedef extractor_name  convertor_class;

           typedef ::reflection::content::inspect::pure_class<data_name,image_name > pure_type;
           typedef ::reflection::property::_internal::carrier_class<storage_name> carrier_type;

           typedef::reflection::property::inspect::base_class<image_name,storage_name,extractor_name> base_class;

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

           using base_class::present;
        };

      }
    }
  }

#endif
