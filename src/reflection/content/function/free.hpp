#ifndef reflection_content_function_free_hpp
 #define reflection_content_function_free_hpp

 // ::reflection::content::function::free_class<return_name,first_name,second_name,third_name,fourth_name,fifth_name>
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
        ,typename return_name     = void
        ,typename first_name      = void
        ,typename second_name     = void
        ,typename third_name      = void
        ,typename fourth_name     = void
        ,typename fifth_name      = void
        >
       class free_class
        : virtual public ::reflection::content::function::pure_class<identifier_name,return_name,first_name,second_name,third_name,fourth_name,fifth_name>
        ,         public ::reflection::property::function::free_class<return_name,first_name,second_name,third_name,fourth_name,fifth_name>
        {
         public:
           typedef return_name    return_type;
           typedef  first_name     first_type;
           typedef second_name    second_type;
           typedef  third_name     third_type;
           typedef fourth_name    fourth_type;
           typedef  fifth_name     fifth_type;

           typedef ::reflection::content::function::pure_class<identifier_name,return_name,first_name,second_name,third_name,fourth_name,fifth_name>    content_type;
           typedef ::reflection::property::function::free_class<return_name,first_name,second_name,third_name,fourth_name,fifth_name   >   property_type;

           typedef typename property_type::pointer_type pointer_type;

         public:
           explicit free_class( pointer_type pointer_param ):property_type( pointer_param ) { }
           virtual ~free_class( ){}

         public:
           using content_type::signature;
           using content_type::execute;
           using property_type::execute;
        };

      template< typename identifier_name, typename return_name, typename first_name, typename second_name, typename third_name, typename fourth_name >
       class free_class<identifier_name,return_name,first_name,second_name,third_name,fourth_name,void>
        : virtual public ::reflection::content::function::pure_class<identifier_name,return_name,first_name,second_name,third_name,fourth_name>
        ,         public ::reflection::property::function::free_class<return_name,first_name,second_name,third_name,fourth_name>
        {
         public:
           typedef return_name    return_type;
           typedef  first_name     first_type;
           typedef second_name    second_type;
           typedef  third_name     third_type;
           typedef fourth_name    fourth_type;

           typedef ::reflection::content::function::pure_class<identifier_name,return_name,first_name,second_name,third_name,fourth_name>    content_type;
           typedef ::reflection::property::function::free_class<return_name,first_name,second_name,third_name,fourth_name>   property_type;

           typedef typename property_type::pointer_type pointer_type;

         public:
           explicit free_class( pointer_type pointer_param ):property_type( pointer_param ) { }
           virtual ~free_class( ){}

         public:
           using content_type::signature;
           using content_type::execute;
           using property_type::execute;
        };

      template< typename identifier_name, typename return_name, typename first_name, typename second_name, typename third_name >
       class free_class<identifier_name,return_name,first_name,second_name,third_name,void,void>
        : virtual public ::reflection::content::function::pure_class<identifier_name,return_name,first_name,second_name,third_name>
        ,         public ::reflection::property::function::free_class<return_name,first_name,second_name,third_name>
        {
         public:
           typedef return_name    return_type;
           typedef  first_name     first_type;
           typedef second_name    second_type;
           typedef  third_name     third_type;

           typedef ::reflection::content::function::pure_class<identifier_name,return_name,first_name,second_name,third_name>              content_type;
           typedef ::reflection::property::function::free_class<return_name,first_name,second_name,third_name>   property_type;

           typedef typename property_type::pointer_type pointer_type;

         public:
           explicit free_class( pointer_type pointer_param ):property_type( pointer_param ) { }
           virtual ~free_class( ){}

         public:
           using content_type::signature;
           using content_type::execute;
           using property_type::execute;
        };

      template< typename identifier_name, typename return_name, typename first_name, typename second_name >
       class free_class<identifier_name,return_name,first_name,second_name,void,void,void>
        : virtual public ::reflection::content::function::pure_class<identifier_name,return_name,first_name,second_name >
        ,         public ::reflection::property::function::free_class<return_name,first_name,second_name >
        {
         public:
           typedef return_name    return_type;
           typedef  first_name     first_type;
           typedef second_name    second_type;

           typedef ::reflection::content::function::pure_class<identifier_name,return_name,first_name,second_name >              content_type;
           typedef ::reflection::property::function::free_class<return_name,first_name,second_name >   property_type;

           typedef typename property_type::pointer_type pointer_type;

         public:
           explicit free_class( pointer_type pointer_param ):property_type( pointer_param ) { }
           virtual ~free_class( ){}

         public:
           using content_type::signature;
           using content_type::execute;
           using property_type::execute;
        };

      template< typename identifier_name, typename return_name, typename first_name >
       class free_class<identifier_name,return_name,first_name,void,void,void,void>
        : virtual public ::reflection::content::function::pure_class<identifier_name,return_name,first_name>
        ,         public ::reflection::property::function::free_class<return_name,first_name>
        {
         public:
           typedef return_name    return_type;
           typedef  first_name     first_type;

           typedef ::reflection::content::function::pure_class<identifier_name,return_name,first_name>                content_type;
           typedef ::reflection::property::function::free_class<return_name,first_name>   property_type;

           typedef typename property_type::pointer_type pointer_type;

         public:
           explicit free_class( pointer_type pointer_param ):property_type( pointer_param ) { }
           virtual ~free_class( ){}

         public:
           using content_type::signature;
           using content_type::execute;
           using property_type::execute;
        };

      template< typename identifier_name, typename return_name >
       class free_class<identifier_name,return_name,void,void,void,void,void>
        : virtual public ::reflection::content::function::pure_class<identifier_name,return_name>
        ,         public ::reflection::property::function::free_class<return_name>
        {
         public:
           typedef return_name    return_type;

           typedef ::reflection::content::function::pure_class<identifier_name,return_name>                content_type;
           typedef ::reflection::property::function::free_class<return_name>   property_type;

           typedef typename property_type::pointer_type pointer_type;

         public:
           explicit free_class( pointer_type pointer_param ):property_type( pointer_param ) { }
           virtual ~free_class( ){}

         public:
           using content_type::signature;
           using content_type::execute;
           using property_type::execute;
        };

      template< typename identifier_name, typename return_name >
       inline
       ::reflection::content::function::free_class<identifier_name, return_name>
       free
        (
         return_name (*pointer_param)()
        )
        {
         typedef ::reflection::content::function::free_class<identifier_name, return_name > free_type;

         return free_type( pointer_param );
        }

      template< typename identifier_name, typename return_name, typename first_name >
       inline
       ::reflection::content::function::free_class< identifier_name, return_name, first_name >
       free
        (
         return_name  (*pointer_param)( first_name )
        )
        {
         typedef ::reflection::content::function::free_class< identifier_name, return_name, first_name > free_type;

         return free_type( pointer_param );
        }

      template< typename identifier_name, typename return_name, typename first_name, typename second_name >
       inline
       ::reflection::content::function::free_class< identifier_name, return_name, first_name, second_name >
       free
        (
         return_name  (*pointer_param)( first_name, second_name )
        )
        {
         typedef ::reflection::content::function::free_class< identifier_name,return_name, first_name, second_name  > free_type;

         return free_type( pointer_param );
        }

      template< typename identifier_name, typename return_name, typename first_name, typename second_name, typename third_name >
       inline
       ::reflection::content::function::free_class< identifier_name, return_name, first_name, second_name, third_name >
       free
        (
         return_name  (*pointer_param)( first_name, second_name, third_name )
        )
        {
         typedef ::reflection::content::function::free_class< identifier_name,return_name, first_name, second_name, third_name > free_type;

         return free_type( pointer_param );
        }

      template< typename identifier_name, typename return_name, typename first_name, typename second_name, typename third_name, typename fourth_name >
       inline
       ::reflection::content::function::free_class< identifier_name, return_name, first_name, second_name, third_name, fourth_name >
       free
        (
         return_name  (*pointer_param)( first_name, second_name, third_name, fourth_name )
        )
        {
         typedef ::reflection::content::function::free_class< identifier_name, return_name, first_name, second_name, third_name, fourth_name, void > free_type;

         return free_type( pointer_param );
        }

      template< typename identifier_name, typename return_name, typename first_name, typename second_name, typename third_name, typename fourth_name, typename fifth_name >
       inline
       ::reflection::content::function::free_class< identifier_name, return_name, first_name, second_name, third_name, fourth_name, fifth_name >
       free
        (
         return_name (*pointer_param)( first_name, second_name, third_name, fourth_name, fifth_name )
        )
        {
         typedef ::reflection::content::function::free_class< identifier_name, return_name, first_name, second_name, third_name, fourth_name, fifth_name > free_type;

         return free_type( pointer_param );
        }

      }
    }
  }

#endif
