#ifndef reflection_property_mutate_diverse
#define reflection_property_mutate_diverse

// ::reflection::property::mutate::diverse_class<model_name,class_name,carrier_name,report_name>

 #include "./base.hpp"

 namespace reflection
  {
   namespace property
    {
     namespace mutate
      {

       template
         <
          typename pretend_name
         ,typename convert_name
         ,typename carrier_name
         ,typename writter_name
         ,typename report_name
         >
        struct   pretend_class
         {
          typedef  pretend_name  pretend_name;
          typedef  convert_name  convert_type;
          typedef  carrier_name  carrier_type;
          typedef  writter_name  writter_type;
          typedef   report_name   report_type;

          typedef class assigner_class
           {
            public:

              explicit assigner_class( writter_type const& writter_param, convert_name const& convert_param )
               :m_writter( writter_param ),m_convert( convert_param )
               {
               }
              report_type operator()( carrier_type & carrier_param, pretend_name input_param )const
               {
                return  m_writter( carrier_param, m_convert( input_param ) );
               }
            private:
             writter_type  m_writter;
             convert_type  m_convert;

           } assigner_type;

          typedef ::reflection::property::mutate::base_class<pretend_name,carrier_name,assigner_type,report_name>      typedef_type;

          static typedef_type make( carrier_type const& carrier_param, writter_type const& writter_param )
                 {
                  return typedef_type( carrier_param, assigner_type( writter_param ) );
                 }

         };

       namespace _internalPretend
        {
         template
          <
          ,typename pretend_name
          ,typename model_name
          ,typename class_name
          ,typename carrier_name
          ,typename report_name
          >

          struct member_class
           {
            typedef pretend_name  ;
            //typedef convert_name  ;
            typedef carrier_name  ;
            //typedef writter_name  ;
            typedef report_name   ;

            // ::reflection::property::mutate::member_class<model_name,class_name,carrier_name,report_name>::assigner_class
            typedef int property_type;
           };
        }

       template
        <
        ,typename pretend_name
        ,typename model_name
        ,typename class_name
        ,typename carrier_name
        ,typename report_name
        >
       inline
       typename ::reflection::property::mutate:: _internalPretend::member_class<pretend_name,model_name,class_name,carrier_name,report_name>::property_type
        pretend
        (
          carrier_name const& carrier_param
        , report_name (class_name::*writter_param)( model_name )
        )
        {
         typedef ::reflection::property::mutate:: pretend_class<pretend_name,convert_name,carrier_name,writter_name,report_name>  pretend_type;
         return  pretend_type::make( carrier_param, writter_param );
        }

     }
   }
 }

#endif
