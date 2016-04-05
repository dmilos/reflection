#ifndef reflection_property_direct_pure
#define reflection_property_direct_pure

// reflection::property::direct::pure_class<original_name>
// reflection::property::direct::get
// reflection::property::direct::check

#include "../_pure.hpp"

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
        : public ::reflection::property::direct::pure_class<original_name>
        , public ::reflection::property::inspect::pure_class<image_name>
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
         typedef ::reflection::property::direct::pure_class<original_name,image_name> variable_type;
         return nullptr != dynamic_cast< direct_type const*>( &property_param );
        }

     }
   }
 }

 #endif
