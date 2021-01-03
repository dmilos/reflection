#ifndef reflection_operation_transfer_tlv_sentinel
#define reflection_operation_transfer_tlv_sentinel

// ::reflection::operation::transfer::tlv::recover_class<input_name,identifier_name,report_name>

#include "../../scan/sentinel.hpp"
#include "./pile.hpp"
#include "./probe.hpp"

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
           typename   identifier_name
          ,typename   key_name    = std::string
          ,typename   report_name = bool
         >
          class sentinel_class
          : public ::reflection::operation::scan::sentinel_class
             <
               ::reflection::operation::transfer::tlv::pile_type<key_name>
              ,std::istream
              ,identifier_name
              ,report_name
             >
          {
           public:
             typedef        ::reflection::operation::transfer::tlv::pile_type<key_name>        pile_type;
             typedef  std::istream    input_type;
             typedef  report_name    report_type;

             typedef ::reflection::operation::scan::probe_class< input_type, identifier_name, report_name > probe_type;
             typedef ::reflection::operation::transfer::tlv::probe_class<identifier_name,report_name> probe_tlv_type;

           public:
             sentinel_class()
              {
              }

             ~sentinel_class()
              {
              }

           public:
             virtual report_type prepare( pile_type& pile_param, input_type & input_param, probe_type & probe ) const
              {
               //if( false == dynamic_cast< probe_tlv_type& >(probe).get_chunk( input_param ) ) 
               // {
               //  return false;
               // }

               return true; 
              }
             virtual report_type clean(   pile_type& pile_param, input_type & input_param ) const{ return true; }
             virtual report_type finish(  pile_type& pile_param, input_type & input_param ) const{ return true; }
          };

       }
     }
   }
 }

#endif
