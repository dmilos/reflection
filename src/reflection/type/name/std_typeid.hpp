#ifndef reflection_type_name_std_type_id
#define reflection_type_name_std_type_id

// ::reflection::type::name::identificatorX< std::string >

#include "./id.hpp"

namespace reflection
 {
  namespace type
   {
    namespace name
     {

      template<>
       struct identificatorX< std::string >
        {
         public:
           typedef std::string identifier_type;

           static identifier_type const& NAT()
            {
             static identifier_type id="";
             return id;
            }

           template< typename data_name >
            static identifier_type const& get()
             {
              static identifier_type id = typeid(data_name).name();
              return id;
             }

           template< typename data_name >
            static identifier_type const& native()
             {
              static identifier_type id = typeid(data_name).name();
              return id;
             }
        };

      template<>
       struct identificatorX<char*>
        {
         public:
           typedef std::string   identifier_type;

           typedef ::reflection::type::name::identificatorX<std::string>  rebind_type;

         public:
           static identifier_type const& NAT(){ return rebind_type::NAT(); }

           template < typename type_name >
             static identifier_type const& get(){ return rebind_type::template get<type_name>(); }
           template < typename type_name >
             static identifier_type const& native(){ return rebind_type::template native<type_name>(); }
        };

      template<>
       struct identificatorX<char[]>
        {
         public:
           typedef std::string   identifier_type;

           typedef ::reflection::type::name::identificatorX<std::string>  rebind_type;

         public:
           static identifier_type const& NAT(){ return rebind_type::NAT(); }

           template < typename type_name >
             static identifier_type const& get(){ return rebind_type::template get<type_name>(); }

           template < typename type_name >
             static identifier_type const& native(){ return rebind_type::template native<type_name>(); }
        };

     }
   }
 }

#endif
