#ifndef reflection_content_function__pure_hpp
 #define reflection_content_function__pure_hpp

 // ::reflection::content::function::pure_class<return_name,first_name,second_name,third_name,fourth_name,fifth_name>

#include "../../type/name/id.hpp"
#include "../../property/function/_pure.hpp"

#include "../_pure.hpp"

#include "./signature.hpp"
#include "./context.hpp"


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
        : virtual public ::reflection::content::pure_class< return_name (first_name,second_name,third_name,fourth_name,fifth_name) >
        , virtual public ::reflection::property::function::pure_class<return_name,first_name,second_name,third_name,fourth_name,fifth_name>
        , virtual public ::reflection::content::function::context_class<identifier_name>
        {
         public:
           typedef identifier_name identifier_type;

           typedef return_name    return_type;
           typedef  first_name     first_type;
           typedef second_name    second_type;
           typedef  third_name     third_type;
           typedef fourth_name    fourth_type;
           typedef  fifth_name     fifth_type;


           typedef ::reflection::content::pure_class< return_name (first_name,second_name,third_name,fourth_name,fifth_name) >        content_type;
           typedef ::reflection::property::function::pure_class<return_name,first_name,second_name,third_name,fourth_name,fifth_name>   property_type;
           typedef ::reflection::content::function::context_class<identifier_type>   context_type;

           typedef ::reflection::type::name::identificatorX< identifier_type > identificator_type;
           typedef typename ::reflection::content::function::signature_struct<identifier_type>::typedef_type   signature_type;
           typedef typename ::reflection::content::function::argument_struct<identifier_type>::typedef_type     argument_type;

         public:
           pure_class()
            {
             this->signature().resize( 6 );
             this->signature()[0] = identificator_type::template get<return_name>();
             this->signature()[1] = identificator_type::template get< first_name>();
             this->signature()[2] = identificator_type::template get<second_name>();
             this->signature()[3] = identificator_type::template get< third_name>();
             this->signature()[4] = identificator_type::template get<fourth_name>();
             this->signature()[5] = identificator_type::template get< fifth_name>();
            }

         public:
           using property_type::execute;
           bool execute( argument_type & argument_param )const
            {
             //! TODO Unrol and call
             return false;
            }
        };

      template< typename identifier_name, typename return_name, typename first_name, typename second_name, typename third_name, typename fourth_name>
       class pure_class< identifier_name, return_name, first_name, second_name, third_name, fourth_name,void>
        : virtual public ::reflection::content::pure_class< return_name (first_name,second_name,third_name,fourth_name) >
        , virtual public ::reflection::property::function::pure_class<return_name,first_name,second_name,third_name,fourth_name,void>
        , virtual public ::reflection::content::function::context_class<identifier_name>
        {
         public:
           typedef identifier_name identifier_type;

           typedef return_name    return_type;
           typedef  first_name     first_type;
           typedef second_name    second_type;
           typedef  third_name     third_type;
           typedef fourth_name    fourth_type;


           typedef ::reflection::content::pure_class< return_name (first_name,second_name,third_name,fourth_name) >        content_type;
           typedef ::reflection::property::function::pure_class<return_name,first_name,second_name,third_name,fourth_name,void>   property_type;

           typedef ::reflection::type::name::identificatorX< identifier_type > identificator_type;
           typedef typename ::reflection::content::function::signature_struct<identifier_type>::typedef_type   signature_type;
           typedef typename ::reflection::content::function::argument_struct<identifier_type>::typedef_type     argument_type;

         public:
           pure_class()
            {
             this->signature().resize( 6 );
             this->signature()[0] = identificator_type::template get< return_name >();
             this->signature()[1] = identificator_type::template get<  first_name >();
             this->signature()[2] = identificator_type::template get< second_name >();
             this->signature()[3] = identificator_type::template get<  third_name >();
             this->signature()[4] = identificator_type::template get< fourth_name >();
             this->signature()[5] = identificator_type::template get< void >();
            }

         public:
           using property_type::execute;
           bool execute( argument_type & argument_param )const
            {
             //! TODO Unrol and call
             return false;
            }
        };

      template< typename identifier_name, typename return_name, typename first_name, typename second_name, typename third_name>
       class pure_class< identifier_name, return_name, first_name, second_name, third_name, void,void>
        : virtual public ::reflection::content::pure_class< return_name (first_name,second_name,third_name) >
        , virtual public ::reflection::property::function::pure_class<return_name,first_name,second_name,third_name,void,void>
        , virtual public ::reflection::content::function::context_class<identifier_name>
        {
         public:
           typedef identifier_name identifier_type;

           typedef return_name    return_type;
           typedef  first_name     first_type;
           typedef second_name    second_type;
           typedef  third_name     third_type;

           typedef ::reflection::content::pure_class< return_name (first_name,second_name,third_name) >        content_type;
           typedef ::reflection::property::function::pure_class<return_name,first_name,second_name,third_name,void,void>   property_type;

           typedef ::reflection::type::name::identificatorX< identifier_type > identificator_type;
           typedef typename ::reflection::content::function::signature_struct<identifier_type>::typedef_type   signature_type;
           typedef typename ::reflection::content::function::argument_struct<identifier_type>::typedef_type     argument_type;

         public:
           pure_class()
            {
             this->signature().resize( 6 );
             this->signature()[0] = identificator_type::template get< return_name >();
             this->signature()[1] = identificator_type::template get<  first_name >();
             this->signature()[2] = identificator_type::template get< second_name >();
             this->signature()[3] = identificator_type::template get<  third_name >();
             this->signature()[4] = identificator_type::template get< void >();
             this->signature()[5] = identificator_type::template get< void >();
            }

         public:
           using property_type::execute;
           bool execute( argument_type & argument_param )const
            {
             //! TODO Unrol and call
             return false;
            }
        };

      template< typename identifier_name, typename return_name, typename first_name, typename second_name>
       class pure_class< identifier_name, return_name, first_name, second_name, void, void,void>
        : virtual public ::reflection::content::pure_class< return_name (first_name,second_name) >
        , virtual public ::reflection::property::function::pure_class<return_name,first_name,second_name,void,void,void>
        , virtual public ::reflection::content::function::context_class<identifier_name>
        {
         public:
           typedef identifier_name identifier_type;

           typedef return_name    return_type;
           typedef  first_name     first_type;
           typedef second_name    second_type;

           typedef ::reflection::content::pure_class< return_name (first_name,second_name) >        content_type;
           typedef ::reflection::property::function::pure_class<return_name,first_name,second_name,void,void,void>   property_type;

           typedef ::reflection::type::name::identificatorX< identifier_type > identificator_type;
           typedef typename ::reflection::content::function::signature_struct<identifier_type>::typedef_type   signature_type;
           typedef typename ::reflection::content::function::argument_struct<identifier_type>::typedef_type     argument_type;

         public:
           pure_class()
            {
             this->signature().resize( 6 );
             this->signature()[0] = identificator_type::template get< return_name >();
             this->signature()[1] = identificator_type::template get<  first_name >();
             this->signature()[2] = identificator_type::template get< second_name >();
             this->signature()[3] = identificator_type::template get<  void >();
             this->signature()[4] = identificator_type::template get<  void >();
             this->signature()[5] = identificator_type::template get<  void >();
            }

         public:
           using property_type::execute;
           bool execute( argument_type & argument_param )const
            {
             //! TODO Unrol and call
             return false;
            }
        };

      template< typename identifier_name, typename return_name, typename first_name>
       class pure_class< identifier_name, return_name, first_name, void, void, void,void>
        : virtual public ::reflection::content::pure_class< return_name (first_name) >
        , virtual public ::reflection::property::function::pure_class<return_name,first_name,void,void,void,void>
        , virtual public ::reflection::content::function::context_class<identifier_name>
        {
         public:
           typedef identifier_name identifier_type;

           typedef return_name    return_type;
           typedef  first_name     first_type;

           typedef ::reflection::content::pure_class< return_name (first_name) >        content_type;
           typedef ::reflection::property::function::pure_class<return_name,first_name,void,void,void,void>   property_type;

           typedef ::reflection::type::name::identificatorX< identifier_type > identificator_type;
           typedef typename ::reflection::content::function::signature_struct<identifier_type>::typedef_type   signature_type;
           typedef typename ::reflection::content::function::argument_struct<identifier_type>::typedef_type     argument_type;

         public:
           pure_class()
            {
             this->signature().resize( 6 );
             this->signature()[0] = identificator_type::template get< return_name >();
             this->signature()[1] = identificator_type::template get<  first_name >();
             this->signature()[2] = identificator_type::template get< void >();
             this->signature()[3] = identificator_type::template get< void >();
             this->signature()[4] = identificator_type::template get< void >();
             this->signature()[5] = identificator_type::template get< void >();
            }

         public:
           using property_type::execute;
           bool execute( argument_type & argument_param )const
            {
             //! TODO Unrol and call
             return false;
            }
        };

      template< typename identifier_name, typename return_name>
       class pure_class< identifier_name,  return_name, void, void, void, void,void>
        : virtual public ::reflection::content::pure_class< return_name () >
        , virtual public ::reflection::property::function::pure_class<return_name,void,void,void,void,void>
        , virtual public ::reflection::content::function::context_class<identifier_name>
        {
         public:
           typedef identifier_name identifier_type;

           typedef return_name    return_type;

           typedef ::reflection::content::pure_class< return_name () >        content_type;
           typedef ::reflection::property::function::pure_class<return_name,void,void,void,void,void>   property_type;

           typedef ::reflection::type::name::identificatorX< identifier_type > identificator_type;
           typedef typename ::reflection::content::function::signature_struct<identifier_type>::typedef_type   signature_type;
           typedef typename ::reflection::content::function::argument_struct<identifier_type>::typedef_type     argument_type;

         public:
           pure_class()
            {
             this->signature().resize( 6 );
             this->signature()[0] = identificator_type::template get< return_name >();
             this->signature()[1] = identificator_type::template get< void >();
             this->signature()[2] = identificator_type::template get< void >();
             this->signature()[3] = identificator_type::template get< void >();
             this->signature()[4] = identificator_type::template get< void >();
             this->signature()[5] = identificator_type::template get< void >();
            }

         public:
           using property_type::execute;
           bool execute( argument_type & argument_param )const
            {
             //! TODO Unrol and call
             return false;
            }
        };

      }
    }
  }

#endif
