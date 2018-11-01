#ifndef reflection_content_enumeration_pure_hpp
 #define reflection_content_enumeration_pure_hpp

 // ::reflection::content::enumeration::pure_class<identifier_name,enumarator_name, size_name>

 #include "../../property/enum/base.hpp"

 #include "../_pure.hpp"

namespace reflection
 {
  namespace content
   {
    namespace enumeration
     {

      template
       <
         typename  identifier_name
        ,typename  enumarator_name
        ,typename        name_name
        ,typename       value_name
       >
       class pure_class
        : virtual public ::reflection::content::pure_class< identifier_name >
        , virtual public ::reflection::property::enumeration::base_class<enumarator_name,name_name, value_name>
        {
         public:
           typedef  identifier_name  identifier_type;
           typedef  enumarator_name  enumarator_type;
           typedef        name_name        name_type;
           typedef       value_name       value_type;

           typedef ::reflection::content::pure_class< identifier_type >                                           content_type;
           typedef ::reflection::property::enumeration::pure_class<name_name, value_name>                   property_pure_type;
           typedef ::reflection::property::enumeration::base_class<enumarator_name,name_name, value_name>    property_base_type;

           typedef property_pure_type data_type;

           typedef ::reflection::type::name::identificatorX< identifier_name  > identificator_type;

           pure_class()
            :content_type( identificator_type::template get<data_type>() )
            {
             this->type( identificator_type::template get<data_type>() );
            }

        };

      }
    }
  }

#endif
