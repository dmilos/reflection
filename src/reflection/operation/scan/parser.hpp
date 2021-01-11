#ifndef reflection_operation_scan_parser
#define reflection_operation_scan_parser

// ::reflection::operation::scan::parser_class< pile_name, input_name, identifier_name, report_name>

#include "./accumulator.hpp"
#include "./sentinel.hpp"
#include "../factory/facility.hpp"

namespace reflection
 {
  namespace operation
   {
    namespace scan
     {

        template
         <
           typename    pile_name
          ,typename    input_name
          ,typename    identifier_name
          ,typename    report_name = bool
         >
         struct parser_class
          {
           public:
             typedef  pile_name           pile_type;
             typedef  input_name          input_type;
             typedef  identifier_name     identifier_type;
             typedef  report_name         report_type;

             typedef ::reflection::property::pure_class     property_type;
             typedef ::std::shared_ptr<property_type>       property_pointer_type;

             typedef ::reflection::operation::scan::probe_class< input_name, identifier_name, report_name > probe_type;
             typedef std::shared_ptr<probe_type> probe_pointer_type;

             typedef ::reflection::operation::factory::facility_class<identifier_name,report_name>  facility_type;

             typedef ::reflection::operation::scan::sentinel_class< pile_name, input_name, identifier_name, report_name  > sentinel_type;
             typedef ::std::shared_ptr<sentinel_type>       sentinel_pointer_type;

             typedef ::reflection::operation::scan::accumulator::pure_class< pile_name, input_name, identifier_name, report_name > accumulator_type;
             typedef ::std::shared_ptr<accumulator_type>       accumulator_pointer_type;

           public:
             report_type parse( pile_type &pile_param, input_name &input_param ) const
              {
               identifier_type  identifier;
               auto & probe       = *(m_probe.get() );
               auto & sentinel    = *(m_sentinel.get() );
               auto & accumulator = *(m_accumulator.get() );

               if( false == sentinel.prepare( pile_param, input_param, probe ) )
                {
                 return false;
                }

               while( false == probe.eof( input_param ) )
                {
                 if( false == probe.poke( identifier, input_param ) )
                  {
                   if( false == probe.skip( input_param ) )
                    {
                     sentinel.clean( pile_param, input_param );
                     return false;
                    }
                   continue;
                  }

                 auto proprty = m_facility.template create<input_name&>( identifier, input_param );
                 if( nullptr == proprty )
                  {
                   if( false == probe.skip( input_param ) )
                    {
                     sentinel.clean( pile_param, input_param );
                     return false;
                    }
                   continue;
                  }

                 if( false == accumulator.attach( pile_param, proprty, probe ) )
                  {
                   break;
                  }
                }

               return sentinel.finish( pile_param, input_param );
              }

           public:
             sentinel_pointer_type const& sentinel( )const
              {
               return m_sentinel;
              }
             sentinel_pointer_type & sentinel( )
              {
               return m_sentinel;
              }
             void sentinel( sentinel_pointer_type const& sentinel_param )
              {
               m_sentinel = sentinel_param;
              }
           private:
             sentinel_pointer_type m_sentinel;

           public:
             probe_pointer_type const& probe( )const
              {
               return m_probe;
              }
             probe_pointer_type & probe( )
              {
               return m_probe;
              }
             void probe( probe_pointer_type const& probe_param )
              {
               m_probe = probe_param;
              }
           private:
             probe_pointer_type m_probe;

           public:
             facility_type const& facility( )const
              {
               return m_facility;
              }
             facility_type & facility( )
              {
               return m_facility;
              }
             void facility( facility_type const& facility_param )
              {
               m_facility = facility_param;
              }

           private:
             facility_type        m_facility;

           public:
             accumulator_pointer_type const& accumulator( )const
              {
               return m_accumulator;
              }
             accumulator_pointer_type & accumulator( )
              {
               return m_accumulator;
              }
             void accumulator( accumulator_pointer_type const& accumulator_param )
              {
               m_accumulator = accumulator_param;
              }
           private:
             accumulator_pointer_type m_accumulator;

          };

     }
   }
 }

#endif
