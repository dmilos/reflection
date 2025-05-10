#ifndef reflection_property_function_free
#define reflection_property_function_free

// ::reflection::property::function::free_class<return_name,argument_name...>
// ::reflection::property::function::free<return_name, argument_name... >( )

#include "../_pure.hpp"
#include "../../utility/function/free.hpp"


namespace reflection
 {
  namespace property
   {
    namespace function
     {

      template
       <
         typename return_name = void
        ,typename ...argument_name
        >
       class free_class
        : virtual public ::reflection::property::function::pure_class<return_name,argument_name...>
        ,         public ::reflection::utility::function::free_class<return_name,argument_name...>
        , virtual public ::reflection::ornament::accessibility_class
        , virtual public ::reflection::ornament::qualification_class
        {
         public:
           typedef return_name    return_type;
         //typedef argument_name...     argument_type...;
 
           typedef ::reflection::utility::function::free_class<return_name,argument_name...> utility_type;
           typedef typename    utility_type::pointer_type pointer_type;

                    free_class( pointer_type pointer_param ):utility_type(pointer_param) { }
           virtual ~free_class( ){}

         public:
          return_type  execute( argument_name ...args )const
           {
            return utility_type::execute( args... );
           }
        };


      template< typename return_name, typename ...argument_name >
       inline
       ::reflection::property::function::free_class< return_name, argument_name ... >
       free
        (
         return_name (*pointer_param)( argument_name ... )
        )
        {
         typedef ::reflection::property::function::free_class< return_name, argument_name ...> free_type;

         return free_type( pointer_param );
        }

     }
   }
 }

#endif