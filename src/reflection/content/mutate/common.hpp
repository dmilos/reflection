#ifndef reflection_content_mutate_common_hpp
#define reflection_content_mutate_common_hpp
 // ::reflection::content::mutate::common_struct<data_name, model_name,class_name,storage_name>
 // ::reflection::content::mutate::common( )

#include "../../property/mutate/common.hpp"

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
        ,typename report_name
       >
       class common_class
        : public ::reflection::content::distinctive_class<identifier_name,data_name>
        , public ::reflection::property::mutate::common_class< data_name, model_name, class_name, report_name >
        {
         public:
           typedef identifier_name  identifier_type;
           typedef data_name        data_type;
           typedef model_name    model_type;
           typedef class_name       class_type;

           typedef ::reflection::content::distinctive_class<identifier_name,data_name>                     distinctive_type;
           typedef ::reflection::property::mutate::common_class< data_name, model_name, class_name, report_name >   common_type;

           using common_type::common_type;
        };

      template
       <
         typename identifier_name
        ,typename class_name
        ,typename data_name
        ,typename model_name   = data_name const&
        ,typename report_name  = bool
       >
       inline
       typename ::reflection::content::mutate::common_class<identifier_name,data_name,model_name,class_name,report_name>
       common
        (
          data_name       *storage_param
        )
        {
         typedef ::reflection::content::mutate::common_class<identifier_name,data_name,model_name,class_name,report_name> common_type;
         return common_type( storage_param );
        }

      }
    }
  }

#endif
