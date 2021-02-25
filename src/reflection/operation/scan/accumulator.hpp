#ifndef reflection_operation_scan_accumulator_pure
#define reflection_operation_scan_accumulator_pure

// ::reflection::operation::scan::accumulator::pure_class< pile_name, input_name, identifier_name, report_name >

#include "../../property/property.hpp"


namespace reflection
 {
  namespace operation
   {
    namespace scan
     {
     namespace accumulator
      {

         template
          <
            typename  pile_name
           ,typename  input_name
           ,typename  identifier_name = std::string
           ,typename  report_name = bool
          >
          class pure_class
           {
            public:
              typedef  pile_name           pile_type;
              typedef  input_name          input_type;
              typedef  identifier_name     identifier_type;
              typedef  report_name         report_type;

              typedef ::reflection::property::pure_class     property_type;

              typedef ::reflection::operation::scan::probe_class< input_name, identifier_name, report_name > probe_type;

               typedef typename probe_type::property_pointer_type       property_pointer_type;

           public:
              pure_class(){}
              virtual ~pure_class(){}

            public:
              virtual report_type attach( pile_type & pile_param, identifier_name const& identifier, property_pointer_type const& pointer, probe_type const& probe_param ) const=0;
              virtual report_type attach( pile_type & pile_param, identifier_name const& identifier, input_type & input_param,             probe_type const& probe_param ) const=0;
          };

       }
     }
   }
 }

#endif
