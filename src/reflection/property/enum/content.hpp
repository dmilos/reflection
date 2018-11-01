/*
#ifndef reflection_property_enumeration_content
#define reflection_property_enumeration_content

// ::reflection::property::enumeration::pure_class<size_name>
// ::reflection::property::enumeration::check<size_name>()

#include "../_pure.hpp"

namespace reflection
 {
  namespace property
   {
    namespace enumeration
     {

      template
       <
         typename size_name = std::size_t
       >
       class content_class
        : virtual public ::reflection::property::content_class
        {
         public:
           typedef size_name    size_type;
           typedef  std::vector<size_type>   container_type;

                    content_class(){}
           virtual ~content_class(){}

           size_type size()const{ return this->container(); }
           size_type value( size_type const& index )const{ return this->container()[index]; }

         public:
           container_type const& container()const{ return m_container; }
         protected:
           container_type        container()const{ return m_container; }
         private:
           container_type m_container
        };

      template< typename size_name = std::size_t >
       inline bool check( ::reflection::property::content_class const& property_param )
        {
         typedef ::reflection::property::enumeration::content_class<size_name> enumeration_type;
         return nullptr != dynamic_cast< enumeration_type const*>( &property_param );
        }

     }
   }
 }

#endif

*/
