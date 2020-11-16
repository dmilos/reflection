#ifndef reflection_operation_transfer_tlv_recover
#define reflection_operation_transfer_tlv_recover

// ::reflection::operation::transfer::tlv::recover_class<input_name,identifier_name,report_name>

#include "../../scan/recover.hpp"

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
           typename  identifier_name = std::string
          ,typename      report_name = bool
         >
         class recover_class
          : public ::reflection::operation::scan::recover_class< std::istream, identifier_name, report_name >
          {
           public:
             typedef  std::istream             input_type;
             typedef  identifier_name     identifier_type;
             typedef  report_name             report_type;


             typedef ::reflection::type::name::identificatorX< identifier_type > identificator_type;
             typedef ::reflection::operation::scan::probe_class< input_type, identifier_name, report_name > probe_type;

           public:
             recover_class()
              {
              }

             ~recover_class()
              {

              }

           public:
            virtual report_type skip( input_type & input, probe_type const& probe_param ) const
             {
              // read type
              // read size
              // read key
              return true;
             }

          };

       }
     }
   }
 }

#endif
