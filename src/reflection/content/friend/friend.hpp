#ifndef reflection_content_frienddeclaration_pure_hpp
 #define reflection_content_frienddeclaration_pure_hpp

 // ::reflection::content::frienddeclaration::pure_class<identifier_name,friend_name>

 #include "../../property/friend/friend.hpp"

 #include "../_pure.hpp"

namespace reflection
 {
  namespace content
   {
    namespace frienddeclaration
     {

      template
       <
         typename  identifier_name
        ,typename  friend_name
       >
       class pure_class
        : virtual public ::reflection::content::pure_class< identifier_name >
        , virtual public ::reflection::property::frienddeclaration::pure_class< identifier_name >
        {
         public:
           typedef  identifier_name  identifier_type;
           typedef  friend_name          friend_type;

           typedef ::reflection::content::pure_class< identifier_type >                          content_type;
           typedef ::reflection::property::frienddeclaration::pure_class< identifier_name >        property_type;

           typedef property_type data_type;

           typedef ::reflection::type::name::identificatorX< identifier_name  > identificator_type;

           pure_class( typename property_type::string_type const& name )
            :content_type( identificator_type::template get<data_type>() )
            ,property_type( identificator_type::template get<friend_type>(), name )
            {
             this->identifier( identificator_type::template get<data_type>() );
            }

        };

      }
    }
  }

#endif
