#ifndef reflection_property_function_standard
#define reflection_property_function_standard

// ::reflection::property::function::standard_class<return_name,argument_name ...>
// ::reflection::property::function::standard<return_name,argument_name ...>( )

#include "../_pure.hpp"
#include "../../utility/function/standard.hpp"


namespace reflection
 {
  namespace property
   {
    namespace function
     {

      template
       <
         typename return_name  
        ,typename ... argument_name  
         >
       class standard_class
        : virtual public ::reflection::property::function::pure_class<return_name,argument_name ... >
        ,         public ::reflection::utility::function::standard_class<return_name,argument_name ... >
        , virtual public ::reflection::ornament::accessibility_class
        , virtual public ::reflection::ornament::qualification_class 
        {
         public:
           typedef return_name    return_type;
           //typedef argument_name...     argument_type...;

           typedef ::reflection::utility::function::standard_class<return_name, argument_name... > utility_type;
           typedef typename    utility_type::function_type function_type;

                    standard_class( function_type function_param ):utility_type(function_param) { }
           virtual ~standard_class( ){}

         public:
          return_type  execute( argument_name ...args )const
           {
            return utility_type::execute( args... );
           }
        };
 
      template< typename return_name, typename ... argument_name >
       inline
       ::reflection::property::function::standard_class< return_name, argument_name ... >
       standard
        (
         std::function< return_name ( argument_name ... ) > const& function
        )
        {
         typedef ::reflection::property::function::standard_class< return_name, argument_name ... > standard_type;

         return standard_type( function );
        }

     }
   }
 }

#endif
