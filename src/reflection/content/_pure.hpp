#ifndef reflection_content__pure
#define reflection_content__pure

// ::reflection::content::pure_class<identifier_name>

#include "../property/_pure.hpp"
#include "../type/name/id.hpp"
#include "./category.hpp"


namespace reflection
 {
  namespace  content
   {

    template
     <
      typename identifier_name
     >
    class pure_class
     : virtual public ::reflection::property::pure_class
     , virtual public ::reflection::ornament::category_class< identifier_name >
     {
      public:
        typedef identifier_name identifier_type;
        typedef ::reflection::ornament::category_class< identifier_type > category_type;

        explicit pure_class( identifier_type const& type_param = identifier_type{} )
         : category_type( type_param )
         {
         }

        virtual ~pure_class(){}
     };

   }
 }

#endif
