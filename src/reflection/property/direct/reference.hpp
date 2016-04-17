#ifndef reflection_property_direct_reference
#define reflection_property_direct_reference

#include "./base.hpp"

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
       struct  reference_class
        {
         typedef data_name         data_type;
         typedef storage_name      storage_type;

         typedef data_type &       original_type;

         //typedef std::asterisk< original_type, storage_name & >          extractor_type;

         typedef ::reflection::property::direct::base< original_type, storage_name, extractor_type>      typedef_type;

         static typedef_type make( ){ return typedef_type( ); }
         static typedef_type make( storage_name const& carrier_param ){ return typedef_type( carrier_param ); }

        };

      template
       <
         typename data_name
        ,typename storage_name
       >
       inline
       typename reference_class<data_name,storage_name>::typedef_type
       reference
        (
         storage_name  const&  carrier_param
        )
        {
         return reference_class<data_name,storage_name>::make( carrier_param );
        }

        }
      }
    }
  }


#endif
