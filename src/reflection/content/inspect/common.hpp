#ifndef reflection_content_inspect_common_hpp
#define reflection_content_inspect_common_hpp
 // ::reflection::content::inspect::common_struct<data_name, image_name,class_name,storage_name>
 // ::reflection::content::inspect::common( )

#include "../../property/inspect/common.hpp"

#include "./basic.hpp"

namespace reflection
 {
  namespace content
   {
    namespace inspect
     {

      template
       <
         typename identifier_name
        ,typename data_name
        ,typename image_name
        ,typename class_name
       >
       class common_class
        : public ::reflection::content::distinctive_class<identifier_name,data_name>
        , public ::reflection::property::inspect::common_class<data_name,image_name, class_name >
        {
         public:
           typedef identifier_name  identifier_type;
           typedef data_name        data_type;
           typedef image_name    image_type;
           typedef class_name       class_type;

           typedef ::reflection::content::distinctive_class<identifier_name,data_name>                     distinctive_type;
           typedef ::reflection::property::inspect::common_class<data_name, image_name, class_name >   common_type;

           using common_type::common_type;
        };

      template
       <
         typename identifier_name
        ,typename class_name
        ,typename data_name
        ,typename image_name   = data_name const&
       >
       inline
       typename ::reflection::content::inspect::common_class<identifier_name,data_name,image_name,class_name>
       common
        (
          data_name       *storage_param
        )
        {
         typedef ::reflection::content::inspect::common_class<identifier_name,data_name,image_name,class_name> common_type;
         return common_type( storage_param );
        }

      }
    }
  }

#endif
