#ifndef reflection_archive_brawl_class
#define reflection_archive_brawl_class

// ::reflection::archive::brawl_class<identifier_name, key_name, container_name>

#include "../content/class.hpp"

namespace reflection
 {
  namespace  archive
   {

    template
     <
       typename identifier_name   = std::string
      ,typename key_name = std::string
      ,template < typename, typename > class container_name = ::reflection::type::container::map
     >
      using brawl_class = ::reflection::content::composition_class< identifier_name, key_name, container_name >;
   }
 }

#endif
