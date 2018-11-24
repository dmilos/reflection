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
        typedef enum visibility_enum{ unknown_index, default_index, gloabal_index, public_index, protected_index, private_index, local_index,  } accessibility_type;

        typedef ::reflection::ornament::visibility_class  this_type;

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
      public:
        static relation_enum visibility(  ::reflection::property::pure_class const& property_param )
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
