#ifndef reflection_property_set_pure
#define reflection_property_set_pure

#include "../_pure.hpp"

namespace reflection
 {
  namespace property
   {
    namespace set
     {

      template< typename type_name, typename report_name = bool, typename model_name = type_name const& >
       class pure
        : public ::reflection::property::pure
        {
         public:
           typedef type_name   type_type;
           typedef report_name report_type;
           typedef model_name model_type;

                    pure(){}
           virtual ~pure(){}

           void process( model_type m )=0;
        };

      template< typename type_name, typename report_name = bool, typename model_name = type_name const& >
       inline bool check( ::reflection::property::pure const& property_param )
        {
         typedef ::reflection::property::set::pure<type_name,report_name, model_name> set_type;
         return nullptr != dynamic_cast< set_type const*>( &property_param );
        }

      template< typename type_name, typename report_name = bool, typename model_name = type_name const& >
       inline
       report_name
       process( ::reflection::property::pure const& property_param, model_name model_param )
        {
         typedef ::reflection::property::set::pure<type_name,report_name, model_name> set_type;
         return dynamic_cast< set_type &>( property_param ).process( model_param );
        }

     }
   }
 }

 #endif
