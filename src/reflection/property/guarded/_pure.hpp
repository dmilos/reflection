#ifndef reflection_property_guarded_pure
#define reflection_property_guarded_pure

// reflection::property::guarded::pure_class<model_name>
// reflection::property::guarded::get
// reflection::property::guarded::check

#include "../mutate/_pure.hpp"
#include "../inspect/_pure.hpp"

namespace reflection
 {
  namespace property
   {
    namespace guarded
     {

      template
       <
          typename model_name
         ,typename image_name
         ,typename report_name
       >
       class pure_class
        : public ::reflection::property::mutate::pure_class<model_name,report_name>
        , public ::reflection::property::inspect::pure_class<image_name>
        {
         public:
           typedef model_name model_type;
           typedef image_name       image_type;

           typedef  ::reflection::property::mutate::pure_class<model_name,report_name>  mutate_type;
           typedef  ::reflection::property::inspect::pure_class<image_name>    inspect_type;


                    pure_class(){}
           virtual ~pure_class(){}

           using mutate_type::process;
           using inspect_type::present;
        };

      template< typename model_name, typename image_name,typename report_name >
       inline bool check( ::reflection::property::pure_class const& property_param )
        {
         typedef ::reflection::property::guarded::pure_class<model_name,image_name,report_name> guarded_type;
         return nullptr != dynamic_cast< guarded_type const*>( &property_param );
        }

     }
   }
 }

 #endif
