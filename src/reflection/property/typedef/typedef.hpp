#ifndef reflection_property_typedefinition_pure
#define reflection_property_typedefinition_pure

#include "../../type/name/id.hpp"
// ::reflection::property::typedefinition::pure_class<identifier_name>
// ::reflection::property::typedefinition::check()


namespace reflection
 {
  namespace property
   {
    namespace typedefinition
     {

     template
      <
       typename identifier_name
      >
      class pure_class
       : virtual public ::reflection::property::pure_class
       ,         public ::reflection::ornament::visibility_class
       {
        public:
          typedef identifier_name identifier_type;
          typedef std::string string_type;

          typedef ::reflection::ornament::visibility_class  visibility_type;
        public:
//                 pure_class( ){}
                   pure_class( identifier_type const& object, string_type const& name )
                    :m_object(object),m_name(name)
                    ,visibility_type( visibility_type::public_index )
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
      };

      template< typename identifier_name >
       inline bool check( ::reflection::property::pure_class const& property_param )
        {
         typedef ::reflection::property::typedefinition::pure_class<identifier_name> typedefinition_type;
         return nullptr != dynamic_cast< typedefinition_type const*>( &property_param );
        }

     }
   }
 }

reflection__IDSPEC( std::string, "$typedef", ::reflection::property::typedefinition::pure_class<std::string> )


#endif
