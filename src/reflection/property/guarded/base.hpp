#ifndef reflection_property_guarded_base_pure
#define reflection_property_guarded_base_pure

// ::reflection::property::guarded::base_class<base_name,derived_name>
// ::reflection::property::guarded::base<base_name,derived_name>

#include "./basic.hpp"

#include "../base/distinctive.hpp"

namespace reflection
 {
  namespace property
   {
    namespace guarded
     {

      namespace _internal
       {

        template
         <
           typename base_name
          ,typename derived_name
          ,typename storage_name
          ,typename report_name
         >
        struct base_struct
         {
          public:
            typedef base_name              base_type;
            typedef derived_name        derived_type;
            typedef storage_name        storage_type;
            typedef report_name          report_type;

            typedef ::reflection::property::inspect::_internal::base_struct<base_type,derived_type,storage_type>          inspect_type;
            typedef ::reflection::property::mutate::_internal::base_struct<base_type,derived_type,storage_type,report_type> mutate_type;

            typedef typename  mutate_type::model_type         model_type;
            typedef typename  inspect_type::image_type   image_type;

            typedef typename  mutate_type::assigner_type   assigner_type;
            typedef typename inspect_type::retriever_type retriever_type;

            typedef ::reflection::property::guarded::basic_class <model_type, image_type, storage_type,assigner_type,retriever_type,report_name>      typedef_type;

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
        ,typename report_name
       >
       class base_class
        : public ::reflection::property::base::distinctive_class<base_name,derived_name>
        , public ::reflection::property::guarded::_internal::base_struct<base_name,derived_name,storage_name,report_name>::typedef_type
        {
         public:
          typedef          ::reflection::property::base::distinctive_class<base_name,derived_name>                      distinctive_type;
          typedef typename ::reflection::property::guarded::_internal::base_struct<base_name,derived_name,storage_name,report_name>::typedef_type guarded_type;

          using guarded_type::guarded_type;
        };


      template
       <
         typename base_name
        ,typename derived_name
        ,typename storage_name
        ,typename report_name
       >
       ::reflection::property::guarded::base_class<base_name,derived_name,storage_name,report_name>
       base( storage_name const& carrier_param )
        {
         return ::reflection::property::guarded::base_class<base_name,derived_name,storage_name,report_name>( carrier_param );
        }

     }
   }
 }

#endif
