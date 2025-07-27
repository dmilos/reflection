#ifndef reflection_content_variable_pure_hpp
 #define reflection_content_variable_pure_hpp

 // ::reflection::content::variable::pure_class<data_name,original_name >

 #include "../../property/variable/_pure.hpp"

 #include "../_base.hpp"

namespace reflection
 {
  namespace content
   {
    namespace variable
     {

      template
       <
         typename  identifier_name
        ,typename        data_name
        ,typename    original_name
        ,typename       image_name
       >
       class pure_class
        : virtual public ::reflection::content::base_class< identifier_name, data_name >
        , virtual public ::reflection::property::variable::pure_class<original_name,image_name>
        {
         public:
           typedef identifier_name   identifier_type;
           typedef data_name               data_type;
           typedef original_name       original_type;
           typedef image_name             image_type;

           typedef ::reflection::content::pure_class< identifier_name >                      content_type;
           typedef ::reflection::property::variable::pure_class<original_name,image_name>   property_type;

           typedef ::reflection::type::name::identificatorX< identifier_name  > identificator_type;

           using property_type::disclose;
           using property_type::present;
        };

      }
    }
  }

#endif
