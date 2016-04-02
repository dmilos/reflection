#ifndef reflection_property_function_member
#define reflection_property_function_member

#include "../_pure.hpp"

namespace reflection
 {
  namespace property
   {
    namespace function
     {

      template
       <
         typename class_name
        ,typename return_name
        ,typename first_name
        ,typename second_name
        ,typename third_name
        ,typename fourth_name
        ,typename fifth_name
        >
       class member_class
        : public ::reflection::property::function::pure_class<return_name,first_name,second_name,third_name,fourth_name,fifth_name>
        {
         public:
           typedef  class_name     class_type;
           typedef return_name    return_type;
           typedef  first_name     first_type;
           typedef second_name    second_type;
           typedef  third_name     third_type;
           typedef fourth_name    fourth_type;
           typedef  fifth_name     fifth_type;

           typedef return_type (class_name::*function_type)( first_type, second_type , third_type , fourth_type , fifth_type );

                    member_class( class_type * class_param, function_type function_param ):m_class(class_param),m_function(function_param) { }
           virtual ~member_class( );

           return_type execute( first_type first_param, second_type second_param, third_type third_param, fourth_type fourth_param, fifth_type fifth_param )
            {
             return (m_class->*m_function)( first_param, second_param, third_param, fourth_param, fifth_param );
            }
          private:
             class_type   *m_class;
             function_type m_function;

        };


      template< typename class_name, typename return_name, typename first_name, typename second_name, typename third_name, typename fourth_name >
       class member_class< class_name,return_name,first_name,second_name,third_name,fourth_name,void>
        : public ::reflection::property::function::pure_class<return_name,first_name,second_name,third_name,fourth_name,void>
        {
         public:
           typedef  class_name     class_type;
           typedef return_name    return_type;
           typedef  first_name     first_type;
           typedef second_name    second_type;
           typedef  third_name     third_type;
           typedef fourth_name    fourth_type;

           typedef return_type (class_name::*function_type)( first_type, second_type , third_type , fourth_type );

                    member_class( class_type * class_param, function_type function_param ):m_class(class_param),m_function(function_param) { }
           virtual ~member_class( );

           return_type execute( first_type first_param, second_type second_param, third_type third_param, fourth_type fourth_param )
            {
             return (m_class->*m_function)( first_param, second_param, third_param, fourth_param );
            }
          private:
             class_type   *m_class;
             function_type m_function;
        };

      template< typename class_name, typename return_name, typename first_name, typename second_name, typename third_name >
       class member_class< class_name,return_name,first_name,second_name,third_name,void,void>
        : public ::reflection::property::function::pure_class<return_name,first_name,second_name,third_name,void,void>
        {
         public:
           typedef  class_name     class_type;
           typedef return_name    return_type;
           typedef  first_name     first_type;
           typedef second_name    second_type;
           typedef  third_name     third_type;

           typedef return_type (class_name::*function_type)( first_type, second_type , third_type );

                    member_class( class_type * class_param, function_type function_param ):m_class(class_param),m_function(function_param) { }
           virtual ~member_class( );

           return_type execute( first_type first_param, second_type second_param, third_type third_param )
            {
             return (m_class->*m_function)( first_param, second_param, third_param);
            }
          private:
             class_type   *m_class;
             function_type m_function;
        };

      template< typename class_name, typename return_name, typename first_name, typename second_name >
       class member_class< class_name,return_name,first_name,second_name,void,void,void>
        : public ::reflection::property::function::pure_class<return_name,first_name,second_name,void,void,void>
        {
         public:
           typedef  class_name     class_type;
           typedef return_name    return_type;
           typedef  first_name     first_type;
           typedef second_name    second_type;

           typedef return_type (class_name::*function_type)( first_type, second_type );

                    member_class( class_type * class_param, function_type function_param ):m_class(class_param),m_function(function_param) { }
           virtual ~member_class( );

           return_type execute( first_type first_param, second_type second_param )
            {
             return (m_class->*m_function)( first_param, second_param);
            }
          private:
             class_type   *m_class;
             function_type m_function;
        };


      template< typename class_name, typename return_name, typename first_name >
       class member_class< class_name,return_name,first_name,void,void,void,void>
        : public ::reflection::property::function::pure_class<return_name,first_name,void,void,void,void>
        {
         public:
           typedef  class_name     class_type;
           typedef return_name    return_type;
           typedef  first_name     first_type;

           typedef return_type (class_name::*function_type)( first_type );

                    member_class( class_type * class_param, function_type function_param ):m_class(class_param),m_function(function_param) { }
           virtual ~member_class( );

           return_type execute( first_type first_param )
            {
             return (m_class->*m_function)( first_param );
            }
          private:
             class_type   *m_class;
             function_type m_function;
        };

      template< typename class_name, typename return_name >
       class member_class< class_name,return_name,void,void,void,void,void>
        : public ::reflection::property::function::pure_class<return_name,void,void,void,void,void>
        {
         public:
           typedef  class_name     class_type;
           typedef return_name    return_type;

           typedef return_type (class_name::*function_type)();

                    member_class( class_type * class_param, function_type function_param ):m_class(class_param),m_function(function_param) { }
           virtual ~member_class( );

           return_type execute( )
            {
             return (m_class->*m_function)();
            }
          private:
             class_type   *m_class;
             function_type m_function;
        };

      template< typename class_name, typename return_name >
       inline
       ::reflection::property::function::member_class<class_name,return_name,void,void,void,void,void>
       make
        (
          class_name * class_param
         ,return_name (class_name::*function_param)()
        )
        {
         typedef ::reflection::property::function::member_class<class_name,return_name, void, void, void, void, void > member_type;

         return member_type( class_param, function_param );
        }

      template< typename class_name, typename return_name, typename first_name >
       inline
       ::reflection::property::function::member_class<class_name, return_name, first_name,void,void,void,void >
       make
        (
          class_name * class_param
         ,return_name  (class_name::*function_param)( first_name )
        )
        {
         typedef ::reflection::property::function::member_class<class_name, return_name, first_name, void, void, void, void > member_type;

         return member_type( class_param, function_param );
        }

      template< typename class_name, typename return_name, typename first_name, typename second_name >
       inline
       ::reflection::property::function::member_class<class_name, return_name, first_name, second_name,void,void,void>
       make
        (
          class_name * class_param
         ,return_name  (class_name::*function_param)( first_name, second_name )
        )
        {
         typedef ::reflection::property::function::member_class<class_name, return_name, first_name, second_name, void, void, void > member_type;

         return member_type( class_param, function_param );
        }

      template< typename class_name, typename return_name, typename first_name, typename second_name, typename third_name >
       inline
       ::reflection::property::function::member_class<class_name, return_name, first_name, second_name, third_name,void,void>
       make
        (
          class_name * class_param
         ,return_name  (class_name::*function_param)( first_name, second_name, third_name )
        )
        {
         typedef ::reflection::property::function::member_class<class_name, return_name, first_name, second_name, third_name, void, void > member_type;

         return member_type( class_param, function_param );
        }

      template< typename class_name, typename return_name, typename first_name, typename second_name, typename third_name, typename fourth_name >
       inline
       ::reflection::property::function::member_class<class_name, return_name, first_name, second_name, third_name, fourth_name,void>
       make
        (
          class_name * class_param
         ,return_name  (class_name::*function_param)( first_name, second_name, third_name, fourth_name )
        )
        {
         typedef ::reflection::property::function::member_class<class_name, return_name, first_name, second_name, third_name, fourth_name, void > member_type;

         return member_type( class_param, function_param );
        }

      template< typename class_name, typename return_name, typename first_name, typename second_name, typename third_name, typename fourth_name, typename fifth_name >
       inline
       ::reflection::property::function::member_class<class_name, return_name, first_name, second_name, third_name, fourth_name, fifth_name >
       make
        (
          class_name * class_param
         ,return_name (class_name::*function_param)( first_name, second_name, third_name, fourth_name, fifth_name )
        )
        {
         typedef ::reflection::property::function::member_class<class_name, return_name, first_name, second_name, third_name, fourth_name, fifth_name > member_type;

         return member_type( class_param, function_param );
        }



     }
   }
 }

#endif
