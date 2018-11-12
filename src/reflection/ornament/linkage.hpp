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
     {
      public:
        typedef enum linkage_enum{ inline_index, static_index, extern_index, dll_index, default_index } linkage_type;

      public:
        explicit linkage_class( linkage_enum const& s = extern_index ):m_linkage(s){}
        virtual ~linkage_class(){}

      public:
        linkage_type const& linkage()const{ return m_linkage; }
                      void  linkage( linkage_enum const& linkage_param ){ m_linkage = linkage_param; }
      protected:
        linkage_type      & linkage()     { return m_linkage; }
      private:
        linkage_type m_linkage;
     };

   }
 }

#endif
