#ifndef reflection_property_function_member
#define reflection_property_function_member

#include "../_carrier.hpp"

#include "./_pure.hpp"

#include "../../ornament/accessibility.hpp"
#include "../../ornament/qualification.hpp"

namespace reflection
 {
  namespace property
   {
    namespace function
     {

      template
       <
         typename class_name
        ,typename storage_name
        ,typename return_name
        ,typename ... argument_name
        >
       class member_class
        : virtual public ::reflection::property::function::pure_class<return_name,argument_name...>
        , virtual public ::reflection::property::_internal::proxy_class<storage_name>
        , virtual public ::reflection::ornament::accessibility_class
        , virtual public ::reflection::ornament::qualification_class
        {
         public:
           typedef   class_name     class_type;
           typedef storage_name   storage_type;
           typedef  return_name    return_type;
         //typedef argument_name...     argument_type...;

           typedef ::reflection::property::_internal::proxy_class<storage_type>  carrier_type;

           typedef return_type (class_name::*function_type         )( argument_name ... );
           typedef return_type (class_name::*function_const_type   )( argument_name ... )const;
           typedef return_type (class_name::*function_volatile_type)( argument_name ... )volatile;
           typedef return_type (class_name::*function_cv_type      )( argument_name ... )const volatile;

         public:
                    member_class( storage_type const& storage_param, function_const_type function_param ):carrier_type(storage_param),m_function(nullptr),       m_const_function(function_param) { }
                    member_class( storage_type const& storage_param, function_type       function_param ):carrier_type(storage_param),m_function(function_param),m_const_function(nullptr)        { }
           virtual ~member_class( ){}

         public:
           return_type execute(  argument_name ... args )const
            {
             if( nullptr != m_const_function ) return ( (*(this->storage())).*m_const_function)( args ... );
                                               return ( (*(this->storage())).*m_function      )( args ... );
            }

         private:
           function_const_type m_const_function;
           function_type       m_function;
        };


      template< typename class_name, typename storage_name, typename return_name, typename ... argument_name  >
       inline
       ::reflection::property::function::member_class<class_name, storage_name, return_name, argument_name ...  >
       member
        (
          storage_name const& storage_param
         ,return_name (class_name::*function_param)( argument_name ... )const
        )
        {
         typedef ::reflection::property::function::member_class<class_name, storage_name, return_name, argument_name ...  > member_type;

         return member_type( storage_param, function_param );
        }

      template< typename class_name, typename storage_name, typename return_name, typename ... argument_name  >
       inline
       ::reflection::property::function::member_class<class_name, storage_name, return_name, argument_name ...  >
       member
        (
          storage_name const& storage_param
         ,return_name (class_name::*function_param)( argument_name ... )
        )
        {
         typedef ::reflection::property::function::member_class<class_name, storage_name, return_name, argument_name ...  > member_type;

         return member_type( storage_param, function_param );
        }

     }
   }
 }

#endif
