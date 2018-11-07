#ifndef reflection_content_exposed_common_hpp
#define reflection_content_exposed_common_hpp
 // ::reflection::content::exposed::common_class<data_name>
 // ::reflection::content::exposed::common( )

#include "../direct/common.hpp"
#include "../mutate/common.hpp"


#include "./basic.hpp"

namespace reflection
 {
  namespace content
   {
    namespace exposed
     {

      template
       <
         typename identifier_name
        ,typename data_name
        ,typename original_name  //= data_name const&
        ,typename model_name  //= data_name const&
        ,typename class_name
        ,typename report_name
       >
       struct common_struct
        : public ::reflection::content::direct::common_struct< identifier_name, data_name,original_name,class_name>
        , public ::reflection::content::mutate::common_struct< identifier_name,data_name,model_name,class_name, report_name >
        {
         public:
           typedef      data_name         data_type;
           typedef  original_name     original_type;
           typedef     model_name        model_type;
           typedef     class_name        class_type;
           typedef     report_name      report_type;

           typedef ::reflection::content::direct::common_struct< identifier_name,data_type,original_type,class_type>  direct_type;
           typedef ::reflection::content::mutate::common_struct< identifier_name, data_type,model_type,class_type,report_type >    mutate_type;

           typedef typename direct_type::storage_type       storage_type;

           typedef typename direct_type::extractor_type  extractor_type;
           typedef typename mutate_type::assigner_type    assigner_type;

           typedef ::reflection::content::exposed::basic_class<identifier_name,data_type,original_type,model_type,storage_type,extractor_type,assigner_type,report_type > typedef_type;


           static typedef_type make( storage_type const& storage_param )
            {
             return typedef_type( storage_param, extractor_type(), assigner_type() );
            }
        };

      template
       <
         typename identifier_name
        ,typename      class_name
        ,typename       data_name
        ,typename   original_name  = data_name &
        ,typename      model_name  = data_name const&
        ,typename     report_name = bool
       >
       inline
       typename ::reflection::content::exposed::common_struct<identifier_name,data_name,original_name,model_name,class_name,report_name>::typedef_type
       common
        (
          data_name       *storage_param
        )
        {
         typedef ::reflection::content::exposed::common_struct<identifier_name,data_name,original_name,model_name,class_name,report_name> member_type;
         return member_type::make( storage_param );
        }

     }
   }
 }

#endif