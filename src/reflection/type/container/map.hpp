#ifndef reflection_type_container_map
#define reflection_type_container_map
// ::reflection::type::container::map

namespace reflection
 {
  namespace type
   {
    namespace container
     {

      template< typename key_name, typename data_name >
        using map = std::map< key_name, data_name> ;

     }
   }
 }

#endif
