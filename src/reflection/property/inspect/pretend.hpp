#ifndef reflection_property_inspect_pretend
#define reflection_property_inspect_pretend

// ::reflection::property::inspect::pretend::base_class<pretend_name,converter_type,storage_name,reader_name>

 #include "./base.hpp"

 namespace reflection
  {
   namespace property
    {
     namespace inspect
      {
       namespace pretend
        {

         template
           <
            typename pretend_name
           ,typename converter_type
           ,typename storage_name
           ,typename reader_name
           >
          struct   base_class
           {
            typedef  pretend_name    pretend_type;
            typedef  converter_type  convert_type;
            typedef  storage_name    storage_type;
            typedef  reader_name      reader_type;

            typedef class retriever_class
             {
              public:

                explicit retriever_class( reader_type const& reader_param, convert_type const& convert_param )
                 :m_reader( reader_param ),m_convert( convert_param )
                 {
                 }

                pretend_name operator()( storage_type const& storage_param )const
                 {
                  return this->m_convert( this->m_reader( storage_param ) );
                 }

              private:
                mutable reader_type  m_reader;
                mutable convert_type  m_convert;
             } retriever_type;

            typedef ::reflection::property::inspect::base_class<pretend_name,storage_name,retriever_type>      typedef_type;

            static typedef_type make( storage_type const& storage_param, reader_type const& reader_param, convert_type const& convert_param )
                   {
                    return typedef_type( storage_param, retriever_type( reader_param, convert_param ) );
                   }

           };

         template
          <
            typename pretend_name
           ,typename converter_name
           ,typename image_name
           ,typename class_name
           ,typename storage_name
          >
          struct member_class
           {
            typedef pretend_name     pretend_type;
            typedef converter_name converter_type;
            typedef image_name         image_type;
            typedef storage_name     storage_type;

            typedef  image_name       (class_name::*method_type)( void )const;

            typedef class reader_name
             {
              public:
                typedef image_name    image_type;
                typedef storage_name  storage_type;

                explicit reader_name( method_type const& method_param /*= std::nullptr_t()*/ )
                 :m_method( method_param )
                 {
                 }
                image_name operator()( storage_type const& carrier_param )const
                 {
                  return ( (*carrier_param).*(this->m_method))( );
                 }
              private:
               method_type  m_method;
             } reader_type;

            typedef ::reflection::property::inspect::pretend::base_class<pretend_name,converter_type,storage_name,reader_type> base_type;
            typedef typename base_type::typedef_type typedef_type;

            static typedef_type make( storage_type const& storage_param, method_type const& method_param, converter_type const& convert_param = converter_type() )
             {
              return base_type::make( storage_param, reader_type( method_param ), convert_param );
             }
           };

         template
          <
            typename pretend_name
           ,typename converter_name
           ,typename image_name
           ,typename class_name
           ,typename storage_name
          >
          inline
          typename ::reflection::property::inspect::pretend::member_class<pretend_name,converter_name,image_name,class_name,storage_name>::typedef_type
          member
           (
             storage_name const& storage_param
           , image_name       (class_name::*method_param)( void )const
           , converter_name const& convert_param = converter_name()
           )
           {
            typedef ::reflection::property::inspect::pretend::member_class<pretend_name,converter_name,image_name,class_name,storage_name>  member_type;
            return  member_type::make( storage_param, method_param, convert_param );
           }

       }
     }
   }
 }

#endif
