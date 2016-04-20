#ifndef reflection_property_inspect_member
 #define reflection_property_inspect_member
 
// ::reflection::property::inspect::member_class<image_name,class_name,storage_name>

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
        ,typename storage_name
       >
       struct member_class
        {
         typedef image_name    image_type;
         typedef class_name    class_type;
         typedef storage_name  storage_type;

         typedef image_name     (class_name::*reader_type)( )const;

         typedef class retriever_class
          {
           public:
             explicit retriever_class( reader_type const& reader_param = NULL )
              :m_reader( reader_param )
              {
              }
             image_type operator()( storage_type const& carrier_param )const
              {
               if( NULL == m_reader ) 
                {
                 throw (void*)NULL;
                }   
               return ((*carrier_param).*m_reader)();
              }

           private:
             reader_type  m_reader;
          } retriever_type;

         typedef ::reflection::property::inspect::base_class<image_name,storage_name,retriever_type>      typedef_type;

         static typedef_type make( storage_type const& carrier_param, reader_type const& reader_param )
          {
           return typedef_type( carrier_param, retriever_type( reader_param ) );
          }

        };

      template
       <
         typename image_name
        ,typename class_name
        ,typename storage_name
       >
       inline
       typename ::reflection::property::inspect::member_class<image_name,class_name,storage_name>::typedef_type
       member
        (
          storage_name           const& carrier_param
         ,image_name       (class_name::*reader_param)( void )const 
        )
        {
         typedef ::reflection::property::inspect::member_class<image_name,class_name,storage_name> member_type;
         return member_type::make( carrier_param, reader_param );
        }

     }
   }
 }

#endif
