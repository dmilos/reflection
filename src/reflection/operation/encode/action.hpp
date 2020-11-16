#ifndef reflection_operation_encode_action
#define reflection_operation_encode_action

// ::reflection::operation::encode::action_struct< key_type, output_type, qualificator_name>::typedef_type

#include "../../property/property.hpp"
#include "../../type/trait.hpp"


namespace reflection
 {
  namespace operation
   {
    namespace encode
     {

      template
       <
         typename output_name
        ,typename    key_name = std::string
        ,template  < typename > class qualificator_name = std::add_const
        ,typename    report_name = bool
       >
       struct action_struct
        {
         public:
           typedef  output_name       output_type;
           typedef     key_name          key_type;
           typedef     report_name    report_type;

           typedef ::reflection::property::pure_class                property_type;

           typedef typename qualificator_name< property_type >::type                       property_qualified_type;
           typedef typename std::add_lvalue_reference< property_qualified_type >::type     property_qualified_reference_type;

           typedef std::function< report_type ( output_type &, key_type const&, property_qualified_reference_type ) > function_type;

           static function_type const&  always_false()
            {
             static function_type s_false = []( output_type &, key_type const&, property_qualified_reference_type ){ return report_type(false); };
             return s_false;
            }

           static function_type const& always_true()
            {
             static function_type s_true = []( output_type &, key_type const&, property_qualified_reference_type ){ return report_type(true); };
             return s_true;
            }
       };

     }
   }
 }

#endif
