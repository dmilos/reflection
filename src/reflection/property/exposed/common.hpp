#ifndef reflection_property_exposed_type_common
#define reflection_property_exposed_type_common
// ::reflection::property::exposed::common_struct<model_name,class_name,carrier_name,report_name>

 #include "./basic.hpp"

#include "../direct/common.hpp"
#include "../mutate/common.hpp"

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
           typename data_name
          ,typename original_name
          ,typename model_name
          ,typename class_name
          ,typename report_name
          >
         struct  common_struct
          {
           typedef original_name    original_type;
           typedef model_name    model_type;
           typedef class_name    class_type;
           typedef report_name     report_type;

           typedef ::reflection::property::direct::_internal::common_struct<data_name,original_type,class_type>          direct_type;
           typedef ::reflection::property::mutate::_internal::common_struct<data_name,model_type,class_type,report_type> mutate_type;

           typedef typename  direct_type::storage_type   storage_type;

           typedef typename  direct_type::extractor_class   extractor_type;
           typedef typename mutate_type::assigner_class      assigner_type;

           typedef ::reflection::property::exposed::basic_class <original_name, model_name, storage_type, extractor_type, assigner_type, report_name>      typedef_type;


           static typedef_type make( storage_type const& carrier_param )
            {
             return typedef_type( carrier_param, extractor_type( ), assigner_type( ) );
            }
          };

       }


      template
        <
         typename data_name
        ,typename original_name
        ,typename model_name
        ,typename class_name
        ,typename report_name
        >
       class common_class
        : public ::reflection::ornament::relation_class
        , public ::reflection::ornament::accessibility_class
        , public ::reflection::ornament::linkage_class
        , public ::reflection::property::exposed::_internal::common_struct<data_name,original_name,model_name,class_name,report_name>::typedef_type
        {
         public:
          typedef ::reflection::ornament::relation_class relation_type;
          typedef ::reflection::ornament::accessibility_class accessibility_type;

          typedef typename ::reflection::property::exposed::_internal::common_struct<data_name,original_name,model_name,class_name,report_name>  basic_type;
          typedef typename basic_type::typedef_type  base_type;

          typedef typename basic_type::extractor_type extractor_type;
          typedef typename basic_type::assigner_type   assigner_type;

          typedef typename basic_type::storage_type     storage_type;

          explicit common_class( storage_type   const& storage_param )
            : relation_type( relation_type::member_index )
            , accessibility_type( accessibility_type::default_index )
            , linkage_class( linkage_class::static_index )
            , base_type( storage_param, extractor_type(), assigner_type() )
            {
            }

          using base_type::disclose;
        };


      template
       <
         typename    class_name
        ,typename     data_name
        ,typename original_name = data_name &
        ,typename    model_name = data_name const&
        ,typename   report_name = bool
       >
       inline
       ::reflection::property::exposed::common_class<data_name,original_name,model_name,class_name,report_name>
       common
        (
          data_name      *carrier_param
        )
        {
         typedef ::reflection::property::exposed::common_class<data_name,original_name,model_name,class_name,report_name> common_type;
         return common_type( carrier_param );
        }

     }
   }
 }

#endif
