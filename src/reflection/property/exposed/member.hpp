#ifndef reflection_property_exposed_type_member
#define reflection_property_exposed_type_member
// ::reflection::property::exposed::member_struct<model_name,class_name,carrier_name,report_name>

 #include "./basic.hpp"

#include "../direct/member.hpp"
#include "../mutate/member.hpp"

 namespace reflection
  {
   namespace property
    {
     namespace exposed
      {
       namespace _internal
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
         
            typedef ::reflection::property::direct::_internal::member_struct<original_name,class_name,storage_name>          direct_type;
            typedef ::reflection::property::mutate::_internal::member_struct<model_name,class_name,storage_name,report_name> mutate_type;
         
            typedef typename  direct_type::extractor_class   extractor_type;
            typedef typename mutate_type::assigner_class   assigner_type;
         
            typedef ::reflection::property::exposed::basic_class <original_name, model_name, storage_name, extractor_type, assigner_type, report_name>      typedef_type;
         
            typedef typename  direct_type::traitor_type   traitor_type;
            typedef typename mutate_type::writer_type     writer_type;

            static typedef_type make( storage_type const& carrier_param, traitor_type const& traitor_param, writer_type const& writer_param )
             {
              return typedef_type( carrier_param, extractor_type( traitor_param ), assigner_type( writer_param ) );
             }
           };
        }


       template
         <
          typename original_name
         ,typename model_name
         ,typename class_name
         ,typename storage_name
         ,typename report_name
         >
        class member_class
        : public ::reflection::ornament::relation_class
        , public ::reflection::ornament::accessibility_class
        , public ::reflection::property::exposed::_internal::member_struct<original_name,model_name,class_name,storage_name,report_name>::typedef_type
        {
         public:
          typedef ::reflection::ornament::relation_class relation_type;
          typedef ::reflection::ornament::accessibility_class accessibility_type;

          typedef typename ::reflection::property::exposed::_internal::member_struct<original_name,model_name,class_name,storage_name,report_name>  basic_type;
          typedef typename basic_type::typedef_type  base_type;

          typedef typename basic_type::extractor_type     extractor_type;
          typedef typename basic_type::assigner_type       assigner_type;

          typedef typename basic_type::traitor_type         traitor_type;
          typedef typename basic_type::writer_type           writer_type;

          typedef typename basic_type::storage_type     storage_type;


          explicit member_class( storage_type   const& storage_param, traitor_type const& traitor_param, writer_type const& writer_param )
           : relation_type( relation_type::member_index )
           , accessibility_type( accessibility_type::default_index )
           , base_type( storage_param, extractor_type( traitor_param ), assigner_type( writer_param ) )
           {
           }

           using base_type::disclose;
           using base_type::process; 
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
       typename ::reflection::property::exposed::member_class<original_name,model_name,class_name,storage_name,report_name>
       member
        (
          storage_name const& carrier_param
         ,original_name    (class_name::*traitor_param )( void )
         ,report_name      (class_name::*writer_param)( model_name )
        )
        {
         typedef ::reflection::property::exposed::member_class<original_name,model_name,class_name,storage_name,report_name> member_type;
         return member_type( carrier_param, traitor_param, writer_param );
        }

     }
   }
 }

#endif
