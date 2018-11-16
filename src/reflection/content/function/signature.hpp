#ifndef reflection_content_function_signature
#define reflection_content_function_signature

// ::reflection::content::function::signature_class<identificator_name>

#include "./parameter.hpp"

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

           typedef ::reflection::content::function::parameter_class<identificator_type> parameter_type;

           typedef std::vector< parameter_type >   container_type;
        };

     }
   }
 }

#endif
