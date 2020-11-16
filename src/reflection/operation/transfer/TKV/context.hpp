#ifndef  reflection_operation_transfer_tkv_context
#define reflection_operation_transfer_tkv_context

// ::reflection::operation::transfer::tkv::context_struct<size_name>


namespace reflection
 {
  namespace operation
   {
    namespace transfer
     {
      namespace tkv
       {

        template
         <
           typename      size_name = std::size_t
         >
         struct context_struct
          {
           public:
             typedef size_name size_type;

           public:
             size_type size_size=2;
             size_type type_size;
             size_type key_size;
          };

       }
     }
   }
 }

#endif
