#ifndef reflection_property_reset_member
 #define reflection_property_reset_member
// TODO

 #include "./base.hpp"

namespace reflection
 {
  namespace property
   {
    namespace reset
     {

      template
       <
         typename report_name
        ,typename class_name
        ,typename carrier_name
       >
       struct member_class
        {
         typedef report_name   report_type;
         typedef class_name    class_type;
         typedef carrier_name  carrier_type;

         typedef report_type     (class_name::*executor_type)();

         typedef class agent_class
          {
           public:
             explicit agent_class( executor_type const& executor_param = NULL )
              :m_executor( executor_param )
              {
              }
             report_type operator()( carrier_type & carrier_param )const
              {
               if( NULL == m_executor ) 
                {
                 throw (void*)NULL;
                }   
               return  ((*carrier_param).* m_executor)( );
              }

           private:
             executor_type  m_executor;
          } agent_type;

         typedef ::reflection::property::reset::base_class< report_name, carrier_name, agent_type>      typedef_type;

         static typedef_type make(  carrier_type const& carrier_param, executor_type const& executor_param )
          {
           return typedef_type( carrier_param, agent_type( executor_param ) );
          }

        };

      template
       <
         typename report_name
        ,typename class_name
        ,typename carrier_name
       >
       inline
       typename ::reflection::property::reset::member_class<report_name,class_name,carrier_name>::typedef_type
       member
        (
          carrier_name         const& carrier_param
         ,report_name (class_name::*executor_param )( void )
        )
        {
         typedef ::reflection::property::reset::member_class<report_name,class_name,carrier_name> member_type;
         return member_type::make( carrier_param, executor_param );
        }

     }
   }
 }

#endif
