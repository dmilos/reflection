#ifndef reflection_operation_reroute
#define reflection_operation_reroute
// ::reflection::operation::reroute< storage_name >( struct, storage )

#include "../property/structure.hpp"

namespace reflection
 {
  namespace  operation
   {

    template
     <
       typename storage_name
      ,typename key_name
    //,typename pointer_name = ::std::shared_ptr< ::reflection::property::pure_class >
      ,template < typename, typename > class container_name
     >
     void reroute
      (
       ::reflection::property::structure_class<key_name,container_name>       & structure_param
       ,storage_name const& storage_param
      )
      {
       for( auto iterator  =  structure_param.begin();
                 iterator !=  structure_param.end();
               ++iterator )
        {
         auto  const &   key =  structure_param.key(  iterator );
         auto        &   data = structure_param.data( iterator );

         if( nullptr == data.get() )
          {
           continue;
          }

         typedef ::reflection::property::_internal::carrier_class<storage_name> carrier_type;
         carrier_type *carrier = dynamic_cast<carrier_type*>( data.get() );
         if( nullptr == carrier )
          {
           continue;
          }
          carrier->storage( storage_param );
        }
       }

   }
 }

 #endif

