#ifndef reflection_content_function_member_hpp
 #define reflection_content_function_member_hpp

 // ::reflection::content::function::member_class<class_name,return_name,first_name,second_name,third_name,fourth_name,fifth_name>


#include "../../property/function/member.hpp"

#include "./_pure.hpp"


namespace reflection
 {
  namespace content
   {
    namespace function
     {

      template
       <
         typename identifier_name
        ,typename class_name
        ,typename storage_name
        ,typename return_name
        ,typename first_name
        ,typename second_name
        ,typename third_name
        ,typename fourth_name
        ,typename fifth_name
        >
       class member_class
        :  public ::reflection::content::function::pure_class<identifier_name,return_name,first_name,second_name,third_name,fourth_name,fifth_name>
        ,  public ::reflection::property::function::member_class<class_name,storage_name,return_name,first_name,second_name,third_name,fourth_name,fifth_name>
        {
         public:
           typedef class_name      class_type;
           typedef return_name    return_type;
           typedef  first_name     first_type;
           typedef second_name    second_type;
           typedef  third_name     third_type;
           typedef fourth_name    fourth_type;
           typedef  fifth_name     fifth_type;

           typedef ::reflection::content::function::pure_class<identifier_name,return_name,first_name,second_name,third_name,fourth_name,fifth_name>              content_type;
           typedef ::reflection::property::function::member_class<class_name,storage_name,return_name,first_name,second_name,third_name,fourth_name,fifth_name>   property_type;

           typedef typename property_type::function_const_type function_const_type;
           typedef typename property_type::function_type       function_type;

         public:
           using property_type::property_type;

         public:
           return_type execute( first_name first, second_name second, third_name third, fourth_name fourth, fifth_name fifth )const
            {
             return this->property_type::execute( first, second, third, fourth, fifth );
            }

           using content_type::signature;
        };

      template< typename identifier_name, typename class_name, typename storage_name, typename return_name, typename first_name, typename second_name, typename third_name, typename fourth_name >
       class member_class<identifier_name,class_name,storage_name,return_name,first_name,second_name,third_name,fourth_name,void>
        : virtual public ::reflection::content::function::pure_class<identifier_name,return_name,first_name,second_name,third_name,fourth_name,void>
        ,         public ::reflection::property::function::member_class<class_name,storage_name,return_name,first_name,second_name,third_name,fourth_name,void>
        {
         public:
           typedef class_name      class_type;
           typedef return_name    return_type;
           typedef  first_name     first_type;
           typedef second_name    second_type;
           typedef  third_name     third_type;
           typedef fourth_name    fourth_type;

           typedef ::reflection::content::function::pure_class<identifier_name,return_name,first_name,second_name,third_name,fourth_name,void>              content_type;
           typedef ::reflection::property::function::member_class<class_name,storage_name,return_name,first_name,second_name,third_name,fourth_name,void>   property_type;

           typedef typename property_type::function_type function_type;
           typedef typename property_type::function_const_type functionfunction_const_type_type;

         public:
           using property_type::property_type;


         public:
           return_type execute( first_name first, second_name second, third_name third, fourth_name fourth )const
            {
             return this->property_type::execute( first, second, third, fourth );
            }

           using content_type::signature;
        };

      template< typename identifier_name, typename class_name, typename storage_name, typename return_name, typename first_name, typename second_name, typename third_name >
       class member_class<identifier_name,class_name,storage_name,return_name,first_name,second_name,third_name,void,void>
        : virtual public ::reflection::content::function::pure_class<identifier_name,return_name,first_name,second_name,third_name,void,void>
        ,         public ::reflection::property::function::member_class<class_name,storage_name,return_name,first_name,second_name,third_name,void,void>
        {
         public:
           typedef class_name      class_type;
           typedef return_name    return_type;
           typedef  first_name     first_type;
           typedef second_name    second_type;
           typedef  third_name     third_type;

           typedef ::reflection::content::function::pure_class<identifier_name,return_name,first_name,second_name,third_name,void,void>              content_type;
           typedef ::reflection::property::function::member_class<class_name,storage_name,return_name,first_name,second_name,third_name,void,void>   property_type;

           typedef typename property_type::function_type function_type;
           typedef typename property_type::function_const_type functionfunction_const_type_type;

         public:
           using property_type::property_type;

         public:
           return_type execute( first_name first, second_name second, third_name third )const
            {
             return this->property_type::execute( first, second, third );
            }

           using content_type::signature;
        };

      template< typename identifier_name, typename class_name, typename storage_name, typename return_name, typename first_name, typename second_name >
       class member_class<identifier_name,class_name,storage_name,return_name,first_name,second_name,void,void,void>
        : virtual public ::reflection::content::function::pure_class<identifier_name,return_name,first_name,second_name,void,void,void>
        ,         public ::reflection::property::function::member_class<class_name,storage_name,return_name,first_name,second_name,void,void,void>
        {
         public:
           typedef class_name      class_type;
           typedef return_name    return_type;
           typedef  first_name     first_type;
           typedef second_name    second_type;

           typedef ::reflection::content::function::pure_class<identifier_name,return_name,first_name,second_name,void,void,void>              content_type;
           typedef ::reflection::property::function::member_class<class_name,storage_name,return_name,first_name,second_name,void,void,void>   property_type;

           typedef typename property_type::function_type function_type;
           typedef typename property_type::function_const_type functionfunction_const_type_type;

         public:
           using property_type::property_type;

         public:
           return_type execute( first_name first, second_name second )const
            {
             return this->property_type::execute( first, second );
            }

           using content_type::signature;
        };


      template< typename identifier_name, typename class_name, typename storage_name, typename return_name, typename first_name >
       class member_class<identifier_name,class_name,storage_name,return_name,first_name,void,void,void,void>
        : virtual public ::reflection::content::function::pure_class<identifier_name,return_name,first_name,void,void,void,void>
        ,         public ::reflection::property::function::member_class<class_name,storage_name,return_name,first_name,void,void,void,void>
        {
         public:
           typedef class_name      class_type;
           typedef return_name    return_type;
           typedef  first_name     first_type;

           typedef ::reflection::content::function::pure_class<identifier_name,return_name,first_name,void,void,void,void>                content_type;
           typedef ::reflection::property::function::member_class<class_name,storage_name,return_name,first_name,void,void,void,void>   property_type;

           typedef typename property_type::function_type function_type;
           typedef typename property_type::function_const_type functionfunction_const_type_type;

         public:
           using property_type::property_type;

         public:
           return_type execute( first_name first )const
            {
             return this->property_type::execute( first );
            }
           using content_type::signature;
        };

      template< typename identifier_name, typename class_name, typename storage_name, typename return_name >
       class member_class<identifier_name,class_name,storage_name,return_name,void,void,void,void,void>
        : virtual public ::reflection::content::function::pure_class<identifier_name,return_name,void,void,void,void,void>
        ,         public ::reflection::property::function::member_class<class_name,storage_name,return_name,void,void,void,void,void>
        {
         public:
           typedef class_name      class_type;
           typedef return_name    return_type;

           typedef ::reflection::content::function::pure_class<identifier_name,return_name,void,void,void,void,void>                content_type;
           typedef ::reflection::property::function::member_class<class_name,storage_name,return_name,void,void,void,void,void>   property_type;

           typedef typename property_type::function_type function_type;
           typedef typename property_type::function_const_type functionfunction_const_type_type;

         public:
           using property_type::property_type;

         public:
           return_type execute()const
            {
             return this->property_type::execute();
            }

           using content_type::signature;
        };

      template< typename identifier_name, typename class_name, typename storage_name, typename return_name >
       inline
       ::reflection::content::function::member_class<identifier_name,class_name,storage_name,return_name,void,void,void,void,void>
       member
        (
          storage_name const& class_param
         ,return_name (class_name::*function_param)()const
        )
        {
         typedef ::reflection::content::function::member_class<identifier_name,class_name,storage_name,return_name, void, void, void, void, void > property_type;

         return property_type( class_param, function_param );
        }


      template< typename identifier_name, typename class_name, typename storage_name, typename return_name >
       inline
       ::reflection::content::function::member_class<identifier_name,class_name,storage_name,return_name,void,void,void,void,void>
       member
        (
          storage_name const& class_param
         ,return_name (class_name::*function_param)()
        )
        {
         typedef ::reflection::content::function::member_class<identifier_name,class_name,storage_name,return_name, void, void, void, void, void > property_type;

         return property_type( class_param, function_param );
        }

      template< typename identifier_name, typename class_name, typename storage_name, typename return_name, typename first_name >
       inline
       ::reflection::content::function::member_class<identifier_name, class_name, storage_name, return_name, first_name, void, void, void, void >
       member
        (
          storage_name const& class_param
         ,return_name  (class_name::*function_param)( first_name )const
        )
        {
         typedef ::reflection::content::function::member_class<identifier_name,class_name, storage_name, return_name, first_name, void, void, void, void > property_type;

         return property_type( class_param, function_param );
        }

      template< typename identifier_name, typename class_name, typename storage_name, typename return_name, typename first_name >
       inline
       ::reflection::content::function::member_class<identifier_name, class_name, storage_name, return_name, first_name, void, void, void, void >
       member
        (
          storage_name const& class_param
         ,return_name  (class_name::*function_param)( first_name )
        )
        {
         typedef ::reflection::content::function::member_class<identifier_name,class_name, storage_name, return_name, first_name, void, void, void, void > property_type;

         return property_type( class_param, function_param );
        }


      template< typename identifier_name, typename class_name, typename storage_name, typename return_name, typename first_name, typename second_name >
       inline
       ::reflection::content::function::member_class<identifier_name,class_name, storage_name, return_name, first_name, second_name,void,void,void>
       member
        (
          storage_name const& class_param
         ,return_name  (class_name::*function_param)( first_name, second_name )const
        )
        {
         typedef ::reflection::content::function::member_class<identifier_name,class_name, storage_name, return_name, first_name, second_name, void, void, void > property_type;

         return property_type( class_param, function_param );
        }

      template< typename identifier_name, typename class_name, typename storage_name, typename return_name, typename first_name, typename second_name >
       inline
       ::reflection::content::function::member_class<identifier_name,class_name, storage_name, return_name, first_name, second_name,void,void,void>
       member
        (
          storage_name const& class_param
         ,return_name  (class_name::*function_param)( first_name, second_name )
        )
        {
         typedef ::reflection::content::function::member_class<identifier_name,class_name, storage_name, return_name, first_name, second_name, void, void, void > property_type;

         return property_type( class_param, function_param );
        }

      template< typename identifier_name, typename class_name, typename storage_name, typename return_name, typename first_name, typename second_name, typename third_name >
       inline
       ::reflection::content::function::member_class<identifier_name,class_name, storage_name, return_name, first_name, second_name, third_name,void,void>
       member
        (
          storage_name const& class_param
         ,return_name  (class_name::*function_param)( first_name, second_name, third_name )const
        )
        {
         typedef ::reflection::content::function::member_class<identifier_name,class_name, storage_name, return_name, first_name, second_name, third_name, void, void > property_type;

         return property_type( class_param, function_param );
        }

      template< typename identifier_name, typename class_name, typename storage_name, typename return_name, typename first_name, typename second_name, typename third_name >
       inline
       ::reflection::content::function::member_class<identifier_name,class_name, storage_name, return_name, first_name, second_name, third_name,void,void>
       member
        (
          storage_name const& class_param
         ,return_name  (class_name::*function_param)( first_name, second_name, third_name )
        )
        {
         typedef ::reflection::content::function::member_class<identifier_name,class_name, storage_name, return_name, first_name, second_name, third_name, void, void > property_type;

         return property_type( class_param, function_param );
        }

      template< typename identifier_name, typename class_name, typename storage_name, typename return_name, typename first_name, typename second_name, typename third_name, typename fourth_name >
       inline
       ::reflection::content::function::member_class<identifier_name,class_name, storage_name, return_name, first_name, second_name, third_name, fourth_name,void>
       member
        (
          storage_name const& class_param
         ,return_name  (class_name::*function_param)( first_name, second_name, third_name, fourth_name )const
        )
        {
         typedef ::reflection::content::function::member_class<identifier_name,class_name, storage_name, return_name, first_name, second_name, third_name, fourth_name, void > property_type;

         return property_type( class_param, function_param );
        }

      template< typename identifier_name, typename class_name, typename storage_name, typename return_name, typename first_name, typename second_name, typename third_name, typename fourth_name >
       inline
       ::reflection::content::function::member_class<identifier_name,class_name, storage_name, return_name, first_name, second_name, third_name, fourth_name,void>
       member
        (
          storage_name const& class_param
         ,return_name  (class_name::*function_param)( first_name, second_name, third_name, fourth_name )
        )
        {
         typedef ::reflection::content::function::member_class<identifier_name,class_name, storage_name, return_name, first_name, second_name, third_name, fourth_name, void > property_type;

         return property_type( class_param, function_param );
        }

      template< typename identifier_name, typename class_name, typename storage_name, typename return_name, typename first_name, typename second_name, typename third_name, typename fourth_name, typename fifth_name >
       inline
       ::reflection::content::function::member_class< identifier_name, class_name, storage_name, return_name, first_name, second_name, third_name, fourth_name, fifth_name >
       member
        (
          storage_name const& class_param
         ,return_name (class_name::*function_param)( first_name, second_name, third_name, fourth_name, fifth_name )const
        )
        {
         typedef ::reflection::content::function::member_class<identifier_name,class_name, storage_name, return_name, first_name, second_name, third_name, fourth_name, fifth_name > property_type;

         return property_type( class_param, function_param );
        }

      template< typename identifier_name, typename class_name, typename storage_name, typename return_name, typename first_name, typename second_name, typename third_name, typename fourth_name, typename fifth_name >
       inline
       ::reflection::content::function::member_class< identifier_name, class_name, storage_name, return_name, first_name, second_name, third_name, fourth_name, fifth_name >
       member
        (
          storage_name const& class_param
         ,return_name (class_name::*function_param)( first_name, second_name, third_name, fourth_name, fifth_name )
        )
        {
         typedef ::reflection::content::function::member_class<identifier_name,class_name, storage_name, return_name, first_name, second_name, third_name, fourth_name, fifth_name > property_type;

         return property_type( class_param, function_param );
        }

      }
    }
  }

#endif