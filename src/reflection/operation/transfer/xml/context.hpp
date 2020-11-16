#ifndef reflection_operation_transfer_xml_context
#define reflection_operation_transfer_xml_context

// ::reflection::operation::transfer::xml::context_struct<output_name>

#include "../context.hpp"
#include "../_common/indenting.hpp"
#include "./attribute.hpp"
#include "./tag.hpp"

namespace reflection
 {
  namespace operation
   {
    namespace transfer
     {
      namespace xml
       {

        template
         <
           typename      output_name
          ,typename      string_name
         >
        struct context_struct 
         : public ::reflection::operation::transfer::context_struct<output_name,string_name> 
         {
          public:
            typedef output_name output_type;
            typedef string_name string_type;

            typedef ::reflection::operation::transfer::_common::indenting_class<        output_type, string_type>      indent_type;
            typedef ::reflection::operation::transfer::xml::_common::attribute_struct<  output_type, string_type>   attribute_type;
            typedef ::reflection::operation::transfer::xml::_common::tag_struct<        output_type, string_type>         tag_type;

            indent_type m_indent;

            tag_type m_intro   ={ true, "xml"};
            tag_type m_element ={ true, "e"  };
            tag_type m_item    ={ true, "i"  };

            attribute_type m_identifier     ={ true, "i", "" };

            tag_type m_remark  ={ true, "r"   };
            tag_type m_note    ={ true, "note"};
         };

       }
     }
   }
 }

#endif
