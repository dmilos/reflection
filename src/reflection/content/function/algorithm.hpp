#ifndef reflection_content_function_algorithm_hpp
 #define reflection_content_function_algorithm_hpp

 // ::reflection::content::function::algorithm_class<identifier_name>
 // ::reflection::content::function::check<identifier_name>
 // ::reflection::content::function::execute<identifier_name>

#include "../../type/name/id.hpp"
#include "../../property/function/_pure.hpp"

#include "../_pure.hpp"

#include "./signature.hpp"
#include "./context.hpp"
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
       class algorithm_class
        : virtual public ::reflection::content::pure_class< identifier_name >
        , virtual public ::reflection::content::function::context_class<identifier_name>
        {
         public:
           typedef identifier_name identifier_type;

           typedef ::reflection::content::pure_class< identifier_name >        content_type;
           typedef ::reflection::content::function::context_class<identifier_type>   context_type;

           typedef::reflection::content::function::algorithm_class<identifier_name> algorithm_type;

           typedef ::reflection::type::name::identificatorX< identifier_type > identificator_type;

           typedef typename ::reflection::content::function::signature_struct<identifier_type>::container_type     signature_type;
           typedef typename ::reflection::content::function::argument_struct<identifier_type>                       argument_type;
           typedef typename ::reflection::content::function::argument_struct<identifier_type>::container_type      parameter_type;

         public:
           algorithm_class()
            : content_type( identificator_type::template get<algorithm_type>() )
            {
            }

         public:
           using context_type::execute;
        };


      template< typename identifier_type >
       inline
       bool
       check
       (
         ::reflection::property::pure_class & property_param
       )
       {
        typedef ::reflection::content::function::context_class<identifier_type>   context_type;

        return nullptr != dynamic_cast< context_type *>( property_param );
       }

      template< typename identifier_type >
       inline
       bool
       execute
       (
         ::reflection::property::pure_class & property_param
        ,typename ::reflection::content::function::argument_struct<identifier_type>::container_type & parameter_param
       )
       {
        typedef ::reflection::content::function::context_class<identifier_type>   context_type;

        return dynamic_cast< context_type &>( property_param ).execute( parameter_param );
       }

      }
    }
  }

#endif