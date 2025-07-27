#ifndef reflection_content_trinity_pure_hpp
 #define reflection_content_trinity_pure_hpp

// ::reflection::content::trinity::pure_class<data_name,model_name,image_name,report_name>

 #include "../../property/trinity/_pure.hpp"

 #include "../_base.hpp"

namespace reflection
 {
  namespace content
   {
    namespace trinity
     {

      template
       <
         typename  identifier_name
        ,typename        data_name
        ,typename    original_name
        ,typename       model_name
        ,typename       image_name
        ,typename      report_name
       >
       class pure_class
        : virtual public ::reflection::content::base_class< identifier_name, data_name >
        , virtual public ::reflection::property::trinity::pure_class<original_name,model_name,image_name,report_name>
        {
         public:
           typedef identifier_name    identifier_type;
           typedef data_name                data_type;
           typedef original_name        original_type;
           typedef model_name              model_type;
           typedef image_name              image_type;
           typedef report_name            report_type;

           typedef ::reflection::content::pure_class< identifier_type >              content_type;
           typedef ::reflection::property::trinity::pure_class<original_name,model_name,image_name,report_name>   property_type;

           typedef ::reflection::type::name::identificatorX< identifier_name  > identificator_type;
 
           using  property_type::disclose;
           using  property_type::process;
           using  property_type::present;
        };

      }
    }
  }

#endif
