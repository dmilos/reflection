#ifndef reflection_property_direct_pure
#define reflection_property_direct_pure

#include "../_pure.hpp"

namespace reflection
 {
  namespace property
   {
    namespace direct
     {

      template
       <
         typename type_name
        ,typename original_name = type_name const& 
       >
       class pure_class
        : public ::reflection::property::pure_class
        {
         public:
           typedef type_name type_type;
           typedef original_name original_type;

                    pure_class(){}
           virtual ~pure_class(){}

           original_type get()=0;
        };

      template< typename type_name, typename original_name = type_name const&  >
       inline bool check( ::reflection::property::pure_class const& property_param )
        {
         typedef ::reflection::property::direct::pure_class<type_name, original_name> direct_type;
         return nullptr != dynamic_cast< direct_type const*>( &property_param );
        }

      template< typename type_name, typename original_name = type_name const&  >
       inline direct_name get( ::reflection::property::pure_class const& property_param )
        {
         typedef ::reflection::property::direct::pure_class<type_name,original_name> direct_type;
         return dynamic_cast< direct_type &>( property_param ).get();
        }

     }
   }
 }

 #endif
