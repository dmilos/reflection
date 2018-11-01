#ifndef reflection_type_name_identificator
#define reflection_type_name_identificator

// ::reflection::type::name::identificatorX< std::string >::get< MySomeClass>()
// ::reflection::type::name::identificatorX< MySomeEnum  >::get< MySomeClass>()


namespace reflection
 {
  namespace type
   {
    namespace name
     {

      template
       <
         typename type_name
        ,typename identifier_name
       >
       struct identificatorA
        {
         public:
           typedef type_name             type_type;
           typedef identifier_name identifier_type;
         public:
           static identifier_type const& get(){ static identifier_type id; return id; }
         //static const  identifier_type s_id;
        };

      template
       <
        typename identifier_name
       >
       struct identificatorX
        {
         public:
           typedef identifier_name identifier_type;
           typedef ::reflection::type::name::identificatorX<identifier_type>     rebind_type;

         public:
           static identifier_type const& NAT(){ static identifier_type id; return id; }

           template < typename type_name >
             static identifier_type const& get(){ static identifier_type id; return id; }
        };

     }
   }
 }

#include "./std_typeid.hpp"

#endif

