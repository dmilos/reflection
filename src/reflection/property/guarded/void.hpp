#ifndef reflection_property_guarded_void
#define reflection_property_guarded_void

// ::reflection::property::guarded::void_class<report_name>

#include "../void.hpp"
#include "./_pure.hpp"


#include "../mutate/void.hpp"
#include "../inspect/void.hpp"




namespace reflection
 {
  namespace property
   {
    namespace guarded
     {

      template
       <
         typename report_name
       >
       class void_class
        : virtual public ::reflection::property::void_class
        , virtual public ::reflection::property::guarded::pure_class<void,void,report_name>
        ,         public ::reflection::property::mutate::void_class<  report_name >
        ,         public ::reflection::property::inspect::void_class
        {
         public:
           typedef void           model_type;
           typedef void           image_type;
           typedef report_name   report_type;

           typedef ::reflection::property::guarded::pure_class<model_type,image_type,report_name> pure_type;

           typedef ::reflection::property::mutate::void_class<  report_name >       mutate_type;
           typedef ::reflection::property::inspect::void_class                     inspect_type;

                    void_class()
                     {
                     }

         public:
           using mutate_type::process;
           using inspect_type::present;
        };

      }
    }
  }

#endif