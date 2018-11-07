#ifndef reflection_property_enumeration_base
#define reflection_property_enumeration_base

// ::reflection::property::enumeration::base_class<enumarator_name,size_name>

#include "../_pure.hpp"
#include "./_pure.hpp"

namespace reflection
 {
  namespace property
   {
    namespace enumeration
     {

      template
       <
         typename enumarator_name
        ,typename       name_name //= std::string
        ,typename      value_name //= std::size_t
       >
       class base_class
        : virtual public ::reflection::property::enumeration::pure_class<name_name,value_name >
        {
         public:
           typedef enumarator_name    enumarator_type;
           typedef       name_name          name_type;
           typedef      value_name         value_type;

           typedef ::reflection::property::enumeration::pure_class<name_name,value_name> pure_type;

         public:
                    base_class( name_name const& name ):pure_type( name ){}
           virtual ~base_class(){}

         public:
           void push( name_type const& n, enumarator_type const& v )
            {
             this->pure_type::push( n, v );
            }

           //enumarator_type value( size_type const& index )
           // {
           //  return enumarator_type { this->container()[index]; }
           // }
        };

     }
   }
 }

#endif
