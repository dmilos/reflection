#ifndef reflection_property_reset_base
#define reflection_property_reset_base

#include "./_pure.hpp"
#include "../_carrier.hpp"

namespace reflection
 {
  namespace property
   {
    namespace reset
     {

      template
       <
         typename report_name
        ,typename storage_name    //= type_name
        ,typename agent_name  //= stl_ext::identity_cast<  type_name const&, storage_name const& >
       >
       class base_class
        : virtual public ::reflection::property::reset::pure_class< report_name >
        , virtual public ::reflection::property::_internal::carrier_class<storage_name>
        {
         public:
           typedef report_name   report_type;
           typedef storage_name    storage_type;
           typedef agent_name  agent_type;

           typedef ::reflection::property::_internal::carrier_class<storage_name> carrier_type;

                     base_class(){ }

            explicit base_class( agent_type const& agent_param )
              : m_agent( agent_param )
              {
              }

            explicit base_class( storage_type   const& carrier_param, agent_type const& agent_param = agent_type() )
              : carrier_type( carrier_param ), m_agent( agent_param )
              {
              }

         public:
           report_type process( void )
            {
             return this->F1_agent()( this->carrier_type::storage() );
            }

         public:
           agent_type const&   agent()const{ return m_agent; }
           void                 agent( agent_type const& agent_param ){ m_agent = agent_param; }
         //agent_type       &   agent(){ return m_agent; }
         protected:
           agent_type      &   F1_agent(){ return m_agent; }
         private:
           agent_type          m_agent;
        };

      }
    }
  }

#endif
