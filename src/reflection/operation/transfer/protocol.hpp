#ifndef reflection_operation_transfer_protocol
#define reflection_operation_transfer_protocol

// ::reflection::operation::transfer::protocol<output_name,key_name,type_name>

#include "../content/category.hpp"
#include "./property/structure.hpp"

#include "../../type/container/vector.hpp"

namespace reflection
 {
  namespace operation
   {
    namespace transfer
     {

      template
       <
         typename output_name
        ,typename    key_name = std::string
        ,typename   type_name = std::string
        ,template  < typename > class qualificator_name = std::add_const
        ,template <typename,typename> class container_name  = ::reflection::type::container::map
       >
       struct protocol_struct
        {
         public:

           typedef output_name       output_type;
           typedef     key_name   key_type;
           typedef    type_name   type_type;
           typedef typename qualificator_name<container_name>::type  property_qualified_type;

           typedef typename ::reflection::operation::transfer::action_struct< output_type, key_type, qualificator_name >::typedef_type action_type;

           typedef container_name< type_type, action_type > container_type, typedef_type ;

       };

     }
   }
 }

#endif
