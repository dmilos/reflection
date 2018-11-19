#ifndef reflection_content_inspect_reference_hpp
#define reflection_content_inspect_reference_hpp
 // ::reflection::content::inspect::reference_struct<data_name, image_name,storage_name>
 // ::reflection::content::inspect::reference( )

#include "../../property/inspect/reference.hpp"

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
       class reference_class
        : public ::reflection::content::distinctive_class<identifier_name,data_name>
        , public ::reflection::property::inspect::reference_class<data_name >
        {
         public:
           typedef identifier_name  identifier_type;
           typedef data_name        data_type;

           typedef ::reflection::content::distinctive_class<identifier_name,data_name>                     distinctive_type;
           typedef ::reflection::property::inspect::reference_class<data_name >   reference_type;

           using reference_type::reference_type;
        };

      template
       <
         typename identifier_name
        ,typename data_name
       >
       inline
       typename ::reflection::content::inspect::reference_class<identifier_name,data_name>
       reference
        (
          data_name     const&      storage_param
        )
        {
         typedef ::reflection::content::inspect::reference_class<identifier_name,data_name> reference_type;
         return reference_type( storage_param );
        }

      }
    }
  }

#endif
