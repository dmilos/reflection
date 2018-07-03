#ifndef reflection_type_container_vector
#define reflection_type_container_vector
// ::reflection::type::container::vector

namespace reflection
 {
  namespace type
   {
    namespace container
     {

      template< typename key_name, typename data_name >
        using vector = std::vector< data_name >;

     }
   }
 }

#endif
