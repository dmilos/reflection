#ifndef reflection_content_big_block_hpp
#define reflection_content_big_block_hpp
 // ::reflection::content::big::block_class

#include "../../property/big/block.hpp"

#include "./_pure.hpp"

namespace reflection
 {
  namespace content
   {
    namespace big
     {

       class block_class
        : virtual public ::reflection::content::big::pure_class< std::size_t, std::vector< std::uint8_t > >
        ,         public ::reflection::property::big::block_class
        {
         public:
           typedef ::reflection::content::big::pure_class< std::size_t, std::vector< std::uint8_t > >  pure_type;
           typedef ::reflection::property::big::block_class       block_type;

           using block_type::size;
           using block_type::get;
           using block_type::insert;
           using block_type::replace;
           using block_type::erase;
        };

      }
    }
  }

#endif
