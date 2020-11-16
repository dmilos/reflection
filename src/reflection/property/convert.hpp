#ifndef reflection_property_convert
#define reflection_property_convert

// ::reflection::property::assign<type_name>

#include "./direct/_pure.hpp"
#include "./mutate/_pure.hpp"
#include "./inspect/_pure.hpp"

namespace reflection
 {
  namespace property
   {

    template
     <
       typename   left_name
      ,typename  right_name
      ,typename report_name = bool
     >
     inline
     bool
     convert
      (
         ::reflection::property::pure_class       &  left_param
       , ::reflection::property::pure_class  const& right_param
      )
      {
       typedef ::reflection::property::inspect::pure_class< left_name const& >                inspect_type;
       typedef ::reflection::property::mutate::pure_class<  left_name const&, report_name >    mutate_type;
       typedef ::reflection::property::direct::pure_class<  right_name & >                     direct_type;

       auto right_inspect = dynamic_cast< inspect_type const* > ( &right_param );
       if( nullptr == right_inspect )
        {
         return report_name( false );
        }

       auto left_mutate = dynamic_cast< mutate_type * > ( &left_param );
       if( nullptr != left_mutate )
        {
         return left_mutate->process( right_inspect->present() );
        }

       auto left_direct = dynamic_cast< direct_type * > ( &left_param );
       if( nullptr != left_direct )
        {
         left_direct->disclose() = right_inspect->present();
         return report_name( true );
        }

       return report_name( false );
      }

   }
 }

#endif
