#ifndef reflection_content_inspect_member_hpp
#define reflection_content_inspect_member_hpp

 // ::reflection::content::inspect::member_class<identifier_name,data_name, original_name,class_name,storage_name>
 // ::reflection::content::inspect::member( )

#include "../../property/inspect/member.hpp"

#include "../distinctive.hpp"

#include "./basic.hpp"

namespace reflection
 {
  namespace content
   {
    namespace inspect
     {

      template
       <
        typename identifier_name
       ,typename data_name
       ,typename image_name
       ,typename class_name
       ,typename storage_name
       >
       struct member_class
        : public ::reflection::content::distinctive_class<identifier_name,data_name>
        , public ::reflection::property::inspect::member_class<image_name, class_name, storage_name >
        {
          typedef identifier_name  identifier_type;
          typedef data_name        data_type;
          typedef image_name    image_type;
          typedef class_name       class_type;
          typedef storage_name     storage_type;

         typedef ::reflection::content::distinctive_class<identifier_name,data_name>                     distinctive_type;
         typedef ::reflection::property::inspect::member_class<image_name, class_name, storage_name >   member_type;

         using member_type::member_type;
        };

      template
       <
         typename identifier_name
        ,typename data_name
        ,typename image_name
        ,typename class_name
        ,typename storage_name
       >
       inline
       typename ::reflection::content::inspect::member_class<identifier_name,data_name,image_name,class_name,storage_name>::typedef_type
       member
        (
          storage_name const&             storage_param
         ,image_name       ( class_name::*reader_param )()const
        )
        {
         typedef ::reflection::content::inspect::member_class<identifier_name,data_name,image_name,class_name,storage_name> member_type;
         return member_type::make( storage_param, reader_param );
        }

      template
       <
         typename identifier_name
        ,typename data_name
        ,typename class_name
        ,typename storage_name
       >
       inline
       typename ::reflection::content::inspect::member_class<identifier_name,data_name,data_name const&,class_name,storage_name>
       member
        (
          storage_name const&                  storage_param
         ,data_name const&       ( class_name::*reader_param )( )const
        )
        {
         typedef ::reflection::content::inspect::member_class<identifier_name,data_name,data_name const&,class_name,storage_name> member_type;
         return member_type( storage_param, reader_param );
        }

      }
    }
  }

#endif
