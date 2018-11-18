#ifndef reflection_content_inspect_base_hpp
#define reflection_content_inspect_base_hpp
 // ::reflection::content::inspect::base_class<data_name, original_name,class_name,storage_name>
 // ::reflection::content::inspect::base( )

#include "../../property/inspect/base.hpp"

#include "../distinctive.hpp"

namespace reflection
 {
  namespace content
   {
    namespace inspect
     {

      template
       <
        typename identifier_name
       ,typename base_name
       ,typename derived_name
       ,typename storage_name
       >
       class base_class
        : public ::reflection::content::distinctive_class<identifier_name,base_name>
        , public ::reflection::property::inspect::base_class<base_name, derived_name, storage_name >
        {
         public:
           typedef identifier_name  identifier_type;
           typedef base_name              base_type;
           typedef derived_name        derived_type;
           typedef storage_name        storage_type;

           typedef ::reflection::content::distinctive_class<identifier_name,base_name>     distinctive_type;
           typedef ::reflection::property::inspect::base_class<base_name, derived_name,storage_name >    property_type;

           using property_type::property_type;
         };

      template
       <
         typename identifier_name
        ,typename base_name
        ,typename derived_name
        ,typename storage_name
       >
       inline
       typename ::reflection::content::inspect::base_class<identifier_name,base_name,derived_name,storage_name>
       base
        (
          storage_name const&             storage_param
        )
        {
         typedef ::reflection::content::inspect::base_class<identifier_name,base_name,derived_name,storage_name> base_type;
         return base_type( );
        }

      }
    }
  }

#endif
