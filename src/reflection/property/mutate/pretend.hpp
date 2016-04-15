#ifndef reflection_property_mutate_pretend
#define reflection_property_mutate_pretend

// ::reflection::property::mutate::pretend::base_class<pretend_name,convert_name,storage_name,writter_name,report_name>

 #include "./base.hpp"

 namespace reflection
  {
   namespace property
    {
     namespace mutate
      {
       namespace pretend
        {

         template
           <
            typename pretend_name
           ,typename convert_name
           ,typename storage_name
           ,typename writter_name
           ,typename report_name
           >
          struct   base_class
           {
            typedef  pretend_name    pretend_type;
            typedef  convert_name    convert_type;
            typedef  storage_name    storage_type;
            typedef  writter_name    writter_type;
            typedef   report_name     report_type;

            typedef class assigner_class
             {
              public:

                explicit assigner_class( writter_type const& writter_param, convert_type const& convert_param )
                 :m_writter( writter_param ),m_convert( convert_param )
                 {
                 }
                report_type operator()( storage_type & storage_param, pretend_type pretend_param )const
                 {
                  return  this->m_writter( storage_param, this->m_convert( pretend_param ) );
                 }
              private:
                mutable writter_type  m_writter;
                mutable convert_type  m_convert;
             } assigner_class;

            typedef ::reflection::property::mutate::base_class<pretend_name,storage_name,assigner_class,report_name>      typedef_type;

            static typedef_type make( storage_type const& storage_param, writter_type const& writter_param, convert_type const& convert_param )
                   {
                    return typedef_type( storage_param, assigner_class( writter_param, convert_param ) );
                   }

           };

         template
          <
            typename pretend_name
           ,typename convert_name
           ,typename model_name
           ,typename class_name
           ,typename storage_name
           ,typename report_name
          >
          struct member_class
           {
            typedef pretend_name pretend_type;
            typedef convert_name convert_type;
            typedef model_name     model_type;
            typedef storage_name storage_type;
            typedef report_name   report_type;

            typedef       report_type       (class_name::*method_type)( model_type );


            typedef class writter_class
             {
              public:
                typedef model_name    model_type,    T_2nd;
                typedef storage_name  storage_type;
                typedef report_name   report_type,   T_0th;

                explicit writter_class( method_type const& method_param /*= std::nullptr_t()*/ )
                 :m_method( method_param )
                 {
                 }
                report_type operator()( storage_type & carrier_param, model_type model_param )const
                 {
                  return ( (*carrier_param).*(this->m_method))( model_param );
                 }
              private:
               method_type  m_method;
             } writter_type;

            typedef ::reflection::property::mutate::pretend::base_class<pretend_name,convert_name,storage_name,writter_type,report_type> base_type;
            typedef typename ::reflection::property::mutate::pretend::base_class<pretend_name,convert_name,storage_name,writter_type,report_type>::typedef_type typedef_type;

            static typedef_type make( storage_type const& storage_param, method_type const& method_param, convert_type const& convert_param = convert_type() )
             {
              return base_type::make( storage_param, writter_type( method_param ), convert_param );
             }
           };

         template
          <
            typename pretend_name
           ,typename convert_name
           ,typename model_name
           ,typename class_name
           ,typename storage_name
           ,typename report_name
          >
          inline
          typename ::reflection::property::mutate::pretend::member_class<pretend_name,convert_name,model_name,class_name,storage_name,report_name>::typedef_type
           member
           (
             storage_name const& storage_param
           , report_name (class_name::*method_param)( model_name )
           , convert_name const& convert_param = convert_name()
           )
           {
            typedef ::reflection::property::mutate::pretend::member_class<pretend_name,convert_name,model_name,class_name,storage_name,report_name>  member_type;
            return  member_type::make( storage_param, method_param, convert_param );
           }

       }
     }
   }
 }

#endif
