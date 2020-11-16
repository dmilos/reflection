#ifndef reflection_operation_transfer_json_accumulator
#define reflection_operation_transfer_json_accumulator

// ::reflection::operation::transfer::json::accumulator_class<input_name,identifier_name,report_name>

#include "../../equalizer.hpp"
#include "../../scan/accumulator.hpp"
#include "./pile.hpp"
#include "./probe.hpp"

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
          ,typename      report_name
         >
        using accumulator_class = ::reflection::operation::scan::accumulator::simple_class< input_name, identifier_name, key_name, ::reflection::type::container::map, report_name >;

       }
     }
   }
 }

#endif
