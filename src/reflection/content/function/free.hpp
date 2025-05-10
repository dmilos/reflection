#ifndef reflection_content_function_free_hpp
 #define reflection_content_function_free_hpp

 // ::reflection::content::function::free_class<return_name,argument_name ...>
 // ::reflection::content::function::free( )

#include "../../property/function/free.hpp"

#include "./_pure.hpp"


namespace reflection
 {
  namespace content
   {
    namespace function
     {

      template
       <
         typename identifier_name
        ,typename return_name
        ,typename ... argument_name
        >
       class free_class
        : virtual public ::reflection::content::function::pure_class<identifier_name,return_name, argument_name ... >
        ,         public ::reflection::property::function::free_class<return_name, argument_name ...>
        {
         public:
           typedef return_name    return_type;
         //typedef  ... argument_name;

           typedef ::reflection::content::function::pure_class<identifier_name,return_name,argument_name ...>    content_type;
           typedef ::reflection::property::function::free_class<return_name, argument_name ... >   property_type;

           typedef typename property_type::pointer_type pointer_type;

         public:
           explicit free_class( pointer_type pointer_param ):property_type( pointer_param ) { }
           virtual ~free_class( ){}

         public:
           using content_type::signature;
           using content_type::execute;
           using property_type::execute;
        };

      template< typename identifier_name, typename return_name, typename ... argument_name  >
       inline
       ::reflection::content::function::free_class< identifier_name, return_name, argument_name ... >
       free
        (
         return_name (*pointer_param)( argument_name ... )
        )
        {
         typedef ::reflection::content::function::free_class< identifier_name, return_name, argument_name ... > free_type;

         return free_type( pointer_param );
        }

      }
    }
  }

#endif
