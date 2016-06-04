#ifndef reflection_content_mutate_pure_hpp
 #define reflection_content_mutate_pure_hpp
 // ::reflection::content::mutate::pure_class<data_name,model_name >

 #include "../../property/mutate/_pure.hpp"

 #include "../_pure.hpp"

namespace reflection
 {
  namespace content
   {
    namespace mutate
     {

      template
       <
         typename data_name
        ,typename model_name
        ,typename report_name
       >
       class pure_class
        : virtual public ::reflection::content::pure_class< data_name >
        , virtual public ::reflection::property::mutate::pure_class<model_name, report_name>
        {
         public:
           typedef data_name   data_type;
           typedef model_name  model_type;

           typedef ::reflection::content::pure_class< data_name >            content_type;
           typedef ::reflection::property::mutate::pure_class<model_name>   property_type;

           using property_type::process;
        };

      }
    }
  }

#endif
