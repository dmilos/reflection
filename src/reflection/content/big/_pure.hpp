#ifndef reflection_content_big_pure_hpp
#define reflection_content_big_pure_hpp
 // ::reflection::content::big::pure_class<data_name,original_name >

 #include "../../property/big/_pure.hpp"

 #include "../_pure.hpp"

namespace reflection
 {
  namespace content
   {
    namespace big
     {

      template 
       <
         typename size_name = std::size_t
        ,typename data_name = std::vector< std::uint8_t >
      //,typename copy_name = std::vector< std::uint8_t >
       >
       class pure_class
        : virtual public ::reflection::content::pure_class< data_name >
        , virtual public ::reflection::property::big::pure_class<size_name,data_name>
        {
         public:
           typedef size_name  size_type;
           typedef data_name  data_type;

           typedef ::reflection::content::pure_class< data_name >                  content_pure_type;
           typedef ::reflection::property::big::pure_class<size_name,data_name>   property_pure_type;

           using property_pure_type::disclose;

           using property_pure_type::size;
           using property_pure_type::get;
           using property_pure_type::insert;
           using property_pure_type::replace;
           using property_pure_type::erase;
        };

      }
    }
  }

#endif
