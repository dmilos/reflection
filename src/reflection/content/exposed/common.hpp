#ifndef reflection_content_exposed_common_hpp
#define reflection_content_exposed_common_hpp
 // ::reflection::content::exposed::common_class<data_name>
 // ::reflection::content::exposed::common( )

#include "../direct/common.hpp"
#include "../mutate/common.hpp"


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
        ,typename report_name
       >
       class common_class
        : public ::reflection::content::distinctive_class<identifier_name,data_name>
        , public ::reflection::property::exposed::common_class< data_name, original_name, model_name, class_name, report_name >
        {
         public:
           typedef identifier_name  identifier_type;
           typedef data_name        data_type;
           typedef model_name    model_type;
           typedef     original_name    original_type;
           typedef class_name       class_type;

           typedef ::reflection::content::distinctive_class<identifier_name,data_name>                     distinctive_type;
           typedef ::reflection::property::exposed::common_class< data_name, original_name, model_name, class_name, report_name >  common_type;

           using common_type::common_type;
        };

      template
       <
         typename identifier_name
        ,typename      class_name
        ,typename       data_name
        ,typename   original_name  = data_name &
        ,typename      model_name  = data_name const&
        ,typename     report_name = bool
       >
       inline
       typename ::reflection::content::exposed::common_class<identifier_name,data_name,original_name,model_name,class_name,report_name>
       common
        (
          data_name       *storage_param
        )
        {
         typedef ::reflection::content::exposed::common_class<identifier_name,data_name,original_name,model_name,class_name,report_name> member_type;
         return member_type( storage_param );
        }

     }
   }
 }

#endif