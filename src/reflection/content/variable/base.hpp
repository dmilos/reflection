#ifndef reflection_content_variable_base_hpp
#define reflection_content_variable_base_hpp
 // ::reflection::content::variable::base_struct<data_name>
 // ::reflection::content::variable::base( )


#include "../../property/variable/base.hpp"


#include "../distinctive.hpp"

namespace reflection
 {
  namespace content
   {
    namespace variable
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
        , public ::reflection::property::variable::base_class< base_name, derived_name, storage_name >
        {
         public:
           typedef identifier_name  identifier_type;
           typedef base_name              base_type;
           typedef derived_name        derived_type;
           typedef storage_name        storage_type;

           typedef ::reflection::content::distinctive_class<identifier_name,base_name>                     distinctive_type;
           typedef ::reflection::property::variable::base_class< base_name, derived_name, storage_name >  property_type;

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
       typename ::reflection::content::variable::base_class<identifier_name,base_name,derived_name,storage_name>
       base
        (
          storage_name     const&      storage_param
        )
        {
         typedef ::reflection::content::variable::base_class<identifier_name,base_name,derived_name,storage_name> base_type;
         return base_type( storage_param );
        }

     }
   }
 }

#endif