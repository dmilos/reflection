#ifndef reflection_property_mutate_pretend_base
#define reflection_property_mutate_pretend_base

// ::reflection::property::mutate::pretend::basic_class<pretend_name,converter_name,storage_name,writer_name,report_name>

 #include "../base.hpp"

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
           ,typename storage_name
           ,typename writer_name
           ,typename report_name
           >
          struct   basic_class
           {
            typedef  pretend_name    pretend_type;
            typedef  converter_name    converter_type;
            typedef  storage_name    storage_type;
            typedef  writer_name    writer_type;
            typedef   report_name     report_type;

            typedef class assigner_class
             {
              public:

                explicit assigner_class( writer_type const& writer_param, converter_type const& convert_param )
                 :m_writer( writer_param )
                 ,m_convert( convert_param )
                 {
                 }
                report_type operator()( storage_type & storage_param, pretend_type pretend_param )const
                 {
                  return  this->m_writer( storage_param, this->m_convert( pretend_param ) );
                 }
              private:
                mutable writer_type  m_writer;
                mutable converter_type  m_convert;
             } assigner_type;

            typedef ::reflection::property::mutate::basic_class<pretend_name,storage_name,assigner_type,report_name>      typedef_type;

            static typedef_type make( storage_type const& storage_param, writer_type const& writer_param, converter_type const& convert_param )
                   {
                    return typedef_type( storage_param, assigner_type( writer_param, convert_param ) );
                   }

           };

       }
     }
   }
 }

#endif
