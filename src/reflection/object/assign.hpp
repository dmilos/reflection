#ifndef reflection_object_assign
#define reflection_object_assign

// ::reflection::object::assign<key_name>

#include "./structure.hpp"

#include "../property/assign.hpp"

namespace reflection
 {
  namespace object
   {

    template
     <
      ,typename  key_name = std::string
     >
     inline
     void
     assign
      (
        ::reflection::object::structure_class<key_name>      &  left_param
       ,::reflection::object::structure_class<key_name> const& right_param
       )
      {
       for( auto const& right_item : right_param.container() )
        {
         auto left_item = left_param.find( right_item->first );
         if( left_item == left_param.end() )
          {
           continue;
          }
         ::reflection:property::assign( *left_item->second.get(), *right_item->second.get() );
        }
       return left_param;
      }

   }
 }

#endif
