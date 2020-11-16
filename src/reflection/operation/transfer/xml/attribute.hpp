#ifndef reflection_operation_transfer_xml_attribute
#define reflection_operation_transfer_xml_attribute

// ::reflection::operation::transfer::xml::_common::attribute_struct<string_type>

namespace reflection
 {
  namespace operation
   {
    namespace transfer
     {
      namespace xml
       {
        namespace _common
         {

          template
           <
             typename      output_name
            ,typename      string_name
           >
          struct attribute_struct
           {
            public:
              typedef string_name    string_type;
              typedef output_name   output_type;

               typedef ::reflection::operation::transfer::xml::_common::attribute_struct<output_name,string_name> this_type;

              bool        m_show;
              string_type m_name;
              string_type m_content;

              this_type & content( string_type const& c )
               {
                m_content = c;
                return *this;
               }

              void print( output_type & output_param ) const
               {
                output_param << m_name << "=\"" << m_content << "\" ";
               }

              template
               <
                 typename      type_name
               >
              this_type & print( output_type & output_param, type_name const& content_param )
               {
                output_param << this->m_name << "=\"" << content_param << "\" ";
                return *this;
               }

           };

         }
       }
     }
   }
 }

#endif
