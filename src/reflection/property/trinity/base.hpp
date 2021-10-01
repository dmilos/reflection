#ifndef reflection_property_trinity_base_pure
#define reflection_property_trinity_base_pure

// ::reflection::property::trinity::base_class<base_name,derived_name>
// ::reflection::property::trinity::base<base_name,derived_name>

#include "./basic.hpp"

#include "../base/distinctive.hpp"

namespace reflection
 {
  namespace property
   {
    namespace trinity
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

            typedef ::reflection::property::direct::_internal::base_struct<base_type,derived_type,storage_type>          direct_type;
            typedef ::reflection::property::inspect::_internal::base_struct<base_type,derived_type,storage_type>          inspect_type;
            typedef ::reflection::property::mutate::_internal::base_struct<base_type,derived_type,storage_type,report_type> mutate_type;

            typedef typename  direct_type::original_type         original_type;
            typedef typename  mutate_type::model_type         model_type;
            typedef typename  inspect_type::image_type   image_type;

              typedef typename  direct_type::extractor_class    extractor_type;
              typedef typename  mutate_type::assigner_class      assigner_type;
              typedef typename inspect_type::retriever_class    retriever_type;


            typedef ::reflection::property::trinity::basic_class< original_type, model_type, image_type, storage_type, extractor_type, assigner_type, retriever_type, report_name>      typedef_type;

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
        , public ::reflection::property::trinity::_internal::base_struct<base_name,derived_name,storage_name,report_name>::typedef_type
        {
         public:
          typedef          ::reflection::property::base::distinctive_class<base_name,derived_name>                      distinctive_type;
          typedef typename ::reflection::property::trinity::_internal::base_struct<base_name,derived_name,storage_name,report_name>::typedef_type trinity_type;

          using trinity_type::trinity_type;
        };


      template
       <
         typename base_name
        ,typename derived_name
        ,typename storage_name
        ,typename report_name
       >
       ::reflection::property::trinity::base_class<base_name,derived_name,storage_name,report_name>
       base( storage_name const& carrier_param )
        {
         return ::reflection::property::trinity::base_class<base_name,derived_name,storage_name,report_name>( carrier_param );
        }

     }
   }
 }

#endif
