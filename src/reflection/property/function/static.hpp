#ifndef reflection_property_function_static
#define reflection_property_function_static

// ::reflection::property::function::static_class<return_name,first_name,second_name,third_name,fourth_name,fifth_name>
// ::reflection::property::function::static<return_name,first_name,second_name,third_name,fourth_name,fifth_name>( )

#include "../_pure.hpp"

#include "../../ornament/accessibility.hpp"
#include "../../utility/function/static.hpp"

namespace reflection
 {
  namespace property
   {
    namespace function
     {

      template
       <
         typename return_name = void
        ,typename first_name  = void
        ,typename second_name = void
        ,typename third_name  = void
        ,typename fourth_name = void
        ,typename fifth_name  = void
        >
       class static_class
        : virtual public ::reflection::property::function::pure_class<return_name,first_name,second_name,third_name,fourth_name,fifth_name>
        ,         public ::reflection::utility::function::static_class<return_name,first_name,second_name,third_name,fourth_name,fifth_name>
        , virtual public ::reflection::ornament::accessibility_class
        , virtual public ::reflection::ornament::qualification_class
        {
         public:
           typedef return_name    return_type;
           typedef  first_name     first_type;
           typedef second_name    second_type;
           typedef  third_name     third_type;
           typedef fourth_name    fourth_type;
           typedef  fifth_name     fifth_type;

           typedef ::reflection::utility::function::static_class<return_name,first_name,second_name,third_name,fourth_name,fifth_name> utility_type;
           typedef typename    utility_type::pointer_type pointer_type;

                    static_class( pointer_type pointer_param ):utility_type(pointer_param) { }
           virtual ~static_class( ){}

         public:
          return_type  execute( first_name first, second_name second, third_name third, fourth_name fourth, fifth_name fifth  )const
           {
            return utility_type::execute( first, second, third, fourth, fifth );
           }
        };


      template< typename return_name, typename first_name, typename second_name, typename third_name, typename fourth_name >
       class static_class<return_name,first_name,second_name,third_name,fourth_name,void>
        : virtual public ::reflection::property::function::pure_class<return_name,first_name,second_name,third_name,fourth_name>
        ,         public ::reflection::utility::function::static_class<return_name,first_name,second_name,third_name,fourth_name>
        , virtual public ::reflection::ornament::accessibility_class
        , virtual public ::reflection::ornament::qualification_class 
        {
         public:

           typedef return_name    return_type;
           typedef  first_name     first_type;
           typedef second_name    second_type;
           typedef  third_name     third_type;
           typedef fourth_name    fourth_type;

           typedef ::reflection::utility::function::static_class<return_name,first_name,second_name,third_name,fourth_name> utility_type;
           typedef typename    utility_type::pointer_type pointer_type;

                    static_class( pointer_type pointer_param ):utility_type(pointer_param) { }
           virtual ~static_class( ){}

         public:
          return_type  execute( first_name first, second_name second, third_name third, fourth_name fourth )const
           {
            return utility_type::execute( first, second, third, fourth );
           }
        };

      template< typename return_name, typename first_name, typename second_name, typename third_name >
       class static_class<return_name,first_name,second_name,third_name,void,void>
        : virtual public ::reflection::property::function::pure_class<return_name,first_name,second_name,third_name>
        ,         public ::reflection::utility::function::static_class<return_name,first_name,second_name,third_name>
        , virtual public ::reflection::ornament::accessibility_class
        , virtual public ::reflection::ornament::qualification_class 
        {
         public:

           typedef return_name    return_type;
           typedef  first_name     first_type;
           typedef second_name    second_type;
           typedef  third_name     third_type;

           typedef ::reflection::utility::function::static_class<return_name,first_name,second_name,third_name> utility_type;
           typedef typename    utility_type::pointer_type pointer_type;

                    static_class( pointer_type pointer_param ):utility_type(pointer_param) { }
           virtual ~static_class( ){}

         public:
          return_type  execute( first_name first, second_name second, third_name third )const
           {
            return utility_type::execute( first, second, third );
           }
        };

      template< typename return_name, typename first_name, typename second_name >
       class static_class<return_name,first_name,second_name,void,void,void>
        : virtual public ::reflection::property::function::pure_class<return_name,first_name,second_name>
        ,         public ::reflection::utility::function::static_class<return_name,first_name,second_name>
        , virtual public ::reflection::ornament::accessibility_class
        , virtual public ::reflection::ornament::qualification_class 
        {
         public:

           typedef return_name    return_type;
           typedef  first_name     first_type;
           typedef second_name    second_type;

           typedef ::reflection::utility::function::static_class<return_name,first_name,second_name> utility_type;
           typedef typename    utility_type::pointer_type pointer_type;

                    static_class( pointer_type pointer_param ):utility_type(pointer_param) { }
           virtual ~static_class( ){}

         public:
          return_type  execute( first_name first, second_name second )const
           {
            return utility_type::execute( first, second );
           }
        };


      template< typename return_name, typename first_name >
       class static_class<return_name,first_name,void,void,void,void>
        : virtual public ::reflection::property::function::pure_class<return_name,first_name>
        ,         public ::reflection::utility::function::static_class<return_name,first_name>
        , virtual public ::reflection::ornament::accessibility_class
        , virtual public ::reflection::ornament::qualification_class 
        {
         public:

           typedef return_name    return_type;
           typedef  first_name     first_type;

           typedef ::reflection::utility::function::static_class<return_name,first_name> utility_type;
           typedef typename    utility_type::pointer_type pointer_type;

                    static_class( pointer_type pointer_param ):utility_type(pointer_param) { }
           virtual ~static_class( ){}

         public:
          return_type  execute( first_type first )const
           {
            return utility_type::execute( first );
           }
        };

      template< typename return_name >
       class static_class<return_name,void,void,void,void,void>
        : virtual public ::reflection::property::function::pure_class<return_name>
        ,         public ::reflection::utility::function::static_class<return_name>
        , virtual public ::reflection::ornament::accessibility_class
        , virtual public ::reflection::ornament::qualification_class 
        {
         public:

           typedef return_name    return_type;

           typedef ::reflection::utility::function::static_class<return_name> utility_type;
           typedef typename    utility_type::pointer_type pointer_type;

                    static_class( pointer_type pointer_param ):utility_type(pointer_param) { }
           virtual ~static_class( ){}

         public:
          return_name  execute()const
           {
            return utility_type::execute();
           }
        };

      template< typename return_name >
       inline
       ::reflection::property::function::static_class<return_name,void,void,void,void,void>
       static_function
        (
         return_name (*pointer_param)()
        )
        {
         typedef ::reflection::property::function::static_class<return_name, void, void, void, void, void > static_type;

         return static_type( pointer_param );
        }

      template< typename return_name, typename first_name >
       inline
       ::reflection::property::function::static_class< return_name, first_name,void,void,void,void >
       static_function
        (
         return_name  (*pointer_param)( first_name )
        )
        {
         typedef ::reflection::property::function::static_class< return_name, first_name, void, void, void, void > static_type;

         return static_type( pointer_param );
        }

      template< typename return_name, typename first_name, typename second_name >
       inline
       ::reflection::property::function::static_class< return_name, first_name, second_name,void,void,void>
       static_function
        (
         return_name  (*pointer_param)( first_name, second_name )
        )
        {
         typedef ::reflection::property::function::static_class< return_name, first_name, second_name, void, void, void > static_type;

         return static_type( pointer_param );
        }

      template< typename return_name, typename first_name, typename second_name, typename third_name >
       inline
       ::reflection::property::function::static_class< return_name, first_name, second_name, third_name,void,void>
       static_function
        (
         return_name  (*pointer_param)( first_name, second_name, third_name )
        )
        {
         typedef ::reflection::property::function::static_class< return_name, first_name, second_name, third_name, void, void > static_type;

         return static_type( pointer_param );
        }

      template< typename return_name, typename first_name, typename second_name, typename third_name, typename fourth_name >
       inline
       ::reflection::property::function::static_class< return_name, first_name, second_name, third_name, fourth_name,void>
       static_function
        (
         return_name  (*pointer_param)( first_name, second_name, third_name, fourth_name )
        )
        {
         typedef ::reflection::property::function::static_class< return_name, first_name, second_name, third_name, fourth_name, void > static_type;

         return static_type( pointer_param );
        }

      template< typename return_name, typename first_name, typename second_name, typename third_name, typename fourth_name, typename fifth_name >
       inline
       ::reflection::property::function::static_class< return_name, first_name, second_name, third_name, fourth_name, fifth_name >
       static_function
        (
         return_name (*pointer_param)( first_name, second_name, third_name, fourth_name, fifth_name )
        )
        {
         typedef ::reflection::property::function::static_class< return_name, first_name, second_name, third_name, fourth_name, fifth_name > static_type;

         return static_type( pointer_param );
        }

     }
   }
 }

#endif