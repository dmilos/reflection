#ifndef reflection_property_direct_pointer
#define reflection_property_direct_pointer

// ::reflection::property::direct::pointer_class<data_name, storage_name>

#include "./basic.hpp"
#include "../../type/functor/asterisk.hpp"


namespace reflection
 {
  namespace property
   {
    namespace direct
     {

      template
       <
         typename data_name
        ,typename storage_name // = data_name*
       >
       struct  pointer_class
        {
         typedef data_name         data_type;
         typedef storage_name      storage_type;

         typedef data_type &       original_type;

         typedef ::reflection::type::functor::asterisk< original_type, storage_name >          extractor_type;

         typedef ::reflection::property::direct::basic_class< original_type, storage_name, extractor_type>      typedef_type;

         static typedef_type make( ){ return typedef_type( ); }
         static typedef_type make( storage_name const& carrier_param ){ return typedef_type( carrier_param ); }
        };

      template
       <
         typename data_name
        ,typename storage_name
       >
       inline
       typename pointer_class<data_name,storage_name>::typedef_type
       pointer
        (
         storage_name  const&  carrier_param
        )
        {
         return pointer_class<data_name,storage_name>::make( carrier_param );
        }

      }
    }
  }

#endif
