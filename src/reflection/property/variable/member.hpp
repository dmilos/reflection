#ifndef reflection_property_variable_member
#define reflection_property_variable_member
// ::reflection::property::variable::member_struct<model_name,class_name,carrier_name,report_name>

 #include "./basic.hpp"

#include "../direct/member.hpp"
#include "../inspect/member.hpp"

 namespace reflection
  {
   namespace property
    {
     namespace variable
      {

       namespace _internal
        {

         template
           <
            typename original_name
           ,typename image_name
           ,typename class_name
           ,typename storage_name
           >
          struct  member_struct
           {
            typedef original_name    original_type;
            typedef image_name    image_type;
            typedef class_name    class_type;
            typedef storage_name  storage_type;

            typedef ::reflection::property::direct::_internal::member_struct< original_type,class_type,storage_type> direct_type;
            typedef ::reflection::property::inspect::_internal::member_struct<image_name,class_name,storage_type> inspect_type;

            typedef typename  direct_type::extractor_type   extractor_type;
            typedef typename inspect_type::retriever_type   retriever_type;

            typedef ::reflection::property::variable::basic_class < original_name, image_name, storage_name, extractor_type, retriever_type>      typedef_type;

            typedef typename  direct_type::traitor_type   traitor_type;
            typedef typename inspect_type::reader_type     reader_type;

            static typedef_type make( storage_type const& carrier_param, traitor_type const& traitor_param, reader_type const& reader_param )
             {
              return typedef_type( carrier_param, extractor_type( traitor_param ), retriever_type( reader_param ) );
             }
           };
        }


       template
         <
          typename original_name
         ,typename image_name
         ,typename class_name
         ,typename storage_name
         >
        class member_class
        : public ::reflection::ornament::relation_class
        , public ::reflection::ornament::accessibility_class
        , public ::reflection::property::variable::_internal::member_struct<original_name,image_name,class_name,storage_name>::typedef_type
        {
         public:
          typedef ::reflection::ornament::relation_class relation_type;
          typedef ::reflection::ornament::accessibility_class accessibility_type;

          typedef typename ::reflection::property::variable::_internal::member_struct<original_name,image_name,class_name,storage_name>  basic_type;
          typedef typename basic_type::typedef_type  base_type;

          typedef typename basic_type::extractor_type     extractor_type;
          typedef typename basic_type::retriever_type     retriever_type;

          typedef typename basic_type::traitor_type         traitor_type;
          typedef typename basic_type::reader_type           reader_type;

          typedef typename basic_type::storage_type     storage_type;


          explicit member_class( storage_type   const& storage_param, traitor_type const& traitor_param, reader_type const& reader_param )
           : relation_type( relation_type::member_index )
           , accessibility_type( accessibility_type::default_index )
           , base_type( storage_param, extractor_type( traitor_param ), retriever_type( reader_param ) )
           {
           }

           using base_type::disclose;
           using base_type::present;
         };


       template
        <
         typename original_name
        ,typename image_name
        ,typename class_name
        ,typename storage_name
        >
       inline
       typename ::reflection::property::variable::member_class<original_name,image_name,class_name,storage_name>
       member
        (
          storage_name const& carrier_param
         ,original_name    (class_name::*traitor_param )( void )
         ,image_name       (class_name::*reader_param)( void )const
        )
        {
         typedef ::reflection::property::variable::member_class<original_name,image_name,class_name,storage_name> member_type;
         return member_type( carrier_param, traitor_param, reader_param );
        }

     }
   }
 }

#endif
