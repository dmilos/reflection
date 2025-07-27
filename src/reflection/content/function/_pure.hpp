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

             typedef ::reflection::content::function::signature_struct<identifier_type> sign_type;
             sign_type::template construct<return_name,first_name,second_name,third_name,fourth_name,fifth_name>( this->signature() ); 
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

             return call_type::process(
                 *this,
                 *(argument_param[0]),
                 *(argument_param[1]),
                 *(argument_param[2]),
                 *(argument_param[3]),
                 *(argument_param[4]),
                 *(argument_param[5])
               );
            }
        };

      template< typename identifier_name, typename return_name, typename first_name, typename second_name, typename third_name, typename fourth_name>
       class pure_class< identifier_name, return_name, first_name, second_name, third_name, fourth_name,void>
        : virtual public ::reflection::content::function::algorithm_class< identifier_name >
        , virtual public ::reflection::property::function::pure_class<return_name,first_name,second_name,third_name,fourth_name>
        {
         public:
           typedef identifier_name identifier_type;

           typedef return_name    return_type;
           typedef  first_name     first_type;
           typedef second_name    second_type;
           typedef  third_name     third_type;
           typedef fourth_name    fourth_type;

           typedef ::reflection::content::pure_class< identifier_name >        content_type;
           typedef ::reflection::property::function::pure_class<return_name,first_name,second_name,third_name,fourth_name>   property_type;
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

             typedef ::reflection::content::function::signature_struct<identifier_type> sign_type;
             sign_type::template construct<return_name,first_name,second_name,third_name,fourth_name>( this->signature() ); 
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

             return call_type::process(
                 *this,
                 *(argument_param[0]),
                 *(argument_param[1]),
                 *(argument_param[2]),
                 *(argument_param[3]),
                 *(argument_param[4])
               );
            }
        };

      template< typename identifier_name, typename return_name, typename first_name, typename second_name, typename third_name>
       class pure_class< identifier_name, return_name, first_name, second_name, third_name, void,void>
        : virtual public ::reflection::content::function::algorithm_class< identifier_name >
        , virtual public ::reflection::property::function::pure_class<return_name,first_name,second_name,third_name>
        {
         public:
           typedef identifier_name identifier_type;

           typedef return_name    return_type;
           typedef  first_name     first_type;
           typedef second_name    second_type;
           typedef  third_name     third_type;

           typedef ::reflection::content::pure_class< identifier_name >        content_type;
           typedef ::reflection::property::function::pure_class<return_name,first_name,second_name,third_name>   property_type;
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

             typedef ::reflection::content::function::signature_struct<identifier_type> sign_type;
             sign_type::template construct<return_name,first_name,second_name,third_name>( this->signature() );
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

             return call_type::process(
                 *this,
                 *(argument_param[0]),
                 *(argument_param[1]),
                 *(argument_param[2]),
                 *(argument_param[3])
               );
            }
        };

      template< typename identifier_name, typename return_name, typename first_name, typename second_name>
       class pure_class< identifier_name, return_name, first_name, second_name, void, void,void>
        : virtual public ::reflection::content::function::algorithm_class< identifier_name >
        , virtual public ::reflection::property::function::pure_class<return_name,first_name,second_name>
        {
         public:
           typedef identifier_name identifier_type;

           typedef return_name    return_type;
           typedef  first_name     first_type;
           typedef second_name    second_type;

           typedef ::reflection::content::pure_class< identifier_name >        content_type;
           typedef ::reflection::property::function::pure_class<return_name,first_name,second_name>   property_type;
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

             typedef ::reflection::content::function::signature_struct<identifier_type> sign_type;
             sign_type::template construct<return_name,first_name,second_name>( this->signature() );
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

             return call_type::process(
                 *this,
                 *(argument_param[0]),
                 *(argument_param[1]),
                 *(argument_param[2])
               );
            }
        };

      template< typename identifier_name, typename return_name, typename first_name >
       class pure_class< identifier_name, return_name, first_name, void, void, void,void>
        : virtual public ::reflection::content::function::algorithm_class< identifier_name >
        , virtual public ::reflection::property::function::pure_class<return_name,first_name>
        {
         public:
           typedef identifier_name identifier_type;

           typedef return_name    return_type;
           typedef  first_name     first_type;

           typedef ::reflection::content::pure_class< identifier_name >        content_type;
           typedef ::reflection::property::function::pure_class<return_name,first_name>   property_type;
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

             typedef ::reflection::content::function::signature_struct<identifier_type> sign_type;
             sign_type::template construct<return_name,first_name>( this->signature() );
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

             return call_type::process(
                 *this,
                 *(argument_param[0]),
                 *(argument_param[1])
               );
            }
        };

      template< typename identifier_name, typename return_name>
       class pure_class< identifier_name,  return_name, void, void, void, void,void>
        : virtual public ::reflection::content::function::algorithm_class< identifier_name >
        , virtual public ::reflection::property::function::pure_class<return_name>
        {
         public:
           typedef identifier_name identifier_type;

           typedef return_name    return_type;

           typedef ::reflection::content::pure_class< identifier_name >        content_type;
           typedef ::reflection::property::function::pure_class<return_name>   property_type;
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

             typedef ::reflection::content::function::signature_struct<identifier_type> sign_type;
             sign_type::template construct<return_name>( this->signature() );
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

             return call_type::process(
                 *this,
                 *(argument_param[0])
               );
            }
        };


      template< typename identifier_name >
       class pure_class< identifier_name,  void, void, void, void, void,void>
        : virtual public ::reflection::content::function::algorithm_class< identifier_name >
        , virtual public ::reflection::property::function::pure_class<void>
        {
         public:
           typedef identifier_name identifier_type;

           typedef void    return_type;

           typedef ::reflection::content::pure_class< identifier_name >        content_type;
           typedef ::reflection::property::function::pure_class<void>   property_type;
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

             typedef ::reflection::content::function::signature_struct<identifier_type> sign_type;
             sign_type::template construct<void>( this->signature() );
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
