#ifndef reflection_property_inspect_member
 #define reflection_property_inspect_member
// TODO

 #include "./base.hpp"

namespace reflection
 {
  namespace property
   {
    namespace inspect
     {

      template
        <
         typename image_name
        ,typename class_name
        ,typename carrier_name
        >
       struct  member_class
        {
         typedef image_name    image_type;
         typedef class_name    class_type;
         typedef carrier_name  carrier_type;

         typedef image_name     (class_name::*reader_type)( )const;

         typedef class convertor_class
          {
           public:
             explicit convertor_class( reader_type const& reader_param = NULL )
              :m_reader( reader_param )
              {
              }
             image_type operator()( carrier_type const& carrier_param )const
              {
               if( NULL == m_reader ) 
                {
                 throw (void*)NULL;
                }   
               return ((*carrier_param).*m_reader)();
              }

           private:
            reader_type  m_reader;
          } convertor_type;

         typedef ::reflection::property::inspect::base_class<image_name,carrier_name,convertor_type>      typedef_type;

         static typedef_type make( carrier_type const& carrier_param, reader_type const& reader_param )
                {
                 return typedef_type( carrier_param, convertor_type( reader_param ) );
                }

        };

      template
       <
        typename image_name
       ,typename class_name
       ,typename carrier_name
       >
       inline
       typename ::reflection::property::inspect::member_class<image_name,class_name,carrier_name>::typedef_type
       member
        (
          carrier_name const& carrier_param
         ,image_name       (class_name::*reader_param)( void )const 
        )
        {
         typedef ::reflection::property::inspect::member_class<image_name,class_name,carrier_name> member_type;
         return member_type::make( carrier_param, reader_param );
        }

     }
   }
 }

#endif
