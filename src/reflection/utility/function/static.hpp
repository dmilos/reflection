#ifndef reflection_utility_function_static
#define reflection_utility_function_static

// ::reflection::utility::function::static_class<return_name,...>
// ::reflection::utility::function::static<return_name,...>( )

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
       class static_class
        : virtual public ::reflection::utility::function::pure_class<return_name,argument_name... >
        {
         public:
           typedef return_name    return_type;
         //typedef argument_name...     argument_type...;

           typedef return_type (*pointer_type)( argument_name ... );

                    static_class( pointer_type pointer_param ):m_pointer(pointer_param) { }
           virtual ~static_class( ){}

           return_type execute( argument_name ... argument_value )const
            {
             return (*m_pointer)(argument_value...  );
            }
          private:
            pointer_type m_pointer;
        };

      template< typename return_name, typename  ...argument_name >
       inline
       ::reflection::utility::function::static_class< return_name, argument_name... >
       static_function
        (
         return_name (*pointer_param)( argument_name ... )
        )
        {
         typedef ::reflection::utility::function::static_class< return_name, argument_name... > static_type;
         return static_type( pointer_param );
        }

     }
   }
 }

#endif