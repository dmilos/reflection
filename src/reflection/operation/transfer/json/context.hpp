#ifndef reflection_operation_transfer_json_context
#define reflection_operation_transfer_json_context

// ::reflection::operation::transfer::json::context_struct<output_name>

#include "../_common/indenting.hpp"

namespace reflection
 {
  namespace operation
   {
    namespace transfer
     {
      namespace json
       {

        namespace configuration
         {

          template
           <
             typename      string_name //!< conect operator << ()
           >
           struct keys_struct
            {
             public:
               typedef string_name string_type;
               string_type   m_value   = "value";
               string_type   m_type    = "type";
               string_type   m_ordinal = "ordinal";
               string_type   m_name    = "name";
               string_type   m_object  = "object";
               string_type   m_note    = "note";
            };

         }

        template
         <
           typename      string_name //!< conect operator << ()
         >
        struct context_input_struct
         {
          public:
            typedef string_name string_type;
            typedef ::reflection::operation::transfer::json::configuration::keys_struct<string_type>        keys_type;
            keys_type m_key;
         };

        template
         <
           typename      output_name //!< conect operator << ()
          ,typename         key_name //!< conect operator << ()
          ,typename      string_name //!< conect operator << ()
         >
        struct context_struct
         {
          public:

            typedef output_name output_type;
            typedef key_name       key_type;
            typedef string_name string_type;

            typedef std::size_t size_type;

            typedef ::reflection::operation::transfer::_common::indenting_class<output_type, string_type>        indent_type;

            typedef ::reflection::operation::transfer::json::configuration::keys_struct<string_type>        keys_type;
            keys_type m_key;

            struct names_struct
             {
              string_type   m_qualification = "qualification";
              string_type   m_volatile      = "volatile";
              string_type   m_derivation    = "derivation";
              string_type   m_relation      = "relation";
              string_type   m_note          = "note";
              string_type   m_linkage       = "linkage";
              string_type   m_accessibility = "accessibility";
             }m_name;

            struct message_struct
             {
              string_type  m_CnRtV = "Can not retrieve the value.";
              string_type  m_NaS   = "Not a structure.";
              string_type  m_CnDT  = "Can not detect type" ;
              string_type  m_GR    = "General recovery.";
             }m_message;

           public:
             bool        m_skip=false;
             indent_type m_indent;
             key_type    m_invisibleKey = "$<<internal-invisible-key>>$";
         };

       }
     }
   }
 }

#endif
