#ifndef reflection_property_variable_void
#define reflection_property_variable_void

// ::reflection::property::variable::void_class

#include "../void.hpp"
#include "./_pure.hpp"

#include "../direct/void.hpp"

#include "../inspect/void.hpp"




namespace reflection
 {
  namespace property
   {
    namespace variable
     {

       class void_class
        : virtual public ::reflection::property::void_class
        , virtual public ::reflection::property::variable::pure_class<void,void>
        ,         public ::reflection::property::direct::void_class
        ,         public ::reflection::property::inspect::void_class
        {
         public:
           typedef void original_type;
           typedef void    image_type;

           typedef ::reflection::property::variable::pure_class<original_type,image_type>   pure_type;

           typedef ::reflection::property::direct::void_class              direct_type;
           typedef ::reflection::property::inspect::void_class            inspect_type;

                    void_class()
                     {
                     }

         public:
           using direct_type::disclose;
           using inspect_type::present;
        };

      }
    }
  }

#endif
