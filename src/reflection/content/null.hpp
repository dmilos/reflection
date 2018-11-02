#ifndef reflection_content_nullptr_hpp
 #define reflection_content_nullptr_hpp

 // ::reflection::content::null_class<data_name,original_name >

 #include "../../property/direct/_pure.hpp"

 #include "../_pure.hpp"

namespace reflection
 {
  namespace content
   {

    template
     <
       typename  identifier_name
     >
    class null_class
     : virtual public ::reflection::content::pure_class< identifier_name >
     , public ::reflection::property::null_class
     {
      public:
        typedef identifier_name    identifier_type;
        typedef std::nullptr_t                data_type;

        typedef ::reflection::content::pure_class< identifier_type >              content_type;

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

#endif
