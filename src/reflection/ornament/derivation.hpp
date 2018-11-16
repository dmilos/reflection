#ifndef reflection_ornament_derivation
#define reflection_ornament_derivation

// ::reflection::ornament::derivation_class

#include "../property/_pure.hpp"

namespace reflection
 {
  namespace ornament
   {

    class derivation_class
     : virtual public ::reflection::property::pure_class
     {
      public:
        typedef enum derivation_enum{ virtual_index, static_index, default_index, unknown_index } derivation_type;

      public:
        explicit derivation_class( derivation_enum const& derivation_param = default_index ):m_derivation(derivation_param){}
        virtual ~derivation_class(){}

      public:
        derivation_enum const& derivation()const{ return m_derivation; }
                         void  derivation( derivation_enum const& derivation_param ){ m_derivation = derivation_param; }
      protected:
        derivation_enum      & derivation()     { return m_derivation; }
      private:
        derivation_enum m_derivation;
     };

   }
 }

#endif
