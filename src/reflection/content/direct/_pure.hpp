#ifndef reflection_content_direct_pure_hpp
 #define reflection_content_direct_pure_hpp

 // ::reflection::content::direct::pure_class<data_name,original_name >

 #include "../../property/direct/_pure.hpp"

 #include "../_pure.hpp"

namespace reflection
 {
  namespace content
   {
    namespace direct
     {

      template
       <
         typename  identifier_name
        ,typename        data_name
        ,typename    original_name
       >
       class pure_class
        : virtual public ::reflection::content::pure_class< identifier_name >
        , virtual public ::reflection::property::direct::pure_class<original_name>
        {
         public:
           typedef identifier_name    identifier_type;
           typedef data_name                data_type;
           typedef original_name        original_type;

           typedef ::reflection::content::pure_class< identifier_type >              content_type;
           typedef ::reflection::property::direct::pure_class<original_name>        property_type;

           typedef ::reflection::type::name::identificatorX< identifier_name  > identificator_type;

           pure_class()
            :content_type( identificator_type::template get<data_type>() )
            {
             this->identifier( identificator_type::template get<data_type>() );
            }

           using property_type::disclose;
        };

      }
    }
  }

#endif
