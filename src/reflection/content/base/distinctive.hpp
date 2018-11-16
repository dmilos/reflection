#ifndef reflection_content_base_distinctive_hpp
#define reflection_content_base_distinctive_hpp

 // ::reflection::content::base::distinctive_class<identifier_name,data_name >

 #include "../distinctive.hpp"

 #include "./_pure.hpp"

namespace reflection
 {
  namespace content
   {
    namespace base
     {

      template
       <
         typename identifier_name
        ,typename data_name
       >
       class distinctive_class
        : virtual public ::reflection::content::distinctive_class<identifier_name,data_name>
        , virtual public ::reflection::content::base::pure_class<identifier_name >
        {
         public:
           typedef identifier_name identifier_type;
           typedef data_name             data_type;

        };

      }
    }
  }

#endif
