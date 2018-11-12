#ifndef reflection_content_direct_member_hpp
#define reflection_content_direct_member_hpp

 // ::reflection::content::direct::member_class<identifier_name,data_name, original_name,class_name,storage_name>
 // ::reflection::content::direct::member( )

#include "../../property/direct/member.hpp"

#include "../distinctive.hpp"

#include "./basic.hpp"

namespace reflection
 {
  namespace content
   {
    namespace direct
     {

      template
       <
        typename identifier_name
       ,typename data_name
       ,typename original_name
       ,typename class_name
       ,typename storage_name
       >
       class member_class
        : public ::reflection::content::distinctive_class<identifier_name,data_name>
        , public ::reflection::property::direct::member_class<original_name, class_name, storage_name >
        {
         public:
           typedef identifier_name  identifier_type;
           typedef data_name        data_type;
           typedef original_name    original_type;
           typedef class_name       class_type;
           typedef storage_name     storage_type;

           typedef ::reflection::content::distinctive_class<identifier_name,data_name>                     distinctive_type;
           typedef ::reflection::property::direct::member_class<original_name, class_name, storage_name >   member_type;

           using member_type::member_type;
        };

      template
       <
         typename identifier_name
        ,typename data_name
        ,typename original_name
        ,typename class_name
        ,typename storage_name
       >
       inline
       typename ::reflection::content::direct::member_class<identifier_name,data_name,original_name,class_name,storage_name>
       member
        (
          storage_name const&             storage_param
         ,original_name       ( class_name::*traitor_param )( )//!< <data_name,original_name,class_name,storage_name>::T_traitor const& traitor_param
        )
        {
         typedef ::reflection::content::direct::member_class<identifier_name,data_name,original_name,class_name,storage_name> member_type;
         return member_type( storage_param, traitor_param );
        }

      template
       <
         typename identifier_name
        ,typename data_name
        ,typename class_name
        ,typename storage_name
       >
       inline
       typename ::reflection::content::direct::member_class<identifier_name,data_name,data_name&,class_name,storage_name>
       member
        (
          storage_name const&             storage_param
         ,data_name&       ( class_name::*traitor_param )( )
        )
        {
         typedef ::reflection::content::direct::member_class<identifier_name,data_name,data_name&,class_name,storage_name> member_type;
         return member_type( storage_param, traitor_param );
        }

      }
    }
  }

#endif
