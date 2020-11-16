#ifndef reflection_operation_transfer_context
#define reflection_operation_transfer_context

// ::reflection::operation::transfer::context_struct<output_name,string_name>





namespace reflection
 {
  namespace operation
   {
    namespace transfer
     {

      template
       <
         typename      output_name
        ,typename      string_name
       >
      struct context_struct
       {
        public:
          typedef output_name output_type;
          typedef string_name string_type;
       };

     }
   }
 }

#endif
