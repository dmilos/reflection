#ifndef reflection_content_void_hpp
 #define reflection_content_void_hpp

 // ::reflection::content::void_class<identifier_name >

 #include "../property/void.hpp"

 #include "./_base.hpp"

namespace reflection
 {
  namespace content
   {

    template
     <
       typename  identifier_name
     >
    class void_class
     : virtual public ::reflection::content::base_class< identifier_name, void >
     , virtual public ::reflection::property::void_class
     {
      public:
        typedef identifier_name    identifier_type;
        typedef void                data_type;

        typedef ::reflection::content::pure_class< identifier_type >              content_type;
        typedef ::reflection::property::void_class                               property_type;

        typedef ::reflection::type::name::identificatorX< identifier_name  > identificator_type;

     };

    }
  }

#endif
