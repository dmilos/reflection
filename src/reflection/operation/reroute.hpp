#ifndef reflection_operation_reroute
#define reflection_operation_reroute
// ::reflection::operation::reroute< storage_name >( struct, storage )

#include "../property/structure.hpp"

namespace reflection
 {
  namespace  operation
   {
    namespace reroute
     {

      template
       <
         typename storage_name
        ,typename key_name
      //,typename pointer_name = ::std::shared_ptr< ::reflection::property::pure_class >
        ,template < typename, typename > class container_name
       >
      void reset
       (
        ::reflection::property::structure_class<key_name, container_name>& structure_param
        , storage_name const& storage_param
       )
       {
        for( auto& item : structure_param )
         {
          auto const& key  = item.first;
          auto const& data = item.second;

          if( nullptr == data.get() )
           {
            continue;
           }

          {
           auto const& property = *data.get(); //!< debug

           typedef ::reflection::property::_internal::proxy_class<storage_name> proxy_type;
           proxy_type* carrier       = dynamic_cast<proxy_type*>( data.get() );
           if( nullptr == carrier )
            {
             continue;
            }
           carrier->storage( nullptr );
          }
         }
       }

      template
       <
         typename storage_name
        ,typename key_name
      //,typename pointer_name = ::std::shared_ptr< ::reflection::property::pure_class >
        ,template < typename, typename > class container_name
       >
      void set
       (
        ::reflection::property::structure_class<key_name, container_name>& structure_param
        , storage_name const& storage_param
       )
       {
        for( auto& item : structure_param )
         {
          auto const& key  = item.first;
          auto const& data = item.second;

          if( nullptr == data.get() )
           {
            continue;
           }

          {
           auto const& property = *data.get(); //!< debug

           typedef ::reflection::property::_internal::proxy_class<storage_name> proxy_type;
           proxy_type* carrier       = dynamic_cast<proxy_type*>( data.get() );
           if( nullptr == carrier )
            {
             continue;
            }

           carrier->storage( storage_param );

          }
         }
       }

     }
   }
 }

#endif

