#ifndef reflection_property_big_pure
#define reflection_property_big_pure

// reflection::property::big::pure_class<original_name>

// reflection::property::big::check

#include "../_pure.hpp"

namespace reflection
 {
  namespace property
   {
    namespace big
     {

       template 
        <
          typename size_name = std::size_t
         ,typename data_name = std::vector< std::uint8_t >
        >
       class pure_class
        : virtual public ::reflection::property::pure_class
        {
         public:
           typedef size_name size_type;

                    pure_class(){}
           virtual ~pure_class(){}

           virtual size_type  size( )const=0;
           virtual size_type  get( data_type & value,  size_type const& position )const=0;
           virtual bool       insert(  data_type const& value,  size_type const& position )=0;
           virtual bool       replace( data_type const& value,  size_type const& position )=0;
           virtual bool       erase(   size_type const& begin,  size_type const& end )=0;
        };

      template< typename size_name, typename data_name >
       inline bool check( ::reflection::property::pure_class const& property_param )
        {
         typedef ::reflection::property::big::pure_class<size_name, data_name> big_type;
         return nullptr != dynamic_cast< big_type const*>( &property_param );
        }

     }
   }
 }

 #endif
