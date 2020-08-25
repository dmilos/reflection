#ifndef reflection_operation_transfer_restore
#define reflection_operation_transfer_restore

// ::reflection::operation::transfer::restore_class<output_name,key_name,identifier_name>

#include "../../content/category.hpp"
#include "../../property/structure.hpp"

#include "../../type/container/container.hpp"
#include "./action.hpp"

#include "../../type/trait.hpp"


namespace reflection
 {
  namespace operation
   {
    namespace transfer
     {

      template
       <
         typename          input_name
        ,typename             key_name = std::string
        ,typename      identifier_name = std::string
        ,typename          report_name = bool
        ,template <typename,typename> class container_name  = ::reflection::type::container::map
       >
       class restore_class
        {
         public:
           typedef      input_name        output_type;
           typedef         key_name           key_type;
           typedef  identifier_name    identifier_type;
           typedef      report_name        report_type;
           typedef ::reflection::operation::transfer::restore_class<input_name,key_name,identifier_name,report_name, container_name> this_type;

           typedef ::reflection::ornament::category_class<identifier_type>            category_type;
           typedef ::reflection::property::pure_class                                 property_type;
           typedef ::reflection::property::structure_class<key_type,container_name>  structure_type;

           typedef ::reflection::type::name::identificatorX< identifier_name  > identificator_type;

         public:
           restore_class()
            {
            }

         public:
           report_type read
            (
              input_type                        &   output_param
              // TODO
            )const
            {
             // TODO
            }

       };

     }
   }
 }

#endif
