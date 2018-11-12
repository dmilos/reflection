#ifndef reflection_ornament_relation
#define reflection_ornament_relation

// ::reflection::ornament::relation_class

#include "../property/_pure.hpp"

namespace reflection
 {
  namespace ornament
   {

    class relation_class
     : virtual public ::reflection::property::pure_class
     {
      public:
        typedef enum relation_enum{ friend_index, member_index, base_index, unknown_index, injected_index } relation_type;

      public:
         relation_class( ):m_relation(unknown_index)
         {
         }
        explicit relation_class( relation_enum const& r ):m_relation(r) {}
        virtual ~relation_class(){}

      public:
        relation_type const& relation()const{ return m_relation; }
                       void  relation( relation_enum const& relation_param ){ m_relation = relation_param; }
      protected:
        relation_type      & relation()     { return m_relation; }
      private:
        relation_type m_relation;
     };

   }
 }

#endif
