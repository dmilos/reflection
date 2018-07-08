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
         typename return_name
        ,typename first_name
        ,typename second_name
        ,typename third_name
        ,typename fourth_name
        ,typename fifth_name
        >
       class free_class
        : virtual public ::reflection::content::function::pure_class<return_name,first_name,second_name,third_name,fourth_name,fifth_name>
        ,         public ::reflection::property::function::free_class<return_name,first_name,second_name,third_name,fourth_name,fifth_name>
        {
         public:
           typedef return_name    return_type;
           typedef  first_name     first_type;
           typedef second_name    second_type;
           typedef  third_name     third_type;
           typedef fourth_name    fourth_type;
           typedef  fifth_name     fifth_type;

           typedef ::reflection::content::function::pure_class<return_name,first_name,second_name,third_name,fourth_name,fifth_name>    content_type;
           typedef ::reflection::property::function::free_class<return_name,first_name,second_name,third_name,fourth_name,fifth_name   >   free_type;

           typedef typename free_type::function_type function_type;

         public:
                    free_class( function_type function_param ):free_type( function_param ) { }
           virtual ~free_class( ){}

         public:
           return_type execute( first_name first, second_name second, third_name third, fourth_name fourth, fifth_name fifth )
            {
             return this->free_type::execute( first, second, third, fourth, fifth );
            }
           using content_type::signature;

        };

      template< typename return_name, typename first_name, typename second_name, typename third_name, typename fourth_name >
       class free_class<return_name,first_name,second_name,third_name,fourth_name,void>
        : virtual public ::reflection::content::function::pure_class<return_name,first_name,second_name,third_name,fourth_name,void>
        ,         public ::reflection::property::function::free_class<return_name,first_name,second_name,third_name,fourth_name,void>
        {
         public:
           typedef return_name    return_type;
           typedef  first_name     first_type;
           typedef second_name    second_type;
           typedef  third_name     third_type;
           typedef fourth_name    fourth_type;

           typedef ::reflection::content::function::pure_class<return_name,first_name,second_name,third_name,fourth_name,void>    content_type;
           typedef ::reflection::property::function::free_class<return_name,first_name,second_name,third_name,fourth_name,void>   free_type;

           typedef typename free_type::function_type function_type;

         public:
                    free_class( function_type function_param ):free_type( function_param ) { }
           virtual ~free_class( ){}

         public:
           return_type execute( first_name first, second_name second, third_name third, fourth_name fourth )
            {
             return this->free_type::execute( first, second, third, fourth );
            }

           using content_type::signature;
        };

      template< typename return_name, typename first_name, typename second_name, typename third_name >
       class free_class<return_name,first_name,second_name,third_name,void,void>
        : virtual public ::reflection::content::function::pure_class<return_name,first_name,second_name,third_name,void,void>
        ,         public ::reflection::property::function::free_class<return_name,first_name,second_name,third_name,void,void>
        {
         public:
           typedef return_name    return_type;
           typedef  first_name     first_type;
           typedef second_name    second_type;
           typedef  third_name     third_type;

           typedef ::reflection::content::function::pure_class<return_name,first_name,second_name,third_name,void,void>              content_type;
           typedef ::reflection::property::function::free_class<return_name,first_name,second_name,third_name,void,void>   free_type;

           typedef typename free_type::function_type function_type;

         public:
                    free_class( function_type function_param ):free_type( function_param ) { }
           virtual ~free_class( ){}

         public:
           return_type execute( first_name first, second_name second, third_name third )
            {
             return this->free_type::execute( first, second, third );
            }

           using content_type::signature;
        };

      template< typename return_name, typename first_name, typename second_name >
       class free_class<return_name,first_name,second_name,void,void,void>
        : virtual public ::reflection::content::function::pure_class<return_name,first_name,second_name,void,void,void>
        ,         public ::reflection::property::function::free_class<return_name,first_name,second_name,void,void,void>
        {
         public:
           typedef return_name    return_type;
           typedef  first_name     first_type;
           typedef second_name    second_type;

           typedef ::reflection::content::function::pure_class<return_name,first_name,second_name,void,void,void>              content_type;
           typedef ::reflection::property::function::free_class<return_name,first_name,second_name,void,void,void>   free_type;

           typedef typename free_type::function_type function_type;

         public:
                    free_class( function_type function_param ):free_type( function_param ) { }
           virtual ~free_class( ){}

         public:
           return_type execute( first_name first, second_name second )
            {
             return this->free_type::execute( first, second );
            }

           using content_type::signature;
        };


      template< typename return_name, typename first_name >
       class free_class<return_name,first_name,void,void,void,void>
        : virtual public ::reflection::content::function::pure_class<return_name,first_name,void,void,void,void>
        ,         public ::reflection::property::function::free_class<return_name,first_name,void,void,void,void>
        {
         public:
           typedef return_name    return_type;
           typedef  first_name     first_type;

           typedef ::reflection::content::function::pure_class<return_name,first_name,void,void,void,void>                content_type;
           typedef ::reflection::property::function::free_class<return_name,first_name,void,void,void,void>   free_type;

           typedef typename free_type::function_type function_type;

         public:
                    free_class( function_type function_param ):free_type( function_param ) { }
           virtual ~free_class( ){}

         public:
           return_type execute( first_name first )
            {
             return this->free_type::execute( first );
            }
           using content_type::signature;
        };

      template< typename return_name >
       class free_class<return_name,void,void,void,void,void>
        : virtual public ::reflection::content::function::pure_class<return_name,void,void,void,void,void>
        ,         public ::reflection::property::function::free_class<return_name,void,void,void,void,void>
        {
         public:
           typedef return_name    return_type;

           typedef ::reflection::content::function::pure_class<return_name,void,void,void,void,void>                content_type;
           typedef ::reflection::property::function::free_class<return_name,void,void,void,void,void>   free_type;

           typedef typename free_type::function_type function_type;

         public:
                    free_class( function_type function_param ):free_type( function_param ) { }
           virtual ~free_class( ){}

         public:
           return_type execute()
            {
             return this->free_type::execute();
            }

           using content_type::signature;
        };

      template< typename return_name >
       inline
       ::reflection::content::function::free_class<return_name,void,void,void,void,void>
       free
        (
         return_name (*function_param)()
        )
        {
         typedef ::reflection::content::function::free_class<return_name, void, void, void, void, void > free_type;

         return free_type( function_param );
        }

      template< typename return_name, typename first_name >
       inline
       ::reflection::content::function::free_class< return_name, first_name,void,void,void,void >
       free
        (
         return_name  (*function_param)( first_name )
        )
        {
         typedef ::reflection::content::function::free_class< return_name, first_name, void, void, void, void > free_type;

         return free_type( function_param );
        }

      template< typename return_name, typename first_name, typename second_name >
       inline
       ::reflection::content::function::free_class< return_name, first_name, second_name,void,void,void>
       free
        (
         return_name  (*function_param)( first_name, second_name )
        )
        {
         typedef ::reflection::content::function::free_class< return_name, first_name, second_name, void, void, void > free_type;

         return free_type( function_param );
        }

      template< typename return_name, typename first_name, typename second_name, typename third_name >
       inline
       ::reflection::content::function::free_class< return_name, first_name, second_name, third_name,void,void>
       free
        (
         return_name  (*function_param)( first_name, second_name, third_name )
        )
        {
         typedef ::reflection::content::function::free_class< return_name, first_name, second_name, third_name, void, void > free_type;

         return free_type( function_param );
        }

      template< typename return_name, typename first_name, typename second_name, typename third_name, typename fourth_name >
       inline
       ::reflection::content::function::free_class< return_name, first_name, second_name, third_name, fourth_name,void>
       free
        (
         return_name  (*function_param)( first_name, second_name, third_name, fourth_name )
        )
        {
         typedef ::reflection::content::function::free_class< return_name, first_name, second_name, third_name, fourth_name, void > free_type;

         return free_type( function_param );
        }

      template< typename return_name, typename first_name, typename second_name, typename third_name, typename fourth_name, typename fifth_name >
       inline
       ::reflection::content::function::free_class< return_name, first_name, second_name, third_name, fourth_name, fifth_name >
       free
        (
         return_name (*function_param)( first_name, second_name, third_name, fourth_name, fifth_name )
        )
        {
         typedef ::reflection::content::function::free_class< return_name, first_name, second_name, third_name, fourth_name, fifth_name > free_type;

         return free_type( function_param );
        }

      }
    }
  }

#endif
