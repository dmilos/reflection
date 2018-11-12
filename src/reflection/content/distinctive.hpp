#ifndef reflection_content_distinctive
#define reflection_content_distinctive

// ::reflection::content::distinctive_class<identifier_name,data_name>

#include "../type/name/id.hpp"
#include "./_pure.hpp"


namespace reflection
 {
  namespace  content
   {

    template
     <
       typename identifier_name
      ,typename data_name
     >
    class distinctive_class
     : virtual public ::reflection::content::pure_class<identifier_name>
     {
      public:
        typedef identifier_name    identifier_type;
        typedef data_name                data_type;

        typedef ::reflection::content::pure_class< identifier_type > pure_type;

        typedef ::reflection::type::name::identificatorX< identifier_name  > identificator_type;

        explicit distinctive_class( identifier_type const& type_param = identificator_type::template get<data_type>() )
         : pure_type( type_param )
         {
          this->identifier( type_param );
         }

        virtual ~distinctive_class(){}
     };

   }
 }

#endif