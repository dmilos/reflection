#ifndef reflection_content_function_signature
#define reflection_content_function_signature

// ::reflection::content::function::signature_class<identificator_name>


namespace reflection
 {
  namespace content
   {
    namespace function
     {

      template
       <
         typename identificator_name
        >
       class executor_struct
        {
         public:
           typedef identificator_name identificator_type;

           typedef std::vector< identificator_type >   signature_type;
           typedef std::vector< identificator_type >   argument_type;

           static bool process( argument_type & argument_param, signature_type const& signature_param )
            {
             if( false == argument_type::check( argument_param, signature_param ) )
              {
               return false;
              }
            }
        };

     }
   }
 }

#endif
