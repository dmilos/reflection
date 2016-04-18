#ifndef type_category_hpp
 #define type_category_hpp

 // type::category


 namespace type
  {

   template
    <
      typename type_name
    >
    class category
     {
      public:
        typedef type_name type_type;

        explicit  category
                   (
                    type_type const& type_param = type_type()
                   )
                   : m_type( type_param )
                   {
                   }

       virtual   ~category(){ }

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
    type( ::type::category<type_name> const& instance_param )
     {
      return instance_param.type();
     }


  }

#endif
