#ifndef reflection_operation_transfer_xml_tag
#define reflection_operation_transfer_xml_tag

// ::reflection::operation::transfer::xml::_common::tag_struct<string_type,output_param>

#include "./attribute.hpp"

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
           struct tag_struct
            {
             public:
               typedef string_name    string_type;
               typedef output_name   output_type;

               typedef ::reflection::operation::transfer::xml::_common::attribute_struct<output_name,string_type> attribute_type;

               bool        m_show;
               string_type m_name;

               template< bool open_bool = false >
                void open( output_type & output_param )
                 {
                  output_param << "<" << this->m_name <<" ";
                  if( false == open_bool ) output_param << ">";
                 }

               template< bool open_bool = false >
                void open( output_type & output_param , attribute_type const& a1 )
                 {
                  output_param << "<" << this->m_name <<" ";
                  a1.print( output_param );
                  if( false == open_bool ) output_param << ">";
                 }

               template< bool open_bool = false >
                void open( output_type & output_param, attribute_type const& a1, attribute_type const& a2 )
                 {
                  output_param << "<" << this->m_name << " ";
                  a1.print( output_param );
                  a2.print( output_param );
                  if( false == open_bool ) output_param << ">";
                 }

                void close( output_type & output_param )
                 {
                  output_param <<  "</"<< this->m_name << ">" ;
                 }

                void single( output_type & output_param )const
                 {
                  output_param << "<" << this->m_name <<"/>";
                 }

                void single( output_type & output_param , attribute_type const& a1 )const
                 {
                  output_param << "<" << this->m_name <<" ";
                  a1.print( output_param );
                  output_param << "/>";
                 }

                void single( output_type & output_param, attribute_type const& a1, attribute_type const& a2 )const
                 {
                  output_param << "<" << this->m_name << " ";
                  a1.print( output_param );
                  a2.print( output_param );
                  output_param << "/>";
                 }
            };

         }
       }
     }
   }
 }

#endif
