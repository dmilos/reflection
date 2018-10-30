#ifndef reflection_content__pure
#define reflection_content__pure
// ::reflection::content::pure_class<data_name>

#include "../property/_pure.hpp"
#include "../type/name/id.hpp"
#include "./category.hpp"


namespace reflection
 {
  namespace  content
   {

    template
     <
       typename data_name
      ,typename identifier_name = std::string
     >
    class pure_class
     : virtual public ::reflection::property::pure_class
     , virtual public ::reflection::content::category::pure_class< identifier_name >
     {
      public:
        typedef identifier_name identifier_type;
        typedef ::reflection::content::category::pure_class< identifier_type > category_type;

        typedef ::reflection::type::name::identificatorX< identifier_name  > identificator_type;

        explicit pure_class( identifier_type const& type_param = identificator_type:: template get<data_name>() )
         :category_type( type_param )
         {
          this->category_type::type( identificator_type:: template get<data_name>() );
         }

        virtual ~pure_class(){}
     };



   }
 }

 #endif
