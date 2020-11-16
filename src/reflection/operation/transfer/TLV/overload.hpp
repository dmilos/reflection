#ifndef reflection_operation_transfer_tlv_internal_overload_class
#define reflection_operation_transfer_tlv_internal_overload_class

// ::reflection::operation::transfer::tlv::_internal::overload_class<return_name, first_name>

#include "../../../utility/function/std.hpp"

namespace reflection
 {
  namespace operation
   {
    namespace transfer
     {
      namespace tlv
       {
        namespace _internal
        {

         template
          <
            typename return_name  = void
           ,typename first_name   = void
          >
          class overload_class
          : public ::reflection::utility::function::std_class<return_name>
          , public ::reflection::utility::function::std_class<return_name,first_name>
          {
           public:
            typedef ::reflection::utility::function::std_class<return_name>  generator_type;
            typedef ::reflection::utility::function::std_class<return_name,first_name >unary_type;

           public:
            overload_class( ):generator_type(nullptr),unary_type(nullptr){ }
            overload_class( typename generator_type::function_type function ):generator_type(function),unary_type(nullptr){ }
            overload_class( typename unary_type::function_type     function ):generator_type(nullptr),unary_type(function){ }
            ~overload_class( ){ }
          };

        }
       }
     }
   }
 }

#endif
