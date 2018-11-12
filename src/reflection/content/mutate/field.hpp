#ifndef reflection_content_mutate_field_hpp
#define reflection_content_mutate_field_hpp
 // ::reflection::content::mutate::field_struct<data_name, model_name,class_name,storage_name>
 // ::reflection::content::mutate::field( )

#include "../../property/mutate/field.hpp"

#include "./basic.hpp"

namespace reflection
 {
  namespace content
   {
    namespace mutate
     {

      template
       <
         typename identifier_name
        ,typename data_name
        ,typename model_name
        ,typename class_name
        ,typename storage_name
        ,typename report_name
       >
       class field_class
        : public ::reflection::content::distinctive_class<identifier_name,data_name>
        , public ::reflection::property::mutate::field_class< data_name, model_name, class_name, storage_name, report_name >
        {
         public:
           typedef identifier_name  identifier_type;
           typedef data_name        data_type;
           typedef model_name    model_type;
           typedef class_name       class_type;
           typedef storage_name     storage_type;

           typedef ::reflection::content::distinctive_class<identifier_name,data_name>                     distinctive_type;
           typedef ::reflection::property::mutate::field_class< data_name, model_name, class_name, storage_name, report_name >   field_type;

           using field_type::field_type;
        };


      template
       <
         typename identifier_name
        ,typename data_name
        ,typename model_name   = data_name const&
        ,typename class_name
        ,typename storage_name
        ,typename report_name  = bool
       >
       inline
       typename ::reflection::content::mutate::field_class<identifier_name,data_name,model_name,class_name,storage_name,report_name>
       field
        (
          storage_name     const&      storage_param
         ,data_name       class_name::*pointer_param
        )
        {
         typedef ::reflection::content::mutate::field_class<identifier_name,data_name,model_name,class_name,storage_name,report_name> field_type;
         return field_type( storage_param, pointer_param );
        }

      }
    }
  }

#endif
