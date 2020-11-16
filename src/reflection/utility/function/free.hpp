#ifndef reflection_utility_function_free
#define reflection_utility_function_free

// ::reflection::utility::function::free_class<return_name,first_name,second_name,third_name,fourth_name,fifth_name>
// ::reflection::utility::function::free<return_name,first_name,second_name,third_name,fourth_name,fifth_name>( )

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
       class free_class
        : virtual public ::reflection::utility::function::pure_class<return_name,first_name,second_name,third_name,fourth_name,fifth_name>
        {
         public:
           typedef return_name    return_type;
           typedef  first_name     first_type;
           typedef second_name    second_type;
           typedef  third_name     third_type;
           typedef fourth_name    fourth_type;
           typedef  fifth_name     fifth_type;

           typedef return_type (*pointer_type)( first_type, second_type , third_type , fourth_type , fifth_type );

                    free_class( pointer_type pointer_param ):m_pointer(pointer_param) { }
           virtual ~free_class( ){}

           return_type execute( first_type first_param, second_type second_param, third_type third_param, fourth_type fourth_param, fifth_type fifth_param )const
            {
             return (*m_pointer)( first_param, second_param, third_param, fourth_param, fifth_param );
            }
          private:
            pointer_type m_pointer;
        };


      template< typename return_name, typename first_name, typename second_name, typename third_name, typename fourth_name >
       class free_class<return_name,first_name,second_name,third_name,fourth_name,void>
        : virtual public ::reflection::utility::function::pure_class<return_name,first_name,second_name,third_name,fourth_name>
        {
         public:

           typedef return_name    return_type;
           typedef  first_name     first_type;
           typedef second_name    second_type;
           typedef  third_name     third_type;
           typedef fourth_name    fourth_type;

           typedef return_type (*pointer_type)( first_type, second_type , third_type , fourth_type );

                    free_class( pointer_type pointer_param ):m_pointer(pointer_param) { }
           virtual ~free_class( ){}

           return_type execute( first_type first_param, second_type second_param, third_type third_param, fourth_type fourth_param )const
            {
             return (*m_pointer)( first_param, second_param, third_param, fourth_param );
            }
          private:
            pointer_type m_pointer;
        };

      template< typename return_name, typename first_name, typename second_name, typename third_name >
       class free_class<return_name,first_name,second_name,third_name,void,void>
        : virtual public ::reflection::utility::function::pure_class<return_name,first_name,second_name,third_name>
        {
         public:

           typedef return_name    return_type;
           typedef  first_name     first_type;
           typedef second_name    second_type;
           typedef  third_name     third_type;

           typedef return_type (*pointer_type)( first_type, second_type , third_type );

                    free_class( pointer_type pointer_param ):m_pointer(pointer_param) { }
           virtual ~free_class( ){}

           return_type execute( first_type first_param, second_type second_param, third_type third_param )const
            {
             return (*m_pointer)( first_param, second_param, third_param);
            }
          private:
            pointer_type m_pointer;
        };

      template< typename return_name, typename first_name, typename second_name >
       class free_class<return_name,first_name,second_name,void,void,void>
        : virtual public ::reflection::utility::function::pure_class<return_name,first_name,second_name>
        {
         public:

           typedef return_name    return_type;
           typedef  first_name     first_type;
           typedef second_name    second_type;

           typedef return_type (*pointer_type)( first_type, second_type );

                    free_class( pointer_type pointer_param ):m_pointer(pointer_param) { }
           virtual ~free_class( ){}

           return_type execute( first_type first_param, second_type second_param )const
            {
             return (*m_pointer)( first_param, second_param);
            }
          private:
            pointer_type m_pointer;
        };

      template< typename return_name, typename first_name >
       class free_class<return_name,first_name,void,void,void,void>
        : virtual public ::reflection::utility::function::pure_class<return_name,first_name>
        {
         public:

           typedef return_name    return_type;
           typedef  first_name     first_type;

           typedef return_type (*pointer_type)( first_type );

                    free_class( pointer_type pointer_param ):m_pointer(pointer_param) { }
           virtual ~free_class( ){}

           return_type execute( first_type first_param )const
            {
             return (*m_pointer)( first_param );
            }
          private:
            pointer_type m_pointer;
        };

      template< typename return_name >
       class free_class<return_name,void,void,void,void,void>
        : virtual public ::reflection::utility::function::pure_class<return_name>
        {
         public:

           typedef return_name    return_type;

           typedef return_type (*pointer_type)();

                    free_class( pointer_type pointer_param ):m_pointer(pointer_param) { }
           virtual ~free_class( ){}

           return_type execute()const
            {
             return (*m_pointer)();
            }
          private:
            pointer_type m_pointer;
        };

      template< typename return_name >
       inline
       ::reflection::utility::function::free_class<return_name>
       free
        (
         return_name (*pointer_param)()
        )
        {
         typedef ::reflection::utility::function::free_class<return_name> free_type;

         return free_type( pointer_param );
        }

      template< typename return_name, typename first_name >
       inline
       ::reflection::utility::function::free_class< return_name, first_name  >
       free
        (
         return_name  (*pointer_param)( first_name )
        )
        {
         typedef ::reflection::utility::function::free_class< return_name, first_name> free_type;

         return free_type( pointer_param );
        }

      template< typename return_name, typename first_name, typename second_name >
       inline
       ::reflection::utility::function::free_class< return_name, first_name, second_name>
       free
        (
         return_name  (*pointer_param)( first_name, second_name )
        )
        {
         typedef ::reflection::utility::function::free_class< return_name, first_name, second_name > free_type;

         return free_type( pointer_param );
        }

      template< typename return_name, typename first_name, typename second_name, typename third_name >
       inline
       ::reflection::utility::function::free_class< return_name, first_name, second_name, third_name>
       free
        (
         return_name  (*pointer_param)( first_name, second_name, third_name )
        )
        {
         typedef ::reflection::utility::function::free_class< return_name, first_name, second_name, third_name > free_type;

         return free_type( pointer_param );
        }

      template< typename return_name, typename first_name, typename second_name, typename third_name, typename fourth_name >
       inline
       ::reflection::utility::function::free_class< return_name, first_name, second_name, third_name, fourth_name>
       free
        (
         return_name  (*pointer_param)( first_name, second_name, third_name, fourth_name )
        )
        {
         typedef ::reflection::utility::function::free_class< return_name, first_name, second_name, third_name, fourth_name > free_type;

         return free_type( pointer_param );
        }

      template< typename return_name, typename first_name, typename second_name, typename third_name, typename fourth_name, typename fifth_name >
       inline
       ::reflection::utility::function::free_class< return_name, first_name, second_name, third_name, fourth_name, fifth_name >
       free
        (
         return_name (*pointer_param)( first_name, second_name, third_name, fourth_name, fifth_name )
        )
        {
         typedef ::reflection::utility::function::free_class< return_name, first_name, second_name, third_name, fourth_name, fifth_name > free_type;

         return free_type( pointer_param );
        }

     }
   }
 }

#endif