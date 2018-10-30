#ifndef reflection_type_container_map
#define reflection_type_container_map

// ::reflection::type::container::map
// ::reflection::type::container::value
// ::reflection::type::container::insert


namespace reflection
 {
  namespace type
   {
    namespace container
     {

    //  template< typename key_name, typename data_name >
    //    using map = std::map< key_name, data_name >;

      template< typename key_name, typename data_name >
       struct map
        {
         typedef   key_name    key_type;
         typedef   data_name  data_type;

         typedef   std::size_t  size_type;

         typedef          std::map< key_name, data_name >                           container_type;
         typedef typename std::map< key_name, data_name >::value_type                   value_type;
         typedef typename std::map< key_name, data_name >::iterator                  iterator_type;
         typedef typename std::map< key_name, data_name >::const_iterator      const_iterator_type;
        };


      template< typename key_name, typename data_name >
       typename ::reflection::type::container::map< key_name, data_name >::value_type
       value( key_name const& key, data_name const& data )
         {
          return std::make_pair( key, data );
         }

      template< typename key_name, typename data_name >
       bool
       exists
        (
          typename::reflection::type::container::map< key_name, data_name >::container_type const&container
         ,key_name  const& key
        )
        {
         return container.find( key ) != container.end();
        }

      template< typename key_name, typename data_name >
       void
       insert
        (
          typename::reflection::type::container::map< key_name, data_name >::container_type &container
         ,key_name  const& key
         ,data_name const& data
        )
        {
         container.emplace( key, data );
        }

      template< typename key_name, typename data_name >
        void
        erase
        (
          typename::reflection::type::container::map< key_name, data_name >::container_type &container_param
         , key_name const& key
        )
        {
         container_param.erase( key );
        }

      template< typename key_name, typename data_name >
       key_name const&
       key
         (
           typename ::reflection::type::container::map   < key_name, data_name >::container_type        const & container_param
          ,typename ::reflection::type::container::map   < key_name, data_name >::const_iterator_type   const & iterator_param
         )
       {
        return iterator_param->first;
       }

      template< typename key_name, typename data_name >
       data_name const&
       data
         (
           typename ::reflection::type::container::map< key_name, data_name >::container_type         const& container
          ,typename ::reflection::type::container::map< key_name, data_name >::const_iterator_type    const& iterator
         )
       {
        return iterator->second;
       }

      template< typename key_name, typename data_name >
       data_name &
       data
         (
           typename ::reflection::type::container::map< key_name, data_name >::container_type     & container
          ,typename ::reflection::type::container::map< key_name, data_name >::iterator_type      & iterator
         )
       {
        return iterator->second;
       }

      template< typename key_name, typename data_name >
       typename ::reflection::type::container::map< key_name, data_name >::const_iterator_type
       find
         (
           typename ::reflection::type::container::map< key_name, data_name >::container_type   const& container
          ,typename ::reflection::type::container::map< key_name, data_name >::key_type         const& key
         )
       {
        return container.find( key );
       }

       
      template< typename key_name, typename data_name >
       typename ::reflection::type::container::map< key_name, data_name >::iterator_type
       find
         (
           typename ::reflection::type::container::map< key_name, data_name >::container_type        & container
          ,typename ::reflection::type::container::map< key_name, data_name >::key_type         const& key
         )
       {
        return container.find( key );
       }

     }
   }
 }

#endif
