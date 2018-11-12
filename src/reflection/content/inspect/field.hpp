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
       class field_class
        : public ::reflection::content::distinctive_class<identifier_name,data_name>
        , public ::reflection::property::inspect::field_class<data_name,image_name, class_name, storage_name >
        {
         public:
           typedef identifier_name  identifier_type;
           typedef data_name        data_type;
           typedef image_name    image_type;
           typedef class_name       class_type;
           typedef storage_name     storage_type;

           typedef ::reflection::content::distinctive_class<identifier_name,data_name>                     distinctive_type;
           typedef ::reflection::property::inspect::field_class<data_name, image_name, class_name, storage_name >   field_type;

           using field_type::field_type;
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
       typename ::reflection::content::inspect::field_class<identifier_name,data_name,image_name,class_name,storage_name>
       field
        (
          storage_name     const&      storage_param
         ,data_name       class_name::*pointer_param
        )
        {
         typedef ::reflection::content::inspect::field_class<identifier_name,data_name,image_name,class_name,storage_name> field_type;
         return field_type( storage_param, pointer_param );
        }

      }
    }
  }

#endif
