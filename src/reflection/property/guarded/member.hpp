#ifndef reflection_property_guarded_member
#define reflection_property_guarded_member
// ::reflection::property::guarded::member_struct<model_name,class_name,carrier_name,report_name>

 #include "./basic.hpp"

#include "../mutate/member.hpp"
#include "../inspect/member.hpp"

 namespace reflection
  {
   namespace property
    {
     namespace guarded
      {

       namespace _internal
        {

         template
           <
            typename model_name
           ,typename image_name
           ,typename class_name
           ,typename storage_name
           ,typename report_name
           >
          struct  member_struct
           {
            typedef model_name    model_type;
            typedef image_name    image_type;
            typedef class_name    class_type;
            typedef storage_name  storage_type;
            typedef report_name   report_type;

            typedef ::reflection::property::inspect::_internal::member_struct<image_name,class_name,storage_type> inspect_type;
            typedef ::reflection::property::mutate::_internal::member_struct<model_type,class_type,storage_type,report_type> mutate_type;

            typedef typename  mutate_type::assigner_type   assigner_type;
            typedef typename inspect_type::retriever_type retriever_type;

            typedef ::reflection::property::guarded::basic_class <model_name, image_name, storage_name, assigner_type, retriever_type, report_name>      typedef_type;

            typedef typename  mutate_type::writer_type   writer_type;
            typedef typename inspect_type::reader_type     reader_type;

            static typedef_type make( storage_type const& carrier_param, writer_type const& writer_param, reader_type const& reader_param )
             {
              return typedef_type( carrier_param, assigner_type( writer_param ), retriever_type( reader_param )/**/ );
             }
           };

        }

       template
         <
           typename model_name
          ,typename image_name
          ,typename class_name
          ,typename storage_name
          ,typename report_name
         >
        class member_class
        : public ::reflection::ornament::relation_class
        , public ::reflection::ornament::accessibility_class
        , public ::reflection::property::guarded::_internal::member_struct<model_name,image_name,class_name,storage_name,report_name>::typedef_type
        {
         public:
          typedef ::reflection::ornament::relation_class relation_type;
          typedef ::reflection::ornament::accessibility_class accessibility_type;

          typedef typename ::reflection::property::guarded::_internal::member_struct<model_name,image_name,class_name,storage_name,report_name>  basic_type;
          typedef typename basic_type::typedef_type  base_type;

          typedef typename basic_type::assigner_type     assigner_type;
          typedef typename basic_type::retriever_type     retriever_type;

          typedef typename basic_type::writer_type           writer_type;
          typedef typename basic_type::reader_type           reader_type;

          typedef typename basic_type::storage_type     storage_type;


          explicit member_class( storage_type   const& storage_param, writer_type const& writer_param, reader_type const& reader_param )
           : relation_type( relation_type::member_index )
           , accessibility_type( accessibility_type::default_index )
           , base_type( storage_param, assigner_type( writer_param ), retriever_type( reader_param ) )
           {
           }

          using base_type::process;
          using base_type::present;
         };

       template
        <
         typename model_name
        ,typename image_name
        ,typename class_name
        ,typename storage_name
        ,typename report_name
        >
       inline
       typename ::reflection::property::guarded::member_class<model_name,image_name,class_name,storage_name,report_name>
       member
        (
          storage_name const& carrier_param
         ,report_name      (class_name::*writer_param)( model_name )
         ,image_name       (class_name::*reader_param)( void )const
        )
        {
         typedef ::reflection::property::guarded::member_class<model_name,image_name,class_name,storage_name,report_name> member_type;
         return member_type( carrier_param, writer_param, reader_param );
        }

     }
   }
 }

#endif
