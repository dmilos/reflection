#ifndef reflection_property_big_vector
#define reflection_property_big_vector

// ::reflection::property::big::vector_class

#include "./_pure.hpp"

namespace reflection
 {
  namespace property
   {
    namespace big
     {

      class vector_class
       : virtual public ::reflection::property::big::pure_class< std::size_t, std::vector< std::uint8_t > >
       {
        public:

                   vector_class(){}
          virtual ~vector_class(){}

          virtual size_type  size( )const
           {
            return m_data.size();
           }

          virtual size_type  size( size_type const& size_param )
           {
            m_data.resize(size_param); 
            return size();
           }

          virtual size_type  get(     data_type      & value_param,  size_type const& position_param )const
           {
            // TODO range check
            std::copy( m_data.begin() + position_param, m_data.begin() + position_param + value_param.size(), value_param.begin() );
            return 0;
           }

          virtual bool       insert(  data_type const& value_param,  size_type const& position_param )
           {
            // TODO range check
            m_data.insert( m_data.begin() + position_param, value_param.begin(), value_param.end() );
            return 0;
           }

          virtual bool       replace( data_type const& value_param,  size_type const& position_param )
           {
            // TODO range check
            std::copy( value_param.begin(), value_param.end(), m_data.begin() + position_param );
            return false;
           }

          virtual bool       erase(   size_type const& begin_param,  size_type const& end_param )
           {
            m_data.erase( m_data.begin() + begin_param,  m_data.begin() +  end_param); 
            return false;
           }

        public:
                  data_type    const& data()const{ return m_data; }
          virtual bool                data( data_type const& data_param ){ m_data = data_param; return bool( true ); }
                  data_type         & data(){ return m_data; }
        private:
          data_type m_data;
       };

     }
   }
 }

#endif
