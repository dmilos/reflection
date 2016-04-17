#ifndef reflection_property_guarded_base
#define reflection_property_guarded_base

#include "../mutate/base.hpp"
#include "../inspect/base.hpp"

namespace reflection
 {
  namespace property
   {
    namespace guarded
     {

      template
       <
         typename model_name
        ,typename image_name
        ,typename storage_name    //= type_name
        ,typename assigner_name  //= stl_ext::identity_cast<  type_name const&, storage_name const& >
        ,typename retriever_name  //= stl_ext::identity_cast<  type_name const&, storage_name const& >
        ,typename report_name
       >
       class base_class
        :  public ::reflection::property::mutate::base_class< model_name, storage_name, assigner_name, report_name >
        ,  public ::reflection::property::inspect::base_class< image_name, storage_name, retriever_name >
        {
         public:
           typedef model_name          model_type;
           typedef storage_name      storage_type;
           typedef assigner_name    assigner_type;
           typedef retriever_name  retriever_type;
           typedef report_name        report_type;

           typedef ::reflection::property::_internal::carrier_class<storage_name> carrier_type;

           typedef ::reflection::property::mutate::base_class< model_name,storage_name, assigner_name, report_name  > mutate_type;
           typedef ::reflection::property::inspect::base_class< image_name, storage_name, retriever_name > inspect_type;

                     base_class()
                     {
                     }

            explicit base_class
             (
               storage_type   const& storage_param
              ,assigner_type  const& assigner_param = assigner_type()
              ,retriever_type const& retriever_param = retriever_type()
             )
             :  carrier_type(storage_param )
             ,mutate_type( assigner_param )
             ,inspect_type( retriever_param )
             {
             } ////// /**/

         public:
           using mutate_type::process;
           using mutate_type::assigner;

           using inspect_type::present;
           using inspect_type::retriever;
        };

      }
    }
  }

#endif
