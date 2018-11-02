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


namespace reflection
 {
  namespace content
   {
    namespace function
     {

      template
       <
         typename identifier_name
        ,typename return_name
        ,typename first_name
        ,typename second_name
        ,typename third_name
        ,typename fourth_name
        ,typename fifth_name
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
           typedef ::reflection::content::function::context_class<identifier_type>   context_type;

           typedef ::reflection::type::name::identificatorX< identifier_type > identificator_type;
           typedef typename ::reflection::content::function::signature_struct<identifier_type>::container_type   signature_type;
           typedef typename ::reflection::content::function::argument_struct<identifier_type>                   argument_type;


           //typedef return_name (anchor_type)(first_name,second_name,third_name,fourth_name,fifth_name);
           typedef  context_type anchor_type;

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
             this->signature()[5] = identificator_type::template get<typename ::reflection::type::trait<  fifth_name>::instance_type >();
            }

         public:
           using property_type::execute;
           bool execute( typename argument_type::typedef_type & argument_param )const
            {
             if( false == argument_type::check( argument_param, this->signature() ) )
              {
               return false;
              }

             typedef typename ::reflection::type::trait<return_type>::image_type image_type;

             typedef ::reflection::content::function::unpack_struct<return_name>   p0_type;
             typedef ::reflection::content::function::unpack_struct< first_name>   p1_type;
             typedef ::reflection::content::function::unpack_struct<second_name>   p2_type;
             typedef ::reflection::content::function::unpack_struct< third_name>   p3_type;
             typedef ::reflection::content::function::unpack_struct<fourth_name>   p4_type;
             typedef ::reflection::content::function::unpack_struct< fifth_name>   p5_type;

             typename p0_type::return_type * a0 = p0_type::get( argument_param[0] );
             typename p1_type::return_type * a1 = p1_type::get( argument_param[1] );
             typename p2_type::return_type * a2 = p2_type::get( argument_param[2] );
             typename p3_type::return_type * a3 = p3_type::get( argument_param[3] );
             typename p4_type::return_type * a4 = p4_type::get( argument_param[4] );
             typename p5_type::return_type * a5 = p5_type::get( argument_param[5] );

             a0->process(  property_type::execute( p1_type::value(*a1), p2_type::value(*a2), p3_type::value(*a3), p4_type::value(*a4), p5_type::value(*a5) ) );
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
           typedef ::reflection::content::function::context_class<identifier_type>   context_type;

           typedef ::reflection::type::name::identificatorX< identifier_type > identificator_type;
           typedef typename ::reflection::content::function::signature_struct<identifier_type>::container_type   signature_type;
           typedef typename ::reflection::content::function::argument_struct<identifier_type>                   argument_type;

           //typedef return_name (anchor_type)(first_name,second_name,third_name,fourth_name);
           typedef  context_type anchor_type;

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

             typedef typename ::reflection::type::trait<return_type>::image_type image_type;

             typedef ::reflection::property::mutate::pure_class<image_type,bool>   p0_type;
             typedef ::reflection::content::function::unpack_struct< first_name>   p1_type;
             typedef ::reflection::content::function::unpack_struct<second_name>   p2_type;
             typedef ::reflection::content::function::unpack_struct< third_name>   p3_type;
             typedef ::reflection::content::function::unpack_struct<fourth_name>   p4_type;

             p0_type              * a0 = dynamic_cast<p0_type*>(  argument_param[0] );
             typename p1_type::result_type * a1 = p1_type::get( *(argument_param[1]) );
             typename p2_type::result_type * a2 = p2_type::get( *(argument_param[2]) );
             typename p3_type::result_type * a3 = p3_type::get( *(argument_param[3]) );
             typename p4_type::result_type * a4 = p4_type::get( *(argument_param[4]) );

             a0->process( this->execute( p1_type::value(*a1), p2_type::value(*a2), p3_type::value(*a3), p4_type::value(*a4) ) );

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
           typedef ::reflection::content::function::context_class<identifier_type>   context_type;

           typedef ::reflection::type::name::identificatorX< identifier_type > identificator_type;
           typedef typename ::reflection::content::function::signature_struct<identifier_type>::container_type   signature_type;
           typedef typename ::reflection::content::function::argument_struct<identifier_type>                   argument_type;

           //typedef return_name (anchor_type)(first_name,second_name,third_name);
           typedef  context_type anchor_type;

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

             typedef typename ::reflection::type::trait<return_type>::image_type image_type;

             typedef ::reflection::property::mutate::pure_class<image_type,bool>   p0_type;
             typedef ::reflection::content::function::unpack_struct< first_name>   p1_type;
             typedef ::reflection::content::function::unpack_struct<second_name>   p2_type;
             typedef ::reflection::content::function::unpack_struct< third_name>   p3_type;

             p0_type              * a0 = dynamic_cast<p0_type*>(  argument_param[0] );
             typename p1_type::result_type * a1 = p1_type::get( *(argument_param[1]) );
             typename p2_type::result_type * a2 = p2_type::get( *(argument_param[2]) );
             typename p3_type::result_type * a3 = p3_type::get( *(argument_param[3]) );

             a0->process( this->execute( p1_type::value(*a1), p2_type::value(*a2), p3_type::value(*a3) ) );

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
           typedef ::reflection::content::function::context_class<identifier_type>   context_type;

           typedef ::reflection::type::name::identificatorX< identifier_type > identificator_type;
           typedef typename ::reflection::content::function::signature_struct<identifier_type>::container_type   signature_type;
           typedef typename ::reflection::content::function::argument_struct<identifier_type>                   argument_type;

           //typedef return_name (anchor_type)(first_name,second_name);
           typedef  context_type anchor_type;

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

             typedef typename ::reflection::type::trait<return_type>::image_type image_type;

             typedef ::reflection::property::mutate::pure_class<image_type,bool>   p0_type;
             typedef ::reflection::content::function::unpack_struct< first_name>   p1_type;
             typedef ::reflection::content::function::unpack_struct<second_name>   p2_type;

             p0_type              * a0 = dynamic_cast<p0_type*>(  argument_param[0] );
             typename p1_type::result_type * a1 = p1_type::get( *(argument_param[1]) );
             typename p2_type::result_type * a2 = p2_type::get( *(argument_param[2]) );

             a0->process( this->execute( p1_type::value(*a1), p2_type::value(*a2) ) );
             return true;
            }
        };

      template< typename identifier_name, typename return_name, typename first_name>
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
           typedef ::reflection::content::function::context_class<identifier_type>   context_type;

           typedef ::reflection::type::name::identificatorX< identifier_type > identificator_type;
           typedef typename ::reflection::content::function::signature_struct<identifier_type>::container_type   signature_type;
           typedef typename ::reflection::content::function::argument_struct<identifier_type>                    argument_type;

           //typedef return_name (anchor_type)(first_name);
           typedef  context_type anchor_type;

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

             typedef typename ::reflection::type::trait<return_type>::image_type image_type;

             typedef ::reflection::property::mutate::pure_class<image_type,bool>   p0_type;
             typedef ::reflection::content::function::unpack_struct< first_name>   p1_type;

                      p0_type              * a0 = dynamic_cast<p0_type*>( argument_param[0] );
             typename p1_type::result_type * a1 = p1_type::get( *(argument_param[1]) );

             a0->process( this->execute( p1_type::value(*a1) ) );
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
           typedef ::reflection::content::function::context_class<identifier_type>   context_type;

           typedef ::reflection::type::name::identificatorX< identifier_type > identificator_type;
           typedef typename ::reflection::content::function::signature_struct<identifier_type>::container_type   signature_type;
           typedef typename ::reflection::content::function::argument_struct<identifier_type>                   argument_type;

           //typedef return_name (anchor_type)();
           typedef  context_type anchor_type;

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

             typedef typename ::reflection::type::trait<return_type>::image_type image_type;

             typedef ::reflection::property::mutate::pure_class<image_type,bool>   p0_type;

             p0_type              * a0 = dynamic_cast<p0_type*>( argument_param[0] );

             a0->process( this->execute( ) );
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
           typedef ::reflection::content::function::context_class<identifier_type>   context_type;

           typedef ::reflection::type::name::identificatorX< identifier_type > identificator_type;
           typedef typename ::reflection::content::function::signature_struct<identifier_type>::container_type   signature_type;
           typedef typename ::reflection::content::function::argument_struct<identifier_type>                   argument_type;

           //typedef void (anchor_type)();
           typedef  context_type anchor_type;

         public:
           pure_class()
            : content_type( identificator_type::template get<anchor_type>() )
            {
             this->identifier( identificator_type::template get<anchor_type>() );
             this->signature().resize( 0 );
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
