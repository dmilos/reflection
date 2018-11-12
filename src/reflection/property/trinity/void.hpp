#ifndef reflection_property_trinity_void
#define reflection_property_trinity_void

// ::reflection::property::trinity::void_class<report_name>

#include "../void.hpp"
#include "./_pure.hpp"

#include "../direct/void.hpp"
#include "../mutate/void.hpp"
#include "../inspect/void.hpp"




namespace reflection
 {
  namespace property
   {
    namespace trinity
     {

      template
       <
         typename report_name
       >
       class void_class
        : virtual public ::reflection::property::void_class
        , virtual public ::reflection::property::trinity::pure_class<  void, void, void, report_name >
        ,         public ::reflection::property::direct::void_class
        ,         public ::reflection::property::mutate::void_class< report_name >
        ,         public ::reflection::property::inspect::void_class
        {
         public:
           typedef void             original_type;
           typedef void                model_type;
           typedef void                image_type;
           typedef report_name        report_type;

           typedef ::reflection::property::trinity::pure_class< original_type, model_type, image_type,report_name>       pure_type;

           typedef ::reflection::property::direct::void_class                      direct_type;
           typedef ::reflection::property::mutate::void_class< report_name  >      mutate_type;
           typedef ::reflection::property::inspect::void_class                    inspect_type;


                    void_class()
                     {
                     }

         public:
           using direct_type::disclose;

           using mutate_type::process;

           using inspect_type::present;
        };

      }
    }
  }

#endif