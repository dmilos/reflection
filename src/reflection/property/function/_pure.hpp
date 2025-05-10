#ifndef reflection_property_function_base
#define reflection_property_function_base

// ::reflection::property::function::pure_class<return_name,argument_name...>
// ::reflection::property::function::check<return_name,argument_name...>()
// ::reflection::property::function::execute<return_name,argument_name...>()

#include "./_pure.hpp"
#include "../../utility/function/_pure.hpp"
#include "../../ornament/linkage.hpp"

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
       class pure_class
        : virtual public ::reflection::utility::function::pure_class<return_name, argument_name ... >
        , virtual public ::reflection::property::pure_class
        , virtual public ::reflection::ornament::linkage_class
        {
         public:
           typedef return_name    return_type;
         //typedef  argument_name     argument_name;

                    pure_class(){}
           virtual ~pure_class(){}

           virtual return_name execute( argument_name ... args )const=0;
         //virtual return_name execute( argument_name ... args )const=0;
        };

      template< typename return_name, typename ... argument_name >
       inline bool check( ::reflection::property::pure_class const& property_param )
        {
         typedef ::reflection::property::function::pure_class<return_name, argument_name ...> function_type;
         return nullptr != dynamic_cast< function_type const*>( &property_param );
        }

      template< typename return_name, typename ... argument_name >
       inline
       return_name
       execute( ::reflection::property::pure_class & property_param, argument_name ... args )
        {
         typedef ::reflection::property::function::pure_class<return_name,argument_name ... > function_type;

         return dynamic_cast< function_type &>( property_param ).execute( args...   );
        }

     }
   }
 }

#endif
