#ifndef reflection_property_variable_type_common
#define reflection_property_variable_type_common
// ::reflection::property::variable::common_struct<model_name,class_name,carrier_name,report_name>

 #include "./base.hpp"

#include "../direct/common.hpp"
#include "../inspect/common.hpp"

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
         >
        struct  common_struct
         {
          typedef data_name           data_type;
          typedef original_name   original_type;
          typedef image_name         image_type;
          typedef class_name         class_type;

          typedef ::reflection::property::direct::_internal::common_struct<data_name,original_type,class_type>    direct_type;
          typedef ::reflection::property::inspect::_internal::common_struct<data_name,image_type,class_type>     inspect_type;

          typedef typename  direct_type::storage_type   storage_type;

          typedef typename  direct_type::extractor_class   extractor_type;
          typedef typename inspect_type::retriever_type   retriever_type;

          typedef ::reflection::property::variable::basic_class <original_name, image_name, storage_type, extractor_type, retriever_type >      typedef_type;


          static typedef_type make( storage_type const& carrier_param )
           {
            return typedef_type( carrier_param, extractor_type(), retriever_type() );
           }
         };

      }

      template
       <
        typename data_name
       ,typename original_name
       ,typename image_name
       ,typename class_name
       >
       class  common_class
        : public ::reflection::ornament::relation_class
        , public ::reflection::ornament::visibility_class
        , public ::reflection::ornament::linkage_class
        , public ::reflection::property::variable::_internal::common_struct<data_name,original_name,image_name,class_name>::typedef_type
        {
         public:
          typedef ::reflection::ornament::relation_class relation_type;
          typedef ::reflection::ornament::visibility_class visibility_type;

          typedef ::reflection::property::variable::_internal::common_struct<data_name,original_name,image_name,class_name>  basic_type;
          typedef typename basic_type::typedef_type  base_type;

          typedef typename basic_type::extractor_type     extractor_type;
          typedef typename basic_type::retriever_type   retriever_type;

          typedef typename basic_type::storage_type     storage_type;


          explicit common_class( storage_type   const& storage_param )
            : relation_type( relation_type::member_index )
            , visibility_type( visibility_type::unknown_index )
            , linkage_class( linkage_class::static_index )
            , base_type( storage_param, extractor_type(), retriever_type() )
            {
            }

          using base_type::disclose;
          // TODO using base_type::disclose;
        };


      template
       <
         typename    class_name
        ,typename     data_name
        ,typename original_name = data_name &
        ,typename    image_name = data_name const&
       >
       inline
       ::reflection::property::variable::common_class<data_name,original_name,image_name,class_name>
       common
        (
          data_name      *carrier_param
        )
        {
         typedef ::reflection::property::variable::common_class<data_name,original_name,image_name,class_name> common_type;
         return common_type( carrier_param );
        }

     }
   }
 }

#endif
