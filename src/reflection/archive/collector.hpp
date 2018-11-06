#ifndef reflection_archive_collector_class
#define reflection_archive_collector_class

// ::reflection::archive::collector_class<data_name, identifier_name, key_name, container_name>

#include "../content/class.hpp"

namespace reflection
 {
  namespace  archive
   {

    template
     <
       typename data_name
      ,typename identifier_name   = std::string
      ,typename key_name = std::string
      ,template < typename, typename > class container_name = ::reflection::type::container::map
     >
      using collector_class = ::reflection::content::class_class< data_name, identifier_name, key_name, container_name >;

   }
 }

#endif
