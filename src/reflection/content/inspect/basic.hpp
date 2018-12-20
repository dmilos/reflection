#ifndef reflection_content_inspect_basic_hpp
#define reflection_content_inspect_basic_hpp
 // ::reflection::content::inspect::basic_class<data_name,image_name,storage_name,extractor_name >

#include "../../property/inspect/basic.hpp"

#include "./_pure.hpp"

namespace reflection
 {
  namespace content
   {
    namespace inspect
     {

      template
       <
         typename identifier_name
        ,typename data_name       //!< mutablize before use!
        ,typename image_name   //!< mutablize before use!
        ,typename storage_name    //= data_name
        ,typename retriever_name  //= stl_ext::identity_cast<  data_name const&, storage_name const& >
       >
       class basic_class
        :virtual public ::reflection::content::inspect::pure_class<identifier_name,data_name,image_name>
        ,        public ::reflection::property::inspect::basic_class<image_name,storage_name,retriever_name>
        {
         public:
           typedef data_name            data_type;
           typedef image_name          image_type;
           typedef storage_name      storage_type;
           typedef retriever_name  retriever_type;

           typedef ::reflection::content::inspect::pure_class<identifier_name,data_name,image_name > pure_type;
           typedef ::reflection::property::_internal::carrier_class<storage_name> carrier_type;

           typedef::reflection::property::inspect::basic_class<image_name,storage_name,retriever_name> base_type;

                    basic_class()
                     :basic_class( storage_type{}, retriever_type{} )
                     {
                     }

           explicit basic_class
                    (
                      storage_type   const& carrier_param
                     ,retriever_type const& extractor_param = retriever_type()
                    )
                    :base_type( extractor_param )
                    ,carrier_type( carrier_param )
                    {
                    }

           using base_type::present;
           using base_type::retriever;
        };

      }
    }
  }

#endif
