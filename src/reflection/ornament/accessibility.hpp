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
        typedef std::string string_type;
        enum accessibility_enum{ unknown_index, default_index, gloabal_index, public_index, protected_index, private_index, local_index };

        typedef  ::reflection::ornament::accessibility_class this_type;

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
      public:
        static accessibility_enum from_string( string_type const& s )
         {
          if( "gloabal"   == s ) return gloabal_index;
          if( "public"    == s ) return public_index;
          if( "protected" == s ) return protected_index;
          if( "private"   == s ) return private_index;
          if( "local"     == s ) return local_index;
          return unknown_index;
         }

      public:
        static accessibility_enum accessibility(  ::reflection::property::pure_class const& property_param )
         {
          this_type  const* this_item = dynamic_cast< this_type const* >( &property_param );
          if( nullptr == this_item )
           {
            return unknown_index;
           }
          return this_item->accessibility();
         }
     };

   }
 }

#endif
