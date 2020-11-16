#ifndef reflection_property_mutate_field
#define reflection_property_mutate_field

// ::reflection::property::field::field_struct<data_name,model_name,class_name,storage_name,report_name>

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
                report_type operator()( storage_type & carrier_param, model_type model_param )const
                 {
                  if( NULL == m_pointer )
                   {
                    return false; //throw (void*)NULL;
                   }

                  (*carrier_param).*m_pointer = model_param;
                  return  report_type( true );
                 }

              private:
               pointer_type  m_pointer;
             } assigner_type;

            typedef ::reflection::property::mutate::basic_class <model_name,storage_name,assigner_type,report_name>      typedef_type;

            static typedef_type make( storage_type const& carrier_param, pointer_type const& pointer_param )
                   {
                    return typedef_type( carrier_param, assigner_type( pointer_param ) );
                   }
           };

        }

      template
       <
         typename    data_name
        ,typename   model_name
        ,typename   class_name
        ,typename storage_name
        ,typename  report_name
       >
       class  field_class
        : public ::reflection::property::mutate::_internal::field_struct<data_name,model_name,class_name,storage_name,report_name>::typedef_type
        , public ::reflection::ornament::relation_class
        , public ::reflection::ornament::accessibility_class
        , public ::reflection::ornament::linkage_class
        , public ::reflection::ornament::qualification_class
        {
         public:
          typedef ::reflection::ornament::relation_class relation_type;
          typedef ::reflection::ornament::accessibility_class accessibility_type;

          typedef typename ::reflection::property::mutate::_internal::field_struct<data_name,model_name,class_name,storage_name,report_name>  basic_type;
          typedef typename basic_type::typedef_type  base_type;

          typedef typename basic_type::assigner_type   assigner_type;
          typedef typename basic_type::pointer_type     pointer_type;
          typedef typename basic_type::storage_type     storage_type;

          field_class( storage_type   const& storage_param, pointer_type const& pointer_param )
            : relation_type( relation_type::member_index )
            , accessibility_type( accessibility_type::default_index )
            , base_type( storage_param, assigner_type( pointer_param ) )
            {
            }

          using base_type::process;
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
       typename ::reflection::property::mutate::field_class<data_name,model_name,class_name,storage_name,report_name>
       field
        (
          storage_name const& carrier_param
         ,data_name      class_name::*pointer_param
        )
        {
         typedef ::reflection::property::mutate::field_class<data_name,model_name,class_name,storage_name,report_name> field_type;
         return field_type( carrier_param, pointer_param );
        }

     }
   }
 }

#endif
