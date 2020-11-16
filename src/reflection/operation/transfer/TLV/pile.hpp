#ifndef reflection_operation_transfer_tlv_pile
#define reflection_operation_transfer_tlv_pile

// ::reflection::operation::transfer::tlv::pile_type<key_name,container_name>

#include "../../../property/structure.hpp"

namespace reflection
 {
  namespace operation
   {
    namespace transfer
     {
      namespace tlv
       {

        template
         <
           typename         key_name = std::string
          ,template <typename,typename> class container_name  = ::reflection::type::container::map
         >
        using pile_type = ::reflection::property::structure_class<key_name,container_name>;

       }
     }
   }
 }

#endif
