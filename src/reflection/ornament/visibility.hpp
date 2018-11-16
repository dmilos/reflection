#ifndef reflection_ornament_visibility
#define reflection_ornament_visibility

// ::reflection::ornament::visibility_class

#include "../property/_pure.hpp"

namespace reflection
 {
  namespace ornament
   {

    class visibility_class
     : virtual public ::reflection::property::pure_class
     {
      public:
        typedef enum visibility_enum{ gloabal_index, public_index, protected_index, private_index, local_index, unknown_index } accessibility_type;

      public:
        explicit visibility_class( visibility_enum const& visibility_param = public_index ):m_visibility(visibility_param){}
        virtual ~visibility_class(){}

      public:
        visibility_enum const& visibility()const{ return m_visibility; }
                         void  visibility( visibility_enum const& visibility_param ){m_visibility = visibility_param; }
      protected:
        visibility_enum      & visibility()     { return m_visibility; }
      private:
        visibility_enum m_visibility;
     };

   }
 }

#endif
