#ifndef type_content_category_pure_hpp
 #define type_content_category_pure_hpp

// ::reflection::content::category::pure_class<type_name>
// ::reflection::content::category::type()
// ::reflection::content::category::check()

 namespace reflection
  {
   namespace content
    {
     namespace category
      {

       template
        <
          typename type_name
        >
        class pure_class
         {
          public:
            typedef type_name type_type;

            explicit  pure_class
                       (
                        type_type const& type_param = type_type()
                       )
                       : m_type( type_param )
                       {
                       }

            virtual   ~pure_class(){ }

          public:
            type_type const& type()const
             {
              return m_type;
             }
          protected:
            type_type& type( void )
             {
              return m_type;
             }
          private:
            type_type m_type;
         };

       template
        <
         typename type_name
        >
        inline
        type_name const&
        type( ::reflection::content::category::pure_class<type_name> const& instance_param )
         {
          return instance_param.type();
         }

       template
        <
          typename type_name
         ,typename whatever_name
        >
        inline
        bool check( whatever_name const& whatever_param )
         {
          typedef ::reflection::content::category::pure_class<type_name> category_type;
          return nullptr != dynamic_cast< category_type const*>( &whatever_param );
         }

      }
   }
 }

#endif
