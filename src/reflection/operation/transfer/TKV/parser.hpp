#ifndef reflection_operation_transfer_tkv_parser
#define reflection_operation_transfer_tkv_parser

// ::reflection::operation::transfer::tkv::parser_type<input_name,identifier_name,report_name>

#include "./pile.hpp"
#include "../../scan/parser.hpp"

namespace reflection
 {
  namespace operation
   {
    namespace transfer
     {
      namespace tkv
       {

        template
         <
           typename       input_name
          ,typename  identifier_name = std::string
          ,typename         key_name = std::string
          ,template <typename,typename> class container_name  = ::reflection::type::container::map
          ,typename      report_name = bool
         >
         using parser_type = ::reflection::operation::scan::parser_class< ::reflection::operation::transfer::tkv::pile_type<key_name,container_name >, input_name, identifier_name, report_name>;

       }
     }
   }
 }

#endif
