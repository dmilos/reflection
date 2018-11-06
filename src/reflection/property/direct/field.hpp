#ifndef reflection_property_direct_field
#define reflection_property_direct_field

// ::reflection::property::direct::field_struct<original_name,class_name,storage_name>

 #include "./base.hpp"

namespace reflection
 {
  namespace property
   {
    namespace direct
     {

      template
       <
         typename     data_name
        ,typename original_name // = data_name &
        ,typename    class_name
        ,typename  storage_name
       >
       struct field_struct
        {
         typedef data_name            data_type;
         typedef original_name    original_type;
         typedef class_name          class_type;
         typedef storage_name      storage_type;

         typedef data_type         class_name::*pointer_type; //!< By design

         typedef class extractor_class
          {
           public:
             explicit extractor_class( pointer_type const& pointer_param = NULL )
              :m_pointer( pointer_param )
              {
              }

             original_type operator()( storage_type & carrier_param )const
              {
               if( NULL == m_pointer )
                {
                 throw (void*)NULL;
                }
               return  (*carrier_param).*m_pointer;
              }

           private:
             pointer_type  m_pointer;
          } extractor_type;

         typedef ::reflection::property::direct::base_class< original_type, storage_name, extractor_type >      typedef_type;

         static typedef_type make(  storage_type const& carrier_param, pointer_type const& pointer_param )
          {
           return typedef_type( carrier_param, extractor_type( pointer_param ) );
          }

        };

      template
       <
         typename data_name
        ,typename original_name = data_name &
        ,typename class_name
        ,typename storage_name
       >
       inline
       typename ::reflection::property::direct::field_struct<data_name,original_name,class_name,storage_name>::typedef_type
       field
        (
          storage_name         const& carrier_param
         ,data_name      class_name::*pointer_param
        )
        {
         typedef ::reflection::property::direct::field_struct<data_name,original_name,class_name,storage_name> field_type;
         return field_type::make( carrier_param, pointer_param );
        }

     }
   }
 }

#endif
