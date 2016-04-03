#ifndef reflection_object
#define reflection_object

#include "./type/string.hpp"
#include "./type/ptr/ptr.hpp"
#include "./property/property.hpp"

namespace reflection
 {

  class object_class
   {
    public:
      typedef std::string string_type;
      typedef ::reflection::property::pure_class property_type;
      typedef ::reflection::type::ptr::clone<property_type> item_type;

      typedef std::map<string_type, item_type> container_type;

      object_class(){}
      object_class( object_class const& that_param ){ *this = that_param; }
      object_class & operator=( object_class const& that_param )
       {
        // EMPTY!!!
       }

      bool                 exists( string_type const& name )
       {
        return m_container.end() != m_container.find( name );
       }

      void                 insert( string_type const& name, item_type const& item )
       {
        if( true == this->exists( name ) )
         {
          return;
         }
         m_container.emplace( name, item );
       }

      property_type const& get(    string_type const& name )const
       {
        static property_type s_empty;
        auto iterator = m_container.find( name );
        if( m_container.end( ) == iterator )
         {
          return s_empty;
         }
        return *(iterator->second);
       }

      property_type      & get(    string_type const& name )
       {
        static property_type s_empty;
        auto iterator = m_container.find( name );
        if( m_container.end( ) == iterator )
         {
          return s_empty;
         }
        return *(iterator->second);
       }

      bool               set(    string_type const& name, item_type const& item )
       {
        auto iterator = m_container.find( name );
        if( m_container.end( ) == iterator )
         {
          return false;
         }
        iterator->second = item;
        return true;
       }

      void remove(  string_type const& name )
       {
        m_container.erase( name );
       }
      void clear()
       {
        m_container.clear();
       }


      container_type const& container()const{ return m_container; }
      container_type      & container()     { return m_container; }

    private:
      container_type m_container;
   };

 }

#endif
