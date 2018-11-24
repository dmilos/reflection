#ifndef reflection_property_trinity_field
#define reflection_property_trinity_field
// ::reflection::property::trinity::field_struct<model_name,class_name,carrier_name,report_name>

 #include "./basic.hpp"

#include "../mutate/field.hpp"
#include "../inspect/field.hpp"

 namespace reflection
  {
   namespace property
    {
     namespace trinity
      {

       namespace _internal
        {
         template
           <
            typename     data_name
           ,typename original_name
           ,typename    model_name
           ,typename    image_name
           ,typename    class_name
           ,typename  storage_name
           ,typename   report_name
           >
          struct  field_struct
           {
            public:
            typedef data_name           data_type;
              typedef original_name original_type;
              typedef model_name       model_type;
              typedef image_name       image_type;
              typedef class_name       class_type;
              typedef storage_name   storage_type;
              typedef report_name     report_type;

              typedef ::reflection::property::direct::_internal::field_struct<data_type,original_type,class_type,storage_type>          direct_type;
              typedef ::reflection::property::inspect::_internal::field_struct<data_type,image_type,class_type,storage_type>           inspect_type;
              typedef ::reflection::property::mutate::_internal::field_struct<data_type,model_type,class_type,storage_type,report_type> mutate_type;

              typedef typename  direct_type::extractor_class    extractor_type;
              typedef typename  mutate_type::assigner_class      assigner_type;
              typedef typename inspect_type::retriever_class    retriever_type;

              typedef ::reflection::property::trinity::basic_class <original_type,model_name, image_name, storage_name, extractor_type, assigner_type, retriever_type, report_name>      typedef_type;

              typedef typename  direct_type::pointer_type   pointer_type;

              static typedef_type make( storage_type const& carrier_param, pointer_type const& pointer_param )
               {
                return typedef_type( carrier_param, extractor_type( pointer_param ), assigner_type( pointer_param ), retriever_type( pointer_param ) );
               }
           };
        }

      template
       <
         typename     data_name
        ,typename original_name
        ,typename    model_name
        ,typename    image_name
        ,typename    class_name
        ,typename  storage_name
        ,typename   report_name
       >
       class  field_class
        : public ::reflection::property::trinity::_internal::field_struct<data_name,original_name,model_name,image_name,class_name,storage_name,report_name>::typedef_type
        , public ::reflection::ornament::relation_class
        , public ::reflection::ornament::accessibility_class
        , public ::reflection::ornament::linkage_class
        , public ::reflection::ornament::qualification_class
        {
         public:
          typedef ::reflection::ornament::relation_class relation_type;
          typedef ::reflection::ornament::accessibility_class accessibility_type;

          typedef typename ::reflection::property::trinity::_internal::field_struct<data_name,original_name,model_name,image_name,class_name,storage_name,report_name>  basic_type;
          typedef typename basic_type::typedef_type  base_type;

          typedef typename basic_type::extractor_type     extractor_type;
          typedef typename basic_type::assigner_type       assigner_type;
          typedef typename basic_type::retriever_type     retriever_type;

          typedef typename basic_type::pointer_type     pointer_type;
          typedef typename basic_type::storage_type     storage_type;

          explicit field_class( storage_type   const& storage_param, pointer_type const& pointer_param )
            : relation_type( relation_type::member_index )
            , accessibility_type( accessibility_type::default_index )
            , base_type( storage_param, extractor_type( pointer_param ), assigner_type(pointer_param), retriever_type( pointer_param ) )
            {
            }

          using  base_type::disclose;
          using  base_type::process;
          using  base_type::present; 
        };


       template
        <
          typename     data_name
         ,typename  original_name = data_name &
         ,typename     model_name = data_name const &
         ,typename     image_name = data_name const &
         ,typename     class_name
         ,typename   storage_name
         ,typename    report_name = bool
        >
       inline
       typename ::reflection::property::trinity::field_class<data_name,original_name,model_name,image_name,class_name,storage_name,report_name>::typedef_type
       field
        (
           storage_name const& carrier_param
          ,data_name      class_name::*pointer_param
        )
        {
         typedef ::reflection::property::trinity::field_class<data_name,original_name,model_name,image_name,class_name,storage_name,report_name> field_type;
         return field_type::make( carrier_param, pointer_param );
        }

     }
   }
 }

#endif
