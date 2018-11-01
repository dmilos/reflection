#ifndef reflection_property_trinity_base
#define reflection_property_trinity_base

// ::reflection::property::trinity::base_class


#include "./_pure.hpp"

#include "../direct/base.hpp"
#include "../mutate/base.hpp"
#include "../inspect/base.hpp"

namespace reflection
 {
  namespace property
   {
    namespace trinity
     {

      template
       <
         typename  original_name
        ,typename     model_name
        ,typename     image_name
        ,typename   storage_name
        ,typename extractor_name  //= stl_ext::identity_cast<  data_name const&, storage_name const& >
        ,typename  assigner_name  //= stl_ext::identity_cast<  data_name const&, storage_name const& >
        ,typename retriever_name  //= stl_ext::identity_cast<  data_name const&, storage_name const& >
        ,typename report_name
       >
       class base_class
        :  virtual public ::reflection::property::trinity::pure_class<  original_name, model_name, image_name, report_name >
        ,          public ::reflection::property::direct::base_class<   original_name, storage_name, extractor_name >
        ,          public ::reflection::property::mutate::base_class<      model_name, storage_name, assigner_name, report_name >
        ,          public ::reflection::property::inspect::base_class<     image_name, storage_name, retriever_name >
        {
         public:
           typedef original_name    original_type;
           typedef model_name          model_type;
           typedef image_name          image_type;
           typedef storage_name      storage_type;
           typedef extractor_name  extractor_type;
           typedef assigner_name    assigner_type;
           typedef retriever_name  retriever_type;
           typedef report_name        report_type;

           typedef ::reflection::property::_internal::carrier_class<storage_name> carrier_type;

           typedef ::reflection::property::trinity::pure_class< original_name, model_name, image_name,report_name>       pure_type;

           typedef ::reflection::property::direct::base_class< original_name, storage_name, extractor_name >             direct_type;
           typedef ::reflection::property::mutate::base_class< model_name,storage_name, assigner_name, report_name  >   mutate_type;
           typedef ::reflection::property::inspect::base_class< image_name, storage_name, retriever_name >             inspect_type;


                    base_class()
                     {
                     }

           explicit base_class
             (
               extractor_type     const&  extractor_param  =   extractor_type()
              ,assigner_type      const&  assigner_param   =    assigner_type()
              ,retriever_type     const& retriever_param   =   retriever_type()
             )
             : direct_type(    extractor_param )
             , mutate_type(  assigner_param )
             ,inspect_type( retriever_param )
             {
             }

           explicit base_class
            (
              storage_type   const&    storage_param
             ,extractor_type const&  extractor_param   =  extractor_type()
             ,assigner_type  const&  assigner_param   =    assigner_type()
             ,retriever_type const& retriever_param   =   retriever_type()
            )
            :carrier_type(      storage_param )
            , direct_type(    extractor_param )
            , mutate_type(     assigner_param )
            ,inspect_type(    retriever_param )
            {
            }

         public:
           using direct_type::disclose;
           using direct_type::extractor;

           using mutate_type::process;
           using mutate_type::assigner;

           using inspect_type::present;
           using inspect_type::retriever;
        };

      }
    }
  }

#endif
