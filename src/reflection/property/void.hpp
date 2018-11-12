#ifndef reflection_property_void_class
#define reflection_property_void_class

// ::reflection::property::void_class

#include "./_pure.hpp"

namespace reflection
 {
  namespace property
   {

    class void_class
     : virtual public ::reflection::property::pure_class
     {
      public:
                 void_class(){}
        virtual ~void_class(){}

      public:
        static inline bool check( ::reflection::property::pure_class const& property_param )
         {
          typedef ::reflection::property::void_class void_type;
          return nullptr != dynamic_cast< void_type const*>( &property_param );
         }
     };

   }
 }

#endif
