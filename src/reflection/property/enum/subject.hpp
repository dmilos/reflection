#ifndef reflection_property_enumeration_subject
#define reflection_property_enumeration_subject

// ::reflection::property::enumeration::subject_class<name_name,value_name>

#include "../_pure.hpp"

namespace reflection
 {
  namespace property
   {
    namespace enumeration
     {

      template
       <
         typename  name_name
        ,typename value_name
       >
       class subject_class
        {
         public:
           typedef name_name    name_type;
           typedef value_name  value_type;
         public:
           name_type const& name()const{ return m_name; }
         public:
           name_type  m_name;
         public:
           value_type const& value()const{ return m_value; }
         public:
           value_type m_value;
        };

     }
   }
 }

#endif
