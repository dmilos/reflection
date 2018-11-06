#ifndef reflection_content_direct_field_hpp
#define reflection_content_direct_field_hpp
 // ::reflection::content::direct::field_class<data_name, original_name,class_name,storage_name>
 // ::reflection::content::direct::field( )

#include "../../property/direct/field.hpp"

#include "./basic.hpp"

namespace reflection
 {
  namespace content
   {
    namespace direct
     {

      template
       <
        typename identifier_name
       ,typename data_name
       ,typename original_name
       ,typename class_name
       ,typename storage_name
       >
       struct field_struct
        : ::reflection::property::direct::field_struct<data_name, original_name, class_name, storage_name >
        {
         public:
           typedef data_name     data_type;
           typedef original_name original_type;
           typedef class_name    class_type;
           typedef storage_name  storage_type;

           typedef ::reflection::property::direct::field_struct<data_name, original_name, class_name, storage_name > property_type;

           typedef typename property_type::extractor_type  extractor_type;

           typedef ::reflection::content::direct::basic_class<identifier_name,data_name,original_name,storage_name,extractor_type>      typedef_type;

           typedef typename property_type::pointer_type    pointer_type;

           static typedef_type make( storage_type const& storage_param, pointer_type const& pointer_param )
            {
             return typedef_type( storage_param, extractor_type( pointer_param ) );
            }

       };

      template
       <
         typename identifier_name
        ,typename data_name
        ,typename original_name = data_name &
        ,typename class_name
        ,typename storage_name
       >
       inline
       typename ::reflection::content::direct::field_struct<identifier_name,data_name,original_name,class_name,storage_name>::typedef_type
       field
        (
          storage_name const&             storage_param
         ,data_name       class_name::*pointer_param
        )
        {
         typedef ::reflection::content::direct::field_struct<identifier_name,data_name,original_name,class_name,storage_name> field_type;
         return field_type::make( storage_param, pointer_param );
        }

      }
    }
  }

#endif
