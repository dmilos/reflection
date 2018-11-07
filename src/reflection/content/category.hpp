#ifndef type_content_category_pure_hpp
 #define type_content_category_pure_hpp

// ::reflection::content::category::pure_class<identificator_name>
// ::reflection::content::category::identifier()
// ::reflection::content::category::check()
// ::reflection::content::category::pure()

 namespace reflection
  {
   namespace content
    {
     namespace category
      {

       template
        <
          typename identifier_name
        >
        class pure_class
         {
          public:
            typedef identifier_name identifier_type;

          public:
            explicit  pure_class
                       (
                         identifier_type const& id_param = identifier_type()
                       )
                       : m_identifier( id_param )
                       {
                       }

            virtual   ~pure_class(){ }

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
         };

       template
        <
          typename identifier_name
        >
        inline
        bool check( ::reflection::property::pure_class const& property_param )
         {
          typedef ::reflection::content::category::pure_class<identifier_name> category_type;
          return nullptr != dynamic_cast< category_type const*>( &property_param );
         }

       template
        <
          typename identifier_name
        >
        ::reflection::content::category::pure_class<identifier_name> const&
        pure( ::reflection::property::pure_class const& property_param )
         {
          typedef ::reflection::content::category::pure_class<identifier_name> category_type;
          return dynamic_cast< category_type const&>( property_param );
         }

       template
        <
          typename identifier_name
        >
        ::reflection::content::category::pure_class<identifier_name> const&
        pure( ::reflection::property::pure_class & property_param )
         {
          typedef ::reflection::content::category::pure_class<identifier_name> category_type;
          return dynamic_cast< category_type &>( property_param );
         }

      }
   }
 }

#endif
