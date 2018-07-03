#ifndef reflection_property_inspect_pretend_base
#define reflection_property_inspect_pretend_base

// ::reflection::property::inspect::pretend::base_class<pretend_name,converter_type,storage_name,reader_name>

 #include "../base.hpp"

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
            typedef  storage_name    storage_type;
            typedef  converter_type  convert_type;
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
                mutable reader_type   m_reader;
                mutable convert_type  m_convert;
             } retriever_type;

            typedef ::reflection::property::inspect::base_class<pretend_name,storage_name,retriever_type>      typedef_type;

            static typedef_type make( storage_type const& storage_param, reader_type const& reader_param, convert_type const& convert_param )
             {
              return typedef_type( storage_param, retriever_type( reader_param, convert_param ) );
             }

           };

       }
     }
   }
 }

#endif
