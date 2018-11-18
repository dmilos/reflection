#ifndef reflection_property_variable_base_pure
#define reflection_property_variable_base_pure

// ::reflection::property::variable::base_class<base_name,derived_name>
// ::reflection::property::variable::base<base_name,derived_name>

#include "../direct/base.hpp"
#include "../inspect/base.hpp"

#include "../base/distinctive.hpp"

#include "./basic.hpp"

namespace reflection
 {
  namespace property
   {
    namespace variable
     {

      namespace _internal
       {

        template
         <
           typename base_name
          ,typename derived_name
          ,typename storage_name
         >
        struct base_struct
         {
          public:
            typedef base_name              base_type;
            typedef derived_name        derived_type;
            typedef storage_name        storage_type;

            typedef ::reflection::property::direct::_internal::base_struct<base_type,derived_type,storage_type>          direct_type;
            typedef ::reflection::property::inspect::_internal::base_struct< base_type, derived_type, storage_type >    inspect_type;

            typedef typename  direct_type::original_type   original_type;
            typedef typename  inspect_type::image_type        image_type;

            typedef typename  direct_type::extractor_class   extractor_type;
            typedef typename inspect_type::retriever_type   retriever_type;

            typedef ::reflection::property::variable::basic_class <original_type, image_type, storage_name, extractor_type, retriever_type >      typedef_type;

            static typedef_type make( storage_type const& carrier_param )
             {
              return typedef_type( carrier_param );
             }
          };

       }


      template
       <
         typename base_name
        ,typename derived_name
        ,typename storage_name
       >
       class base_class
        : public ::reflection::property::base::distinctive_class<base_name,derived_name>
        , public ::reflection::property::variable::_internal::base_struct<base_name,derived_name,storage_name>::typedef_type
        {
         public:
          typedef          ::reflection::property::base::distinctive_class<base_name,derived_name>                      distinctive_type;
          typedef typename ::reflection::property::variable::_internal::base_struct<base_name,derived_name,storage_name>::typedef_type variable_type;

          using variable_type::variable_type;
        };


      template
       <
         typename base_name
        ,typename derived_name
        ,typename storage_name
       >
       ::reflection::property::variable::base_class<base_name,derived_name,storage_name>
       base( storage_name const& carrier_param )
        {
         return ::reflection::property::variable::base_class<base_name,derived_name,storage_name>( carrier_param );
        }

     }
   }
 }

#endif
