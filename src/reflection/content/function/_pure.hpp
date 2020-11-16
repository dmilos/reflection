#ifndef reflection_content_function__pure_hpp
 #define reflection_content_function__pure_hpp

 // ::reflection::content::function::pure_class<return_name,first_name,second_name,third_name,fourth_name,fifth_name>

#include "../../type/name/id.hpp"
#include "../../property/function/_pure.hpp"

#include "../_pure.hpp"

#include "./algorithm.hpp"

#include "./signature.hpp"
#include "./context.hpp"
#include "./argument.hpp"
#include "./unpack.hpp"
#include "./call.hpp"


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
       class pure_class
        : virtual public ::reflection::content::function::algorithm_class < identifier_name >
        , virtual public ::reflection::property::function::pure_class<return_name,first_name,second_name,third_name,fourth_name,fifth_name>
        {
         public:
           typedef identifier_name identifier_type;

           typedef return_name    return_type;
           typedef  first_name     first_type;
           typedef second_name    second_type;
           typedef  third_name     third_type;
           typedef fourth_name    fourth_type;
           typedef  fifth_name     fifth_type;


           typedef ::reflection::content::pure_class< identifier_name >        content_type;
           typedef ::reflection::property::function::pure_class<return_name,first_name,second_name,third_name,fourth_name,fifth_name>   property_type;
           typedef ::reflection::content::function::algorithm_class<identifier_type>   algorithm_type;

           typedef ::reflection::type::name::identificatorX< identifier_type > identificator_type;
           typedef typename ::reflection::content::function::signature_struct<identifier_type>::container_type   signature_type;
           typedef typename ::reflection::content::function::argument_struct<identifier_type>                   argument_type;

           typedef  algorithm_type anchor_type;

         public:
           pure_class()
            : content_type( identificator_type::template get<anchor_type>() )
            {
             this->identifier( identificator_type::template get<anchor_type>() );
             this->signature().resize( 6 );

             this->signature()[0] = identificator_type::template get< typename ::reflection::type::trait<return_name>::instance_type >();
             this->signature()[1] = identificator_type::template get< typename ::reflection::type::trait< first_name>::instance_type >();
             this->signature()[2] = identificator_type::template get< typename ::reflection::type::trait<second_name>::instance_type >();
             this->signature()[3] = identificator_type::template get< typename ::reflection::type::trait< third_name>::instance_type >();
             this->signature()[4] = identificator_type::template get< typename ::reflection::type::trait<fourth_name>::instance_type >();
             this->signature()[5] = identificator_type::template get< typename ::reflection::type::trait< fifth_name>::instance_type >();
            }

         public:
           using property_type::execute;
           bool execute( typename argument_type::typedef_type & argument_param )const
            {
             if( false == argument_type::check( argument_param, this->signature() ) )
              {
               return false;
              }

             typedef ::reflection::content::function::call_struct< return_name, first_name, second_name, third_name,fourth_name,fifth_name >   call_type;

             auto  * a0 = call_type::u0_type::return_get( *(argument_param[0]) );if( nullptr == a0 ) return false;
             auto  * a1 = call_type::u1_type::get( *(argument_param[1]) );if( nullptr == a1 ) return false;
             auto  * a2 = call_type::u2_type::get( *(argument_param[2]) );if( nullptr == a2 ) return false;
             auto  * a3 = call_type::u3_type::get( *(argument_param[3]) );if( nullptr == a3 ) return false;
             auto  * a4 = call_type::u3_type::get( *(argument_param[4]) );if( nullptr == a4 ) return false;
             auto  * a5 = call_type::u3_type::get( *(argument_param[5]) );if( nullptr == a5 ) return false;

             call_type::process( *this, *a0, *a1, *a2, *a3, *a4 , *a5 );

             return true;
            }
        };

      template< typename identifier_name, typename return_name, typename first_name, typename second_name, typename third_name, typename fourth_name>
       class pure_class< identifier_name, return_name, first_name, second_name, third_name, fourth_name,void>
        : virtual public ::reflection::content::function::algorithm_class< identifier_name >
        , virtual public ::reflection::property::function::pure_class<return_name,first_name,second_name,third_name,fourth_name,void>
        {
         public:
           typedef identifier_name identifier_type;

           typedef return_name    return_type;
           typedef  first_name     first_type;
           typedef second_name    second_type;
           typedef  third_name     third_type;
           typedef fourth_name    fourth_type;


           typedef ::reflection::content::pure_class< identifier_name >        content_type;
           typedef ::reflection::property::function::pure_class<return_name,first_name,second_name,third_name,fourth_name,void>   property_type;
           typedef ::reflection::content::function::algorithm_class<identifier_type>   algorithm_type;

           typedef ::reflection::type::name::identificatorX< identifier_type > identificator_type;
           typedef typename ::reflection::content::function::signature_struct<identifier_type>::container_type   signature_type;
           typedef typename ::reflection::content::function::argument_struct<identifier_type>                   argument_type;

           typedef  algorithm_type anchor_type;

         public:
           pure_class()
            : content_type( identificator_type::template get<anchor_type>() )
            {
             this->identifier( identificator_type::template get<anchor_type>() );
             this->signature().resize( 5 );

             this->signature()[0] = identificator_type::template get< typename ::reflection::type::trait<return_name>::instance_type >();
             this->signature()[1] = identificator_type::template get< typename ::reflection::type::trait< first_name>::instance_type >();
             this->signature()[2] = identificator_type::template get< typename ::reflection::type::trait<second_name>::instance_type >();
             this->signature()[3] = identificator_type::template get< typename ::reflection::type::trait< third_name>::instance_type >();
             this->signature()[4] = identificator_type::template get< typename ::reflection::type::trait<fourth_name>::instance_type >();
            }

         public:
           using property_type::execute;
           bool execute( typename argument_type::container_type & argument_param )const
            {
             if( false == argument_type::check( argument_param, this->signature() ) )
              {
               return false;
              }

             typedef ::reflection::content::function::call_struct< return_name, first_name, second_name, third_name,fourth_name >   call_type;

             auto  * a0 = call_type::u0_type::return_get( *(argument_param[0]) );if( nullptr == a0 ) return false;
             auto  * a1 = call_type::u1_type::get( *(argument_param[1]) );if( nullptr == a1 ) return false;
             auto  * a2 = call_type::u2_type::get( *(argument_param[2]) );if( nullptr == a2 ) return false;
             auto  * a3 = call_type::u3_type::get( *(argument_param[3]) );if( nullptr == a3 ) return false;
             auto  * a4 = call_type::u4_type::get( *(argument_param[4]) );if( nullptr == a4 ) return false;

             call_type::process( *this, *a0, *a1, *a2, *a3, *a4 );

             return true;
            }
        };

      template< typename identifier_name, typename return_name, typename first_name, typename second_name, typename third_name>
       class pure_class< identifier_name, return_name, first_name, second_name, third_name, void,void>
        : virtual public ::reflection::content::function::algorithm_class< identifier_name >
        , virtual public ::reflection::property::function::pure_class<return_name,first_name,second_name,third_name,void,void>
        {
         public:
           typedef identifier_name identifier_type;

           typedef return_name    return_type;
           typedef  first_name     first_type;
           typedef second_name    second_type;
           typedef  third_name     third_type;

           typedef ::reflection::content::pure_class< identifier_name >        content_type;
           typedef ::reflection::property::function::pure_class<return_name,first_name,second_name,third_name,void,void>   property_type;
           typedef ::reflection::content::function::algorithm_class<identifier_type>   algorithm_type;

           typedef ::reflection::type::name::identificatorX< identifier_type > identificator_type;
           typedef typename ::reflection::content::function::signature_struct<identifier_type>::container_type   signature_type;
           typedef typename ::reflection::content::function::argument_struct<identifier_type>                   argument_type;

           typedef  algorithm_type anchor_type;

         public:
           pure_class()
            : content_type( identificator_type::template get<anchor_type>() )
            {
             this->identifier( identificator_type::template get<anchor_type>() );
             this->signature().resize( 4 );

             this->signature()[0] = identificator_type::template get< typename ::reflection::type::trait<return_name>::instance_type >();
             this->signature()[1] = identificator_type::template get< typename ::reflection::type::trait< first_name>::instance_type >();
             this->signature()[2] = identificator_type::template get< typename ::reflection::type::trait<second_name>::instance_type >();
             this->signature()[3] = identificator_type::template get< typename ::reflection::type::trait< third_name>::instance_type >();
            }

         public:
           using property_type::execute;
           bool execute( typename argument_type::container_type & argument_param )const
            {
             if( false == argument_type::check( argument_param, this->signature() ) )
              {
               return false;
              }

             typedef ::reflection::content::function::call_struct< return_name, first_name, second_name, third_name >   call_type;

             auto  * a0 = call_type::u0_type::return_get( *(argument_param[0]) );if( nullptr == a0 ) return false;
             auto  * a1 = call_type::u1_type::get( *(argument_param[1]) );if( nullptr == a1 ) return false;
             auto  * a2 = call_type::u2_type::get( *(argument_param[2]) );if( nullptr == a2 ) return false;
             auto  * a3 = call_type::u3_type::get( *(argument_param[3]) );if( nullptr == a3 ) return false;

             call_type::process( *this, *a0, *a1, *a2, *a3 );

             return true;
            }
        };

      template< typename identifier_name, typename return_name, typename first_name, typename second_name>
       class pure_class< identifier_name, return_name, first_name, second_name, void, void,void>
        : virtual public ::reflection::content::function::algorithm_class< identifier_name >
        , virtual public ::reflection::property::function::pure_class<return_name,first_name,second_name,void,void,void>
        {
         public:
           typedef identifier_name identifier_type;

           typedef return_name    return_type;
           typedef  first_name     first_type;
           typedef second_name    second_type;

           typedef ::reflection::content::pure_class< identifier_name >        content_type;
           typedef ::reflection::property::function::pure_class<return_name,first_name,second_name,void,void,void>   property_type;
           typedef ::reflection::content::function::algorithm_class<identifier_type>   algorithm_type;

           typedef ::reflection::type::name::identificatorX< identifier_type > identificator_type;
           typedef typename ::reflection::content::function::signature_struct<identifier_type>::container_type   signature_type;
           typedef typename ::reflection::content::function::argument_struct<identifier_type>                   argument_type;

           typedef  algorithm_type anchor_type;

         public:
           pure_class()
            : content_type( identificator_type::template get<anchor_type>() )
            {
             this->identifier( identificator_type::template get<anchor_type>() );
             this->signature().resize( 3 );

             this->signature()[0] = identificator_type::template get< typename ::reflection::type::trait<return_name>::instance_type >();
             this->signature()[1] = identificator_type::template get< typename ::reflection::type::trait< first_name>::instance_type >();
             this->signature()[2] = identificator_type::template get< typename ::reflection::type::trait<second_name>::instance_type >();
           }

         public:
           using property_type::execute;
           bool execute( typename argument_type::container_type & argument_param )const
            {
             if( false == argument_type::check( argument_param, this->signature() ) )
              {
               return false;
              }

             typedef ::reflection::content::function::call_struct< return_name, first_name, second_name >   call_type;

             auto  * a0 = call_type::u0_type::return_get( *(argument_param[0]) );if( nullptr == a0 ) return false;
             auto  * a1 = call_type::u1_type::get( *(argument_param[1]) );if( nullptr == a1 ) return false;
             auto  * a2 = call_type::u2_type::get( *(argument_param[2]) );if( nullptr == a2 ) return false;

             call_type::process( *this, *a0, *a1, *a2 );

             return true;
            }
        };

      template< typename identifier_name, typename return_name, typename first_name >
       class pure_class< identifier_name, return_name, first_name, void, void, void,void>
        : virtual public ::reflection::content::function::algorithm_class< identifier_name >
        , virtual public ::reflection::property::function::pure_class<return_name,first_name,void,void,void,void>
        {
         public:
           typedef identifier_name identifier_type;

           typedef return_name    return_type;
           typedef  first_name     first_type;

           typedef ::reflection::content::pure_class< identifier_name >        content_type;
           typedef ::reflection::property::function::pure_class<return_name,first_name,void,void,void,void>   property_type;
           typedef ::reflection::content::function::algorithm_class<identifier_type>   algorithm_type;

           typedef ::reflection::type::name::identificatorX< identifier_type > identificator_type;
           typedef typename ::reflection::content::function::signature_struct<identifier_type>::container_type   signature_type;
           typedef typename ::reflection::content::function::argument_struct<identifier_type>                    argument_type;

           typedef  algorithm_type anchor_type;

         public:
           pure_class()
            : content_type( identificator_type::template get<anchor_type>() )
            {
             this->identifier( identificator_type::template get<anchor_type>() );
             this->signature().resize( 2 );
             this->signature()[0] = identificator_type::template get< typename ::reflection::type::trait<return_name>::instance_type >();
             this->signature()[1] = identificator_type::template get< typename ::reflection::type::trait< first_name>::instance_type >();
           }

         public:
           using property_type::execute;
           bool execute( typename argument_type::container_type & argument_param )const
            {
             if( false == argument_type::check( argument_param, this->signature() ) )
              {
               return false;
              }

             typedef ::reflection::content::function::call_struct< return_name, first_name >   call_type;

             auto  * a0 = call_type::u0_type::return_get( *(argument_param[0]) );if( nullptr == a0 ) return false;
             auto  * a1 = call_type::u1_type::get( *(argument_param[1]) );if( nullptr == a1 ) return false;

             call_type::process( *this, *a0, *a1 );
             return true;
            }
        };

      template< typename identifier_name, typename return_name>
       class pure_class< identifier_name,  return_name, void, void, void, void,void>
        : virtual public ::reflection::content::function::algorithm_class< identifier_name >
        , virtual public ::reflection::property::function::pure_class<return_name,void,void,void,void,void>
        {
         public:
           typedef identifier_name identifier_type;

           typedef return_name    return_type;

           typedef ::reflection::content::pure_class< identifier_name >        content_type;
           typedef ::reflection::property::function::pure_class<return_name,void,void,void,void,void>   property_type;
           typedef ::reflection::content::function::algorithm_class<identifier_type>   algorithm_type;

           typedef ::reflection::type::name::identificatorX< identifier_type > identificator_type;
           typedef typename ::reflection::content::function::signature_struct<identifier_type>::container_type   signature_type;
           typedef typename ::reflection::content::function::argument_struct<identifier_type>                   argument_type;

           typedef  algorithm_type anchor_type;

         public:
           pure_class()
            : content_type( identificator_type::template get<anchor_type>() )
            {
             this->identifier( identificator_type::template get<anchor_type>() );
             this->signature().resize( 1 );
             this->signature()[0] = identificator_type::template get< typename ::reflection::type::trait<return_name>::instance_type >();
           }

         public:
           using property_type::execute;
           bool execute( typename argument_type::container_type & argument_param )const
            {
             if( false == argument_type::check( argument_param, this->signature() ) )
              {
               return false;
              }

             typedef ::reflection::content::function::call_struct< return_name >   call_type;

             auto  * a0 = call_type::u0_type::return_get( *(argument_param[0]) );if( nullptr == a0 ) return false;

             call_type::process( *this, *a0 );
             return true;
            }
        };


      template< typename identifier_name >
       class pure_class< identifier_name,  void, void, void, void, void,void>
        : virtual public ::reflection::content::function::algorithm_class< identifier_name >
        , virtual public ::reflection::property::function::pure_class<void,void,void,void,void,void>
        {
         public:
           typedef identifier_name identifier_type;

           typedef void    return_type;

           typedef ::reflection::content::pure_class< identifier_name >        content_type;
           typedef ::reflection::property::function::pure_class<void,void,void,void,void,void>   property_type;
           typedef ::reflection::content::function::algorithm_class<identifier_type>   algorithm_type;

           typedef ::reflection::type::name::identificatorX< identifier_type > identificator_type;
           typedef typename ::reflection::content::function::signature_struct<identifier_type>::container_type   signature_type;
           typedef typename ::reflection::content::function::argument_struct<identifier_type>                   argument_type;

           typedef  algorithm_type anchor_type;

         public:
           pure_class()
            : content_type( identificator_type::template get<anchor_type>() )
            {
             this->identifier( identificator_type::template get<anchor_type>() );
             this->signature().resize( 1 );
             this->signature()[0] = identificator_type::template get< typename ::reflection::type::trait<void>::instance_type >();
           }

         public:
           using property_type::execute;
           bool execute( typename argument_type::container_type & argument_param )const
            {
             if( false == argument_type::check( argument_param, this->signature() ) )
              {
               return false;
              }

             this->execute();

             return true;
            }
        };

      }
    }
  }

#endif
