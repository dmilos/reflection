#ifndef reflection_content_big_pure_hpp
#define reflection_content_big_pure_hpp

 // ::reflection::content::big::pure_class<size_name,data_name >

 #include "../../property/big/_pure.hpp"

 #include "../_base.hpp"

namespace reflection
 {
  namespace content
   {
    namespace big
     {

      template
       <
         typename identifier_name
        ,typename size_name = std::size_t
        ,typename data_name = std::vector< std::uint8_t >
      //,typename copy_name = std::vector< std::uint8_t >
       >
       class pure_class
        : virtual public ::reflection::content::base_class< identifier_name, data_name >
        , virtual public ::reflection::property::big::pure_class<size_name,data_name>
        {
         public:
           typedef identifier_name identifier_type;
           typedef size_name             size_type;
           typedef data_name             data_type;

           typedef ::reflection::type::name::identificatorX< identifier_name  > identificator_type;


           typedef ::reflection::content::pure_class< identifier_name >            content_type;
           typedef ::reflection::property::big::pure_class<size_name,data_name>   property_type;

           using property_type::size;
           using property_type::get;
           using property_type::insert;
           using property_type::replace;
           using property_type::erase;
        };

      }
    }
  }

#endif
