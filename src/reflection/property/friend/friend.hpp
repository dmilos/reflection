#ifndef reflection_property_friend_pure
#define reflection_property_friend_pure

#include "../../type/name/id.hpp"
// ::reflection::property::frienddeclaration::pure_class<identifier_name>
// ::reflection::property::frienddeclaration::check()


namespace reflection
 {
  namespace property
   {
    namespace frienddeclaration
     {

      template
       <
        typename identifier_name
       >
       class pure_class
        : virtual public ::reflection::property::pure_class
        ,         public ::reflection::ornament::relation_class
        {
         public:
           typedef identifier_name identifier_type;
           typedef std::string string_type;

           typedef ::reflection::ornament::relation_class  relation_type;
           typedef ::reflection::type::name::identificatorX< identifier_name  > identificator_type;

           typedef ::reflection::property::frienddeclaration::pure_class<identifier_name>  this_type;

         public:
//                  pure_class( ){}
                    pure_class( identifier_type const& object, string_type const& name )
                     :m_object(object),m_name(name)
                     ,relation_type( relation_type::friend_index )
                     {
                     }
           virtual ~pure_class( ){}

        public:
          identifier_type   const&  object ( void )const
          {
            return m_object;
          }
          void                   object( identifier_type const& object_param )
          {
            m_object = object_param;
          }

        protected:
          identifier_type&          object()
          {
            return m_object;
          }

        private:
          identifier_type         m_object;

        public:
          string_type   const&  name ( void )const
           {
            return m_name;
           }
          void                   name( string_type const& name_param )
           {
            m_name = name_param;
           }

        protected:
          string_type&          name()
           {
            return m_name;
           }

        private:
          string_type         m_name;

        public:
          static identifier_type object( ::reflection::property::pure_class const& property_param )
           {
            this_type  const* this_item = dynamic_cast< this_type const* >( &property_param );
            if( nullptr == this_item )
             {
              return identificator_type::NAT();
             }
            return this_item->object();
           }

       };

      template< typename identifier_name >
       inline bool check( ::reflection::property::pure_class const& property_param )
        {
         typedef ::reflection::property::frienddeclaration::pure_class<identifier_name> friend_type;
         return nullptr != dynamic_cast< friend_type const*>( &property_param );
        }

     }
   }
 }

reflection__IDSPEC( std::string, "$friend", ::reflection::property::frienddeclaration::pure_class<std::string> )


#endif
