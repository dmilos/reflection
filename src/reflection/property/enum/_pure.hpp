#ifndef reflection_property_enumeration_pure
#define reflection_property_enumeration_pure

// ::reflection::property::enumeration::pure_class<size_name>
// ::reflection::property::enumeration::check<size_name>()

#include "../../type/name/id.hpp"
#include "../../define/idspec.hpp"
#include "../_pure.hpp"
#include "./subject.hpp"

namespace reflection
 {
  namespace property
   {
    namespace enumeration
     {

      template
       <
         typename name_name  //= identifier_name
        ,typename value_name //= delete std::size_t
       >
       class pure_class
        : virtual public ::reflection::property::pure_class
        {
         public:
           typedef name_name    name_type;
           typedef value_name  value_type;

           typedef ::reflection::property::enumeration::subject_class<name_name,value_name> subject_type;

           typedef  std::vector<subject_type>    container_type;
           typedef typename container_type::size_type size_type;

                    pure_class(){}
           virtual ~pure_class(){}

           size_type size()const
            {
             return this->container();
            }

           void push( name_name const& name, value_name const& value )
            {
             this->container().push_back( subject_type{ name, value }  );
            }

           subject_type subject( size_type const& index )const
            {
             return this->container()[index];
            }

         public:
           container_type const& container()const{ return m_container; }
         protected:
           container_type      & container()     { return m_container; }
         private:
           container_type m_container;
        };

      template< typename name_name, typename value_name >
       inline bool check( ::reflection::property::pure_class const& property_param )
        {
         typedef ::reflection::property::enumeration::pure_class<name_name, value_name> enumeration_type;
         return nullptr != dynamic_cast< enumeration_type const*>( &property_param );
        }

       typedef ::reflection::property::enumeration::pure_class<std::string, std::size_t>   standard_t;
     }
   }
 }

reflection__IDSPEC( std::string, "$enum", ::reflection::property::enumeration::standard_t )


#endif
