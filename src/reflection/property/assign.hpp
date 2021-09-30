#ifndef reflection_property_assign
#define reflection_property_assign

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
       typename  fundamental_name
      ,typename     report_name = bool
      ,typename      image_name = typename std::add_lvalue_reference< typename std::add_const<fundamental_name>::type >::type
      ,typename   original_name = typename std::add_lvalue_reference< fundamental_name >::type
      ,typename      model_name = typename std::add_lvalue_reference< typename std::add_const<fundamental_name>::type >::type
     >
     inline
     bool
     assign
      (
         ::reflection::property::pure_class       &  left_param
       , ::reflection::property::pure_class  const& right_param
      )
      {
       typedef ::reflection::property::inspect::pure_class< image_name >                inspect_type;
       typedef ::reflection::property::direct::pure_class<  original_name >             direct_type;
       typedef ::reflection::property::mutate::pure_class<  model_name, report_name >   mutate_type;

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
