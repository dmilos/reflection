#ifndef reflection_utility_function_std
#define reflection_utility_function_std

// ::reflection::utility::function::std_class<return_name,first_name,second_name,third_name,fourth_name,fifth_name>
// ::reflection::utility::function::std<return_name,first_name,second_name,third_name,fourth_name,fifth_name>( )

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
        ,typename first_name   = void
        ,typename second_name  = void
        ,typename third_name   = void
        ,typename fourth_name  = void
        ,typename fifth_name   = void
        >
       class std_class
        : virtual public ::reflection::utility::function::pure_class<return_name,first_name,second_name,third_name,fourth_name,fifth_name>
        {
         public:
           typedef return_name    return_type;
           typedef  first_name     first_type;
           typedef second_name    second_type;
           typedef  third_name     third_type;
           typedef fourth_name    fourth_type;
           typedef  fifth_name     fifth_type;

           typedef std::function< return_type( first_type, second_type , third_type , fourth_type , fifth_type ) > function_type;

                    std_class( function_type function_param ):m_function(function_param) { }
           virtual ~std_class( ){}

           return_type execute( first_type first_param, second_type second_param, third_type third_param, fourth_type fourth_param, fifth_type fifth_param )const
            {
             return m_function( first_param, second_param, third_param, fourth_param, fifth_param );
            }
          private:
            function_type m_function;
        };


      template< typename return_name, typename first_name, typename second_name, typename third_name, typename fourth_name >
       class std_class<return_name,first_name,second_name,third_name,fourth_name,void>
        : virtual public ::reflection::utility::function::pure_class<return_name,first_name,second_name,third_name,fourth_name>
        {
         public:

           typedef return_name    return_type;
           typedef  first_name     first_type;
           typedef second_name    second_type;
           typedef  third_name     third_type;
           typedef fourth_name    fourth_type;

           typedef std::function< return_type( first_type, second_type , third_type , fourth_type ) > function_type;

                    std_class( function_type function_param ):m_function(function_param) { }
           virtual ~std_class( ){}

           return_type execute( first_type first_param, second_type second_param, third_type third_param, fourth_type fourth_param )const
            {
             return m_function( first_param, second_param, third_param, fourth_param );
            }
          private:
            function_type m_function;
        };

      template< typename return_name, typename first_name, typename second_name, typename third_name >
       class std_class<return_name,first_name,second_name,third_name,void,void>
        : virtual public ::reflection::utility::function::pure_class<return_name,first_name,second_name,third_name>
        {
         public:

           typedef return_name    return_type;
           typedef  first_name     first_type;
           typedef second_name    second_type;
           typedef  third_name     third_type;

           typedef std::function< return_type ( first_type, second_type , third_type ) > function_type;

                    std_class( function_type function_param ):m_function(function_param) { }
           virtual ~std_class( ){}

           return_type execute( first_type first_param, second_type second_param, third_type third_param )const
            {
             return m_function( first_param, second_param, third_param);
            }
          private:
            function_type m_function;
        };

      template< typename return_name, typename first_name, typename second_name >
       class std_class<return_name,first_name,second_name,void,void,void>
        : virtual public ::reflection::utility::function::pure_class<return_name,first_name,second_name>
        {
         public:

           typedef return_name    return_type;
           typedef  first_name     first_type;
           typedef second_name    second_type;

           typedef std::function< return_type( first_type, second_type ) > function_type;

                    std_class( function_type function_param ):m_function(function_param) { }
           virtual ~std_class( ){}

           return_type execute( first_type first_param, second_type second_param )const
            {
             return m_function( first_param, second_param);
            }
          private:
            function_type m_function;
        };

      template< typename return_name, typename first_name >
       class std_class<return_name,first_name,void,void,void,void>
        : virtual public ::reflection::utility::function::pure_class<return_name,first_name>
        {
         public:

           typedef return_name    return_type;
           typedef  first_name     first_type;

           typedef std::function< return_type ( first_type ) > function_type;

                    std_class( function_type function_param ):m_function(function_param) { }
           virtual ~std_class( ){}

           return_type execute( first_type first_param )const
            {
             return m_function( first_param );
            }
          private:
            function_type m_function;
        };

      template< typename return_name >
       class std_class<return_name,void,void,void,void,void>
        : virtual public ::reflection::utility::function::pure_class<return_name>
        {
         public:

           typedef return_name    return_type;

           typedef std::function< return_type() > function_type;

                    std_class( function_type function_param ):m_function(function_param) { }
           virtual ~std_class( ){}

           return_type execute()const
            {
             return m_function();
            }
          private:
            function_type m_function;
        };

      template< typename return_name >
       inline
       ::reflection::utility::function::std_class<return_name>
       std_function
        (
         std::function< return_name( ) > const& function_param
        )
        {
         typedef ::reflection::utility::function::std_class<return_name> std_type;

         return std_type( function_param );
        }

      template< typename return_name, typename first_name >
       inline
       ::reflection::utility::function::std_class< return_name, first_name  >
       std_function
        (
         std::function< return_name( first_name ) > const& function_param
        )
        {
         typedef ::reflection::utility::function::std_class< return_name, first_name> std_type;

         return std_type( function_param );
        }

      template< typename return_name, typename first_name, typename second_name >
       inline
       ::reflection::utility::function::std_class< return_name, first_name, second_name>
       std_function
        (
         std::function< return_name( first_name, second_name ) > const& function_param
        )
        {
         typedef ::reflection::utility::function::std_class< return_name, first_name, second_name > std_type;

         return std_type( function_param );
        }

      template< typename return_name, typename first_name, typename second_name, typename third_name >
       inline
       ::reflection::utility::function::std_class< return_name, first_name, second_name, third_name>
       std_function
        (
         std::function< return_name( first_name, second_name, third_name  ) > const& function_param
        )
        {
         typedef ::reflection::utility::function::std_class< return_name, first_name, second_name, third_name > std_type;

         return std_type( function_param );
        }

      template< typename return_name, typename first_name, typename second_name, typename third_name, typename fourth_name >
       inline
       ::reflection::utility::function::std_class< return_name, first_name, second_name, third_name, fourth_name>
       std_function
        (
         std::function< return_name( first_name, second_name, third_name , fourth_name ) > const& function_param
        )
        {
         typedef ::reflection::utility::function::std_class< return_name, first_name, second_name, third_name, fourth_name > std_type;

         return std_type( function_param );
        }

      template< typename return_name, typename first_name, typename second_name, typename third_name, typename fourth_name, typename fifth_name >
       inline
       ::reflection::utility::function::std_class< return_name, first_name, second_name, third_name, fourth_name, fifth_name >
       std_function
        (
         std::function< return_name( first_name, second_name, third_name , fourth_name , fifth_name ) > const& function_param
        )
        {
         typedef ::reflection::utility::function::std_class< return_name, first_name, second_name, third_name, fourth_name, fifth_name > std_type;

         return std_type( function_param );
        }

     }
   }
 }

#endif