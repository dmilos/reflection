#ifndef reflection_property_direct_pure
#define reflection_property_direct_pure

#include "../_pure.hpp"

namespace reflection
 {
  namespace property
   {
    namespace direct
     {

      template< typename type_name, typename direct_name = type_name const& >
       class pure
        : public ::reflection::property::pure
        {
         public:
           typedef type_name type_type;
           typedef direct_name direct_type;

                    pure(){}
           virtual ~pure(){}

           direct_type get()=0;
        };

      template< typename type_name, typename direct_name = type_name const&  >
       inline bool check( ::reflection::property::pure const& property_param )
        {
         typedef ::reflection::property::direct::pure<type_name, direct_name> direct_type;
         return nullptr != dynamic_cast< direct_type const*>( &property_param );
        }

      template< typename type_name, typename direct_name = type_name const&  >
       inline direct_name get( ::reflection::property::pure const& property_param )
        {
         typedef ::reflection::property::direct::pure<type_name,direct_name> direct_type;
         return dynamic_cast< direct_type &>( property_param ).get();
        }

     }
   }
 }

 #endif
