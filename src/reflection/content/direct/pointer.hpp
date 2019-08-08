#ifndef reflection_content_direct_pointer_hpp
#define reflection_content_direct_pointer_hpp
 // ::reflection::content::direct::pointer_class<identifier_name,data_name,original_name,class_name>
 // ::reflection::content::direct::pointer( )

#include "../../property/direct/pointer.hpp"

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
       ,typename storage_name
       >
       class pointer_class
        : public ::reflection::content::distinctive_class<identifier_name,data_name>
        , public ::reflection::property::direct::pointer_class< original_name, storage_name >
        {
         public:
           typedef identifier_name  identifier_type;
           typedef data_name              data_type;
           typedef original_name      original_type;
           typedef storage_name        storage_type;

           typedef ::reflection::content::distinctive_class<identifier_name,data_name>                 distinctive_type;
           typedef ::reflection::property::direct::pointer_class<original_name, storage_name >         pointer_type;

           using pointer_type::pointer_type;
       };

      template
       <
         typename identifier_name
        ,typename data_name
        ,typename original_name = data_name   &
        ,typename storage_name  = data_name   *const
       >
       inline
       typename ::reflection::content::direct::pointer_class<identifier_name,data_name,original_name,storage_name>
       pointer
        (
          storage_name const& storage_param
        )
        {
         typedef ::reflection::content::direct::pointer_class<identifier_name,data_name,original_name,storage_name> pointer_type;
         return pointer_type( storage_param );
        }

      }
    }
  }

#endif
