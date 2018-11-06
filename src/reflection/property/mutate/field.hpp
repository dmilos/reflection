#ifndef reflection_property_mutate_field
#define reflection_property_mutate_field

// ::reflection::property::field::field_struct<data_name,model_name,class_name,storage_name,report_name>

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
         ,typename storage_name
         ,typename  report_name
         >
        struct  field_struct
         {
          typedef data_name        data_type;
          typedef model_name      model_type;
          typedef class_name      class_type;
          typedef storage_name  storage_type;
          typedef report_name    report_type;

          typedef data_type         class_name::*pointer_type; //!< By design

          typedef class assigner_class
           {
            public:
              explicit assigner_class( pointer_type const& pointer_param = NULL )
               :m_pointer( pointer_param )
               {
               }
              report_type operator()( storage_type & carrier_param, model_type input_param )const
               {
                if( NULL == m_pointer )
                 {
                  return false; //throw (void*)NULL;
                 }

                (*carrier_param).*m_pointer = input_param ;
                return  report_type( true );
               }

            private:
             pointer_type  m_pointer;
           } assigner_type;

          typedef ::reflection::property::mutate::base_class <model_name,storage_name,assigner_type,report_name>      typedef_type;

          static typedef_type make( storage_type const& carrier_param, pointer_type const& pointer_param )
                 {
                  return typedef_type( carrier_param, assigner_type( pointer_param ) );
                 }

         };

       template
        <
          typename    data_name
         ,typename   model_name = data_name const&
         ,typename   class_name
         ,typename storage_name
         ,typename  report_name
        >
       inline
       typename ::reflection::property::mutate::field_struct<data_name,model_name,class_name,storage_name,report_name>::typedef_type
       field
        (
          storage_name const& carrier_param
         ,data_name      class_name::*pointer_param
        )
        {
         typedef ::reflection::property::mutate::field_struct<data_name,model_name,class_name,storage_name,report_name> field_type;
         return field_type::make( carrier_param, pointer_param );
        }

     }
   }
 }

#endif
