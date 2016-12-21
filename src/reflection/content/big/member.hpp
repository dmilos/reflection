#ifndef reflection_content_big_member_hpp
#define reflection_content_big_member_hpp
 // ::reflection::content::big::member_class

#include "../../property/big/member.hpp"

#include "./_pure.hpp"

namespace reflection
 {
  namespace content
   {
    namespace big
     {

      template
       <
         typename class_name
       >
       class member_class
        : virtual public ::reflection::content::big::pure_class< std::size_t, std::vector< std::uint8_t > >
        ,         public ::reflection::property::big::member_class<class_name>
        {
         public:
           typedef ::reflection::content::big::pure_class<std::size_t, std::vector< std::uint8_t > >  pure_type;
           typedef ::reflection::property::big::member_class<class_name>       member_type;

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
