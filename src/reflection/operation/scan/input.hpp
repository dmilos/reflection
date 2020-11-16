#ifndef reflection_operation_input
#define reflection_operation_input

// ::reflection::operation::input::pure_class

#include "../../property/_pure.hpp"

namespace reflection
 {
  namespace operation
   {
    namespace input
     {

       class pure_class
        {
         public:
           typedef ::reflection::property::pure_class  property_type;
           pure_class( )
            {
            }

           virtual ~pure_class()
            {
            }
         public:
           virtual pure_class& receive( property_type  & p )const=0;
        };


      template
       <
         typename data_name
       >
       class base_class 
        : virtual public ::reflection::operation::input::pure_class
        {
         public:
           typedef data_name data_type;
           typedef ::reflection::operation::input::pure_class  pure_type;
           base_class( )
            {
            }

           virtual ~base_class()
            {
            }
         public:
           using pure_type::receive;
           virtual pure_class& receive( data_type const& data, property_type const& p )const=0;
        };

     }
   }
 }

#endif
