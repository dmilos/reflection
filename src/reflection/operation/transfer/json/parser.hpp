#ifndef reflection_operation_transfer_json_parser
#define reflection_operation_transfer_json_parser

// ::reflection::operation::transfer::json::parser_type<input_name,identifier_name,report_name>

#include "./pile.hpp"
#include "../../scan/parser.hpp"

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
           typename       input_name
          ,typename  identifier_name
          ,typename         key_name
          ,template <typename,typename> class container_name  = ::reflection::type::container::map
          ,typename      report_name = bool
         >
         using parser_type = ::reflection::operation::scan::parser_class< ::reflection::operation::transfer::json::pile_type<key_name,container_name >, input_name, identifier_name, report_name>;

       }
     }
   }
 }

#endif
