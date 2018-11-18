#ifndef reflection_property_mutate_base_pure
#define reflection_property_mutate_base_pure

// ::reflection::property::mutate::base_class<base_name,derived_name>
// ::reflection::property::mutate::base<base_name,derived_name>

#include "./basic.hpp"

#include "../base/distinctive.hpp"

namespace reflection
 {
  namespace property
   {
    namespace mutate
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

            typedef base_type const&   model_type;

            typedef class assigner_class
             {
              public:
                explicit assigner_class( )
                 {
                 }
                report_type operator()( storage_type & carrier_param, model_type input_param )const
                 {
                  dynamic_cast< base_type & >( *carrier_param ) = input_param ;
                  return  report_type( true );
                 }
             } assigner_type;

           typedef ::reflection::property::mutate::basic_class< model_type, storage_type, assigner_type, report_type >      typedef_type;

           static typedef_type make( storage_type const& carrier_param )
            {
             return typedef_type( carrier_param, assigner_type( ) );
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
        , public ::reflection::property::mutate::_internal::base_struct<base_name,derived_name,storage_name,report_name>::typedef_type
        {
         public:
          typedef          ::reflection::property::base::distinctive_class<base_name,derived_name>                      distinctive_type;
          typedef typename ::reflection::property::mutate::_internal::base_struct<base_name,derived_name,storage_name,report_name>::typedef_type mutate_type;

          using mutate_type::mutate_type;

        };


        template
         <
           typename base_name
          ,typename derived_name
          ,typename storage_name
          ,typename report_name   = bool
         >
         ::reflection::property::mutate::base_class<base_name,derived_name,storage_name,report_name>
         base( storage_name const& carrier_param )
          {
           return ::reflection::property::mutate::base_class<base_name,derived_name,storage_name,report_name>( carrier_param );
          }


     }
   }
 }

#endif
