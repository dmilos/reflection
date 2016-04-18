#ifndef reflection_content_direct_member_hpp
#define reflection_content_direct_member_hpp
 // ::reflection::content::direct::member_class<data_name, original_name,class_name,storage_name>
 // ::reflection::content::direct::member( )

#include "../../property/direct/member.hpp"

#include "./basic.hpp"

namespace reflection
 {
  namespace content
   {
    namespace direct
     {

      template
       <
        typename data_name
       ,typename original_name
       ,typename class_name
       ,typename storage_name
       >
       struct member_class
        : ::reflection::property::direct::member_class<original_name, class_name, storage_name >
        {
         typedef data_name     data_type;
         typedef original_name original_type;
         typedef class_name    class_type;
         typedef storage_name  storage_type;

         typedef ::reflection::property::direct::member_class<original_name, class_name, storage_name > property_type;

         typedef typename property_type::traitor_type    traitor_type;
         typedef typename property_type::extractor_type  extractor_type;

         typedef ::reflection::content::direct::basic_class<data_name,original_name,storage_name,extractor_type>      type_type;

         static type_type make( storage_type const& storage_param, traitor_type const& traitor_param )
          {
           return type_type( storage_param, extractor_type( traitor_param ) );
          }

       };

      template
       <
        typename data_name
       ,typename original_name
       ,typename class_name
       ,typename storage_name
       >
       inline
       typename ::reflection::content::direct::member_class<data_name,original_name,class_name,storage_name>::type_type
       member
        (
          storage_name const&             storage_param
         ,original_name       ( class_name::*traitor_param )( )//!< <data_name,original_name,class_name,storage_name>::T_traitor const& traitor_param
        )
        {
         typedef ::reflection::content::direct::member_class<data_name,original_name,class_name,storage_name> member_type;
         return typename member_type::type_type( storage_param, typename member_type::extractor_type( traitor_param ) );
        }


      template
       <
        typename data_name
       ,typename class_name
       ,typename storage_name
       >
       inline
       typename ::reflection::content::direct::member_class<data_name,data_name&,class_name,storage_name>::type_type
       member
        (
          storage_name const&             storage_param
         ,data_name&       ( class_name::*traitor_param )( )//!< <data_name,original_name,class_name,storage_name>::T_traitor const& traitor_param
        )
        {
         typedef ::reflection::content::direct::member_class<data_name,data_name&,class_name,storage_name> member_type;
         return typename member_type::type_type( storage_param, typename member_type::extractor_type( traitor_param ) );
        }


      }
    }
  }

#endif
