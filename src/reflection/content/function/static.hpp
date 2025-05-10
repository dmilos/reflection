#ifndef reflection_content_function_static_hpp
 #define reflection_content_function_static_hpp

 // ::reflection::content::function::static_class<return_name,argument_name...>
 // ::reflection::content::function::static_function( )

#include "../../property/function/static.hpp"

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
        ,typename return_name     = void
        ,typename ... argument_name
        >
       class static_class
        : virtual public ::reflection::content::function::pure_class<identifier_name,return_name,argument_name ...>
        ,         public ::reflection::property::function::static_class<return_name,argument_name ... >
        {
         public:
           typedef return_name    return_type;
           //typedef  argument_name ...     argument_type;


           typedef ::reflection::content::function::pure_class<identifier_name,return_name,argument_name...>    content_type;
           typedef ::reflection::property::function::static_class<return_name, argument_name...>   property_type;

           typedef typename property_type::pointer_type pointer_type;

         public:
           explicit static_class( pointer_type pointer_param ):property_type( pointer_param ) { }
           virtual ~static_class( ){}

         public:
           using content_type::signature;
           using content_type::execute;
           using property_type::execute;
        };

      template< typename identifier_name, typename return_name, typename ... argument_name >
       inline
       ::reflection::content::function::static_class< identifier_name, return_name, argument_name... >
       static_function
        (
         return_name  (*pointer_param)( argument_name ... )
        )
        {
         typedef ::reflection::content::function::static_class< identifier_name, return_name,  argument_name ... > static_type;

         return static_type( pointer_param );
        }

      }
    }
  }

#endif 