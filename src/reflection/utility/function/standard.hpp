#ifndef reflection_utility_function_standard
#define reflection_utility_function_standard

// ::reflection::utility::function::standard_class<return_name,argument_name...>
// ::reflection::utility::function::standard<return_name,argument_name...>( )

#include "./_pure.hpp"


namespace reflection
 {
  namespace utility
   {
    namespace function
     {

      template
       <
         typename return_name  = void
        ,typename ... argument_name
        >
       class standard_class
        : virtual public ::reflection::utility::function::pure_class<return_name,argument_name ...>
        {
         public:
           typedef return_name    return_type;
         //typedef  argument_name...     argument_type...;

           typedef std::function< return_type( argument_name ... ) > function_type;

                    standard_class( function_type function_param ):m_function(function_param) { }
           virtual ~standard_class( ){}

           return_type execute( argument_name ... args )const
            {
             return m_function( args... );
            }
         private:
           function_type m_function;
        };

      template< typename return_name, typename ... argument_name >
       inline
       ::reflection::utility::function::standard_class< return_name, argument_name ... >
       standard
        (
         std::function< return_name( argument_name ... ) > const& function_param
        )
        {
         typedef ::reflection::utility::function::standard_class< return_name, argument_name ... > standard_type;

         return standard_type( function_param );
        }

     }
   }
 }

#endif