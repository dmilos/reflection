#ifndef reflection_ornament_linkage
#define reflection_ornament_linkage

// ::reflection::ornament::linkage_class

#include "../property/_pure.hpp"

namespace reflection
 {
  namespace ornament
   {

    class linkage_class
     : virtual public ::reflection::property::pure_class
     { // https://en.cppreference.com/w/cpp/language/storage_duration
      public:
        enum linkage_enum{ unknown_index, default_index, inline_index, static_index, extern_index, dll_index };

        typedef ::reflection::ornament::linkage_class this_type;

      public:
        explicit linkage_class( linkage_enum const& s = extern_index ):m_linkage(s){}
        virtual ~linkage_class(){}

      public:
        linkage_enum const& linkage()const{ return m_linkage; }
                      void  linkage( linkage_enum const& linkage_param ){ m_linkage = linkage_param; }
      protected:
        linkage_enum      & linkage()     { return m_linkage; }
      private:
        linkage_enum m_linkage;
      public:
        static linkage_enum linkage(  ::reflection::property::pure_class const& property_param )
         {
          this_type  const* this_item = dynamic_cast< this_type const* >( &property_param );
          if( nullptr == this_item )
           {
            return unknown_index;
           }
          return this_item->linkage();
         }
     };

   }
 }

#endif


