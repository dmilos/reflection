#ifndef type_ornament_category_pure_hpp
 #define type_ornament_category_pure_hpp

// ::reflection::ornament::category::pure_class<identificator_name>
// ::reflection::ornament::category::pure()

#include "../property/_pure.hpp"

 namespace reflection
  {
   namespace ornament
    {

     template
      <
        typename identifier_name
      >
      class category_class
       {
        public:
          typedef identifier_name identifier_type;

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
            typedef ::reflection::ornament::category_class<identifier_name> category_type;
            return nullptr != dynamic_cast< category_type const*>( &property_param );
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
