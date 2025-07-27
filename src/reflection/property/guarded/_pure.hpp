#ifndef reflection_property_guarded_pure
#define reflection_property_guarded_pure

// ::reflection::property::guarded::pure_class<model_name,image_name,report_name>
// ::reflection::property::guarded::check
// ::reflection::property::guarded::check_weak
// ::reflection::property::guarded::check_any
// ::reflection::property::guarded::unpack

#include "../mutate/_pure.hpp"
#include "../inspect/_pure.hpp"

namespace reflection
 {
  namespace property
   {
    namespace guarded
     {

      template
       <
          typename model_name
         ,typename image_name
         ,typename report_name
       >
       class pure_class
        : virtual public ::reflection::property::pure_class
        , virtual public ::reflection::property::mutate::pure_class<model_name,report_name>
        , virtual public ::reflection::property::inspect::pure_class<image_name>
        {
         public:
           typedef model_name     model_type;
           typedef image_name     image_type;
           typedef report_name   report_type;

           typedef  ::reflection::property::mutate::pure_class<model_name,report_name>  mutate_type;
           typedef  ::reflection::property::inspect::pure_class<image_name>    inspect_type;


                    pure_class(){}
           virtual ~pure_class(){}

           using  mutate_type::process;
           using inspect_type::present;
        };

      template< typename model_name, typename image_name, typename report_name >
       inline bool check( ::reflection::property::pure_class const& property_param )
        {
         typedef ::reflection::property::guarded::pure_class<model_name,image_name,report_name> guarded_type;
         return nullptr != dynamic_cast< guarded_type const*>( &property_param );
        }

      template< typename model_name, typename image_name, typename report_name >
       inline bool check_weak( ::reflection::property::pure_class const& property_param )
        {
         typedef  ::reflection::property::mutate::pure_class<model_name,report_name>  mutate_type;
         typedef  ::reflection::property::inspect::pure_class<image_name>            inspect_type;
         
         bool A = nullptr != dynamic_cast< mutate_type  const*>( &property_param );
         bool B = nullptr != dynamic_cast< inspect_type const*>( &property_param );
         return A && B;
        }
      template< typename model_name, typename image_name, typename report_name >
       inline bool check_any( ::reflection::property::pure_class const& property_param )
        {
         typedef  ::reflection::property::mutate::pure_class<model_name,report_name>  mutate_type;
         typedef  ::reflection::property::inspect::pure_class<image_name>            inspect_type;

         bool A = nullptr != dynamic_cast< mutate_type  const*>( &property_param );
         bool B = nullptr != dynamic_cast< inspect_type const*>( &property_param );
         return A || B;
        }

       template< typename model_name, typename image_name, typename report_name >
       inline bool unpack
        (
          ::reflection::property::pure_class                                   & property_param
         ,::reflection::property::mutate::pure_class<model_name, report_name>  **mutator   = nullptr
         ,::reflection::property::inspect::pure_class<image_name>              **inspector = nullptr
        )
        {
         typedef  ::reflection::property::mutate::pure_class<model_name, report_name>  mutate_type;
         typedef  ::reflection::property::inspect::pure_class<image_name>             inspect_type;

         auto M = dynamic_cast< mutate_type  *>( &property_param ); if( nullptr != mutator   ) *mutator   = M;
         auto I = dynamic_cast< inspect_type *>( &property_param ); if( nullptr != inspector ) *inspector = I;
         return ( nullptr != M ) && ( nullptr != I );
        }

     }
   }
 }

 #endif
