#ifndef reflection_object
#define reflection_object

#include "./type/string.hpp"
#include "./type/ptr/clone.hpp"
#include "./property/property.hpp"

namespace reflection
 {

  class object
   {
    public:
      typedef std::string string_type;
      typedef ::reflection::property::pure property_type;
      typedef ::reflection::type::ptr::clone<property_type> item_type;

      typedef std::map<string_type, item_type> container_type;

      void                 insert( string_type const& name, item_type const& property );
      property_type const& get(    string_type const& name )const;
      property_type      & get(    string_type const& name );
      void                 set(    string_type const& name, item_type const& property );

      container_type const& container()const{ return m_container; }
      container_type      & container()     { return m_container; }

    private:
      container_type m_container;
   };

 }

#endif
