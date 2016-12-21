#ifndef reflection_content_big_file_hpp
#define reflection_content_big_file_hpp
 // ::reflection::content::big::file_class

#include "../../property/big/file.hpp"

#include "./_pure.hpp"

namespace reflection
 {
  namespace content
   {
    namespace big
     {

       class file_class
        : virtual public ::reflection::content::big::pure_class<std::size_t,std::vector< std::uint8_t > >
        ,         public ::reflection::property::big::file_class
        {
         public:
           typedef ::reflection::content::big::pure_class< std::size_t, std::vector< std::uint8_t > >  pure_type;
           typedef ::reflection::property::big::file_class                                           member_type;

           using member_type::size;
           using member_type::get;
           using member_type::insert;
           using member_type::replace;
           using member_type::erase;
        };

      }
    }
  }

#endif
