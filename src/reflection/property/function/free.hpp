#ifndef reflection_property_function_free
#define reflection_property_function_free

// ::reflection::property::function::free_class<return_name,first_name,second_name,third_name,fourth_name,fifth_name>
// ::reflection::property::function::free<return_name,first_name,second_name,third_name,fourth_name,fifth_name>( )

#include "../_pure.hpp"

namespace reflection
 {
  namespace property
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
        : public ::reflection::property::function::pure_class<return_name,first_name,second_name,third_name,fourth_name,fifth_name>
        {
         public:
           typedef return_name    return_type;
           typedef  first_name     first_type;
           typedef second_name    second_type;
           typedef  third_name     third_type;
           typedef fourth_name    fourth_type;
           typedef  fifth_name     fifth_type;

           typedef return_type (*function_type)( first_type, second_type , third_type , fourth_type , fifth_type );

                    free_class( function_type function_param ):m_function(function_param) { }
           virtual ~free_class( ){}

           return_type execute( first_type first_param, second_type second_param, third_type third_param, fourth_type fourth_param, fifth_type fifth_param )
            {
             return (*m_function)( first_param, second_param, third_param, fourth_param, fifth_param );
            }
          private:
             function_type m_function;

        };


      template< typename return_name, typename first_name, typename second_name, typename third_name, typename fourth_name >
       class free_class<return_name,first_name,second_name,third_name,fourth_name,void>
        : public ::reflection::property::function::pure_class<return_name,first_name,second_name,third_name,fourth_name,void>
        {
         public:

           typedef return_name    return_type;
           typedef  first_name     first_type;
           typedef second_name    second_type;
           typedef  third_name     third_type;
           typedef fourth_name    fourth_type;

           typedef return_type (*function_type)( first_type, second_type , third_type , fourth_type );

                    free_class( function_type function_param ):m_function(function_param) { }
           virtual ~free_class( ){}

           return_type execute( first_type first_param, second_type second_param, third_type third_param, fourth_type fourth_param )
            {
             return (*m_function)( first_param, second_param, third_param, fourth_param );
            }
          private:

             function_type m_function;
        };

      template< typename return_name, typename first_name, typename second_name, typename third_name >
       class free_class<return_name,first_name,second_name,third_name,void,void>
        : public ::reflection::property::function::pure_class<return_name,first_name,second_name,third_name,void,void>
        {
         public:

           typedef return_name    return_type;
           typedef  first_name     first_type;
           typedef second_name    second_type;
           typedef  third_name     third_type;

           typedef return_type (*function_type)( first_type, second_type , third_type );

                    free_class( function_type function_param ):m_function(function_param) { }
           virtual ~free_class( ){}

           return_type execute( first_type first_param, second_type second_param, third_type third_param )
            {
             return (*m_function)( first_param, second_param, third_param);
            }
          private:

             function_type m_function;
        };

      template< typename return_name, typename first_name, typename second_name >
       class free_class<return_name,first_name,second_name,void,void,void>
        : public ::reflection::property::function::pure_class<return_name,first_name,second_name,void,void,void>
        {
         public:

           typedef return_name    return_type;
           typedef  first_name     first_type;
           typedef second_name    second_type;

           typedef return_type (*function_type)( first_type, second_type );

                    free_class( function_type function_param ):m_function(function_param) { }
           virtual ~free_class( ){}

           return_type execute( first_type first_param, second_type second_param )
            {
             return (*m_function)( first_param, second_param);
            }
          private:

             function_type m_function;
        };


      template< typename return_name, typename first_name >
       class free_class<return_name,first_name,void,void,void,void>
        : public ::reflection::property::function::pure_class<return_name,first_name,void,void,void,void>
        {
         public:

           typedef return_name    return_type;
           typedef  first_name     first_type;

           typedef return_type (*function_type)( first_type );

                    free_class( function_type function_param ):m_function(function_param) { }
           virtual ~free_class( ){}

           return_type execute( first_type first_param )
            {
             return (*m_function)( first_param );
            }
          private:

             function_type m_function;
        };

      template< typename return_name >
       class free_class<return_name,void,void,void,void,void>
        : public ::reflection::property::function::pure_class<return_name,void,void,void,void,void>
        {
         public:

           typedef return_name    return_type;

           typedef return_type (*function_type)();

                    free_class( function_type function_param ):m_function(function_param) { }
           virtual ~free_class( ){}

           return_type execute( )
            {
             return (*m_function)();
            }
          private:

             function_type m_function;
        };

      template< typename return_name >
       inline
       ::reflection::property::function::free_class<return_name,void,void,void,void,void>
       free
        (
         return_name (*function_param)()
        )
        {
         typedef ::reflection::property::function::free_class<return_name, void, void, void, void, void > free_type;

         return free_type( function_param );
        }

      template< typename return_name, typename first_name >
       inline
       ::reflection::property::function::free_class< return_name, first_name,void,void,void,void >
       free
        (
         return_name  (*function_param)( first_name )
        )
        {
         typedef ::reflection::property::function::free_class< return_name, first_name, void, void, void, void > free_type;

         return free_type( function_param );
        }

      template< typename return_name, typename first_name, typename second_name >
       inline
       ::reflection::property::function::free_class< return_name, first_name, second_name,void,void,void>
       free
        (
         return_name  (*function_param)( first_name, second_name )
        )
        {
         typedef ::reflection::property::function::free_class< return_name, first_name, second_name, void, void, void > free_type;

         return free_type( function_param );
        }

      template< typename return_name, typename first_name, typename second_name, typename third_name >
       inline
       ::reflection::property::function::free_class< return_name, first_name, second_name, third_name,void,void>
       free
        (
         return_name  (*function_param)( first_name, second_name, third_name )
        )
        {
         typedef ::reflection::property::function::free_class< return_name, first_name, second_name, third_name, void, void > free_type;

         return free_type( function_param );
        }

      template< typename return_name, typename first_name, typename second_name, typename third_name, typename fourth_name >
       inline
       ::reflection::property::function::free_class< return_name, first_name, second_name, third_name, fourth_name,void>
       free
        (
         return_name  (*function_param)( first_name, second_name, third_name, fourth_name )
        )
        {
         typedef ::reflection::property::function::free_class< return_name, first_name, second_name, third_name, fourth_name, void > free_type;

         return free_type( function_param );
        }

      template< typename return_name, typename first_name, typename second_name, typename third_name, typename fourth_name, typename fifth_name >
       inline
       ::reflection::property::function::free_class< return_name, first_name, second_name, third_name, fourth_name, fifth_name >
       free
        (
         return_name (*function_param)( first_name, second_name, third_name, fourth_name, fifth_name )
        )
        {
         typedef ::reflection::property::function::free_class< return_name, first_name, second_name, third_name, fourth_name, fifth_name > free_type;

         return free_type( function_param );
        }

     }
   }
 }

#endif