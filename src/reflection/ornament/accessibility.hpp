#ifndef reflection_ornament_accessibility
#define reflection_ornament_accessibility

// ::reflection::ornament::accessibility_class

#include "../property/_pure.hpp"

namespace reflection
 {
  namespace ornament
   {

    class accessibility_class
     : virtual public ::reflection::property::pure_class
     {
      public:
        typedef enum accessibility_enum{ gloabal_index, public_index, protected_index, private_index, local_index, unknown_index } accessibility_type;

      public:
        explicit accessibility_class( accessibility_enum const& accessibility_param = public_index ):m_accessibility(accessibility_param){}
        virtual ~accessibility_class(){}

      public:
        accessibility_enum const& accessibility()const{ return m_accessibility; }
                         void  accessibility( accessibility_enum const& accessibility_param ){m_accessibility = accessibility_param; }
      protected:
        accessibility_enum      & accessibility()     { return m_accessibility; }
      private:
        accessibility_enum m_accessibility;
     };

   }
 }

#endif
