#ifndef reflection_property_structure
#define reflection_property_structure

// ::reflection::property::structure_class<key_name,container_name>

#include "../type/ptr/ptr.hpp"
#include "../property/_pure.hpp"
#include "../type/container/container.hpp"

namespace reflection
 {
  namespace property
   {

    template
     <
       typename key_name = std::string
    //,typename pointer_name = ::std::shared_ptr< ::reflection::property::pure_class >
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

         typedef typename container_name< key_type, item_type >::size_type                        size_type;
         typedef typename container_name< key_type, item_type >::container_type              container_type;
         typedef typename container_name< key_type, item_type >::iterator_type                iterator_type;
         typedef typename container_name< key_type, item_type >::const_iterator_type    const_iterator_type;

         structure_class(){}
         structure_class( structure_class const& that_param ){ *this = that_param; }
         structure_class & operator=( structure_class const& that_param )
          {
           // Do nothing!
           return *this;
          }

        ~structure_class(){}

         const_iterator_type  begin()const { return this->container().begin(); }
         iterator_type        begin()      { return this->container().begin(); }
         const_iterator_type    end()const { return this->container().end(); }
         iterator_type          end()      { return this->container().end(); }
         size_type             size()const { return this->container().size(); }

         key_type const key( const_iterator_type const& iterator )const
          {
           return ::reflection::type::container::key< key_type, item_type >( this->container(), iterator ); 
          }
         key_type const key( iterator_type            & iterator )    
          {
           return ::reflection::type::container::key< key_type, item_type >( this->container(), iterator ); 
          }

         item_type const& data( const_iterator_type  const& iterator )const
          { 
           return ::reflection::type::container::data<key_type, item_type >( this->container(), iterator );
          }
         item_type      & data( iterator_type             & iterator )     
          {
           return ::reflection::type::container::data<key_type, item_type >( this->container(), iterator ); 
          }

         bool                 exists( key_type const& name )
          {
           return ::reflection::type::container::exists<key_type, item_type >( this->container(), name );
          }

         const_iterator_type                 find( key_type const& name )const
          {
           return ::reflection::type::container::find<key_type, item_type >( this->container(), name );
          }

         iterator_type                 find( key_type const& name )
          {
           return ::reflection::type::container::find<key_type, item_type >( this->container(), name );
          }

         void                 insert( key_type const& name, item_type const& item )
          {
           if( true == this->exists( name ) )
            {
             return;
            }
           ::reflection::type::container::insert<key_type, item_type >( this->container(), name, item );
          }

         property_type const& get(    key_type const& name )const
          {
           auto iterator = this->find( name );
           if( this->container().end( ) == iterator )
            {
             return empty();
            }
           return *::reflection::type::container::data<key_type, item_type >( this->container(), iterator );
          }

         property_type      & get(    key_type const& name )
          {
           auto iterator = this->find( name );
           if( this->container().end( ) == iterator )
            {
             return empty();
            }
           return *::reflection::type::container::data<key_type, item_type >( this->container(), iterator );;
          }

         bool               set(    key_type const& name, item_type const& item_param )
          {
           auto iterator = this->find( name );
           if( this->container().end( ) == iterator )
            {
             return false;
            }
           ::reflection::type::container::data<key_type, item_type >( this->container(), iterator ) = item_param;
           return true;
          }

         void remove(  key_type const& name )
          {
           this->container().erase( name );
          }

         void clear()
          {
           this->container().clear();
          }

       public:
         static bool  & is_empty()
          {
           return true;
          }

         static property_type  & empty()
          {
           static property_type s_empty;
           return s_empty;
          }

       private:
         container_type const& container()const{ return this->m_container; }
         container_type      & container()     { return this->m_container; }

       private:
         container_type m_container;
      };

   }
 }

#endif
