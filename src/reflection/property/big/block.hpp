#ifndef reflection_property_big_block
#define reflection_property_big_block

// ::reflection::property::big::block_class

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

          explicit block_class( pointer_type const &pointer_param = nullptr, size_type const& size_param =0 )
                    : m_pointer( pointer_param  )
                    , m_size( size_param  )
                    {
                    }


          virtual ~block_class(){}

          virtual size_type  size( )const
           {
            return m_size;
           }

          virtual size_type  size( size_type const& size_param )
           {
            return m_size; // can not change size
           }

          virtual size_type  get(     data_type      & value_param,  size_type const& position_param )const
           {
            // TODO range check
            std::copy( m_pointer + position_param, m_pointer + position_param + value_param.size(), value_param.begin() );
            return size();
           }
          virtual size_type  insert(  data_type const& value_param,  size_type const& position_param )
           {
            /*TODO*/
            return size();
           }
          virtual size_type  replace( data_type const& value_param,  size_type const& position_param )
           {
            /*TODO*/
            return size();
           }
          virtual size_type  erase(   size_type const& begin_param,   size_type const& end_param )
           {
            /*TODO*/
            return size();
           }

        private:
          size_type m_size;
        public:
                  pointer_type    const& pointer()const{ return m_pointer; }
          virtual bool                   pointer( pointer_type const& pointer_param ){ m_pointer = pointer_param; return bool( true ); }
        protected:
          pointer_type                 & pointer(){ return m_pointer; }
        private:
          pointer_type m_pointer;

       };

     }
   }
 }

 #endif