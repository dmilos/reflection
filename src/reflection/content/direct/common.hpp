#ifndef reflection_content_direct_common_hpp
#define reflection_content_direct_common_hpp
 // ::reflection::content::direct::common_class<data_name, original_name,class_name>
 // ::reflection::content::direct::common( )

#include "../../property/direct/common.hpp"

#include "./basic.hpp"

namespace reflection
 {
  namespace content
   {
    namespace direct
     {

      template
       <
        typename identifier_name
       ,typename data_name
       ,typename original_name
       ,typename class_name
       >
       class common_class
        : public ::reflection::content::distinctive_class<identifier_name,data_name>
        , public ::reflection::property::direct::common_class<data_name, original_name, class_name >
        {
         public:
           typedef identifier_name  identifier_type;
           typedef data_name        data_type;
           typedef original_name    original_type;
           typedef class_name       class_type;

           typedef ::reflection::content::distinctive_class<identifier_name,data_name>                 distinctive_type;
           typedef ::reflection::property::direct::common_class<data_name,original_name, class_name >         common_type;

           using common_type::common_type;
       };

      template
       <
         typename identifier_name
        ,typename class_name
        ,typename data_name
        ,typename original_name = data_name &
       >
       inline
       typename ::reflection::content::direct::common_class<identifier_name,data_name,original_name,class_name>
       common
        (
          data_name                      *pointer_param
        )
        {
         typedef ::reflection::content::direct::common_class<identifier_name,data_name,original_name,class_name> common_type;
         return common_type( pointer_param );
        }

      }
    }
  }

#endif
