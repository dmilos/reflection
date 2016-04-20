#ifndef reflection_property_inspect_pure
#define reflection_property_inspect_pure

// reflection::property::inspect::pure_class<image_name>
// reflection::property::inspect::present
// reflection::property::inspect::check

#include "../_pure.hpp"

namespace reflection
 {
  namespace property
   {
    namespace inspect
     {

      template
       <
        typename image_name 
       >
       class pure_class
        : virtual public ::reflection::property::pure_class
        {
         public:
           typedef image_name  image_type;

                    pure_class(){}
           virtual ~pure_class(){}

           virtual image_type present()const=0;
        };

      template< typename image_name>
       inline bool check( ::reflection::property::pure_class const& property_param )
        {
         typedef ::reflection::property::inspect::pure_class<image_name> image_type;
         return nullptr != dynamic_cast< image_type const*>( &property_param );
        }

      template< typename image_name >
       inline image_name present( ::reflection::property::pure_class const& property_param )
        {
         typedef ::reflection::property::inspect::pure_class<image_name> image_type;
         return dynamic_cast< image_type const&>( property_param ).present();
        }

     }
   }
 }

 #endif
