#ifndef reflection_property_direct_base_pure
#define reflection_property_direct_base_pure

// ::reflection::property::direct::base_class<base_name,derived_name>
// ::reflection::property::direct::base<base_name,derived_name>

#include "./basic.hpp"

#include "../base/distinctive.hpp"

namespace reflection
 {
  namespace property
   {
    namespace direct
     {

      namespace _internal
       {

        template
         <
           typename base_name
          ,typename derived_name
          ,typename storage_name
         >
        struct base_struct
         {
          public:
            typedef base_name              base_type;
            typedef derived_name        derived_type;
            typedef storage_name        storage_type;

            typedef base_type &   original_type;

            typedef class extractor_class
             {
              public:
                extractor_class()
                 {
                 }
                original_type operator()( storage_type const& carrier_param )const
                 {
                  return  dynamic_cast< original_type >( *carrier_param );
                 }
             } extractor_type;

           typedef ::reflection::property::direct::basic_class< original_type, storage_type, extractor_type >      typedef_type;

           static typedef_type make( storage_type const& carrier_param )
            {
             return typedef_type( carrier_param, extractor_type( ) );
            }
         };

       }


        template
         <
           typename base_name
          ,typename derived_name
          ,typename storage_name
         >
       class base_class
        : public ::reflection::property::base::distinctive_class<base_name,derived_name>
        , public ::reflection::property::direct::_internal::base_struct<base_name,derived_name,storage_name>::typedef_type
        {
         public:
          typedef          ::reflection::property::base::distinctive_class<base_name,derived_name>                      distinctive_type;
          typedef typename ::reflection::property::direct::_internal::base_struct<base_name,derived_name,storage_name>::typedef_type direct_type;

          using direct_type::direct_type;

        };


        template
         <
           typename base_name
          ,typename derived_name
          ,typename storage_name
         >
         ::reflection::property::direct::base_class<base_name,derived_name,storage_name>
         base( storage_name const& carrier_param )
          {
           return ::reflection::property::direct::base_class<base_name,derived_name,storage_name>( carrier_param );
          }
        template
         <
           typename base_name
          ,typename derived_name
         >
         ::reflection::property::direct::base_class<base_name,derived_name,derived_name *>
         base( derived_name * carrier_param )
          {
           return ::reflection::property::direct::base_class<base_name,derived_name,derived_name *>( carrier_param );
          }


     }
   }
 }

#endif
