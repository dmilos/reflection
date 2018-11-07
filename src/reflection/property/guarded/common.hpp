#ifndef reflection_property_guarded_common
#define reflection_property_guarded_common
// ::reflection::property::guarded::common_struct<model_name,class_name,carrier_name,report_name>

 #include "./base.hpp"

#include "../mutate/common.hpp"
#include "../inspect/common.hpp"

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
         ,typename report_name
         >
        struct  common_struct
         {
          typedef data_name           data_type;
          typedef model_name    model_type;
          typedef image_name    image_type;
          typedef class_name    class_type;
          typedef report_name   report_type;

          typedef ::reflection::property::inspect::common_struct<data_name,image_name,class_name> inspect_type;
          typedef ::reflection::property::mutate::common_struct<data_name,model_type,class_type,report_type> mutate_type;

          typedef typename  mutate_type::storage_type   storage_type;

          typedef typename  mutate_type::assigner_type   assigner_type;
          typedef typename inspect_type::retriever_type retriever_type;

          typedef ::reflection::property::guarded::base_class <model_name, image_name, storage_type, assigner_type, retriever_type, report_name>      typedef_type;

          static typedef_type make( storage_type const& carrier_param )
           {
            return typedef_type( carrier_param, assigner_type(  ), retriever_type(  ) );
           }
         };

       template
        <
          typename class_name
         ,typename     data_name
         ,typename model_name = data_name const&
         ,typename image_name = data_name const&
         ,typename report_name
        >
        inline
        typename ::reflection::property::guarded::common_struct<data_name,model_name,image_name,class_name,report_name>::typedef_type
        common
         (
           data_name      *carrier_param
         )
         {
          typedef ::reflection::property::guarded::common_struct<data_name,model_name,image_name,class_name,report_name> common_type;
          return common_type::make( carrier_param );
         }

     }
   }
 }

#endif
