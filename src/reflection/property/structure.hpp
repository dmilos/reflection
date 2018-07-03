#ifndef reflection_property_structure
#define reflection_property_structure

// ::reflection::property::structure_class<key_name,container_name>

#include "../type/ptr/ptr.hpp"
#include "../property/_pure.hpp"
#include "../type/container/map.hpp"

namespace reflection
 {
  namespace property
   {

    template
     < 
       typename key_name = std::string
      ,template < typename, typename > class container_name = ::reflection::type::container::map
     >
     class structure_class
      : public virtual ::reflection::property::pure_class
      {
       public:
         typedef key_name key_type;
         typedef ::reflection::property::pure_class property_type;
         //typedef ::std::unique_ptr<property_type> item_type;
         typedef ::std::shared_ptr<property_type> item_type;
         //typedef ::reflection::type::ptr::clone<property_type> item_type;

         typedef container_name< key_type, item_type> container_type;

         structure_class(){}
         structure_class( structure_class const& that_param ){ *this = that_param; }
         structure_class & operator=( structure_class const& that_param )
          {
           // Do nothing!
           return *this;
          }

        ~structure_class(){}

         bool                 exists( key_type const& name )
          {
           return m_container.end() != m_container.find( name );
          }

         void                 insert( key_type const& name, item_type const& item )
          {
           if( true == this->exists( name ) )
            {
             return;
            }
            m_container.emplace( name, item );
          }

         property_type const& get(    key_type const& name )const
          {
           auto iterator = m_container.find( name );
           if( m_container.end( ) == iterator )
            {
             return empty();
            }
           return *(iterator->second);
          }

         property_type      & get(    key_type const& name )
          {
           auto iterator = m_container.find( name );
           if( m_container.end( ) == iterator )
            {
             return empty();
            }
           return *(iterator->second);
          }

         bool               set(    key_type const& name, item_type const& item_param )
          {
           auto iterator = m_container.find( name );
           if( m_container.end( ) == iterator )
            {
             return false;
            }
           iterator->second = item_param;
           return true;
          }

         void remove(  key_type const& name )
          {
           m_container.erase( name );
          }

         void clear()
          {
           m_container.clear();
          }

       public:
         static property_type  & empty()
          {
           static property_type s_empty;
           return s_empty;
          }

       public:
         container_type const& container()const{ return m_container; }
         container_type      & container()     { return m_container; }

       private:
         container_type m_container;
      };

   }
 }

#endif
