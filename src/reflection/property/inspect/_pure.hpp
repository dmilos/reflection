#ifndef reflection_property_inspect_pure
#define reflection_property_inspect_pure

#include "../_pure.hpp"

namespace reflection
 {
  namespace property
   {
    namespace inspect
     {

      template< typename type_name, typename image_name = type_name const& >
       class pure_class
        : public ::reflection::property::pure_class
        {
         public:
           typedef  type_name   type_type;
           typedef image_name  image_type;

                    pure_class(){}
           virtual ~pure_class(){}

           image_type get()const=0;
        };

      template< typename type_name, typename image_name = type_name const& >
       inline bool check( ::reflection::property::pure_class const& property_param )
        {
         typedef ::reflection::property::inspect::pure_class<type_name,image_name> image_type;
         return nullptr != dynamic_cast< image_type const*>( &property_param );
        }

      template< typename type_name, typename image_name = type_name const& >
       inline image_name get( ::reflection::property::pure_class const& property_param )
        {
         typedef ::reflection::property::inspect::pure_class<type_name,image_name> image_type;
         return dynamic_cast< image_type &>( property_param ).get();
        }

     }
   }
 }

 #endif
