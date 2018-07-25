#ifndef reflection_operation_view
#define reflection_operation_view
// ::reflection::operation::view_

#include "../content/class.hpp"

namespace reflection
 {
  namespace  operation
   {

    template
     <
       typename data_name
      ,typename key_name = std::string
      ,template < typename, typename > class container_name = ::reflection::type::container::map
     >
     void view
      (
       ::reflection::content::class_class<data_name,key_name, container_name >      & v
       ::reflection::content::class_class<data_name,key_name, container_name > const& reflection
      )
      {
       v.container() = reflection.container();
       return ;
      }

   }
 }

 #endif