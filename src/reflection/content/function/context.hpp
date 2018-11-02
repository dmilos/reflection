#ifndef reflection_content_function_context
#define reflection_content_function_context

// ::reflection::content::function::context_class<identifier_name>

#include "./signature.hpp"
#include "./argument.hpp"

namespace reflection
 {
  namespace content
   {
    namespace function
     {

      template
       <
         typename identifier_name
        >
       class context_class
        {
         public:
           typedef identifier_name identifier_type;

           typedef typename ::reflection::content::function::signature_struct<identifier_type>::container_type   signature_type;
           typedef typename ::reflection::content::function::argument_struct<identifier_type>::container_type     argument_type;

         public:
           virtual bool execute( argument_type & argument_param )const=0;

         public:
           signature_type const& signature()const{ return m_signature; }
         protected:
           signature_type      & signature(){ return m_signature; }
         private:
           signature_type m_signature;

        };

     }
   }
 }

#endif
