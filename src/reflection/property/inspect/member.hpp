#ifndef reflection_property_inspect_member
 #define reflection_property_inspect_member

// ::reflection::property::inspect::member_struct<image_name,class_name,storage_name>

 #include "./basic.hpp"

namespace reflection
 {
  namespace property
   {
    namespace inspect
     {

     namespace _internal
      {
       template
        <
          typename image_name
         ,typename class_name
         ,typename storage_name
        >
        struct member_struct
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

          typedef ::reflection::property::inspect::basic_class<image_name,storage_name,retriever_type>      typedef_type;

          static typedef_type make( storage_type const& carrier_param, reader_type const& reader_param )
           {
            return typedef_type( carrier_param, retriever_type( reader_param ) );
           }

         };
       }

      template
       <
         typename image_name
        ,typename class_name
        ,typename storage_name
       >
       class member_class
        : public ::reflection::ornament::relation_class
        , public ::reflection::ornament::accessibility_class
        , public ::reflection::property::inspect::_internal::member_struct<image_name,class_name,storage_name>::typedef_type
        {
         public:
          typedef ::reflection::ornament::relation_class relation_type;
          typedef ::reflection::ornament::accessibility_class accessibility_type;

          typedef typename ::reflection::property::inspect::_internal::member_struct<image_name,class_name,storage_name>  basic_type;
          typedef typename basic_type::typedef_type  base_type;

          typedef typename basic_type::retriever_class retriever_class;
          typedef typename basic_type::reader_type         reader_type;
          typedef typename basic_type::storage_type       storage_type;

          explicit member_class( storage_type   const& storage_param, reader_type const& reader_param )
            : relation_type( relation_type::member_index )
            , accessibility_type( accessibility_type::default_index )
            , base_type( storage_param, retriever_class( reader_param ) )
            {
            }

          using base_type::present;
        };


      template
       <
         typename image_name
        ,typename class_name
        ,typename storage_name
       >
       inline
       typename ::reflection::property::inspect::member_class<image_name,class_name,storage_name>
       member
        (
          storage_name           const& carrier_param
         ,image_name       (class_name::*reader_param)( void )const
        )
        {
         typedef ::reflection::property::inspect::member_class<image_name,class_name,storage_name> member_type;
         return member_type( carrier_param, reader_param );
        }

     }
   }
 }

#endif
