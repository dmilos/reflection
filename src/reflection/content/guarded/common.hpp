#ifndef reflection_content_guarded_common_hpp
#define reflection_content_guarded_common_hpp
 // ::reflection::content::guarded::common_struct<data_name>
 // ::reflection::content::guarded::common( )

#include "../mutate/common.hpp"
#include "../inspect/common.hpp"


#include "./basic.hpp"

namespace reflection
 {
  namespace content
   {
    namespace guarded
     {

      template
       <
         typename identifier_name
        ,typename data_name
        ,typename model_name  //= data_name const&
        ,typename image_name  //= data_name const&
        ,typename class_name
        ,typename report_name = bool
       >
       class common_class
        : public ::reflection::content::distinctive_class<identifier_name,data_name>
        , public ::reflection::property::guarded::common_class< data_name, model_name, image_name, class_name, report_name >
        {
         public:
           typedef identifier_name  identifier_type;
           typedef data_name        data_type;
           typedef model_name    model_type;
           typedef     image_name    image_type;
           typedef class_name       class_type;

           typedef ::reflection::content::distinctive_class<identifier_name,data_name>                     distinctive_type;
           typedef ::reflection::property::guarded::common_class< data_name, model_name, image_name, class_name, report_name >  common_type;

           using common_type::common_type;
        };

      template
       <
         typename identifier_name
        ,typename      class_name
        ,typename       data_name
        ,typename      model_name   = data_name const&
        ,typename      image_name   = data_name const&
        ,typename     report_name = bool
       >
       inline
       typename ::reflection::content::guarded::common_class<identifier_name,data_name,model_name,image_name,class_name,report_name>
       common
        (
         data_name       *storage_param
        )
        {
         typedef ::reflection::content::guarded::common_class<identifier_name,data_name,model_name,image_name,class_name,report_name> common_type;
         return common_type( storage_param );
        }

     }
   }
 }

#endif
