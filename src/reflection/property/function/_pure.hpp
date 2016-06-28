#ifndef reflection_property_function_pure
#define reflection_property_function_pure

// ::reflection::property::function::pure_class<return_name,first_name,second_name,third_name,fourth_name,fifth_name>
// ::reflection::property::function::check<return_name,first_name,second_name,third_name,fourth_name,fifth_name>()
// ::reflection::property::function::execute<return_name,first_name,second_name,third_name,fourth_name,fifth_name>()

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
       class pure_class
        : public ::reflection::property::pure_class
        {
         public:
           typedef return_name    return_type;
           typedef  first_name     first_type;
           typedef second_name    second_type;
           typedef  third_name     third_type;
           typedef fourth_name    fourth_type;
           typedef  fifth_name     fifth_type;

                    pure_class(){}
           virtual ~pure_class(){}

           virtual return_name execute( first_name first_param, second_name second_param, third_name third_param, fourth_name fourth_param, fifth_name fifth_param )=0;
         //virtual return_name execute( first_name first_param, second_name second_param, third_name third_param, fourth_name fourth_param, fifth_name fifth_param )const=0;
        };

      template< typename return_name, typename first_name, typename second_name, typename third_name, typename fourth_name >
       class pure_class< return_name,first_name,second_name,third_name,fourth_name,void>
        : public ::reflection::property::pure_class
        {
         public:
           typedef return_name    return_type;
           typedef  first_name     first_type;
           typedef second_name    second_type;
           typedef  third_name     third_type;
           typedef fourth_name    fourth_type;

                    pure_class(){}
           virtual ~pure_class(){}
         public:
           virtual return_name execute( first_name first_param, second_name second_param, third_name third_param, fourth_name fourth_param )=0;
         //virtual return_name execute( first_name first_param, second_name second_param, third_name third_param, fourth_name fourth_param )const=0;
        };

      template< typename return_name, typename first_name, typename second_name, typename third_name >
       class pure_class< return_name,first_name,second_name,third_name,void,void>
        : public ::reflection::property::pure_class
        {
         public:
           typedef return_name    return_type;
           typedef  first_name     first_type;
           typedef second_name    second_type;
           typedef  third_name     third_type;

                    pure_class(){}
           virtual ~pure_class(){}

         public:
           virtual return_name execute( first_name first_param, second_name second_param, third_name third_param )=0;/*{ return this->execute( first_param,second_param,third_param ); }*/
         //virtual return_name execute( first_name first_param, second_name second_param, third_name third_param )const=0;
        };

      template< typename return_name, typename first_name, typename second_name >
       class pure_class< return_name,first_name,second_name,void,void,void>
        : public ::reflection::property::pure_class
        {
         public:
           typedef return_name    return_type;
           typedef  first_name     first_type;
           typedef second_name    second_type;

                    pure_class(){}
           virtual ~pure_class(){}

         public:
           virtual return_name execute( first_name first_param, second_name second_param )=0;/*{ return this->execute( first_param,second_param ); }*/
         //virtual return_name execute( first_name first_param, second_name second_param )const=0;
        };

      template< typename return_name, typename first_name >
       class pure_class< return_name,first_name,void,void,void,void>
        : public ::reflection::property::pure_class
        {
         public:
           typedef return_name    return_type;
           typedef  first_name     first_type;

                    pure_class(){}
           virtual ~pure_class(){}

         public:
           virtual return_name execute( first_name first_param )=0;/*{ return this->execute( first_param ); }*/
         //virtual return_name execute( first_name first_param )const=0;
        };

      template< typename return_name >
       class pure_class< return_name,void,void,void,void,void>
        : public ::reflection::property::pure_class
        {
         public:
           typedef return_name    return_type;

                    pure_class(){}
           virtual ~pure_class(){}

         public:
           virtual return_name execute()=0;/*{ return this->execute( ); }*/
         //virtual return_name execute()const=0;
        };

      template< typename return_name=void, typename first_name=void, typename second_name=void, typename third_name=void, typename fourth_name=void, typename fifth_name=void >
       inline bool check( ::reflection::property::pure_class const& property_param )
        {
         typedef ::reflection::property::function::pure_class<return_name,first_name,second_name,third_name,fourth_name,fifth_name > function_type;
         return nullptr != dynamic_cast< function_type const*>( &property_param );
        }

      template< typename return_name >
       inline
       return_name
       execute( ::reflection::property::pure_class & property_param )
        {
         typedef ::reflection::property::function::pure_class<return_name,void,void,void,void,void> function_type;

         return dynamic_cast< function_type &>( property_param ).execute();
        }

      // TODO template< typename return_name >
      // TODO  inline
      // TODO  return_name
      // TODO  execute( ::reflection::property::pure_class const& property_param )
      // TODO   {
      // TODO    typedef ::reflection::property::function::pure_class<return_name,void,void,void,void,void> function_type;
      // TODO 
      // TODO    return dynamic_cast< function_type &>( property_param ).execute();
      // TODO   }

      template< typename return_name, typename first_name >
       inline
       return_name
       execute( ::reflection::property::pure_class & property_param, first_name first_param )
        {
         typedef ::reflection::property::function::pure_class<return_name,first_name,void,void,void,void> function_type;

         return dynamic_cast< function_type &>( property_param ).execute( first_param );
        }

      template< typename return_name, typename first_name, typename second_name >
       inline
       return_name
       execute( ::reflection::property::pure_class & property_param, first_name first_param, second_name second_param )
        {
         typedef ::reflection::property::function::pure_class<return_name,first_name,second_name,void,void,void> function_type;

         return dynamic_cast< function_type &>( property_param ).execute( first_param, second_param );
        }

      template< typename return_name, typename first_name, typename second_name, typename third_name >
       inline
       return_name
       execute( ::reflection::property::pure_class & property_param, first_name first_param, second_name second_param, third_name third_param )
        {
         typedef ::reflection::property::function::pure_class<return_name,first_name,second_name,third_name,void,void> function_type;

         return dynamic_cast< function_type &>( property_param ).execute( first_param, second_param, third_param );
        }

      template< typename return_name, typename first_name, typename second_name, typename third_name, typename fourth_name >
       inline
       return_name
       execute( ::reflection::property::pure_class & property_param, first_name first_param, second_name second_param, third_name third_param, fourth_name fourth_param )
        {
         typedef ::reflection::property::function::pure_class<return_name,first_name,second_name,third_name,fourth_name,void> function_type;

         return dynamic_cast< function_type &>( property_param ).execute( first_param, second_param, third_param, fourth_param );
        }

      template< typename return_name, typename first_name, typename second_name, typename third_name, typename fourth_name, typename fifth_name >
       inline
       return_name
       execute( ::reflection::property::pure_class & property_param, first_name first_param, second_name second_param, third_name third_param, fourth_name fourth_param, fifth_name fifth_param )
        {
         typedef ::reflection::property::function::pure_class<return_name,first_name,second_name,third_name,fourth_name,fifth_name> function_type;

         return dynamic_cast< function_type &>( property_param ).execute( first_param, second_param, third_param, fourth_param, fifth_param );
        }

     }
   }
 }

#endif
