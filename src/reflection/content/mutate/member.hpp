#ifndef reflection_content_mutate_member_hpp
#define reflection_content_mutate_member_hpp
 // ::reflection::content::mutate::member_struct<data_name, model_name,class_name,storage_name>
 // ::reflection::content::mutate::member( )

#include "../../property/mutate/member.hpp"

#include "./basic.hpp"

namespace reflection
 {
  namespace content
   {
    namespace mutate
     {

      template
       <
         typename identifier_name
        ,typename data_name
        ,typename model_name
        ,typename class_name
        ,typename storage_name
        ,typename report_name
       >
       class member_class
        : public ::reflection::content::distinctive_class<identifier_name,data_name>
        , public ::reflection::property::mutate::member_class< model_name, class_name, storage_name, report_name >
        {
          typedef identifier_name  identifier_type;
          typedef data_name        data_type;
          typedef model_name    model_type;
          typedef class_name       class_type;
          typedef storage_name     storage_type;

         typedef ::reflection::content::distinctive_class<identifier_name,data_name>                     distinctive_type;
         typedef ::reflection::property::mutate::member_class< model_name, class_name, storage_name, report_name >   member_type;

         using member_type::member_type;
        };


      template
       <
         typename identifier_name
        ,typename data_name
        ,typename model_name
        ,typename class_name
        ,typename storage_name
        ,typename report_name
       >
       inline
       typename ::reflection::content::mutate::member_class<identifier_name,data_name,model_name,class_name,storage_name,report_name>
       member
        (
          storage_name const&             storage_param
         ,report_name       (class_name::*writer_param)( model_name )
        )
        {
         typedef ::reflection::content::mutate::member_class<identifier_name,data_name,model_name,class_name,storage_name,report_name> member_type;
         return member_type( storage_param, writer_param );
        }

      template
       <
         typename identifier_name
        ,typename data_name
        ,typename class_name
        ,typename storage_name
        ,typename report_name
       >
       inline
       typename ::reflection::content::mutate::member_class<identifier_name, data_name, data_name const&,class_name,storage_name,report_name>
       member
        (
          storage_name const&             storage_param
         ,report_name       (class_name::*writer_param)( data_name const& )
        )
        {
         typedef ::reflection::content::mutate::member_class<identifier_name,data_name,data_name const&,class_name,storage_name,report_name> member_type;
         return member_type( storage_param, writer_param );
        }

      }
    }
  }

#endif
