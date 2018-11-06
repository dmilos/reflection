#ifndef reflection_content_composition
#define reflection_content_composition

// ::reflection::content::composition_class<identifier_name,key_name,container_name>

#include "../content/content.hpp"
#include "../property/structure.hpp"

namespace reflection
 {
  namespace content
   {

    template
     <
       typename identifier_name   = std::string
      ,typename key_name          = std::string
      ,template < typename, typename > class container_name = ::reflection::type::container::map
     >
     class composition_class
      : virtual public ::reflection::content::pure_class<identifier_name>
      , /*virtual */public ::reflection::property::structure_class<key_name, container_name >
      {
       public:
         typedef identifier_name   identifier_type;
         typedef key_name                 key_type;

         typedef ::reflection::type::name::identificatorX< identifier_name  > identificator_type;

         typedef ::reflection::content::pure_class<identifier_name>                   content_type;
         typedef ::reflection::property::structure_class<key_name, container_name >  structure_type;

         explicit composition_class( identifier_name const& id )
          :content_type( id )
          {
          }

        ~composition_class(){}
      };

   }
 }

#endif
