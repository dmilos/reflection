#ifndef reflection_property_mutate_common
#define reflection_property_mutate_common

// ::reflection::property::common::common_struct<data_name,model_name,class_name,storage_name,report_name>

 #include "./base.hpp"

 namespace reflection
  {
   namespace property
    {
     namespace mutate
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

          typedef ::reflection::property::mutate::base_class <model_name,storage_type,assigner_type,report_name>      typedef_type;

          static typedef_type make( storage_type const& carrier_param)
                 {
                  return typedef_type( carrier_param, assigner_type( ) );
                 }

         };

       template
        <
          typename   class_name
         ,typename    data_name
         ,typename   model_name = data_name const&
         ,typename  report_name
        >
       inline
       typename ::reflection::property::mutate::common_struct<data_name,model_name,class_name,report_name>::typedef_type
       common
        (
          data_name      *carrier_param
        )
        {
         typedef ::reflection::property::mutate::common_struct<data_name,model_name,class_name,report_name> common_type;
         return common_type::make( carrier_param );
        }

     }
   }
 }

#endif
