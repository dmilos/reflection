#ifndef reflection_property_big_file
#define reflection_property_big_file

// reflection::property::big::file_class

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
          typedef std::size_t                 size_type;
          typedef std::vector< std::uint8_t > data_type;

                   file_class(){}
          virtual ~file_class(){}

          virtual size_type  size( )const{ return 0; }
          virtual size_type  size( size_type const& size_param ){ return 0; }
          virtual size_type  get(     data_type      & target_param,  size_type const& position_param )const{ /*TODO*/ return 0; }
          virtual bool       insert(  data_type const& target_param,  size_type const& position_param ){ /*TODO*/ return false; }
          virtual bool       replace( data_type const& target_param,  size_type const& position_param ){ /*TODO*/ return false; }
          virtual bool       erase(   size_type const& begin_param,   size_type const& end_param ){ /*TODO*/ return false; }

       };

     }
   }
 }

#endif
