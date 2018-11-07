#ifndef reflection_property_mutate_void
#define reflection_property_mutate_void

// ::reflection::property::mutate::void_class< model_name, storage_name, assigner_name, report_name >

#include "./_pure.hpp"
#include "../_carrier.hpp"

 namespace reflection
  {
   namespace property
    {
     namespace mutate
      {

       template
        <
          typename report_name     //= bool
        >
        class void_class
         : virtual public ::reflection::property::mutate::pure_class<void,report_name>
         {
          public:

            typedef report_name     report_type;
            
            typedef void     model_type;

            typedef ::reflection::property::mutate::pure_class<model_type,report_name>  pure_type;

            void_class()
              {
              }

            ~void_class( void ){ }

          public:
            report_type       process( model_type /*model_param*/ )
             {
              return report_type(true);
             }

         };

      }
    }
  }

#endif
