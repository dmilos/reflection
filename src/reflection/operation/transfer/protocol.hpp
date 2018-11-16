#ifndef reflection_operation_transfer_protocol
#define reflection_operation_transfer_protocol

// ::reflection::operation::transfer::protocol<output_name,key_name,identificator_name>

#include "../../content/category.hpp"
#include "../../property/structure.hpp"

#include "../../type/container/container.hpp"

#include "./action.hpp"

namespace reflection
 {
  namespace operation
   {
    namespace transfer
     {

      template
       <
         typename   output_name
        ,typename      key_name = std::string
        ,typename     identificator_name = std::string
        ,typename   report_name = bool
        ,template  <typename>          class  qualificator_name = std::add_const
        ,template  <typename,typename> class     container_name = ::reflection::type::container::map
       >
       struct protocol_struct
        {
         public:

           typedef         output_name           output_type;
           typedef            key_name              key_type;
           typedef  identificator_name    identificator_type;
           typedef         report_name           report_type;

           typedef typename ::reflection::operation::transfer::action_struct< output_type, identificator_type, qualificator_name, report_type > action_type;

           typedef typename  action_type::function_type function_type;

           typedef typename container_name< identificator_type, function_type >::container_type menu_type;

           typedef typename qualificator_name<menu_type>::type  menu_qualified_type;
           typedef typename qualificator_name<menu_type>::type  menu_qualified_reference_type;

           static bool               exists( menu_type const& container, identificator_type const& key )
            {
             return ::reflection::type::container::exists< identificator_type, function_type >( container, key );
            }

           static function_type const& find( menu_type const& container, identificator_type const& key )
            {
             auto iterator = ::reflection::type::container::find< identificator_type, function_type >( container, key );
             if( container.end() == iterator )
              {
               return action_type::always_false();
              }
             return ::reflection::type::container::data< identificator_type, function_type >( container, iterator );
            }

           static function_type      & find( menu_type      & container, identificator_type const& key )
            {
             auto iterator = ::reflection::type::container::find< identificator_type, function_type  >( container, key );
             if( container().end() == iterator )
              {
               return action_type::always_false();
              }
              return ::reflection::type::container::data< identificator_type, function_type  >( container, key );
            }

           static void               insert( menu_type      & container, key_type const& key, function_type const& function )
            {
             ::reflection::type::container::insert< key_name, function_type >( container, key, function );
            }

      };

     }
   }
 }

#endif
