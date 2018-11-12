#ifndef reflection_content_exposed_field_hpp
#define reflection_content_exposed_field_hpp
 // ::reflection::content::exposed::field_struct<data_name>
 // ::reflection::content::exposed::field( )

#include "../direct/field.hpp"
#include "../mutate/field.hpp"


#include "./basic.hpp"

namespace reflection
 {
  namespace content
   {
    namespace exposed
     {

      template
       <
         typename identifier_name
        ,typename data_name
        ,typename original_name  //= data_name const&
        ,typename model_name  //= data_name const&
        ,typename class_name
        ,typename storage_name
        ,typename report_name
       >
       class field_class
        : public ::reflection::content::distinctive_class<identifier_name,data_name>
        , public ::reflection::property::exposed::field_class< data_name, original_name, model_name, class_name, storage_name, report_name >
        {
         public:
           typedef identifier_name  identifier_type;
           typedef data_name        data_type;
           typedef model_name    model_type;
           typedef     original_name    original_type;
           typedef class_name       class_type;
           typedef storage_name     storage_type;

           typedef ::reflection::content::distinctive_class<identifier_name,data_name>                     distinctive_type;
           typedef ::reflection::property::exposed::field_class< data_name, original_name, model_name, class_name, storage_name, report_name >  field_type;

           using field_type::field_type;
        };


      template
       <
         typename identifier_name
        ,typename       data_name
        ,typename   original_name  = data_name &
        ,typename      model_name  = data_name const&
        ,typename      class_name
        ,typename    storage_name
        ,typename     report_name = bool
       >
       inline
       typename ::reflection::content::exposed::field_class<identifier_name,data_name,original_name,model_name,class_name,storage_name,report_name>
       field
        (
          storage_name     const&      storage_param
         ,data_name       class_name::*pointer_param
        )
        {
         typedef ::reflection::content::exposed::field_class<identifier_name,data_name,original_name,model_name,class_name,storage_name,report_name> field_type;
         return field_type( storage_param, pointer_param );
        }

     }
   }
 }

#endif