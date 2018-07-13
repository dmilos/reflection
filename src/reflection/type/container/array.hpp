#ifndef reflection_type_container_array
#define reflection_type_container_array

// ::reflection::type::container::array
// ::reflection::type::container::value
// ::reflection::type::container::insert

namespace reflection
 {
  namespace type
   {
    namespace container
     {

        template < unsigned  size_number >
        struct array
         {
          template< typename key_name, typename data_name >
           struct inside
            {
             typedef          std::array< data_name, size_number >                           container_type;
             typedef typename std::array< data_name, size_number >::value_type                   value_type;
             typedef typename std::array< data_name, size_number >::iterator                  iterator_type;
             typedef typename std::array< data_name, size_number >::const_iterator      const_iterator_type;
            };
         };

     template< unsigned size_number, typename key_name, typename data_name >
       typename ::reflection::type::container::array<size_number>::template inside< key_name, data_name >::value_type const&
       value( key_name const& key, data_name const& data )
         {
          return data;
         }
/*      template< typename key_name, typename data_name >
        void
        insert
         (
           typename ::reflection::type::container::array<size_number>::template inside< key_name, data_name >::container_type &container_param
          ,key_name  const& key
          ,data_name const& data
         )
         {
          if( container_param.size() <= key )
           {
            container_param.resize( key + 1 );
           }
          container_param[ key ] = data;
         }

      template< typename key_name, typename data_name >
        void
        erase
        (
          typename ::reflection::type::container::array<size_number>::template inside< key_name, data_name >::container_type &container_param
         , key_name const& key
        )
        {
          container_param.erase( container_param.begin() + key );
        }

      template< typename key_name, typename data_name >
        key_name const&
        iterator2key
          (
            typename ::reflection::type::container::array<size_number>::template inside< key_name, data_name >::container_type &container_param
           ,typename ::reflection::type::container::array<size_number>::template inside< key_name, data_name >::itaertor    const& iterator
          )
        {
         return iterator - container_param.begin();
        }

      template< typename key_name, typename data_name >
       data_name &
       find
         (
           typename ::reflection::type::container::array<size_number>::template inside< key_name, data_name >::container_type        & container
          ,typename ::reflection::type::container::array<size_number>::template inside< key_name, data_name >::key_type         const& iterator
         )
       {
        return iterator->second;
       }

      template< typename key_name, typename data_name >
       data_name const&
       find
         (
           typename ::reflection::type::container::array<size_number>::template inside< key_name, data_name >::container_type    const & container
          ,typename ::reflection::type::container::array<size_number>::template inside< key_name, data_name >::key_type          const& iterator
         )
       {
        return iterator->second;
       }

*/
     }
   }
 }

#endif
