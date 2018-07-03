#ifndef reflection_object_assign
#define reflection_object_assign

// ::reflection::operation::transfer::assign<key_name>

#include "../../property/structure.hpp"
#include "../content/category.hpp"

#include "../property/assign.hpp"

namespace reflection
 {
  namespace operation
   {
    namespace transfer
     {


    template
     <
       typename  key_name  = std::string
      ,template < typename, typename > class container_name = ::reflection::type::container::map
     >
     struct assign_struct
      {
       public:
         typedef     key_name        key_type;

         typedef ::reflection::property::pure_class                                   property_type;
         typedef ::reflection::property::structure_class<key_type,container_name>     structure_type;

         enum error_enum
          {
           true_index                = (true),
           left_not_found_index      = true_index + 1,
           left_not_property_index   = true_index + 2,
           assign_fail_index         = true_index + 3,
          };

       public:
         template
          <
            typename       type_name
           ,typename      image_name = typename std::add_lvalue_reference< typename std::add_const<type_name>::type >::type
           ,typename   original_name = typename std::add_lvalue_reference< type_name >::type
           ,typename      model_name = typename std::add_lvalue_reference< typename std::add_const<type_name>::type >::type
          >
         static error_enum process( structure_type & output_param, key_type const& key_param, property_type const& property_param )
          {
           auto iterator = output_param.container().find( key_param );
           if( output_param.container().end() == iterator )
            {
             return left_not_found_index;
            }
           auto right = iterator->second;

           property_type *  left = dynamic_cast< property_type * >( iterator->second.get() );
           if( nullptr == left )
            {
             return left_not_property_index;
            }

           if( false == ::reflection::property::assign<type_name, error_enum, image_name, original_name, model_name >( *left, *right ) )
            {
             return assign_fail_index;
            }

           return true_index;
          }

      };

     }
   }
 }

#endif
