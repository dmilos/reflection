#ifndef reflection_content_variable_field_hpp
#define reflection_content_variable_field_hpp
 // ::reflection::content::variable::field_class<data_name>
 // ::reflection::content::variable::field( )

#include "../direct/field.hpp"
#include "../inspect/field.hpp"


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
        ,typename    storage_name
       >
       struct field_struct
        : public ::reflection::content::direct::field_struct< identifier_name,  data_name,original_name,class_name,storage_name>
        , public ::reflection::content::inspect::field_struct< identifier_name,  data_name,image_name,class_name,storage_name >
        {
         public:
           typedef      data_name     data_type;
           typedef  original_name    model_type;
           typedef     image_name    image_type;
           typedef     class_name    class_type;
           typedef   storage_name  storage_type;

           typedef ::reflection::content::direct::field_struct< identifier_name,  data_name,original_name,class_name,storage_name>  direct_type;
           typedef ::reflection::content::inspect::field_struct< identifier_name,  data_name,image_name,class_name,storage_name >   inspect_type;

           typedef typename direct_type::extractor_type      extractor_type;
           typedef typename inspect_type::retriever_type       retriever_type;

           typedef ::reflection::content::variable::basic_class< identifier_name, data_name,original_name,image_name,storage_type, extractor_type, retriever_type> typedef_type;

           typedef typename direct_type::pointer_type       pointer_type;
           
           static typedef_type make( storage_type const& storage_param, pointer_type const& pointer_param )
            {
             return typedef_type( storage_param, extractor_type(pointer_param), retriever_type(pointer_param) );
            }
        };

      template
       <
         typename  identifier_name
        ,typename        data_name
        ,typename    original_name = data_name &
        ,typename       image_name = data_name const&
        ,typename       class_name
        ,typename     storage_name
       >
       inline
       typename ::reflection::content::variable::field_struct< identifier_name, data_name,original_name,image_name,class_name,storage_name>::typedef_type
       field
        (
          storage_name     const&      storage_param
         ,data_name       class_name::*pointer_param
        )
        {
         typedef ::reflection::content::variable::field_struct< identifier_name, data_name,original_name,image_name,class_name,storage_name> field_type;
         return field_type::make( storage_param, pointer_param );
        }

     }
   }
 }

#endif 