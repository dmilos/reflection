#ifndef reflection_property_variable_pure
#define reflection_property_variable_pure

// ::reflection::property::variable::pure_class<original_name,image_name>
// ::reflection::property::variable::get
// ::reflection::property::variable::check

#include "../direct/_pure.hpp"
#include "../inspect/_pure.hpp"

namespace reflection
 {
  namespace property
   {
    namespace variable
     {

      template
       <
         typename original_name
        ,typename    image_name
       >
       class pure_class
        : virtual public ::reflection::property::direct::pure_class<original_name>
        , virtual public ::reflection::property::inspect::pure_class<image_name>
        {
         public:
           typedef original_name original_type;
           typedef image_name       image_type;

           typedef  ::reflection::property::direct::pure_class<original_name>  direct_type;
           typedef  ::reflection::property::inspect::pure_class<image_name>    inspect_type;


                    pure_class(){}
           virtual ~pure_class(){}

           using direct_type::disclose;
           using inspect_type::present;
        };

      template< typename original_name, typename image_name >
       inline bool check( ::reflection::property::pure_class const& property_param )
        {
         typedef ::reflection::property::variable::pure_class<original_name,image_name> variable_type;
         return nullptr != dynamic_cast< variable_type const*>( &property_param );
        }

     }
   }
 }

 #endif
