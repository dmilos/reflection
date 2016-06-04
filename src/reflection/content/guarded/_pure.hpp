#ifndef reflection_content_guarded_pure_hpp
 #define reflection_content_guarded_pure_hpp

// ::reflection::content::guarded::pure_class<data_name,model_name,image_name,report_name>

 #include "../../property/guarded/_pure.hpp"

 #include "../_pure.hpp"

namespace reflection
 {
  namespace content
   {
    namespace guarded
     {

      template
       <
          typename   data_name
         ,typename  model_name
         ,typename  image_name
         ,typename report_name
       >
       class pure_class
        : virtual public ::reflection::content::pure_class< data_name >
        , virtual public ::reflection::property::guarded::pure_class<model_name,image_name,report_name>
        {
         public:
           typedef data_name   data_type;
           typedef model_name   model_type;
           typedef image_name   image_type;
           typedef report_name   report_type;

           typedef ::reflection::content::pure_class< data_name >              content_type;
           typedef ::reflection::property::guarded::pure_class<model_name,image_name,report_name>   property_type;

           using property_type::process;
           using property_type::present;
        };

      }
    }
  }

#endif
