#ifndef reflection_property_null_class
#define reflection_property_null_class

// ::reflection::property::null_class
// ::reflection::property::check

#include "./_pure.hpp"

namespace reflection
 {
  namespace property
   {

    class null_class
     : virtual public ::reflection::property::pure_class
     {
      public:
                 null_class(){}
        virtual ~null_class(){}
     };

     inline bool check( ::reflection::property::pure_class const& property_param )
      {
       typedef ::reflection::property::null_class null_type;
       return nullptr != dynamic_cast< null_type const*>( &property_param );
      }

   }
 }

#endif
