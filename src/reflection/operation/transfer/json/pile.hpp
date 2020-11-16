#ifndef reflection_operation_transfer_json_pile
#define reflection_operation_transfer_json_pile

// ::reflection::operation::transfer::json::pile_type<key_name,container_name>

#include "../../../property/structure.hpp"

namespace reflection
 {
  namespace operation
   {
    namespace transfer
     {
      namespace json
       {

        template
         <
           typename         key_name
          ,template <typename,typename> class container_name  = ::reflection::type::container::map
         >
        using pile_type = ::reflection::property::structure_class<key_name,container_name>;

       }
     }
   }
 }

#endif
