#ifndef reflection_property_reset_pure
#define reflection_property_reset_pure

#include "../_pure.hpp"

namespace reflection
 {
  namespace property
   {
    namespace reset
     {

      template< typename type_name, typename report_name = bool >
       class pure_class
        : public ::reflection::property::pure_class
        {
         public:
           typedef type_name type_type;
           typedef report_name report_type;

                    pure_class(){}
           virtual ~pure_class(){}

           report_type process()=0;
        };

      template< typename type_name, typename reset_name = type_name const&  >
       inline bool check( ::reflection::property::pure_class const& property_param )
        {
         typedef ::reflection::property::reset::pure_class<type_name, reset_name> reset_type;
         return nullptr != dynamic_cast< reset_type const*>( &property_param );
        }

      template< typename type_name, typename reset_name = type_name const&  >
       inline reset_name process( ::reflection::property::pure_class const& property_param )
        {
         typedef ::reflection::property::reset::pure_class<type_name,reset_name> reset_type;
         return dynamic_cast< reset_type &>( property_param ).get();
        }

     }
   }
 }

 #endif
