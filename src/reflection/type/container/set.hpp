#ifndef reflection_type_container_set
#define reflection_type_container_set
// ::reflection::type::container::set

namespace reflection
 {
  namespace type
   {
    namespace container
     {

      template< typename key_name, typename data_name >
        using set = std::set< data_name >;

     }
   }
 }

#endif
