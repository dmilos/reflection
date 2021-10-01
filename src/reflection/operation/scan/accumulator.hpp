#ifndef reflection_operation_scan_accumulator_pure
#define reflection_operation_scan_accumulator_pure

// ::reflection::operation::scan::accumulator::pure_class< pile_name, input_name, identifier_name, report_name >
// ::reflection::operation::scan::accumulator::simple_class< input_name, identifier_name, key_name, container_name,report_name >

#include "../../property/property.hpp"

#include "./probe.hpp"

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
          ,typename  report_name     = bool
         >
         class pure_class
          {
           public:
             typedef  pile_name           pile_type;
             typedef  input_name          input_type;
             typedef  identifier_name     identifier_type;
             typedef  report_name         report_type;

             typedef ::reflection::operation::scan::probe::pure_class< input_name, identifier_name, report_name > probe_pure_type;

             typedef ::reflection::property::pure_class     property_type;
             typedef ::std::shared_ptr<property_type>       property_pointer_type;

          public:
             pure_class(){}
             virtual ~pure_class(){}

           public:
             virtual report_type attach( pile_type & pile_param, identifier_name const& identifier, property_pointer_type const& pointer, probe_pure_type const& probe_param ) const=0;
             virtual report_type attach( pile_type & pile_param, identifier_name const& identifier, input_type & input_param,             probe_pure_type const& probe_param ) const=0;
         };


        template
         <
           typename       input_name
          ,typename  identifier_name = std::string
          ,typename         key_name = std::string
          ,template <typename,typename> class container_name  = ::reflection::type::container::map
          ,typename      report_name = bool
         >
         class simple_class
          : public ::reflection::operation::scan::accumulator::pure_class< ::reflection::property::structure_class<key_name,container_name>, input_name, identifier_name, report_name >
          {
           public:
             typedef   ::reflection::property::structure_class<key_name,container_name>       pile_type;
             typedef       input_name       input_type;
             typedef       key_name           key_type;
             typedef  identifier_name  identifier_type;
             typedef      report_name      report_type;

             typedef ::reflection::operation::scan::accumulator::pure_class< pile_type, input_name, identifier_name, report_name >  pure_type;

             typedef ::reflection::type::name::identificatorX< identifier_name > identificator_type;

             typedef ::reflection::operation::scan::probe::pure_class< input_name, identifier_name, report_name > probe_pure_type;
             typedef ::reflection::operation::scan::probe::base_class< input_name, key_name, identifier_name, report_name > probe_base_type;

             typedef typename pure_type::property_pointer_type       property_pointer_type;

             typedef ::reflection::operation::transfer::equalizer_class<identifier_name,report_name> equalizer_type;

           public:
             simple_class()
              {
              }

             ~simple_class()
              {
              }

           public:
             virtual report_type attach( pile_type & pile_param, identifier_name const& identifier, property_pointer_type const& pointer, probe_pure_type const& probe_param ) const override
              {
               auto const& key = dynamic_cast<  probe_base_type const& >( probe_param ).key();
               auto iterator = pile_param.find( key );
               if( pile_param.end() == iterator )
                {
                 //if( true == m_dynamic )
                 // {
                 //  // TODO left = m_constructor.process( identifier );
                 //  // TODO pile_param.insert( key, left );
                 // }
                 return report_type( false );
                }
               auto      &  left = * pile_param.data( iterator ).get();
               auto const& right =*pointer;
               return m_equalizer.align( left, right );
              }

           public:
             virtual report_type attach( pile_type & pile_param, identifier_name const& identifier, input_type & input_param,             probe_pure_type const& probe_param ) const override
              {
               auto const& key = dynamic_cast<  probe_base_type const& >( probe_param ).key();
               auto iterator = pile_param.find( key );
               if( pile_param.end() == iterator )
                {
                 //if( true == m_dynamic )
                 // {
                 //  // TODO left = m_constructor.process( identifier );
                 //  // TODO pile_param.insert( key, left );
                 // }
                 return report_type( false );
                }
               auto      &  left = * pile_param.data( iterator ).get();
               // TODO return m_convertor.process( left, input_param );
               return false;
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
