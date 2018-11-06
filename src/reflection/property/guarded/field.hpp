#ifndef reflection_property_guarded_field
#define reflection_property_guarded_field
// ::reflection::property::guarded::field_struct<model_name,class_name,carrier_name,report_name>

 #include "./base.hpp"

#include "../mutate/field.hpp"
#include "../inspect/field.hpp"

 namespace reflection
  {
   namespace property
    {
     namespace guarded
      {

       template
         <
          typename     data_name
         ,typename model_name
         ,typename image_name
         ,typename class_name
         ,typename storage_name
         ,typename report_name
         >
        struct  field_struct
         {
          typedef data_name           data_type;
          typedef model_name    model_type;
          typedef image_name    image_type;
          typedef class_name    class_type;
          typedef storage_name  storage_type;
          typedef report_name   report_type;

          typedef ::reflection::property::inspect::field_struct<data_name,image_name,class_name,storage_type> inspect_type;
          typedef ::reflection::property::mutate::field_struct<data_name,model_type,class_type,storage_type,report_type> mutate_type;

          typedef typename  mutate_type::assigner_type   assigner_type;
          typedef typename inspect_type::retriever_type retriever_type;

          typedef ::reflection::property::guarded::base_class <model_name, image_name, storage_name, assigner_type, retriever_type, report_name>      typedef_type;

          typedef typename  mutate_type::pointer_type   pointer_type;

          static typedef_type make( storage_type const& carrier_param, pointer_type const& pointer_param )
           {
            return typedef_type( carrier_param, assigner_type( pointer_param ), retriever_type( pointer_param ) );
           }
         };

       template
        <
          typename     data_name
         ,typename model_name = data_name const&
         ,typename image_name = data_name const&
         ,typename class_name
         ,typename storage_name
         ,typename report_name
        >
        inline
        typename ::reflection::property::guarded::field_struct<data_name,model_name,image_name,class_name,storage_name,report_name>::typedef_type
        field
         (
            storage_name const& carrier_param
           ,data_name      class_name::*pointer_param
         )
         {
          typedef ::reflection::property::guarded::field_struct<data_name,model_name,image_name,class_name,storage_name,report_name> field_type;
          return field_type::make( carrier_param, pointer_param );
         }

     }
   }
 }

#endif
