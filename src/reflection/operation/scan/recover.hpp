#ifndef reflection_operation_scan_recover_pure
#define reflection_operation_scan_recover_pure

// ::reflection::operation::scan::recover::pure_class< pile_name, input_name, identifier_name, report_name >

#include "../../property/property.hpp"


namespace reflection
 {
  namespace operation
   {
    namespace scan
     {

      template
       <
         typename  input_name
        ,typename  identifier_name = std::string
        ,typename  report_name = bool
       >
       class recover_class
        {
         public:
           typedef  input_name          input_type;
           typedef  identifier_name     identifier_type;
           typedef  report_name         report_type;

           typedef ::reflection::property::pure_class     property_type;

           typedef ::reflection::operation::scan::probe_class< input_name, identifier_name, report_name > probe_type;

            typedef typename probe_type::property_pointer_type       property_pointer_type;

        public:
           recover_class(){}
           virtual ~recover_class(){}

         public:
           virtual report_type skip( input_type & input, probe_type const& probe_param ) const=0;
       };

     }
   }
 }

#endif
