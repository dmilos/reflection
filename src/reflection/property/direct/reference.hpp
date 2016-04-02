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
        ,typename carrier_name // = data_name*
       >
       struct  reference_class
        {
         typedef data_name         data_type;
         typedef carrier_name      carrier_type;

         typedef data_type &       original_type;

         //typedef std::asterisk< original_type, carrier_name & >          extractor_type;

         typedef ::reflection::property::direct::base< original_name, carrier_name, extractor_type>      typedef_type;

         static typedef_type make( ){ return typedef_type( ); }
         static typedef_type make( carrier_name const& carrier_param ){ return typedef_type( carrier_param ); }

        };

      template
       <
         typename data_name
        ,typename carrier_name
       >
       inline
       typename reference_class<data_name,carrier_name>::typedef_type
       reference
        (
         carrier_name  const&  carrier_param
        )
        {
         return reference_class<data_name,carrier_name>::make( carrier_param );
        }

        }
      }
    }
  }


#endif
