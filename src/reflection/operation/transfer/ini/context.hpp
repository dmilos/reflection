#ifndef reflection_operation_transfer_ini_context
#define reflection_operation_transfer_ini_context

// ::reflection::operation::transfer::ini::context_struct<string_name>



namespace reflection
 {
  namespace operation
   {
    namespace transfer
     {
      namespace ini
       {

        template
         <
          typename      string_name //!< connect operator << ()
         >
        struct context_struct
         {
          public:

            typedef std::size_t size_type;
            typedef string_name string_type;

            bool m_isStructure = false;
         };

       }
     }
   }
 }

#endif
