#ifndef reflection_property_big_block
#define reflection_property_big_block

// reflection::property::big::block_class

#include "./_pure.hpp"

namespace reflection
 {
  namespace property
   {
    namespace big
     {

      class block_class
       : virtual public ::reflection::property::big::pure_class< std::size_t, std::vector< std::uint8_t > >
       {
        public:
          typedef std::size_t size_type;
          typedef std::vector< std::uint8_t > data_type;
          typedef std::uint8_t *pointer_type;

                   block_class(){}
          virtual ~block_class(){}

          virtual size_type  size( )const{ return 0; }
          virtual size_type  size( size_type const& size_param ){ return 0; }
          virtual size_type  get(     data_type      & target_param,  size_type const& position_param )const{ /*TODO*/ return 0; }
          virtual bool       insert(  data_type const& target_param,  size_type const& position_param ){ /*TODO*/ return false; }
          virtual bool       replace( data_type const& target_param,  size_type const& position_param ){ /*TODO*/ return false; }
          virtual bool       erase(   size_type const& begin_param,   size_type const& end_param ){ /*TODO*/ return false; }

        public:
                  pointer_type    const& pointer()const{ return m_pointer; }
          virtual bool         pointer( pointer_type const& pointer_param ){ m_pointer = pointer_param; return bool( true ); }
        protected:
          pointer_type        & pointer(){ return m_pointer; }
        private:
          pointer_type m_pointer;

       };

     }
   }
 }

 #endif