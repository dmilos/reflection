#ifndef type_content_category_pure_hpp
 #define type_content_category_pure_hpp

// ::reflection::content::category::pure_class<identificator_name>
// ::reflection::content::category::identifier()
// ::reflection::content::category::check()

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
        identifier_name const&
        identifier( ::reflection::content::category::pure_class<identifier_name> const& instance_param )
         {
          return instance_param.identifier();
         }

       template
        <
          typename identifier_name
         ,typename whatever_name
        >
        inline
        bool check( whatever_name const& whatever_param )
         {
          typedef ::reflection::content::category::pure_class<identifier_name> category_type;
          return nullptr != dynamic_cast< category_type const*>( &whatever_param );
         }

      }
   }
 }

#endif
