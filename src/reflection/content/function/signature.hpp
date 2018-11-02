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
       //,typename name_name
        >
       class signature_struct
        {
         public:
           typedef identificator_name identificator_type;

           //typedef name_name                   name_type;
           //typedef std::pair< identificator_type, name_type > parameter_type;
           //typedef std::vector< parameter_type >   signature_type;

           typedef std::vector< identificator_type >   container_type;
        };

     }
   }
 }

#endif
