#ifndef reflection_ornament_kind
#define reflection_ornament_kind

// ::reflection::ornament::kind_class

#include "../property/_pure.hpp"

namespace reflection
 {
  namespace ornament
   {

    class kind_class //! Rename to category
     : virtual public ::reflection::property::pure_class
     {
      public:
        enum kind_enum{ unknown_index, default_index, hiden_index, function_index, data_index, cluster_index, ID_index };

        typedef ::reflection::ornament::kind_class  this_type;

      public:
        explicit kind_class( kind_enum const& kind_param = unknown_index ):m_kind(kind_param){}
        virtual ~kind_class(){}

      public:
        kind_enum const& kind()const{ return m_kind; }
                         void  kind( kind_enum const& kind_param ){m_kind = kind_param; }
      protected:
        kind_enum      & kind()     { return m_kind; }
      private:
        kind_enum m_kind;
      public:
        static kind_enum kind(  ::reflection::property::pure_class const& property_param )
         {
          this_type  const* this_item = dynamic_cast< this_type const* >( &property_param );
          if( nullptr == this_item )
           {
            return unknown_index;
           }
          return this_item->kind();
         }
     };

   }
 }

#endif
