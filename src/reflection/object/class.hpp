#ifndef reflection_object_class
#define reflection_object_class

// ::reflection::object::class_class<key_name>

#include "../content/content.hpp"
#include "./structure.hpp"

namespace reflection
 {
  namespace object
   {

    template< typename data_name, typename key_name = std::string >
     class class_class
      : virtual public ::reflection::content::pure_class<data_name>
      , /*virtual */public ::reflection::object::structure_class<key_name>
      {
       public:
         typedef data_name   data_type;
         typedef std::string  key_type;

         class_class(){}
         class_class( class_class const& that_param ){ *this = that_param; }
         class_class & operator=( class_class const& that_param )
          {
           // EMPTY!!!
           return *this;
          }

        ~class_class(){}

      };

   }
 }

#endif 