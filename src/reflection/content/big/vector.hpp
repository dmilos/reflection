#ifndef reflection_content_big_vector_hpp
#define reflection_content_big_vector_hpp
 // ::reflection::content::big::vector_class

#include "../../property/big/vector.hpp"

#include "./_pure.hpp"

namespace reflection
 {
  namespace content
   {
    namespace big
     {

       class vector_class
        : virtual public ::reflection::content::big::pure_class<std::size_t, std::vector< std::uint8_t > >
        ,         public ::reflection::property::big::vector_class
        {
         public:
           typedef ::reflection::content::big::pure_class< std::size_t, std::vector< std::uint8_t > >  pure_type;
           typedef ::reflection::property::big::vector_class     vector_type;

           using vector_type::size;
           using vector_type::get;
           using vector_type::insert;
           using vector_type::replace;
           using vector_type::erase;
        };

      }
    }
  }

#endif
