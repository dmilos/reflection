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
       struct common_struct
        : ::reflection::property::direct::common_struct<data_name, original_name, class_name >
        {
         public:
           typedef data_name     data_type;
           typedef original_name original_type;
           typedef class_name    class_type;

           typedef ::reflection::property::direct::common_struct<data_name, original_name, class_name > property_type;

           typedef typename property_type::storage_type  storage_type;
           typedef typename property_type::extractor_type  extractor_type;

           typedef ::reflection::content::direct::basic_class<identifier_name,data_name,original_name,storage_type,extractor_type>      typedef_type;

           typedef typename property_type::pointer_type    pointer_type;

           static typedef_type make( storage_type const& storage_param )
            {
             return typedef_type( storage_param );
            }

       };

      template
       <
         typename identifier_name
        ,typename class_name
        ,typename data_name
        ,typename original_name = data_name &
       >
       inline
       typename ::reflection::content::direct::common_struct<identifier_name,data_name,original_name,class_name>::typedef_type
       common
        (
          data_name                      *pointer_param
        )
        {
         typedef ::reflection::content::direct::common_struct<identifier_name,data_name,original_name,class_name> common_type;
         return common_type::make( pointer_param );
        }

      }
    }
  }

#endif
