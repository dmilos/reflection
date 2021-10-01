#ifndef reflection_property_trinity_common
#define reflection_property_trinity_common
// ::reflection::property::trinity::common_struct<model_name,class_name,carrier_name,report_name>

 #include "./basic.hpp"

#include "../mutate/common.hpp"
#include "../inspect/common.hpp"

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
          ,typename model_name
          ,typename image_name
          ,typename class_name
          ,typename report_name
          >
         struct  common_struct
          {
           public:
             typedef data_name           data_type;
             typedef original_name   original_type;
             typedef model_name         model_type;
             typedef image_name         image_type;
             typedef class_name         class_type;
             typedef report_name       report_type;

             typedef ::reflection::property::direct::_internal::common_struct<data_name,original_name,class_name>          direct_type;
             typedef ::reflection::property::mutate::_internal::common_struct<data_name,model_name,class_name,report_name> mutate_type;
             typedef ::reflection::property::inspect::_internal::common_struct<data_name,image_name,class_name>           inspect_type;


             typedef typename  direct_type::storage_type   storage_type;

             typedef typename  direct_type::extractor_class    extractor_type;
             typedef typename  mutate_type::assigner_class      assigner_type;
             typedef typename inspect_type::retriever_class    retriever_type;

             typedef ::reflection::property::trinity::basic_class< original_name, model_name, image_name, storage_type, extractor_type, assigner_type, retriever_type, report_name>      typedef_type;


             static typedef_type make( storage_type const& carrier_param )
              {
               return typedef_type( carrier_param, extractor_type( ), assigner_type( ), retriever_type( ) );
              }
          };

       }

       template
        <
         typename     data_name
        ,typename original_name
        ,typename model_name
        ,typename image_name
        ,typename class_name
        ,typename report_name
        >
        class common_class
         : public ::reflection::ornament::relation_class
         , public ::reflection::ornament::accessibility_class
         , public ::reflection::ornament::linkage_class
         , public ::reflection::property::trinity::_internal::common_struct<data_name,original_name,model_name,image_name,class_name,report_name>::typedef_type
         {
         public:
          typedef ::reflection::ornament::relation_class relation_type;
          typedef ::reflection::ornament::accessibility_class accessibility_type;

          typedef typename ::reflection::property::trinity::_internal::common_struct<data_name,original_name,model_name,image_name,class_name,report_name>  basic_type;
          typedef typename basic_type::typedef_type  base_type;

          typedef typename basic_type::extractor_type     extractor_type;
          typedef typename basic_type::assigner_type       assigner_type;
          typedef typename basic_type::retriever_type     retriever_type;

          typedef typename basic_type::storage_type     storage_type;

          explicit common_class( storage_type   const& storage_param )
            : relation_type( relation_type::member_index )
            , accessibility_type( accessibility_type::default_index )
            , linkage_class( linkage_class::static_index )
            , base_type( storage_param, extractor_type(), assigner_type(), retriever_type() )
            {
            }

          using  base_type::disclose;
          using  base_type::process;
          using  base_type::present; 
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
       ::reflection::property::trinity::common_class<data_name,original_name,model_name,image_name,class_name,report_name>
       common
        (
          data_name      class_name::*carrier_param
        )
        {
         typedef ::reflection::property::trinity::common_class<data_name,original_name,model_name,image_name,class_name,report_name> common_type;
         return common_type( carrier_param );
        }

     }
   }
 }

#endif
