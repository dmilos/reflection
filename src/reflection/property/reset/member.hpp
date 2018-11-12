#ifndef reflection_property_reset_member
 #define reflection_property_reset_member

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
        ,typename storage_name
       >
       struct member_struct
        {
         typedef report_name   report_type;
         typedef class_name    class_type;
         typedef storage_name  storage_type;

         typedef report_type     (class_name::*executor_type)();

         typedef class agent_class
          {
           public:
             explicit agent_class( executor_type const& executor_param = nullptr )
              :m_executor( executor_param )
              {
              }

             report_type operator()( storage_type & carrier_param )const
              {
               if( nullptr == m_executor ) 
                {
                 throw (void*)nullptr;
                }   
               return  ((*carrier_param).* m_executor)( );
              }

           private:
             executor_type  m_executor;
          } agent_type;

         typedef ::reflection::property::reset::basic_class< report_name, storage_name, agent_type>      typedef_type;

         static typedef_type make(  storage_type const& carrier_param, executor_type const& executor_param )
          {
           return typedef_type( carrier_param, agent_type( executor_param ) );
          }

        };

      template
       <
         typename report_name
        ,typename class_name
        ,typename storage_name
       >
       inline
       typename ::reflection::property::reset::member_struct<report_name,class_name,storage_name>::typedef_type
       member
        (
          storage_name         const& carrier_param
         ,report_name (class_name::*executor_param )( void )
        )
        {
         typedef ::reflection::property::reset::member_struct<report_name,class_name,storage_name> member_type;
         return member_type::make( carrier_param, executor_param );
        }

     }
   }
 }

#endif
