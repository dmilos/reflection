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
        enum relation_enum{ unknown_index, default_index, unrelated_index, friend_index, member_index, derived_index, base_index, injected_index, field_index };

        typedef ::reflection::ornament::relation_class this_type;

      public:
         relation_class( ):m_relation(default_index)
         {
         }
        explicit relation_class( relation_enum const& r ):m_relation(r) {}
        virtual ~relation_class(){}

      public:
        relation_enum const& relation()const{ return m_relation; }
                       void  relation( relation_enum const& relation_param ){ m_relation = relation_param; }
      protected:
        relation_enum      & relation()     { return m_relation; }
      private:
        relation_enum m_relation;
      public:
        static relation_enum relation(  ::reflection::property::pure_class const& property_param )
         {
          this_type  const* this_item = dynamic_cast< this_type const* >( &property_param );
          if( nullptr == this_item )
           {
            return unknown_index;
           }
          return this_item->relation();
         }
     };

   }
 }

#endif
