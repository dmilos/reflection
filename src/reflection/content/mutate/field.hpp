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
       struct field_struct
        : ::reflection::property::mutate::field_struct<data_name, model_name, class_name, storage_name, report_name >
        {
         public:
           typedef data_name     data_type;
           typedef model_name    model_type;
           typedef class_name    class_type;
           typedef storage_name  storage_type;

           typedef ::reflection::property::mutate::field_struct<data_name,model_name, class_name, storage_name, report_name > property_type;

           typedef typename property_type::assigner_class  assigner_type;

           typedef ::reflection::content::mutate::basic_class<identifier_name,data_name,model_name,storage_name,assigner_type, report_name>      typedef_type;

           typedef typename property_type::pointer_type       pointer_type;

           static typedef_type make( storage_type const& storage_param, pointer_type const& pointer_param )
           {
            return typedef_type( storage_param, assigner_type( pointer_param ) );
           }

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
       typename ::reflection::content::mutate::field_struct<identifier_name,data_name,model_name,class_name,storage_name,report_name>::typedef_type
       field
        (
          storage_name     const&      storage_param
         ,data_name       class_name::*pointer_param
        )
        {
         typedef ::reflection::content::mutate::field_struct<identifier_name,data_name,model_name,class_name,storage_name,report_name> field_type;
         return field_type::make( storage_param, pointer_param );
        }

      }
    }
  }

#endif
