#ifndef reflection_property_mutate_pure
#define reflection_property_mutate_pure

// ::reflection::property::mutate::pure_class<model_name,report_name>
// ::reflection::property::mutate::check<model_name,report_name>( property )
// ::reflection::property::mutate::process<model_name,report_name>( property, model )

#include "../_pure.hpp"

namespace reflection
 {
  namespace property
   {
    namespace mutate
     {

      template
       <
         typename model_name
        ,typename report_name = bool
       >
       class pure_class
        : virtual public ::reflection::property::pure_class
        {
         public:
           typedef model_name   model_type; //!< Expect to be constant reference
           typedef report_name report_type; //!< Expect bool or integer or enum

                    pure_class(){}
           virtual ~pure_class(){}

           virtual report_name process( model_type model_param )=0;
        };

      template
       <
        typename report_name
       >
       class pure_class< void, report_name >
        : virtual public ::reflection::property::pure_class
        {
         public:
           typedef report_name report_type;

                    pure_class(){}
           virtual ~pure_class(){}

           virtual report_name process( void )=0;
        };


      template< typename model_name, typename report_name = bool >
       inline bool check( ::reflection::property::pure_class const& property_param )
        {
         typedef ::reflection::property::mutate::pure_class<model_name,report_name> mutate_type;
         return nullptr != dynamic_cast< mutate_type const*>( &property_param );
        }

      template< typename model_name, typename report_name = bool >
       inline
       report_name
       process( ::reflection::property::pure_class & property_param, model_name model_param )
        {
         typedef ::reflection::property::mutate::pure_class<model_name,report_name> mutate_type;
         return dynamic_cast< mutate_type &>( property_param ).process( model_param );
        }

      template< typename report_name = bool >
       inline
       report_name
       process( ::reflection::property::pure_class & property_param )
        {
         typedef ::reflection::property::mutate::pure_class<void,report_name> mutate_type;
         return dynamic_cast< mutate_type &>( property_param ).process( );
        }

     }
   }
 }

 #endif
