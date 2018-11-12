#ifndef reflection_content_direct_void_hpp
#define reflection_content_direct_void_hpp

 // ::reflection::content::direct::void_class<identifier_name>

#include "../../property/direct/void.hpp"

#include "../void.hpp"
#include "./_pure.hpp"

namespace reflection
 {
  namespace content
   {
    namespace direct
     {

      template
       <
         typename identifier_name
       >
       class void_class
        :virtual public ::reflection::content::void_class < identifier_name >
        ,virtual public ::reflection::content::direct::pure_class<identifier_name,void,void>
        ,        public ::reflection::property::direct::void_class
        {
         public:
           typedef void       data_type;
           typedef void   original_type;

           typedef ::reflection::content::direct::pure_class<identifier_name,void,void > pure_type;

           typedef ::reflection::property::direct::void_class property_type;

                     void_class()
                      {
                      }

           using property_type::disclose;
        };

      }
    }
  }

#endif
