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
       struct common_struct
        : public ::reflection::content::direct::common_struct< identifier_name,  data_name,original_name,class_name>
        , public ::reflection::content::inspect::common_struct< identifier_name,  data_name,image_name,class_name >
        {
         public:
           typedef      data_name     data_type;
           typedef  original_name    model_type;
           typedef     image_name    image_type;
           typedef     class_name    class_type;

           typedef ::reflection::content::direct::common_struct< identifier_name,  data_name,original_name,class_name>  direct_type;
           typedef ::reflection::content::inspect::common_struct< identifier_name,  data_name,image_name,class_name >   inspect_type;

           typedef typename direct_type::storage_type      storage_type;

           typedef typename direct_type::extractor_type      extractor_type;
           typedef typename inspect_type::retriever_type       retriever_type;

           typedef ::reflection::content::variable::basic_class< identifier_name, data_name,original_name,image_name,storage_type, extractor_type, retriever_type> typedef_type;

           static typedef_type make( storage_type const& storage_param )
            {
             return typedef_type( storage_param, extractor_type(), retriever_type() );
            }
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
       typename ::reflection::content::variable::common_struct< identifier_name, data_name,original_name,image_name,class_name>::typedef_type
       common
        (
          data_name       *storage_param
        )
        {
         typedef ::reflection::content::variable::common_struct< identifier_name, data_name,original_name,image_name,class_name> common_type;
         return common_type::make( storage_param );
        }

     }
   }
 }

#endif