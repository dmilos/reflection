#ifndef reflection_property_big_file
#define reflection_property_big_file

// ::reflection::property::big::file_class

#include "../../type/string.hpp"
#include "./_pure.hpp"


namespace reflection
 {
  namespace property
   {
    namespace big
     {

      class file_class
       : virtual public ::reflection::property::big::pure_class< std::size_t, std::vector< std::uint8_t > >
       {
        public:
          typedef std::size_t                        size_type;
          typedef std::vector< std::uint8_t >        data_type;

          typedef ::reflection::type::string_type    string_type;

          explicit file_class( /* TODO */ string_type const& filename_param = string_type() ){ open( filename_param ); }
          virtual ~file_class(){}

          virtual size_type  size( )const
           {
            if( false == this->good() ) { return 0; }
            /*TODO*/
            return 0;
           }

          virtual size_type  size( size_type const& size_param )
           {
            if( false == this->good() ) { return size(); }
            /*TODO*/
            return size();
           }

          virtual size_type  get(     data_type      & value_param,  size_type const& position_param )const
           {
            if( false == this->good() ) { return size(); }
            /*TODO*/
            return size();
           }

          virtual size_type  insert(  data_type const& value_param,  size_type const& position_param )
           {
            if( false == this->good() ) { return size(); }
            /*TODO*/
            return size();
           }

          virtual size_type  replace( data_type const& value_param,  size_type const& position_param )
           {
            if( false == this->good() ) { return size(); }
            /*TODO*/
            return size();
           }

          virtual size_type  erase(   size_type const& begin_param,   size_type const& end_param )
           {
            if( false == this->good() ) { return size(); }
            /*TODO*/
            return size();
           }
        private:
          void open( string_type const& filename_param ){ }

        public:
          bool    const& good()const{ return m_good; }
        private:
          bool m_good;

       };

     }
   }
 }

#endif
