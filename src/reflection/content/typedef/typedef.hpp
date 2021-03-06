#ifndef reflection_content_typedefinition_pure_hpp
 #define reflection_content_typedefinition_pure_hpp

 // ::reflection::content::typedefinition::pure_class<identifier_name,typedef_name>

 #include "../../property/typedef/typedef.hpp"

 #include "../_pure.hpp"

namespace reflection
 {
  namespace content
   {
    namespace typedefinition
     {

      template
       <
         typename  identifier_name
        ,typename     typedef_name
       >
       class pure_class
        : virtual public ::reflection::content::pure_class< identifier_name >
        , virtual public ::reflection::property::typedefinition::pure_class< identifier_name >
        {
         public:
           typedef  identifier_name  identifier_type;
           typedef  typedef_name        typedef_type;

           typedef ::reflection::content::pure_class< identifier_type >                          content_type;
           typedef ::reflection::property::typedefinition::pure_class< identifier_name >        property_type;

           typedef property_type data_type;

           typedef ::reflection::type::name::identificatorX< identifier_name  > identificator_type;

           pure_class( typename property_type::string_type const& name )
            :content_type( identificator_type::template get<data_type>() )
            ,property_type( identificator_type::template get<typedef_type>(), name )
            {
             this->identifier( identificator_type::template get<data_type>() );
            }

        };

      }
    }
  }

#endif
