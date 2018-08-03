#ifndef reflection_property_exposed_type_member
#define reflection_property_exposed_type_member
// ::reflection::property::exposed::member_struct<model_name,class_name,carrier_name,report_name>

 #include "./base.hpp"

#include "../direct/member.hpp"
#include "../mutate/member.hpp"

 namespace reflection
  {
   namespace property
    {
     namespace exposed
      {

       template
         <
          typename original_name
         ,typename model_name
         ,typename class_name
         ,typename storage_name
         ,typename report_name
         >
        struct  member_struct
         {
          typedef original_name    original_type;
          typedef model_name    model_type;
          typedef class_name    class_type;
          typedef storage_name  storage_type;
            typedef report_name     report_type;

          typedef ::reflection::property::direct::member_struct<original_type,class_type,storage_type>          direct_type;
          typedef ::reflection::property::mutate::member_struct<model_type,class_type,storage_type,report_type> mutate_type;

          typedef typename  direct_type::extractor_class   extractor_type;
          typedef typename mutate_type::assigner_class   assigner_type;

          typedef ::reflection::property::exposed::base_class <original_name, model_name, storage_name, extractor_type, assigner_type, report_name>      typedef_type;

          typedef typename  direct_type::traitor_type   traitor_type;
          typedef typename mutate_type::writter_type     writter_type;

          static typedef_type make( storage_type const& carrier_param, traitor_type const& traitor_param, writter_type const& writter_param )
           {
            return typedef_type( carrier_param, extractor_type( traitor_param ), assigner_type( writter_param ) );
           }
         };

       template
        <
         typename original_name
        ,typename    model_name
        ,typename    class_name
        ,typename  storage_name
        ,typename   report_name
        >
       inline
       typename ::reflection::property::exposed::member_struct<original_name,model_name,class_name,storage_name,report_name>::typedef_type
       member
        (
          storage_name const& carrier_param
         ,original_name    (class_name::*traitor_param )(  )
         ,report_name      (class_name::*writter_param)( model_name )
        )
        {
         typedef ::reflection::property::exposed::member_struct<original_name,model_name,class_name,storage_name,report_name> member_type;
         return member_type::make( carrier_param, traitor_param, writter_param );
        }

     }
   }
 }

#endif
