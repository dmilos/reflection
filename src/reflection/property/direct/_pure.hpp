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
         typename original_name
       >
       class pure_class
        : public ::reflection::property::pure_class
        {
         public:
           typedef original_name original_type;

                    pure_class(){}
           virtual ~pure_class(){}

           virtual original_type get()=0;
        };

      template< typename original_name >
       inline bool check( ::reflection::property::pure_class const& property_param )
        {
         typedef ::reflection::property::direct::pure_class<original_name> direct_type;
         return nullptr != dynamic_cast< direct_type const*>( &property_param );
        }

      template< typename original_name >
       inline original_name get( ::reflection::property::pure_class const& property_param )
        {
         typedef ::reflection::property::direct::pure_class<original_name> direct_type;
         return dynamic_cast< direct_type &>( property_param ).get();
        }

     }
   }
 }

 #endif
