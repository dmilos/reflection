#ifndef reflection_property_direct_member
#define reflection_property_direct_member

// ::reflection::property::direct::member_class<original_name,class_name,storage_name>

 #include "./base.hpp"

namespace reflection
 {
  namespace property
   {
    namespace direct
     {

      template
       <
         typename original_name
        ,typename class_name
        ,typename storage_name
       >
       struct member_class
        {
         typedef original_name original_type;
         typedef class_name    class_type;
         typedef storage_name  storage_type;

         typedef original_type     (class_name::*traitor_type)();

         typedef class extractor_class
          {
           public:
             explicit extractor_class( traitor_type const& traitor_param = NULL )
              :m_traitor( traitor_param )
              {
              }
             original_type operator()( storage_type & carrier_param )const
              {
               if( NULL == m_traitor )
                {
                 throw (void*)NULL;
                }
               return  ((*carrier_param).* m_traitor)( );
              }

           private:
             traitor_type  m_traitor;
          } extractor_type;

         typedef ::reflection::property::direct::base_class< original_name, storage_name, extractor_type>      typedef_type;

         static typedef_type make(  storage_type const& carrier_param, traitor_type const& traitor_param )
          {
           return typedef_type( carrier_param, extractor_type( traitor_param ) );
          }

        };

      template
       <
         typename original_name
        ,typename class_name
        ,typename storage_name
       >
       inline
       typename ::reflection::property::direct::member_class<original_name,class_name,storage_name>::typedef_type
       member
        (
          storage_name         const& carrier_param
         ,original_name (class_name::*traitor_param )( void )
        )
        {
         typedef ::reflection::property::direct::member_class<original_name,class_name,storage_name> member_type;
         return member_type::make( carrier_param, traitor_param );
        }

     }
   }
 }

#endif
