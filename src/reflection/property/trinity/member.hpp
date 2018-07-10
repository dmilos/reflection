#ifndef reflection_property_trinity_member
#define reflection_property_trinity_member
// ::reflection::property::trinity::member_struct<model_name,class_name,carrier_name,report_name>

 #include "./base.hpp"

#include "../mutate/member.hpp"
#include "../inspect/member.hpp"

 namespace reflection
  {
   namespace property
    {
     namespace trinity
      {

       template
         <
          typename data_name
         ,typename original_name// =  data_name &
         ,typename model_name   //= data_name const&
         ,typename image_name   //= data_name const&
         ,typename class_name
         ,typename storage_name
         ,typename report_name = bool
         >
        struct  member_struct
         {
          public:
            typedef   data_name       data_type;
            typedef original_name original_type;
            typedef model_name       model_type;
            typedef image_name       image_type;
            typedef class_name       class_type;
            typedef storage_name   storage_type;
            typedef report_name     report_type;
            
            typedef ::reflection::property::direct::member_struct<original_type,class_name,storage_type>          direct_type;
            typedef ::reflection::property::inspect::member_struct<image_name,class_name,storage_type>           inspect_type;
            typedef ::reflection::property::mutate::member_struct<model_type,class_type,storage_type,report_type> mutate_type;
            
            typedef typename  direct_type::extractor_class   extractor_type;
            typedef typename  mutate_type::assigner_type      assigner_type;
            typedef typename inspect_type::retriever_type    retriever_type;
            
            typedef ::reflection::property::trinity::base_class <data_type,original_type,model_name, image_name, storage_name, extractor_type, assigner_type, retriever_type, report_name>      typedef_type;
            
            typedef typename  direct_type::traitor_type   traitor_type;
            typedef typename  mutate_type::writter_type   writter_type;
            typedef typename inspect_type::reader_type     reader_type;
            
            static typedef_type make( storage_type const& carrier_param, traitor_type const& traitor_param,writter_type const& writter_param, reader_type const& reader_param )
             {
              return typedef_type( carrier_param, extractor_type( traitor_param ), assigner_type( writter_param ), retriever_type( reader_param )/**/ );
             }
         };

       template
        <
          typename      data_name
         ,typename     model_name
         ,typename  original_name
         ,typename     image_name
         ,typename     class_name
         ,typename   storage_name
         ,typename    report_name
        >
       inline
       typename ::reflection::property::trinity::member_struct<data_name,original_name,model_name,image_name,class_name,storage_name,report_name>::typedef_type
       member
        (
          storage_name const& carrier_param
          ,original_name    (class_name::*traitor_param)(  )
          ,report_name      (class_name::*writter_param)( model_name )
          ,image_name       (class_name::*reader_param)( void )const
        )
        {
         typedef ::reflection::property::trinity::member_struct<data_name,model_name,image_name,class_name,storage_name,report_name> member_type;
         return member_type::make( carrier_param, writter_param, reader_param );
        }

     }
   }
 }

#endif
