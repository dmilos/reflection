#ifndef reflection_content_trinity_common_hpp
#define reflection_content_trinity_common_hpp
 // ::reflection::content::trinity::common_struct<data_name>
 // ::reflection::content::trinity::common( )

#include "../direct/common.hpp"
#include "../mutate/common.hpp"
#include "../inspect/common.hpp"


#include "./basic.hpp"

namespace reflection
 {
  namespace content
   {
    namespace trinity
     {

      template
       <
         typename  identifier_name
        ,typename        data_name
        ,typename original_name  //= data_name &
        ,typename model_name     //= data_name const&
        ,typename image_name     //= data_name const&
        ,typename class_name
        ,typename report_name = bool
       >
       struct common_struct
        : public ::reflection::content::direct::common_struct<  identifier_name, data_name,original_name,class_name >
        , public ::reflection::content::mutate::common_struct<  identifier_name, data_name,model_name,class_name,report_name >
        , public ::reflection::content::inspect::common_struct<  identifier_name, data_name,image_name,class_name >
        {
         public:
           typedef       data_name        data_type;
           typedef   original_name    original_type;
           typedef      model_name       model_type;
           typedef      image_name       image_type;
           typedef      class_name       class_type;
           typedef     report_name      report_type;

           typedef ::reflection::content::direct::common_struct<  identifier_name, data_name,original_name,class_name >  direct_type;
           typedef ::reflection::content::mutate::common_struct<  identifier_name,  data_name,   model_name,class_name,report_name >  mutate_type;
           typedef ::reflection::content::inspect::common_struct< identifier_name, data_name,   image_name,class_name >            inspect_type;

           typedef typename direct_type::storage_type       storage_type;

           typedef typename direct_type::extractor_type   extractor_type;
           typedef typename mutate_type::assigner_type     assigner_type;
           typedef typename inspect_type::retriever_type  retriever_type;

           typedef ::reflection::content::trinity::basic_class< identifier_name, data_name,original_type,image_name,model_name,storage_type,extractor_type, assigner_type, retriever_type, report_name  > typedef_type;

           static typedef_type make( storage_type const& storage_param )
            {
             return typedef_type( storage_param, extractor_type(),assigner_type(), retriever_type() );
            }
        };

      template
       <
         typename  identifier_name
        ,typename class_name
        ,typename     data_name
        ,typename original_name   = data_name &
        ,typename model_name      = data_name const&
        ,typename image_name      = data_name const&
        ,typename report_name     = bool
       >
       inline
       typename ::reflection::content::trinity::common_struct< identifier_name, data_name,original_name, model_name, image_name,class_name,report_name>::typedef_type
       common
        (
         data_name       *storage_param
        )
        {
         typedef ::reflection::content::trinity::common_struct< identifier_name, data_name,original_name,model_name,image_name,class_name,report_name> common_type;
         return common_type::make( storage_param );
        }


     }
   }
 }

#endif
