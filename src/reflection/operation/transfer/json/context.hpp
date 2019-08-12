#ifndef reflection_operation_transfer_json_context
#define reflection_operation_transfer_json_context

// ::reflection::operation::transfer::json::context_struct<output_name>



namespace reflection
 {
  namespace operation
   {
    namespace transfer
     {
      namespace json
       {

        //namespace configuration
        // {
        //
        //
        // }

        template
         <
           typename      output_name //!< conect operator << ()
         >
        struct context_struct
         {
          public:
             typedef      output_name        output_type;

           public:
            typedef std::size_t size_type;
            typedef std::string string_type;
            string_type m_tabulator="    ";
            bool   m_skip=false;
            void inc(){ ++m_ident; }
            void dec(){ --m_ident; }
            size_type const& get()const{ return m_ident; }
            void indent( output_type & output_param ){ for( size_type i=0; i< this->get(); ++i ) output_param <<  m_tabulator; }
            void newl( output_type & output_param ){ output_param << std::endl; }
          private:
            size_type m_ident=0;
         };

       }
     }
   }
 }

#endif
