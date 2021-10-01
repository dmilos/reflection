#ifndef reflection_property_exposed_type_pure
#define reflection_property_exposed_type_pure

// ::reflection::property::exposed::pure_class<original_name,model_name>
// ::reflection::property::exposed::get
// ::reflection::property::exposed::check

#include "../direct/_pure.hpp"
#include "../mutate/_pure.hpp"

namespace reflection
 {
  namespace property
   {
    namespace exposed
     {

      template
       <
         typename original_name
        ,typename    model_name
        ,typename   report_name
        >
       class pure_class
        : virtual public ::reflection::property::pure_class
        , virtual public ::reflection::property::direct::pure_class<original_name>
        , virtual public ::reflection::property::mutate::pure_class<model_name, report_name>
        {
         public:
           typedef original_name original_type;
           typedef model_name       model_type;
           typedef report_name     report_type;

           typedef  ::reflection::property::direct::pure_class<original_name>  direct_type;
           typedef  ::reflection::property::mutate::pure_class<model_name, report_name>    mutate_type;


                    pure_class(){}
           virtual ~pure_class(){}

           using direct_type::disclose;
           using mutate_type::process;
        };

      template
       < 
          typename original_name
         ,typename model_name
         ,typename report_name 
       >
       inline bool check( ::reflection::property::pure_class const& property_param )
        {
         typedef ::reflection::property::exposed::pure_class<original_name,model_name,report_name> exposed_type;
         return nullptr != dynamic_cast< exposed_type const*>( &property_param );
        }

     }
   }
 }

 #endif
