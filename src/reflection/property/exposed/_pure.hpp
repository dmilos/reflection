#ifndef reflection_property_exposed_type_pure
#define reflection_property_exposed_type_pure

// ::reflection::property::exposed::pure_class<original_name,model_name,report_name>
// ::reflection::property::exposed::check     <original_name,model_name,report_name>
// ::reflection::property::exposed::check_weak<original_name,model_name,report_name>
// ::reflection::property::exposed::check_any <original_name,model_name,report_name>
// ::reflection::property::exposed::dispatch  <original_name,model_name,report_name>
// ::reflection::property::exposed::dispatch  <original_name,model_name,report_name>
// ::reflection::property::exposed::unpack    <original_name,model_name,report_name>

#include "../direct/_pure.hpp"
#include "../mutate/_pure.hpp"

namespace reflection
 {
  namespace property
   {
    namespace exposed
     {

      template
       <
         typename original_name
        ,typename    model_name
        ,typename   report_name
       >
       class pure_class
        : virtual public ::reflection::property::pure_class
        , virtual public ::reflection::property::direct::pure_class<original_name>
        , virtual public ::reflection::property::mutate::pure_class<model_name, report_name>
        {
         public:
           typedef original_name original_type;
           typedef model_name       model_type;
           typedef report_name     report_type;

           typedef  ::reflection::property::direct::pure_class<original_name>  direct_type;
           typedef  ::reflection::property::mutate::pure_class<model_name, report_name>    mutate_type;

         public:
                    pure_class(){}
           virtual ~pure_class(){}

           using direct_type::disclose;
           using mutate_type::process;
        };

      template< typename original_name, typename model_name, typename report_name >
       inline bool check( ::reflection::property::pure_class const& property_param )
        {
         typedef ::reflection::property::exposed::pure_class<original_name,model_name,report_name> exposed_type;
         return nullptr != dynamic_cast< exposed_type const*>( &property_param );
        }

      template< typename original_name, typename model_name, typename report_name >
       inline bool check_weak( ::reflection::property::pure_class const& property_param )
        {
         typedef  ::reflection::property::direct::pure_class<original_name>  direct_type;
         typedef  ::reflection::property::mutate::pure_class<model_name, report_name>    mutate_type;

         bool A = nullptr != dynamic_cast< direct_type const*>( &property_param );
         bool B = nullptr != dynamic_cast< mutate_type const*>( &property_param );
         return A && B;
        }

      template< typename original_name, typename model_name, typename report_name >
       inline bool unpack
        (
           ::reflection::property::pure_class                                   & property_param
          ,::reflection::property::direct::pure_class<original_name>            **director = nullptr
          ,::reflection::property::mutate::pure_class<model_name, report_name>  **mutator  = nullptr
         )
        {
         typedef  ::reflection::property::direct::pure_class<original_name>  direct_type;
         typedef  ::reflection::property::mutate::pure_class<model_name, report_name>    mutate_type;

         auto D = dynamic_cast< direct_type*>( &property_param ); if( nullptr != director ) *director = D;
         auto M = dynamic_cast< mutate_type*>( &property_param ); if( nullptr != mutator  ) *mutator  = M;
         return ( nullptr != D ) && ( nullptr != M );
        }

      template< typename original_name, typename model_name, typename report_name >
       inline bool check_any( ::reflection::property::pure_class const& property_param )
        {
         typedef  ::reflection::property::direct::pure_class<original_name>  direct_type;
         typedef  ::reflection::property::mutate::pure_class<model_name, report_name>    mutate_type;

         bool A = nullptr != dynamic_cast< direct_type const*>( &property_param );
         bool B = nullptr != dynamic_cast< mutate_type const*>( &property_param );
         return A || B;
        }

      template< typename original_name, typename model_name, typename report_name >
       inline report_name dispatch( ::reflection::property::pure_class & property_param, model_name model )
        {
         typedef  ::reflection::property::mutate::pure_class<model_name, report_name>    mutate_type;

         auto mutator = dynamic_cast< mutate_type *>( &property_param );
         if( nullptr != mutator )
          {
           return mutator->process( model );
          }

         typedef  ::reflection::property::direct::pure_class<original_name>  direct_type;
         auto director = dynamic_cast< direct_type *>( &property_param );
         if( nullptr != director )
          {
           director->disclose() = model;
           return report_name( true );
          }

         return report_name( false );
        }

      template< typename original_name, typename model_name, typename report_name >
       inline report_name dispatch
        (
          ::reflection::property::direct::pure_class<original_name>            *director
         ,::reflection::property::mutate::pure_class<model_name, report_name>  *mutator
         ,model_name model
        )
        {
         if( nullptr != director )
          {
           director->disclose() = model;
           return report_name( true );
          }

         if( nullptr != mutator )
          {
           return mutator->process( model );
          }

         return report_name( false );
        }
      template< typename report_name >
       inline report_name dispatch
        (
          ::reflection::property::direct::pure_class<void>               *director
         ,::reflection::property::mutate::pure_class<void, report_name>  *mutator
        )
        {
         if( nullptr != director )
          {
           director->disclose();
           return report_name( true );
          }

         if( nullptr != mutator )
          {
           return mutator->process();
          }

         return report_name( false );
        }

     }
   }
 }

 #endif
