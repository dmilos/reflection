#ifndef reflection_content_inspect_pointer_hpp
#define reflection_content_inspect_pointer_hpp
 // ::reflection::content::inspect::pointer_struct<data_name, image_name,storage_name>
 // ::reflection::content::inspect::pointer( )

#include "../../property/inspect/pointer.hpp"

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
       >
       class pointer_class
        : public ::reflection::content::distinctive_class<identifier_name,data_name>
        , public ::reflection::property::inspect::pointer_class<data_name >
        {
         public:
           typedef identifier_name  identifier_type;
           typedef data_name        data_type;

           typedef ::reflection::content::distinctive_class<identifier_name,data_name>                     distinctive_type;

           typedef ::reflection::property::inspect::pointer_class<data_name >   pointer_type;

           using pointer_type::pointer_type;

        };

      template
       <
         typename identifier_name
        ,typename data_name
       >
       inline
       typename ::reflection::content::inspect::pointer_class<identifier_name,data_name>
       pointer
        (
          data_name     const*      storage_param
        )
        {
         typedef ::reflection::content::inspect::pointer_class<identifier_name,data_name> pointer_type;
         return pointer_type( storage_param );
        }

      }
    }
  }

#endif
