#ifndef reflection_content_trinity_field_hpp
#define reflection_content_trinity_field_hpp
 // ::reflection::content::trinity::field_struct<data_name>
 // ::reflection::content::trinity::field( )

#include "../direct/field.hpp"
#include "../mutate/field.hpp"
#include "../inspect/field.hpp"


#include "./basic.hpp"

namespace reflection
 {
  namespace content
   {
    namespace trinity
     {

      template
       <
         typename  identifier_name
        ,typename        data_name
        ,typename original_name  //= data_name &
        ,typename model_name     //= data_name const&
        ,typename image_name     //= data_name const&
        ,typename class_name
        ,typename storage_name
        ,typename report_name = bool
       >
       class field_class
        : public ::reflection::content::distinctive_class<identifier_name,data_name>
        , public ::reflection::property::trinity::field_class<data_name,original_name, model_name, image_name, class_name, storage_name, report_name >
        {
         public:
           typedef identifier_name  identifier_type;
           typedef data_name        data_type;
           typedef original_name    original_type;
           typedef     image_name    image_type;
           typedef class_name       class_type;
           typedef storage_name     storage_type;

           typedef ::reflection::content::distinctive_class<identifier_name,data_name>                     distinctive_type;
           typedef ::reflection::property::trinity::field_class< data_name, original_name, model_name, image_name, class_name, storage_name, report_name  >  field_type;

           using field_type::field_type;
        };
 
      template
       <
         typename  identifier_name
        ,typename     data_name
        ,typename original_name   = data_name &
        ,typename model_name      = data_name const&
        ,typename image_name      = data_name const&
        ,typename class_name
        ,typename storage_name
        ,typename report_name     = bool
       >
       inline
       typename ::reflection::content::trinity::field_class< identifier_name, data_name,original_name, model_name, image_name,class_name,storage_name,report_name>
       field
        (
          storage_name     const&      storage_param
         ,data_name       class_name::*pointer_param
        )
        {
         typedef ::reflection::content::trinity::field_class< identifier_name, data_name,original_name,model_name,image_name,class_name,storage_name,report_name> field_type;
         return field_type( storage_param, pointer_param );
        }


     }
   }
 }

#endif
