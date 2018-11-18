#ifndef reflection_content_guarded_base_hpp
#define reflection_content_guarded_base_hpp
 // ::reflection::content::guarded::base_struct<data_name>
 // ::reflection::content::guarded::base( )

#include "../direct/base.hpp"
#include "../mutate/base.hpp"
#include "../../property/guarded/base.hpp"


#include "./basic.hpp"

namespace reflection
 {
  namespace content
   {
    namespace guarded
     {

      template
       <
         typename identifier_name
        ,typename base_name
        ,typename derived_name
        ,typename storage_name
        ,typename report_name
       >
       class base_class
        : public ::reflection::content::distinctive_class<identifier_name,base_name>
        , public ::reflection::property::guarded::base_class< base_name, derived_name, storage_name, report_name >
        {
         public:
           typedef identifier_name  identifier_type;
           typedef base_name              base_type;
           typedef derived_name        derived_type;
           typedef storage_name        storage_type;
           typedef report_name          report_type;

           typedef ::reflection::content::distinctive_class<identifier_name,base_name>                     distinctive_type;
           typedef ::reflection::property::guarded::base_class< base_name, derived_name, storage_name, report_name >  property_type;

           using property_type::property_type;
        };


      template
       <
         typename identifier_name
        ,typename base_name
        ,typename derived_name
        ,typename storage_name
        ,typename report_name = bool
       >
       inline
       typename ::reflection::content::guarded::base_class<identifier_name,base_name,derived_name,storage_name,report_name>
       base
        (
          storage_name     const&      storage_param
        )
        {
         typedef ::reflection::content::guarded::base_class<identifier_name,base_name,derived_name,storage_name,report_name> base_type;
         return base_type( storage_param );
        }

     }
   }
 }

#endif