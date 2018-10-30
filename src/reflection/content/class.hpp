#ifndef reflection_object_class
#define reflection_object_class

// ::reflection::content::class_class<data_name,key_name,container_name>

#include "../content/content.hpp"
#include "../property/structure.hpp"

namespace reflection
 {
  namespace content
   {

    template
     <
       typename class_name
      ,typename identifier_name   = std::string
      ,typename key_name          = std::string
      ,template < typename, typename > class container_name = ::reflection::type::container::map
     >
     class class_class
      : virtual public ::reflection::content::pure_class<identifier_name>
      , /*virtual */public ::reflection::property::structure_class<key_name, container_name >
      {
       public:
         typedef class_name             class_type;
         typedef identifier_name   identifier_type;
         typedef key_name                 key_type;

         typedef ::reflection::type::name::identificatorX< identifier_name  > identificator_type;

         typedef ::reflection::content::pure_class<identifier_name>                   content_type;
         typedef ::reflection::property::structure_class<key_name, container_name >  structure_type;

         class_class( )
          :content_type( identificator_type::template get<class_name>() )
          {
           this->type( identificator_type::template get<class_name>() );
          }

         class_class( class_class const& that_param )
          :content_type( identificator_type::template get<class_name>() )
          {
           this->type( identificator_type::template get<class_name>() );
           *this = that_param; 
          }

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
