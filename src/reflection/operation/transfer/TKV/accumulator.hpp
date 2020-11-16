#ifndef reflection_operation_transfer_tkv_accumulator
#define reflection_operation_transfer_tkv_accumulator

// ::reflection::operation::transfer::tkv::accumulator_class<input_name,identifier_name,report_name>

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
      namespace tkv
       {

        template
         <
           typename       input_name
          ,typename  identifier_name = std::string
          ,typename         key_name = std::string
          ,typename      report_name = bool
         >
        using accumulator_class = ::reflection::operation::scan::accumulator::simple_class< input_name, identifier_name, key_name, ::reflection::type::container::map, report_name >;

       }
     }
   }
 }

#endif
