#ifndef reflection_type_name_std_type_id
#define reflection_type_name_std_type_id

// ::reflection::type::name::id

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

           template< typename data_name >
            static identifier_type const& get()
             {
              static identifier_type id = typeid(data_name).name(); 
              return id; 
             }
        };

     }
   }
 }


#endif

