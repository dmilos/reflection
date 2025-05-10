#ifndef reflection_property_valid_member
 #define reflection_property_valid_member

#include "./base.hpp"

namespace reflection
 {
  namespace property
   {
    namespace valid
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

         typedef report_type     (class_name::*tester_type)();

         typedef class agent_class
          {
           public:
             explicit agent_class( tester_type const& tester_param = nullptr )
              :m_tester( tester_param )
              {
              }

             report_type operator()( storage_type & carrier_param )const
              {
               if( nullptr == m_tester ) 
                {
                 throw (void*)nullptr;
                }   
               return  ((*carrier_param).*m_tester)( );
              }

           private:
             tester_type  m_tester;
          } agent_type;

         typedef ::reflection::property::valid::basic_class< report_name, storage_name, agent_type>      typedef_type;

         static typedef_type make(  storage_type const& carrier_param, tester_type const& tester_param )
          {
           return typedef_type( carrier_param, agent_type( tester_param ) );
          }

        };

      template
       <
         typename report_name
        ,typename class_name
        ,typename storage_name
       >
       inline
       typename ::reflection::property::valid::member_struct<report_name,class_name,storage_name>::typedef_type
       member
        (
          storage_name         const& carrier_param
         ,report_name (class_name::*tester_param )( void )
        )
        {
         typedef ::reflection::property::valid::member_struct<report_name,class_name,storage_name> member_type;
         return member_type::make( carrier_param, tester_param );
        }

     }
   }
 }

#endif
