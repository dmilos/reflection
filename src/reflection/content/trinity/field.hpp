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
       struct field_struct
        : public ::reflection::content::direct::field_struct<  identifier_name, data_name,original_name,class_name,storage_name >
        , public ::reflection::content::mutate::field_struct<  identifier_name, data_name,model_name,class_name,storage_name,report_name >
        , public ::reflection::content::inspect::field_struct<  identifier_name, data_name,image_name,class_name,storage_name >
        {
         public:
           typedef       data_name        data_type;
           typedef   original_name    original_type;
           typedef      model_name       model_type;
           typedef      image_name       image_type;
           typedef      class_name       class_type;
           typedef    storage_name     storage_type;
           typedef     report_name      report_type;

           typedef ::reflection::content::direct::field_struct<  identifier_name, data_name,original_name,class_name,storage_name >  direct_type;
           typedef ::reflection::content::mutate::field_struct<  identifier_name,  data_name,   model_name,class_name,storage_name,report_name >  mutate_type;
           typedef ::reflection::content::inspect::field_struct< identifier_name, data_name,   image_name,class_name,storage_name >            inspect_type;

           typedef typename direct_type::extractor_type   extractor_type;
           typedef typename mutate_type::assigner_type     assigner_type;
           typedef typename inspect_type::retriever_type  retriever_type;

           typedef ::reflection::content::trinity::basic_class< identifier_name, data_name,original_type,image_name,model_name,storage_type,extractor_type, assigner_type, retriever_type, report_name  > typedef_type;

           typedef typename direct_type::pointer_type       pointer_type;
           static typedef_type make( storage_type const& storage_param, pointer_type const& pointer_param )
            {
             return typedef_type( storage_param, extractor_type(pointer_param),assigner_type(pointer_param), retriever_type(pointer_param) );
            }
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
       typename ::reflection::content::trinity::field_struct< identifier_name, data_name,original_name, model_name, image_name,class_name,storage_name,report_name>::typedef_type
       field
        (
          storage_name     const&      storage_param
         ,data_name       class_name::*pointer_param
        )
        {
         typedef ::reflection::content::trinity::field_struct< identifier_name, data_name,original_name,model_name,image_name,class_name,storage_name,report_name> field_type;
         return field_type::make( storage_param, pointer_param );
        }


     }
   }
 }

#endif
