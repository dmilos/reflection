#ifndef reflection_operation_transfer_tlv_accumulator
#define reflection_operation_transfer_tlv_accumulator

// ::reflection::operation::transfer::tlv::accumulator_class<input_name,identifier_name,report_name>

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
      namespace tlv
       {

        template
         <
           typename       input_name
          ,typename  identifier_name = std::string
          ,typename      report_name = bool
         >
         class accumulator_class
          : public ::reflection::operation::scan::accumulator::pure_class< ::reflection::operation::transfer::tlv::pile_type<>, input_name, identifier_name, report_name >
          {
           public:
             typedef        ::reflection::operation::transfer::tlv::pile_type<>        pile_type;
             typedef       input_name       input_type;
             typedef  identifier_name  identifier_type;
             typedef      report_name      report_type;

             typedef ::reflection::type::name::identificatorX< identifier_name > identificator_type;
             typedef ::reflection::operation::scan::probe_class< input_name, identifier_name, report_name > probe_type;
             typedef ::reflection::operation::transfer::tlv::probe_class<identifier_name,report_name> probe_tlv_type;

              typedef ::reflection::property::pure_class     property_type;

              typedef typename probe_type::property_pointer_type       property_pointer_type;

              typedef ::reflection::operation::transfer::equalizer_class<identifier_name,report_name> equalizer_type;


           public:
             accumulator_class()
              {
              }

             ~accumulator_class()
              {
              }

           public:
             virtual report_type attach( pile_type & pile_param, property_pointer_type const& pointer, probe_type const& probe_param ) const
             {
              auto const& key = dynamic_cast<  probe_tlv_type const& >( probe_param ).cache().m_key;
              auto iterator = pile_param.find( key );
              if( pile_param.end() == iterator )
               {
                // TODO ?? insert
                return report_type( false );
               }
              auto & left = * pile_param.data( iterator ).get(); 
              auto const& right =*pointer; 
              return m_equalizer.align( left, right );
             }

           public:
             equalizer_type const& equalizer()const{ return m_equalizer; }
             equalizer_type      & equalizer()     { return m_equalizer; }
           private:
             equalizer_type m_equalizer;

          };

       }
     }
   }
 }

#endif
