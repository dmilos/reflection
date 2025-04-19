#ifndef reflection_content_void_hpp
 #define reflection_content_void_hpp

 // ::reflection::content::void_class<identifier_name >

 #include "../property/void.hpp"

 #include "./_pure.hpp"

namespace reflection
 {
  namespace content
   {

    template
     <
       typename  identifier_name
     >
    class void_class
     : virtual public ::reflection::content::pure_class< identifier_name >
     , virtual public ::reflection::property::void_class
     {
      public:
        typedef identifier_name    identifier_type;
        typedef void                data_type;

        typedef ::reflection::content::pure_class< identifier_type >              content_type;
        typedef ::reflection::property::void_class                               property_type;

        typedef ::reflection::type::name::identificatorX< identifier_name  > identificator_type;

        void_class()
         :content_type( identificator_type::template get<data_type>() )
         {
          this->identifier( identificator_type::template get<data_type>() );
         }

     };

    }
  }

#endif
