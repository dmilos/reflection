#ifndef reflection_content_trinity_common_hpp
#define reflection_content_trinity_common_hpp
 // ::reflection::content::trinity::common_struct<data_name>
 // ::reflection::content::trinity::common( )

#include "../direct/common.hpp"
#include "../mutate/common.hpp"
#include "../inspect/common.hpp"


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
        ,typename report_name = bool
       >
       class common_class
        : public ::reflection::content::distinctive_class<identifier_name,data_name>
        , public ::reflection::property::trinity::common_class<data_name,original_name, model_name, image_name, class_name, report_name >
        {
         public:
           typedef identifier_name  identifier_type;
           typedef data_name        data_type;
           typedef original_name    original_type;
           typedef     image_name    image_type;
           typedef class_name       class_type;

           typedef ::reflection::content::distinctive_class<identifier_name,data_name>                     distinctive_type;
           typedef ::reflection::property::trinity::common_class< data_name, original_name, model_name, image_name, class_name, report_name  >  common_type;

           using common_type::common_type;
        };

      template
       <
         typename  identifier_name
        ,typename class_name
        ,typename     data_name
        ,typename original_name   = data_name &
        ,typename model_name      = data_name const&
        ,typename image_name      = data_name const&
        ,typename report_name     = bool
       >
       inline
       ::reflection::content::trinity::common_class< identifier_name, data_name,original_name, model_name, image_name,class_name,report_name>
       common
        (
         data_name       *storage_param
        )
        {
         typedef ::reflection::content::trinity::common_class< identifier_name, data_name,original_name,model_name,image_name,class_name,report_name> common_type;
         return common_type( storage_param );
        }


     }
   }
 }

#endif
