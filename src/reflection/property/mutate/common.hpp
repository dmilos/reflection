#ifndef reflection_property_mutate_common
#define reflection_property_mutate_common

// ::reflection::property::common::common_struct<data_name,model_name,class_name,storage_name,report_name>

 #include "./basic.hpp"

namespace reflection
 {
  namespace property
   {
    namespace mutate
     {

      namespace _internal
       {

        template
          <
           typename    data_name
          ,typename   model_name
          ,typename   class_name
          ,typename  report_name
          >
         struct  common_struct
          {
           typedef data_name        data_type;
           typedef model_name      model_type;
           typedef class_name      class_type;
           typedef report_name    report_type;

           typedef data_type        *storage_type; //!< By design

           typedef class assigner_class
            {
             public:
               explicit assigner_class()
                {
                }
               report_type operator()( storage_type & carrier_param, model_type input_param )const
                {
                 (*carrier_param) = input_param ;
                 return  report_type( true );
                }

            } assigner_type;

           typedef ::reflection::property::mutate::basic_class <model_name,storage_type,assigner_type,report_name>      typedef_type;

           static typedef_type make( storage_type const& carrier_param)
                  {
                   return typedef_type( carrier_param, assigner_type( ) );
                  }

          };

       }

       template
        <
         typename    data_name
        ,typename   model_name
        ,typename   class_name
        ,typename  report_name
        >
        class common_class
         : public ::reflection::ornament::relation_class
         , public ::reflection::ornament::accessibility_class
         , public ::reflection::ornament::linkage_class
         , public ::reflection::property::mutate::_internal::common_struct<data_name,model_name,class_name,report_name>::typedef_type
         {
         public:
          typedef ::reflection::ornament::relation_class relation_type;
          typedef ::reflection::ornament::accessibility_class accessibility_type;
          typedef ::reflection::ornament::linkage_class linkage_type;

          typedef typename ::reflection::property::mutate::_internal::common_struct<data_name,model_name,class_name,report_name>  basic_type;
          typedef typename basic_type::typedef_type  base_type;

          typedef typename basic_type::assigner_type   assigner_type;
          typedef typename basic_type::storage_type     storage_type;

          explicit common_class( storage_type   const& storage_param )
            : relation_type( relation_type::member_index )
            , accessibility_type( accessibility_type::default_index )
            , linkage_type( linkage_type::static_index )
            , base_type( storage_param, assigner_type() )
            {
            }

          using base_type::process;
         };


      template
       <
         typename   class_name
        ,typename    data_name
        ,typename   model_name = data_name const&
        ,typename  report_name
       >
       inline
       typename ::reflection::property::mutate::common_class<data_name,model_name,class_name,report_name>
       common
        (
          data_name      *carrier_param
        )
        {
         typedef ::reflection::property::mutate::common_class<data_name,model_name,class_name,report_name> common_type;
         return common_type( carrier_param );
        }

     }
   }
 }

#endif
