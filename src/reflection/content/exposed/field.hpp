#ifndef reflection_content_exposed_field_hpp
#define reflection_content_exposed_field_hpp
 // ::reflection::content::exposed::field_class<data_name>
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
       struct field_struct
        : public ::reflection::content::direct::field_struct< identifier_name, data_name,original_name,class_name,storage_name>
        , public ::reflection::content::mutate::field_struct< identifier_name,data_name,model_name,class_name,storage_name, report_name >
        {
         public:
           typedef      data_name         data_type;
           typedef  original_name     original_type;
           typedef     model_name        model_type;
           typedef     class_name        class_type;
           typedef   storage_name      storage_type;
           typedef     report_name      report_type;

           typedef ::reflection::content::direct::field_struct< identifier_name,data_type,original_type,class_type,storage_type>  direct_type;
           typedef ::reflection::content::mutate::field_struct< identifier_name, data_type,model_type,class_type,storage_type,report_type >    mutate_type;

           typedef typename direct_type::extractor_type  extractor_type;
           typedef typename mutate_type::assigner_type    assigner_type;

           typedef ::reflection::content::exposed::basic_class<identifier_name,data_type,original_type,model_type,storage_type,extractor_type,assigner_type,report_type > typedef_type;

           typedef typename direct_type::pointer_type       pointer_type;
           
           static typedef_type make( storage_type const& storage_param, pointer_type const& pointer_param )
            {
             return typedef_type( storage_param, extractor_type(pointer_param), assigner_type(pointer_param) );
            }
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
       typename ::reflection::content::exposed::field_struct<identifier_name,data_name,original_name,model_name,class_name,storage_name,report_name>::typedef_type
       field
        (
          storage_name     const&      storage_param
         ,data_name       class_name::*pointer_param
        )
        {
         typedef ::reflection::content::exposed::field_struct<identifier_name,data_name,original_name,model_name,class_name,storage_name,report_name> member_type;
         return member_type::make( storage_param, pointer_param );
        }

     }
   }
 }

#endif