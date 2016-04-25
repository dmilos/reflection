#ifndef reflection_property_mutate_member
#define reflection_property_mutate_member

// ::reflection::property::mutate::member_class<model_name,class_name,carrier_name,report_name>

 #include "./base.hpp"

 namespace reflection
  {
   namespace property
    {
     namespace mutate
      {

       template
         <
          typename model_name
         ,typename class_name
         ,typename storage_name
         ,typename report_name
         >
        struct  member_class
         {
          typedef model_name    model_type;
          typedef class_name    class_type;
          typedef storage_name  storage_type;
          typedef report_name   report_type;

          typedef       report_type       (class_name::*writter_type)( model_type );

          typedef class assigner_class
           {
            public:
              typedef model_name    model_type,    T_2nd;
              typedef storage_name  storage_type;
              typedef report_name   report_type,   T_0th;

              explicit assigner_class( writter_type const& writter_param = NULL )
               :m_writter( writter_param )
               {
               }
              report_type operator()( storage_type & carrier_param, model_type input_param )const
               {
                return  ( (*carrier_param).*m_writter)( input_param );
               }
            private:
             writter_type  m_writter;
           } assigner_type;

          typedef ::reflection::property::mutate::base_class <model_name,storage_name,assigner_type,report_name>      typedef_type;

          static typedef_type make( storage_type const& carrier_param, writter_type const& writter_param )
                 {
                  return typedef_type( carrier_param, assigner_type( writter_param ) );
                 }

         };

       template
        <
         typename model_name
        ,typename class_name
        ,typename storage_name
        ,typename report_name
        >
       inline
       typename ::reflection::property::mutate::member_class<model_name,class_name,storage_name,report_name>::typedef_type
       member
        (
          storage_name const& carrier_param
        , report_name (class_name::*writter_param)( model_name )
        )
        {
         typedef ::reflection::property::mutate::member_class<model_name,class_name,storage_name,report_name> member_type;
         return member_type::make( carrier_param, writter_param );
        }

     }
   }
 }

#endif
