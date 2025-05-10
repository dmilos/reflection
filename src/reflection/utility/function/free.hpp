#ifndef reflection_utility_function_free
#define reflection_utility_function_free

// ::reflection::utility::function::free_class<return_name,...>
// ::reflection::utility::function::free<return_name,...>( )

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
        ,typename  ...  argument_name
        >
       class free_class
        : virtual public ::reflection::utility::function::pure_class<return_name,argument_name... >
        {
         public:
           typedef return_name    return_type;
         //typedef argument_name...     argument_type...;

           typedef return_type (*pointer_type)( argument_name ... );

                    free_class( pointer_type pointer_param ):m_pointer(pointer_param) { }
           virtual ~free_class( ){}

           return_type execute( argument_name ... argument_value )const
            {
             return (*m_pointer)( argument_value...  );
            }
          private:
            pointer_type m_pointer;
        };

      template< typename return_name, typename  ...argument_name >
       inline
       ::reflection::utility::function::free_class< return_name, argument_name... >
       free
        (
         return_name (*pointer_param)( argument_name ...  )
        )
        {
         typedef ::reflection::utility::function::free_class< return_name, argument_name... > free_type;

         return free_type( pointer_param );
        }

     }
   }
 }

#endif