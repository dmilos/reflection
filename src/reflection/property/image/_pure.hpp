#ifndef reflection_property_image_pure
#define reflection_property_image_pure

#include "../_pure.hpp"

namespace reflection
 {
  namespace property
   {
    namespace image
     {

      template< typename type_name, typename image_name = type_name const& >
       class pure
        : public ::reflection::property::pure
        {
         public:
           typedef  type_name   type_type;
           typedef image_name  image_type;

                    pure(){}
           virtual ~pure(){}

           image_type process()const=0;
        };

      template< typename type_name, typename image_name = type_name const& >
       inline bool check( ::reflection::property::pure const& property_param )
        {
         typedef ::reflection::property::image::pure<type_name,image_name> image_type;
         return nullptr != dynamic_cast< image_type const*>( &property_param );
        }

      template< typename type_name, typename image_name = type_name const& >
       inline image_name process( ::reflection::property::pure const& property_param )
        {
         typedef ::reflection::property::image::pure<type_name,image_name> image_type;
         return dynamic_cast< image_type &>( property_param ).process();
        }

     }
   }
 }

 #endif
