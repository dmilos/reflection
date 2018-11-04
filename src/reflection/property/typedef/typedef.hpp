#ifndef reflection_property_typedefinition_pure
#define reflection_property_typedefinition_pure

// ::reflection::property::typedefinition::pure_class<size_name>
// ::reflection::property::typedefinition::check<size_name>()


namespace reflection
 {
  namespace property
   {
    namespace typedefinition
     {

    //template < typename string_name >
       class pure_class
        : virtual public ::reflection::property::pure_class
        {
         public:
           typedef std::string string_type;

                    pure_class(){}
           virtual ~pure_class(){}

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
       };

      template< typename name_name, typename value_name >
       inline bool check( ::reflection::property::pure_class const& property_param )
        {
         typedef ::reflection::property::typedefinition::pure_class typedefinition_type;
         return nullptr != dynamic_cast< typedefinition_type const*>( &property_param );
        }

     }
   }
 }

#endif
