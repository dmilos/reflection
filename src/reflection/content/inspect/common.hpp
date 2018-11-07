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
       struct common_struct
        : ::reflection::property::inspect::common_struct<data_name,image_name, class_name >
        {
         typedef data_name     data_type;
         typedef image_name    image_type;
         typedef class_name    class_type;

         typedef ::reflection::property::inspect::common_struct<data_name,image_name, class_name > property_type;

         typedef typename property_type::storage_type  storage_type;
         typedef typename property_type::retriever_type  retriever_type;

         typedef ::reflection::content::inspect::basic_class<identifier_name,data_name,image_name,storage_type,retriever_type>      typedef_type;

         static typedef_type make( storage_type const& storage_param )
          {
           return typedef_type( storage_param, retriever_type(  ) );
          }

       };

      template
       <
         typename identifier_name
        ,typename class_name
        ,typename data_name
        ,typename image_name   = data_name const&
       >
       inline
       typename ::reflection::content::inspect::common_struct<identifier_name,data_name,image_name,class_name>::typedef_type
       common
        (
          data_name       *storage_param
        )
        {
         typedef ::reflection::content::inspect::common_struct<identifier_name,data_name,image_name,class_name> common_type;
         return common_type::make( storage_param );
        }

      }
    }
  }

#endif
