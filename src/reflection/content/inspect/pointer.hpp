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
        ,typename image_name
        ,typename storage_name
       >
       class pointer_class
        : public ::reflection::content::distinctive_class<identifier_name,data_name>
        , public ::reflection::property::inspect::pointer_class<image_name,storage_name >
        {
         public:
           typedef identifier_name  identifier_type;
           typedef data_name              data_type;
           typedef image_name            image_type;
           typedef storage_name        storage_type;

           typedef ::reflection::content::distinctive_class<identifier_name,data_name>                     distinctive_type;

           typedef ::reflection::property::inspect::pointer_class<image_name, storage_name>   pointer_type;

           using pointer_type::pointer_type;
        };

      template
       <
         typename identifier_name
        ,typename data_name
       >
       inline
       typename ::reflection::content::inspect::pointer_class<identifier_name,data_name, data_name const&, data_name const*>
       pointer
        (
          data_name     const*      storage_param
        )
        {
         typedef data_name   const&image_type;   // By design
         typedef data_name   const*storage_type; // By design

         typedef ::reflection::content::inspect::pointer_class<identifier_name,data_name, image_type, storage_type> pointer_type;
         return pointer_type( storage_param );
        }

      }
    }
  }

#endif
