#ifndef reflection_property_guarded_simple_hpp
#define reflection_property_guarded_simple_hpp
 // ::reflection::property::guarded::simple_struct<data_name>
 // ::reflection::property::guarded::simple( )

#include "../mutate/simple.hpp"
#include "../inspect/simple.hpp"


#include "./basic.hpp"

namespace reflection
 {
  namespace property
   {
    namespace guarded
     {

      template
       <
         typename data_name
        ,typename model_name  = data_name const&
        ,typename image_name  = data_name const&
        ,typename report_name = bool
       >
       struct simple_struct
        : public ::reflection::property::mutate::simple_struct< data_name,model_name,report_name >
        , public ::reflection::property::inspect::simple_struct< data_name,image_name >
        {
         public:
           typedef   data_name    data_type;
           typedef  model_name   model_type;
           typedef  image_name   image_type;
           typedef report_name  report_type;

           typedef  data_name  storage_type;     //!< By design

           typedef ::reflection::property::mutate::simple_struct< data_name,model_name,report_name >  mutate_type;
           typedef ::reflection::property::inspect::simple_struct< data_name,image_name >             inspect_type;

           typedef typename mutate_type::assigner_type  assigner_type;
           typedef typename inspect_type::retriever_type  retriever_type;

           typedef ::reflection::property::guarded::basic_class<model_name,image_name,storage_type,assigner_type,retriever_type,report_name> typedef_type;

           static typedef_type make( void )                 { return typedef_type( ); }
           static typedef_type make( data_type const& value_param )
            {
             return typedef_type( value_param );
            }
        };

      template
       <
         typename data_name
        ,typename model_name  =  data_name const&
        ,typename image_name  =  data_name const&
        ,typename report_name = bool
       >
       inline
       typename ::reflection::property::guarded::simple_struct<data_name, model_name, image_name, report_name >::typedef_type
       simple()
        {
         typedef ::reflection::property::guarded::simple_struct<data_name, model_name, image_name, report_name> simple_type;
         return simple_type::make();
        }

      template
       <
         typename data_name
        ,typename model_name  =  data_name const&
        ,typename image_name  =  data_name const&
        ,typename report_name = bool
       >
       inline
       typename ::reflection::property::guarded::simple_struct<data_name, model_name, image_name, report_name >::typedef_type
       simple( data_name const& data_param )
        {
         typedef ::reflection::property::guarded::simple_struct<data_name, model_name, image_name, report_name> simple_type;
         return simple_type::make( data_param );
        }

     }
   }
 }

#endif

