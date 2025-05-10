#ifndef reflection_content_function_member_hpp
 #define reflection_content_function_member_hpp

 // ::reflection::content::function::member_class<class_name,return_name,...>


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
        ,typename ... argument_name
        >
       class member_class
        :  public ::reflection::content::function::pure_class<identifier_name,return_name,argument_name ...>
        ,  public ::reflection::property::function::member_class<class_name,storage_name,return_name,argument_name ...>
        {
         public:
           typedef class_name      class_type;
           typedef return_name    return_type;
           //typedef  argument_name ...     argument_type ...;

           typedef ::reflection::content::function::pure_class<identifier_name,return_name,argument_name ...>              content_type;
           typedef ::reflection::property::function::member_class<class_name,storage_name,return_name,argument_name ...>   property_type;

           typedef typename property_type::function_const_type function_const_type;
           typedef typename property_type::function_type       function_type;

         public:
           using property_type::property_type;

         public:
           return_type execute( argument_name ...args  )const
            {
             return this->property_type::execute( args ... );
            }

           using content_type::signature;
        };

      template< typename identifier_name, typename class_name, typename storage_name, typename return_name, typename ... argument_name >
       inline
       ::reflection::content::function::member_class<identifier_name, class_name, storage_name, return_name, argument_name ... >
       member
        (
          storage_name const& class_param
         ,return_name  (class_name::*function_param)( argument_name ...  )const
        )
        {
         typedef ::reflection::content::function::member_class<identifier_name,class_name, storage_name, return_name, argument_name ... > property_type;

         return property_type( class_param, function_param );
        }


      template< typename identifier_name, typename class_name, typename storage_name, typename return_name, typename ... argument_name >
       inline
       ::reflection::content::function::member_class<identifier_name, class_name, storage_name, return_name, argument_name ...  >
       member
        (
          storage_name const& class_param
         ,return_name  (class_name::*function_param)( argument_name ... )
        )
        {
         typedef ::reflection::content::function::member_class<identifier_name,class_name, storage_name, return_name, argument_name ... > property_type;

         return property_type( class_param, function_param );
        }
 
      }
    }
  }

#endif