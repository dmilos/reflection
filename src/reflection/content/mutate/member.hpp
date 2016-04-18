#ifndef reflection_content_mutate_member_hpp
#define reflection_content_mutate_member_hpp
 // ::reflection::content::mutate::member_class<data_name, model_name,class_name,storage_name>
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
         typename data_name
        ,typename model_name
        ,typename class_name
        ,typename storage_name
        ,typename report_name
       >
       struct member_class
        : ::reflection::property::mutate::member_class<model_name, class_name, storage_name, report_name >
        {
         typedef data_name     data_type;
         typedef model_name    model_type;
         typedef class_name    class_type;
         typedef storage_name  storage_type;

         typedef ::reflection::property::mutate::member_class<model_name, class_name, storage_name, report_name > property_type;

         typedef typename property_type::writter_type       writter_type;
         typedef typename property_type::assigner_class  assigner_type;

         typedef ::reflection::content::mutate::basic_class<data_name,model_name,storage_name,assigner_type, report_name>      type_type;

         static type_type make( storage_type const& storage_param, writter_type const& writter_param )
          {
           return type_type( storage_param, assigner_type( writter_param ) );
          }

       };

      template
       <
        typename data_name
       ,typename model_name
       ,typename class_name
       ,typename storage_name
       ,typename report_name
       >
       inline
       typename ::reflection::content::mutate::member_class<data_name,model_name,class_name,storage_name,report_name>::type_type
       member
        (
          storage_name const&             storage_param
         ,report_name       (class_name::*writter_param)( model_name )
        )
        {
         typedef ::reflection::content::mutate::member_class<data_name,model_name,class_name,storage_name,report_name> member_type;
         return typename member_type::type_type( storage_param, typename member_type::assigner_type( writter_param ) );
        }


      template
       <
        typename data_name
       ,typename class_name
       ,typename storage_name
       ,typename report_name
       >
       inline
       typename ::reflection::content::mutate::member_class< data_name, data_name const&,class_name,storage_name,report_name>::type_type
       member
        (
          storage_name const&             storage_param
         ,report_name       (class_name::*writter_param)( data_name const& )
        )
        {
         typedef ::reflection::content::mutate::member_class<data_name,data_name const&,class_name,storage_name,report_name> member_type;
         return typename member_type::type_type( storage_param, typename member_type::assigner_type( writter_param ) );
        }


      }
    }
  }

#endif
