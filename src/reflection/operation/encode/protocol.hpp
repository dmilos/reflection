#ifndef reflection_operation_encode_protocol
#define reflection_operation_encode_protocol

// ::reflection::operation::encode::protocol<output_name,key_name,identificator_name>

#include "../../content/category.hpp"
#include "../../property/structure.hpp"

#include "../../type/container/container.hpp"

#include "./action.hpp"

namespace reflection
 {
  namespace operation
   {
    namespace encode
     {

      template
       <
         typename   output_name
        ,typename     identificator_name = std::string
        ,typename   report_name = bool
        ,template  <typename>          class  qualificator_name = std::add_const
        ,template  <typename,typename> class     container_name = ::reflection::type::container::map
       >
       struct protocol_struct //!< Wrapper around menu_type
        {
         public:

           typedef         output_name           output_type;
           typedef  identificator_name    identificator_type;
           typedef         report_name           report_type;

           typedef typename ::reflection::operation::encode::action_struct< output_type, identificator_type, qualificator_name, report_type > action_type;

           typedef typename  action_type::function_type function_type;

           typedef typename container_name< identificator_type, function_type >::container_type menu_type;

           typedef typename qualificator_name<menu_type>::type  menu_qualified_type;
           typedef typename qualificator_name<menu_type>::type  menu_qualified_reference_type;

           static bool               exists( menu_type const& container_param, identificator_type const& identificator )
            {
             return ::reflection::type::container::exists< identificator_type, function_type >( container_param, identificator );
            }

           static function_type const& find( menu_type const& container_param, identificator_type const& identificator )
            {
             auto iterator = ::reflection::type::container::find< identificator_type, function_type >( container_param, identificator );
             if( container_param.end() == iterator )
              {
               return action_type::always_false();
              }
             return ::reflection::type::container::data< identificator_type, function_type >( container_param, iterator );
            }

           static function_type      & find( menu_type      & container_param, identificator_type const& identificator )
            {
             auto iterator = ::reflection::type::container::find< identificator_type, function_type  >( container_param, identificator );
             if( container_param().end() == iterator )
              {
               return action_type::always_false();
              }
              return ::reflection::type::container::data< identificator_type, function_type  >( container_param, identificator );
            }

           static void               insert( menu_type      & container_param, identificator_type const& identificator, function_type const& function )
            {
             ::reflection::type::container::insert< identificator_type, function_type >( container_param, identificator, function );
            }

      };

     }
   }
 }

#endif
