#ifndef reflection_property_trinity_pure
#define reflection_property_trinity_pure

// ::reflection::property::trinity::pure_class<original_name,model_name,image_name,report_name>
// ::reflection::property::trinity::get
// ::reflection::property::trinity::check_weak
// ::reflection::property::trinity::check_any
// ::reflection::property::trinity::unpack

#include "../mutate/_pure.hpp"
#include "../inspect/_pure.hpp"

namespace reflection
 {
  namespace property
   {
    namespace trinity
     {

      template
       <
          typename original_name
         ,typename model_name
         ,typename image_name
         ,typename report_name
       >
       class pure_class
        : virtual public ::reflection::property::pure_class
        , virtual public ::reflection::property::direct::pure_class<original_name>
        , virtual public ::reflection::property::mutate::pure_class<model_name,report_name>
        , virtual public ::reflection::property::inspect::pure_class<image_name>
        {
         public:
           typedef original_name original_type;
           typedef model_name       model_type;
           typedef image_name       image_type;
           typedef report_name     report_type;

           typedef ::reflection::property::pure_class  pure_type;
           typedef  ::reflection::property::direct::pure_class<original_name>           direct_type;
           typedef  ::reflection::property::mutate::pure_class<model_name,report_name>  mutate_type;
           typedef  ::reflection::property::inspect::pure_class<image_name>            inspect_type;

         public:
                    pure_class(){}
           virtual ~pure_class(){}

           using  direct_type::disclose;
           using  mutate_type::process;
           using inspect_type::present;
        };

      template< typename original_name, typename model_name, typename image_name, typename report_name >
       inline bool check( ::reflection::property::pure_class const& property_param )
        {
         typedef ::reflection::property::trinity::pure_class<original_name,model_name,image_name,report_name> trinity_type;
         return nullptr != dynamic_cast< trinity_type const*>( &property_param );
        }

      template< typename original_name, typename model_name, typename image_name, typename report_name >
       inline bool check_weak( ::reflection::property::pure_class const& property_param )
        {
         typedef  ::reflection::property::direct::pure_class<original_name>           direct_type;
         typedef  ::reflection::property::mutate::pure_class<model_name,report_name>  mutate_type;
         typedef  ::reflection::property::inspect::pure_class<image_name>            inspect_type;

         bool A = nullptr != dynamic_cast<  direct_type const*>( &property_param );
         bool B = nullptr != dynamic_cast<  mutate_type const*>( &property_param );
         bool C = nullptr != dynamic_cast< inspect_type const*>( &property_param );

         return A && B && C;
        }

      template< typename original_name, typename model_name, typename image_name, typename report_name >
       inline bool check_any( ::reflection::property::pure_class const& property_param )
        {
         typedef  ::reflection::property::direct::pure_class<original_name>           direct_type;
         typedef  ::reflection::property::mutate::pure_class<model_name,report_name>  mutate_type;
         typedef  ::reflection::property::inspect::pure_class<image_name>            inspect_type;

         bool A = nullptr != dynamic_cast<  direct_type const*>( &property_param );
         bool B = nullptr != dynamic_cast<  mutate_type const*>( &property_param );
         bool C = nullptr != dynamic_cast< inspect_type const*>( &property_param );

         return A || B || C;
        }

      template< typename original_name, typename model_name, typename image_name, typename report_name >
       inline bool unpack
        (
          ::reflection::property::pure_class                                   & property_param
         ,::reflection::property::direct::pure_class<original_name>            **director   = nullptr
         ,::reflection::property::mutate::pure_class<model_name, report_name>  **mutator    = nullptr
         ,::reflection::property::inspect::pure_class<image_name>              **inspector  = nullptr
        )
        {
         typedef ::reflection::property::direct::pure_class<original_name>           direct_type;
         typedef ::reflection::property::mutate::pure_class<model_name,report_name>  mutate_type;
         typedef ::reflection::property::inspect::pure_class<image_name>            inspect_type;

         auto D = dynamic_cast< direct_type *>( &property_param ); if( nullptr != director  ) *director  = D;
         auto M = dynamic_cast< mutate_type *>( &property_param ); if( nullptr != mutator   ) *mutator   = M;
         auto I = dynamic_cast< inspect_type*>( &property_param ); if( nullptr != inspector ) *inspector = I;
         return ( nullptr != D ) && ( nullptr != M ) && ( nullptr != I );
        }

     }
   }
 }

 #endif
