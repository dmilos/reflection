#ifndef reflection_property_trinity_common
#define reflection_property_trinity_common
// ::reflection::property::trinity::common_struct<model_name,class_name,carrier_name,report_name>

 #include "./base.hpp"

#include "../mutate/common.hpp"
#include "../inspect/common.hpp"

 namespace reflection
  {
   namespace property
    {
     namespace trinity
      {

       template
         <
          typename     data_name
         ,typename original_name
         ,typename model_name
         ,typename image_name
         ,typename class_name
         ,typename report_name
         >
        struct  common_struct
         {
          public:
          typedef data_name           data_type;
            typedef original_name original_type;
            typedef model_name       model_type;
            typedef image_name       image_type;
            typedef class_name       class_type;
            typedef report_name     report_type;

            typedef ::reflection::property::direct::common_struct<data_type,original_type,class_type>          direct_type;
            typedef ::reflection::property::inspect::common_struct<data_type,image_type,class_type>           inspect_type;
            typedef ::reflection::property::mutate::common_struct<data_type,model_type,class_type,report_type> mutate_type;

            typedef typename  direct_type::storage_type   storage_type;
            
            typedef typename  direct_type::extractor_class    extractor_type;
            typedef typename  mutate_type::assigner_class      assigner_type;
            typedef typename inspect_type::retriever_class    retriever_type;

            typedef ::reflection::property::trinity::base_class <original_type,model_name, image_name, storage_type, extractor_type, assigner_type, retriever_type, report_name>      typedef_type;


            static typedef_type make( storage_type const& carrier_param )
             {
              return typedef_type( carrier_param, extractor_type( ), assigner_type( ), retriever_type( ) );
             }
         };

       template
        <
          typename     class_name
         ,typename     data_name
         ,typename  original_name = data_name &
         ,typename     model_name = data_name const &
         ,typename     image_name = data_name const &
         ,typename    report_name = bool
        >
       inline
       typename ::reflection::property::trinity::common_struct<data_name,original_name,model_name,image_name,class_name,report_name>::typedef_type
       common
        (
          data_name      class_name::*carrier_param
        )
        {
         typedef ::reflection::property::trinity::common_struct<data_name,original_name,model_name,image_name,class_name,report_name> common_type;
         return common_type::make( carrier_param );
        }

     }
   }
 }

#endif
