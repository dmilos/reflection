#ifndef reflection_property_inspect_field
 #define reflection_property_inspect_field

// ::reflection::property::inspect::field_struct<image_name,class_name,storage_name>

 #include "./base.hpp"

namespace reflection
 {
  namespace property
   {
    namespace inspect
     {

      template
       <
         typename    data_name
        ,typename   image_name
        ,typename   class_name
        ,typename storage_name
       >
       struct field_struct
        {
         typedef data_name        data_type;
         typedef image_name    image_type;
         typedef class_name    class_type;
         typedef storage_name  storage_type;

         typedef data_type         class_name::*pointer_type; //!< By design

         typedef class retriever_class
          {
           public:
             explicit retriever_class( pointer_type const& pointer_param = NULL )
              :m_pointer( pointer_param )
              {
              }
             image_type operator()( storage_type const& carrier_param )const
              {
               if( NULL == m_pointer )
                {
                 throw (void*)NULL;
                }
               return (*carrier_param).*m_pointer;
              }

           private:
             pointer_type  m_pointer;
          } retriever_type;

         typedef ::reflection::property::inspect::base_class<image_name,storage_name,retriever_type>      typedef_type;

         static typedef_type make( storage_type const& carrier_param, pointer_type const& pointer_param )
          {
           return typedef_type( carrier_param, retriever_type( pointer_param ) );
          }

        };

      template
       <
         typename   data_name
        ,typename   image_name
        ,typename   class_name
        ,typename storage_name
       >
       inline
       typename ::reflection::property::inspect::field_struct<data_name,image_name,class_name,storage_name>::typedef_type
       field
        (
          storage_name           const& carrier_param
         ,data_name      class_name::*pointer_param
        )
        {
         typedef ::reflection::property::inspect::field_struct<data_name,image_name,class_name,storage_name> field_type;
         return field_type::make( carrier_param, pointer_param );
        }

     }
   }
 }

#endif
