#ifndef reflection_property_big_member
#define reflection_property_big_member

// reflection::property::big::member_class

#include "./_pure.hpp"

namespace reflection
 {
  namespace property
   {
    namespace big
     {
      template
       <
        typename class_name
       >
      class member_class
       : virtual public ::reflection::property::big::pure_class< std::size_t, std::vector< std::uint8_t > >
       {
        public:
          typedef class_name class_type;

          typedef std::size_t size_type;
          typedef std::vector< std::uint8_t > data_type;
          typedef data_type const&  (class_name::*traitor_type)();

                   member_class(){}
          virtual ~member_class(){}

          virtual size_type  size( )const{ return 0; }
          virtual size_type  size( size_type const& size_param ){ return 0; }
          virtual size_type  get(     data_type      & target_param,  size_type const& position_param )const{ /*TODO*/ return 0; }
          virtual bool       insert(  data_type const& target_param,  size_type const& position_param ){ /*TODO*/ return false; }
          virtual bool       replace( data_type const& target_param,  size_type const& position_param ){ /*TODO*/ return false; }
          virtual bool       erase(   size_type const& begin_param,   size_type const& end_param ){ /*TODO*/ return false; }

        public:
                  traitor_type    const& traitor()const{ return m_traitor; }
          virtual bool         traitor( traitor_type const& traitor_param ){ m_traitor = traitor_param; return bool( true ); }
        protected:
          traitor_type        & traitor(){ return m_traitor; }
        private:
          traitor_type m_traitor;

       };

     }
   }
 }

 #endif