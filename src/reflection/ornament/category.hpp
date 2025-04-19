#ifndef type_ornament_category_pure_hpp
 #define type_ornament_category_pure_hpp

// ::reflection::ornament::category_class<identifier_name>

#include "../property/_pure.hpp"
#include "../type/name/id.hpp"

 namespace reflection
  {
   namespace ornament
    {

     template
      <
        typename identifier_name //!< TODO rename to ID
      >
      class category_class //!< TODO rename to identifier
       {
        public:
          typedef identifier_name identifier_type;
          typedef ::reflection::type::name::identificatorX< identifier_name  > identificator_type;

          typedef ::reflection::ornament::category_class< identifier_name  > this_type;

        public:
          explicit  category_class
                     (
                       identifier_type const& id_param = identifier_type()
                     )
                     : m_identifier( id_param )
                     {
                     }

          virtual   ~category_class(){ }

        public:
          identifier_type const& identifier()const
           {
            return m_identifier;
           }
        protected:
          void identifier( identifier_type const& id_param )
           {
            m_identifier = id_param;
           }
        private:
          identifier_type m_identifier;

        public:
          static bool check( ::reflection::property::pure_class const& property_param )
           {
            return nullptr != dynamic_cast< this_type const*>( &property_param );
           }

        public:
          static identifier_type identifier( ::reflection::property::pure_class const& property_param )
           {
            this_type  const* this_item = dynamic_cast< this_type const* >( &property_param );
            if( nullptr == this_item )
             {
              return identificator_type::NAT();
             }
            return this_item->identifier();
           }

        public:
          static this_type self( ::reflection::property::pure_class const& property_param )
           {
            return dynamic_cast< this_type const&>( property_param );
           }

       };

     template
      <
        typename identifier_name
      >
      ::reflection::ornament::category_class<identifier_name> const&
      category( ::reflection::property::pure_class const& property_param )
       {
        typedef ::reflection::ornament::category_class<identifier_name> category_type;
        return dynamic_cast< category_type const&>( property_param );
       }

     template
      <
        typename identifier_name
      >
      ::reflection::ornament::category_class<identifier_name> const&
      category( ::reflection::property::pure_class & property_param )
       {
        typedef ::reflection::ornament::category_class<identifier_name> category_type;
        return dynamic_cast< category_type &>( property_param );
       }

   }
 }

#endif
