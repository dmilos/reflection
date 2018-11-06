#ifndef reflection_content_inspect_field_hpp
#define reflection_content_inspect_field_hpp
 // ::reflection::content::inspect::field_struct<data_name, image_name,class_name,storage_name>
 // ::reflection::content::inspect::field( )

#include "../../property/inspect/field.hpp"

#include "./basic.hpp"

namespace reflection
 {
  namespace content
   {
    namespace inspect
     {

      template
       <
         typename identifier_name
        ,typename data_name
        ,typename image_name
        ,typename class_name
        ,typename storage_name
       >
       struct field_struct
        : ::reflection::property::inspect::field_struct<data_name,image_name, class_name, storage_name >
        {
         typedef data_name     data_type;
         typedef image_name    image_type;
         typedef class_name    class_type;
         typedef storage_name  storage_type;

         typedef ::reflection::property::inspect::field_struct<data_name,image_name, class_name, storage_name > property_type;

         typedef typename property_type::retriever_type  retriever_type;

         typedef ::reflection::content::inspect::basic_class<identifier_name,data_name,image_name,storage_name,retriever_type>      typedef_type;

         typedef typename property_type::pointer_type        pointer_type;

         static typedef_type make( storage_type const& storage_param, pointer_type const& pointer_param )
          {
           return typedef_type( storage_param, retriever_type( pointer_param ) );
          }

       };

      template
       <
         typename identifier_name
        ,typename data_name
        ,typename image_name   = data_name const&
        ,typename class_name
        ,typename storage_name
       >
       inline
       typename ::reflection::content::inspect::field_struct<identifier_name,data_name,image_name,class_name,storage_name>::typedef_type
       field
        (
          storage_name     const&      storage_param
         ,data_name       class_name::*pointer_param
        )
        {
         typedef ::reflection::content::inspect::field_struct<identifier_name,data_name,image_name,class_name,storage_name> field_type;
         return field_type::make( storage_param, pointer_param );
        }

      }
    }
  }

#endif
