#ifndef reflection_type_container_set
#define reflection_type_container_set

// ::reflection::type::container::set
// ::reflection::type::container::value
// ::reflection::type::container::insert

namespace reflection
 {
  namespace type
   {
    namespace container
     {

      template< typename key_name, typename data_name >
        struct set
         {
          typedef          std::set< data_name >                          constainer_type;
          typedef typename std::set< data_name >::value_type                   value_type;
          typedef typename std::set< data_name >::iterator                  iterator_type;
          typedef typename std::set< data_name >::const_iterator      const_iterator_type;
         };

     template< typename key_name, typename data_name >
       typename ::reflection::type::container::set< key_name, data_name >::value_type const&
       value( key_name const& key, data_name const& data )
         {
          return data;
         }

      template< typename key_name, typename data_name >
        void
        insert
         (
           typename ::reflection::type::container::set< key_name, data_name >::constainer_type &container_param
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
          typename ::reflection::type::container::set< key_name, data_name >::constainer_type &container_param
         , key_name const& key
        )
        {
          container_param.erase( container_param.begin() + key );
        }

      template< typename key_name, typename data_name >
        key_name const&
        iterator2key
          (
            typename ::reflection::type::container::set< key_name, data_name >::constainer_type &container_param
           ,typename ::reflection::type::container::set< key_name, data_name >::itaertor    const& iterator
          )
        {
         return iterator - container_param.begin();
        }

     }
   }
 }

#endif
