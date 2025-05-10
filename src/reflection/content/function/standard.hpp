#ifndef reflection_content_function_standard_hpp
 #define reflection_content_function_standard_hpp

 // ::reflection::content::function::standard_class<return_name,argument_name...>
 // ::reflection::content::function::standard( )

#include "../../property/function/standard.hpp"

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
        ,typename ...argument_name    
        >
       class standard_class
        : virtual public ::reflection::content::function::pure_class<identifier_name,return_name,argument_name ...>
        ,         public ::reflection::property::function::standard_class<return_name,argument_name ...>
        {
         public:
           typedef return_name    return_type;
         //typedef argument_name...     argument_type...;

           typedef ::reflection::content::function::pure_class<identifier_name,return_name,argument_name...>    content_type;
           typedef ::reflection::property::function::standard_class<return_name,argument_name...   >   property_type;

           typedef typename property_type::function_type function_type;

         public:
           explicit standard_class( function_type function_param ):property_type( function_param ) { }
           virtual ~standard_class( ){}

         public:
           using content_type::signature;
           using content_type::execute;
           using property_type::execute;
        };

      template< typename identifier_name, typename return_name, typename ...argument_name  >
       inline
       ::reflection::content::function::standard_class< identifier_name, return_name, argument_name ... >
       std
        (
         std::function< return_name ( argument_name ... ) > const& function_param
        )
        {
         typedef ::reflection::content::function::standard_class< identifier_name, return_name, argument_name ... > std_type;

         return std_type( function_param );
        }

      }
    }
  }

#endif
