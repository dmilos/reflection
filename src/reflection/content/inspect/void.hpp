#ifndef reflection_content_inspect_void_hpp
#define reflection_content_inspect_void_hpp

 // ::reflection::content::inspect::void_class<identifier_name >

#include "../../property/inspect/basic.hpp"

#include "../void.hpp"
#include "./_pure.hpp"

namespace reflection
 {
  namespace content
   {
    namespace inspect
     {

      template
       <
         typename identifier_name
       >
       class void_class
        :virtual public ::reflection::content::void_class< identifier_name >
        ,virtual public ::reflection::content::inspect::pure_class<identifier_name,void,void>
        ,        public ::reflection::property::inspect::void_class
        {
         public:
           typedef void       data_type;
           typedef void      image_type;

           typedef ::reflection::content::inspect::pure_class<identifier_name,data_type,image_type > pure_type;

           typedef::reflection::property::inspect::void_class property_type;

                     void_class()
                      {
                      }

           using property_type::present;
        };

      }
    }
  }

#endif
