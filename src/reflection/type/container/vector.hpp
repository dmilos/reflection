#ifndef reflection_type_container_vector
#define reflection_type_container_vector

// ::reflection::type::container::vector
// ::reflection::type::container::value
// ::reflection::type::container::insert

namespace reflection
 {
  namespace type
   {
    namespace container
     {

      template< typename key_name, typename data_name >
        struct vector
         {
          typedef          std::vector< data_name >                           container_type;
          typedef typename std::vector< data_name >::value_type                   value_type;
          typedef typename std::vector< data_name >::iterator                  iterator_type;
          typedef typename std::vector< data_name >::const_iterator      const_iterator_type;
         };


     template< typename key_name, typename data_name >
       typename ::reflection::type::container::vector< key_name, data_name >::value_type const&
       value( key_name const& key, data_name const& data )
         {
          return data;
         }

      template< typename key_name, typename data_name >
       bool
       exists
        (
          typename::reflection::type::container::vector< key_name, data_name >::container_type const&container
         ,key_name  const& key
        )
        {
         return false;
        }

      template< typename key_name, typename data_name >
        void
        insert
         (
           typename ::reflection::type::container::vector< key_name, data_name >::container_type &container_param
          ,key_name  const& key
          ,data_name const& data
         )
         {
          //if( container_param.size() <= key )
          // {
          //  container_param.resize( key + 1 );
          // }
          //container_param[ key ] = data;
         }

      template< typename key_name, typename data_name >
        void
        erase
        (
          typename ::reflection::type::container::vector< key_name, data_name >::container_type &container_param
         , key_name const& key
        )
        {
         //container_param.erase( container_param.begin() + key );
        }

      template< typename key_name, typename data_name >
       key_name 
       key
         (
           typename ::reflection::type::container::vector< key_name, data_name >::container_type         const& container_param
          ,typename ::reflection::type::container::vector< key_name, data_name >::const_iterator_type    const& iterator_param
         )
       {
        return key_name{};
       }

      template< typename key_name, typename data_name >
       data_name const&
       data
         (
           typename ::reflection::type::container::vector< key_name, data_name >::container_type         const& container
          ,typename ::reflection::type::container::vector< key_name, data_name >::const_iterator_type    const& iterator
         )
       {
        return *iterator;
       }

      template< typename key_name, typename data_name >
       data_name &
       data
         (
           typename ::reflection::type::container::vector< key_name, data_name >::container_type          & container
          ,typename ::reflection::type::container::vector< key_name, data_name >::iterator_type           & iterator
         )
       {
        return *iterator;
       }

      template< typename key_name, typename data_name >
       typename ::reflection::type::container::vector< key_name, data_name >::const_iterator_type
       find
         (
           typename ::reflection::type::container::vector< key_name, data_name >::container_type    const & container
          ,typename ::reflection::type::container::vector< key_name, data_name >::key_type          const& key
         )
       {
        return container.begin();
       }

      template< typename key_name, typename data_name >
       typename ::reflection::type::container::vector< key_name, data_name >::iterator_type
       find
         (
           typename ::reflection::type::container::vector< key_name, data_name >::container_type        & container
          ,typename ::reflection::type::container::vector< key_name, data_name >::key_type         const& key
         )
       {
        return container.begin();
       }

     }
   }
 }

#endif
