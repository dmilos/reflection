#ifndef reflection_property_direct_field
#define reflection_property_direct_field

// ::reflection::property::direct::_internal::field_struct<original_name,class_name,storage_name>

 #include "./basic.hpp"

 #include "../../ornament/relation.hpp"
 #include "../../ornament/accessibility.hpp"
 #include "../../ornament/linkage.hpp"
 #include "../../ornament/qualification.hpp"



namespace reflection
 {
  namespace property
   {
    namespace direct
     {

      namespace _internal
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

           typedef data_type         class_type::*pointer_type; //!< By design

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

           typedef ::reflection::property::direct::basic_class< original_type, storage_type, extractor_type >      typedef_type;

           static typedef_type make(  storage_type const& carrier_param, pointer_type const& pointer_param )
            {
             return typedef_type( carrier_param, extractor_type( pointer_param ) );
            }
          };

      }

      template
       <
         typename     data_name
        ,typename  original_name // = data_name &
        ,typename    class_name
        ,typename  storage_name
       >
       class field_class
        : public ::reflection::property::direct::_internal::field_struct<data_name,original_name,class_name,storage_name>::typedef_type
        , public ::reflection::ornament::relation_class
        , public ::reflection::ornament::accessibility_class
        , public ::reflection::ornament::linkage_class
        , public ::reflection::ornament::qualification_class
        {
         public:
          typedef ::reflection::ornament::relation_class relation_type;
          typedef ::reflection::ornament::accessibility_class accessibility_type;

          typedef typename ::reflection::property::direct::_internal::field_struct<data_name,original_name,class_name,storage_name>  basic_type;
          typedef typename basic_type::typedef_type  base_type;

          typedef typename basic_type::extractor_type extractor_type;
          typedef typename basic_type::pointer_type     pointer_type;
          typedef typename basic_type::storage_type     storage_type;

          explicit field_class( storage_type   const& storage_param, pointer_type const& pointer_param )
            : relation_type( relation_type::member_index )
            , accessibility_type( accessibility_type::default_index )
            , base_type( storage_param, extractor_type( pointer_param ) )
            {
            }

          using base_type::disclose;
        };


      template
       <
         typename data_name
        ,typename original_name = data_name &
        ,typename class_name
        ,typename storage_name
       >
       inline
       typename ::reflection::property::direct::field_class<data_name,original_name,class_name,storage_name>::typedef_type
       field
        (
          storage_name         const& carrier_param
         ,data_name      class_name::*pointer_param
        )
        {
         typedef ::reflection::property::direct::field_class<data_name,original_name,class_name,storage_name> field_type;
         return field_type( carrier_param, pointer_param );
        }

     }
   }
 }

#endif
