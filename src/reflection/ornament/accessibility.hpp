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
        enum accessibility_enum
         {
          unknown_index,
          default_index,
          gloabal_index,
          local_index,

          _internal1_index = 4,
          public_index     = _internal1_index << 1,
          protected_index  = public_index << 1,
          private_index    = protected_index << 1,

          _internal2_index = 32,
          direct_index = _internal2_index << 1,
          inspect_index = direct_index  << 1,
          mutate_index  = inspect_index << 1,
          exposed_index = direct_index                 | mutate_index,
          guarded_index =                inspect_index | mutate_index,
          variable_index= direct_index | inspect_index,
          trinity_index = direct_index | inspect_index | mutate_index
         };

        typedef  ::reflection::ornament::accessibility_class this_type;

      public:
        explicit accessibility_class( accessibility_enum const& accessibility_param = public_index ):m_accessibility(accessibility_param){}
        virtual ~accessibility_class(){}

      public:
        accessibility_enum const& accessibility()const{ return m_accessibility; }
                            void  accessibility( accessibility_enum const& accessibility_param )
                             {
                              m_accessibility = accessibility_param; 
                             }
      protected:
        accessibility_enum      & accessibility()     { return m_accessibility; }
      private:
        accessibility_enum m_accessibility;
      public:
        static accessibility_enum from_string( string_type const& s )
         {
          if( "default"   == s ) return   default_index;
          if( "global"    == s ) return   gloabal_index;
          if( "local"     == s ) return     local_index;
          if( "public"    == s ) return    public_index;
          if( "protected" == s ) return protected_index;
          if( "private"   == s ) return   private_index;
          if( "direct"    == s ) return    direct_index;
          if( "exposed"   == s ) return   exposed_index;
          if( "guarded"   == s ) return   guarded_index;
          if( "inspect"   == s ) return   inspect_index;
          if( "mutate"    == s ) return    mutate_index;
          if( "trinity"   == s ) return   trinity_index;
          if( "variable"  == s ) return  variable_index;

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
