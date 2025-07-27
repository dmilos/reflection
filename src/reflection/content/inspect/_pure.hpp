#ifndef reflection_content_inspect_pure_hpp
 #define reflection_content_inspect_pure_hpp

 // ::reflection::content::inspect::pure_class<data_name,image_name >

 #include "../../property/inspect/_pure.hpp"

 #include "../_base.hpp"

namespace reflection
 {
  namespace content
   {
    namespace inspect
     {

      template
       <
         typename  identifier_name
        ,typename        data_name
        ,typename       image_name
       >
       class pure_class
        : virtual public ::reflection::content::base_class< identifier_name, data_name >
        , virtual public ::reflection::property::inspect::pure_class<image_name>
        {
         public:
           typedef identifier_name    identifier_type;
           typedef data_name                data_type;
           typedef image_name              image_type;

           typedef ::reflection::content::pure_class< identifier_type >              content_type;
           typedef ::reflection::property::inspect::pure_class<image_name>   property_type;

           typedef ::reflection::type::name::identificatorX< identifier_name  > identificator_type;

           using property_type::present;
        };

      }
    }
  }

#endif
