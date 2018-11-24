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
        typedef std::string string_type;
        enum derivation_enum{ unknown_index, default_index, virtual_index, static_index };

        typedef  ::reflection::ornament::derivation_class this_type;

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
      public:
      public:
        static derivation_enum from_string( string_type const& s )
         {
          if( "virtual" == s ) return virtual_index;
          if( "static"  == s ) return static_index;
          if( "default" == s ) return default_index;
          return unknown_index;
         }

      public:
        static derivation_enum derivation(  ::reflection::property::pure_class const& property_param )
         {
          this_type  const* this_item = dynamic_cast< this_type const* >( &property_param );
          if( nullptr == this_item )
           {
            return unknown_index;
           }
          return this_item->derivation();
         }
     };

   }
 }

#endif
