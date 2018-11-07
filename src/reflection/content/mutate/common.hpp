#ifndef reflection_content_mutate_common_hpp
#define reflection_content_mutate_common_hpp
 // ::reflection::content::mutate::common_struct<data_name, model_name,class_name,storage_name>
 // ::reflection::content::mutate::common( )

#include "../../property/mutate/common.hpp"

#include "./basic.hpp"

namespace reflection
 {
  namespace content
   {
    namespace mutate
     {

      template
       <
         typename identifier_name
        ,typename data_name
        ,typename model_name
        ,typename class_name
        ,typename report_name
       >
       struct common_struct
        : ::reflection::property::mutate::common_struct<data_name, model_name, class_name, report_name >
        {
         public:
           typedef data_name     data_type;
           typedef model_name    model_type;
           typedef class_name    class_type;

           typedef ::reflection::property::mutate::common_struct<data_name,model_name, class_name, report_name > property_type;

           typedef typename property_type::assigner_class  assigner_type;
            typedef typename property_type::storage_type       storage_type;

           typedef ::reflection::content::mutate::basic_class<identifier_name,data_name,model_name,storage_type,assigner_type, report_name>      typedef_type;


           static typedef_type make( storage_type const& storage_param )
           {
            return typedef_type( storage_param, assigner_type( ) );
           }

       };

      template
       <
         typename identifier_name
        ,typename class_name
        ,typename data_name
        ,typename model_name   = data_name const&
        ,typename report_name  = bool
       >
       inline
       typename ::reflection::content::mutate::common_struct<identifier_name,data_name,model_name,class_name,report_name>::typedef_type
       common
        (
          data_name       *storage_param
        )
        {
         typedef ::reflection::content::mutate::common_struct<identifier_name,data_name,model_name,class_name,report_name> common_type;
         return common_type::make( storage_param );
        }

      }
    }
  }

#endif
