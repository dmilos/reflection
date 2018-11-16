#ifndef reflection_property_variable_type_field
#define reflection_property_variable_type_field
// ::reflection::property::variable::field_struct<model_name,class_name,carrier_name,report_name>

 #include "./basic.hpp"

#include "../direct/field.hpp"
#include "../inspect/field.hpp"

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
           typename data_name
          ,typename original_name
          ,typename image_name
          ,typename class_name
          ,typename storage_name
          >
         struct  field_struct
          {
           typedef data_name           data_type;
           typedef original_name   original_type;
           typedef image_name         image_type;
           typedef class_name         class_type;
           typedef storage_name     storage_type;

           typedef ::reflection::property::direct::_internal::field_struct<data_name,original_type,class_type,storage_type>    direct_type;
           typedef ::reflection::property::inspect::_internal::field_struct<data_name,image_type,class_type,storage_type>     inspect_type;

           typedef typename  direct_type::extractor_class   extractor_type;
           typedef typename inspect_type::retriever_type   retriever_type;

           typedef ::reflection::property::variable::basic_class <original_name, image_name, storage_name, extractor_type, retriever_type >      typedef_type;

           typedef typename  direct_type::pointer_type   pointer_type;

           static typedef_type make( storage_type const& carrier_param, pointer_type const& pointer_param )
            {
             return typedef_type( carrier_param, extractor_type( pointer_param ), retriever_type( pointer_param ) );
            }
          };

       }

      template
       <
         typename data_name
        ,typename original_name
        ,typename image_name
        ,typename class_name
        ,typename storage_name
       >
       class  field_class
        : public ::reflection::property::variable::_internal::field_struct<data_name,original_name,image_name,class_name,storage_name>::typedef_type
        , public ::reflection::ornament::relation_class
        , public ::reflection::ornament::accessibility_class
        , public ::reflection::ornament::linkage_class
        , public ::reflection::ornament::qualification_class
        {
         public:
          typedef ::reflection::ornament::relation_class relation_type;
          typedef ::reflection::ornament::accessibility_class accessibility_type;

          typedef typename ::reflection::property::variable::_internal::field_struct<data_name,original_name,image_name,class_name,storage_name>  basic_type;
          typedef typename basic_type::typedef_type  base_type;

          typedef typename basic_type::extractor_type     extractor_type;
          typedef typename basic_type::retriever_type   retriever_type;

          typedef typename basic_type::pointer_type     pointer_type;
          typedef typename basic_type::storage_type     storage_type;


          explicit field_class( storage_type   const& storage_param, pointer_type const& pointer_param )
            : relation_type( relation_type::member_index )
            , accessibility_type( accessibility_type::unknown_index )
            , base_type( storage_param, extractor_type( pointer_param ), retriever_type( pointer_param ) )
            {
            }

          using base_type::disclose;
          // TODO using base_type::disclose;
        };


      template
       <
         typename     data_name
        ,typename original_name = data_name &
        ,typename    image_name = data_name const&
        ,typename    class_name
        ,typename  storage_name
       >
       inline
       typename ::reflection::property::variable::field_class<data_name,original_name,image_name,class_name,storage_name>::typedef_type
       field
        (
          storage_name const& carrier_param
         ,data_name      class_name::*pointer_param
        )
        {
         typedef ::reflection::property::variable::field_class<data_name,original_name,image_name,class_name,storage_name> field_type;
         return field_type::make( carrier_param, pointer_param );
        }

    }
  }
}

#endif
