#ifndef reflection_property_valid_pure
#define reflection_property_valid_pure

// ::reflection::property::valid<report_name>
// ::reflection::property::valid::check
// ::reflection::property::valid::process

#include "../_pure.hpp"

namespace reflection
 {
  namespace property
   {
    namespace valid
     {

      template
       <
        typename report_name = bool 
       >
       class pure_class
        : virtual public ::reflection::property::pure_class
        {
         public:
           typedef report_name report_type;

                    pure_class(){}
           virtual ~pure_class(){}

           virtual report_type test()=0;
        };

      template< typename report_name = void >
       inline bool check( ::reflection::property::pure_class const& property_param )
        {
         typedef ::reflection::property::valid::pure_class<report_name> valid_type;
         return nullptr != dynamic_cast< valid_type const*>( &property_param );
        }

      template< typename report_name = void  >
       inline report_name test( ::reflection::property::pure_class & property_param )
        {
         typedef ::reflection::property::valid::pure_class<report_name> valid_type;
         return dynamic_cast< valid_type &>( property_param ).test();
        }

     }
   }
 }

 #endif
