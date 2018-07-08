#ifndef reflection_content__pure
#define reflection_content__pure
// ::reflection::content::pure_class<data_name>

#include "../property/_pure.hpp"
#include "../type/string.hpp"
#include "./category.hpp"


namespace reflection
 {
  namespace  content
   {

    template
     <
      typename data_name
     >
    class pure_class
     : virtual public ::reflection::property::pure_class
     , virtual public ::reflection::content::category::pure_class< ::reflection::type::string_type >
     {
      public:
        typedef ::reflection::type::string_type string_type;
        typedef ::reflection::content::category::pure_class< ::reflection::type::string_type > category_type;

        explicit pure_class( string_type const& type_param = typeid(data_name).name() )
         :category_type( type_param )
         {
          this->category_type::type() = string_type( typeid(data_name).name() );
         }

        virtual ~pure_class(){}
     };



   }
 }

 #endif
