#ifndef reflection_property_big_pure
#define reflection_property_big_pure

// ::reflection::property::big::pure_class<size_name,data_name>
// ::reflection::property::big::check
// ::reflection::property::big::convert

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
       //,typename copy_name = std::vector< std::uint8_t >
        >
       class pure_class
        : virtual public ::reflection::property::pure_class
        {
         public:
           typedef size_name size_type;
           typedef data_name data_type;

                    pure_class(){}
           virtual ~pure_class(){}

           virtual size_type  size( )const=0;
           virtual size_type  size( size_type const& size_param )=0;
           virtual size_type  get(     data_type      & value_param,  size_type const& position_param )const=0;
           virtual bool       insert(  data_type const& value_param,  size_type const& position_param )=0;
           virtual bool       replace( data_type const& value_param,  size_type const& position_param )=0;
           virtual bool       erase(   size_type const& begin_param,  size_type const& end_param )=0;
        };

      template< typename size_name, typename data_name >
       inline bool check( ::reflection::property::pure_class const& property_param )
        {
         typedef ::reflection::property::big::pure_class<size_name, data_name> big_type;
         return nullptr != dynamic_cast< big_type const*>( &property_param );
        }

      template< typename size_name, typename data_name >
       inline
       ::reflection::property::big::pure_class<size_name, data_name> const*
       convert( ::reflection::property::pure_class const& property_param )
        {
         typedef ::reflection::property::big::pure_class<size_name, data_name> big_type;
         return dynamic_cast< big_type const*>( &property_param );
        }

     }
   }
 }

 #endif
