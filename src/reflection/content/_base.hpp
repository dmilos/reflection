#ifndef reflection_content__base
#define reflection_content__base

// ::reflection::content::base_class<identifier_name>

#include "./_pure.hpp"
#include "../type/name/id.hpp"


namespace reflection
 {
  namespace  content
   {

    template
     <
       typename identifier_name
      ,typename data_name
     >
    class base_class
     : public ::reflection::content::pure_class<identifier_name>
     {
      public:
        typedef identifier_name identifier_type;
        typedef data_name             data_type;

        typedef ::reflection::content::pure_class< identifier_type >              pure_type;

        typedef ::reflection::type::name::identificatorX< identifier_name  > identificator_type;

      public:
        base_class( )
         : pure_type( identificator_type::template get<data_type>() )
         {
          //this->identifier( identificator_type::template get<data_type>() );
         }

        virtual ~base_class(){}
     };

   }
 }

#endif
