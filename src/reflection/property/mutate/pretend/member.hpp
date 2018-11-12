#ifndef reflection_property_mutate_pretend_member
#define reflection_property_mutate_pretend_member

// ::reflection::property::mutate::pretend::base_class<pretend_name,converter_name,storage_name,writer_name,report_name>

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
           ,typename converter_name
           ,typename model_name
           ,typename class_name
           ,typename storage_name
           ,typename report_name
          >
          struct member_class
           {
            typedef pretend_name pretend_type;
            typedef converter_name converter_type;
            typedef model_name     model_type;
            typedef class_name     class_type;
            typedef storage_name storage_type;
            typedef report_name   report_type;

            typedef       report_type       (class_type::*method_type)( model_type );


            typedef class writer_class
             {
              public:
                typedef model_name    model_type,    T_2nd;
                typedef storage_name  storage_type;
                typedef report_name   report_type,   T_0th;

                explicit writer_class( method_type const& method_param /*= std::nullptr_t()*/ )
                 :m_method( method_param )
                 {
                 }
                report_type operator()( storage_type & carrier_param, model_type model_param )const
                 {
                  return ( (*carrier_param).*(this->m_method))( model_param );
                 }
              private:
               method_type  m_method;
             } writer_type;

            typedef ::reflection::property::mutate::pretend::basic_class<pretend_name,converter_name,storage_name,writer_type,report_type> base_type;
            typedef typename ::reflection::property::mutate::pretend::base_class<pretend_name,converter_name,storage_name,writer_type,report_type>::typedef_type typedef_type;

            static typedef_type make( storage_type const& storage_param, method_type const& method_param, converter_type const& convert_param = converter_type() )
             {
              return base_type::make( storage_param, writer_type( method_param ), convert_param );
             }
           };

         template
          <
            typename pretend_name
           ,typename converter_name
           ,typename model_name
           ,typename class_name
           ,typename storage_name
           ,typename report_name
          >
          inline
          typename ::reflection::property::mutate::pretend::member_class<pretend_name,converter_name,model_name,class_name,storage_name,report_name>::typedef_type
           member
           (
             storage_name const& storage_param
           , report_name (class_name::*method_param)( model_name )
           , converter_name const& convert_param = converter_name()
           )
           {
            typedef ::reflection::property::mutate::pretend::member_class<pretend_name,converter_name,model_name,class_name,storage_name,report_name>  member_type;
            return  member_type::make( storage_param, method_param, convert_param );
           }

       }
     }
   }
 }

#endif
