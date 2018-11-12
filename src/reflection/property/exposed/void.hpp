#ifndef reflection_property_exposed_type_void
#define reflection_property_exposed_type_void

// ::reflection::property::exposed::void_class<report_name>

#include "../void.hpp"
#include "./_pure.hpp"

#include "../direct/void.hpp"
#include "../mutate/void.hpp"





namespace reflection
 {
  namespace property
   {
    namespace exposed
     {

      template
       <
         typename report_name
       >
       class void_class
        : virtual public ::reflection::property::void_class
        , virtual public ::reflection::property::exposed::pure_class<void,void,report_name>
        ,         public ::reflection::property::direct::void_class
        ,         public ::reflection::property::mutate::void_class< report_name >
        {
         public:
           typedef void           original_type;
           typedef void              model_name;
           typedef report_name      report_type;


           typedef ::reflection::property::exposed::pure_class<original_type,model_name,report_name>      pure_type;

           typedef ::reflection::property::direct::void_class                direct_type;
           typedef ::reflection::property::mutate::void_class< report_name > mutate_type;

                    void_class()
                     {
                     }

         public:
           using direct_type::disclose;

           using mutate_type::process;
        };

      }
    }
  }

#endif