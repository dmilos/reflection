#ifndef reflection_content_variable_common_hpp
#define reflection_content_variable_common_hpp
 // ::reflection::content::variable::common_class<data_name>
 // ::reflection::content::variable::common( )

#include "../direct/common.hpp"
#include "../inspect/common.hpp"


#include "./basic.hpp"

namespace reflection
 {
  namespace content
   {
    namespace variable
     {

      template
       <
         typename identifier_name
        ,typename       data_name
        ,typename   original_name  //= data_name const&
        ,typename      image_name  //= data_name const&
        ,typename      class_name
       >
       class common_class
        : public ::reflection::content::distinctive_class<identifier_name,data_name>
        , public ::reflection::property::variable::common_class<data_name,original_name, image_name, class_name >
        {
         public:
           typedef identifier_name  identifier_type;
           typedef data_name        data_type;
           typedef original_name    original_type;
           typedef     image_name    image_type;
           typedef class_name       class_type;

           typedef ::reflection::content::distinctive_class<identifier_name,data_name>                     distinctive_type;
           typedef ::reflection::property::variable::common_class<data_name,original_name, image_name, class_name >  common_type;

           using common_type::common_type;
        };

      template
       <
         typename  identifier_name
        ,typename       class_name
        ,typename        data_name
        ,typename    original_name = data_name &
        ,typename       image_name = data_name const&
       >
       inline
       typename ::reflection::content::variable::common_class< identifier_name, data_name,original_name,image_name,class_name>
       common
        (
          data_name       *storage_param
        )
        {
         typedef ::reflection::content::variable::common_class< identifier_name, data_name,original_name,image_name,class_name> common_type;
         return common_type( storage_param );
        }

     }
   }
 }

#endif