#ifndef reflection_content_exposed_simple_hpp
#define reflection_content_exposed_simple_hpp
 // ::reflection::content::exposed::simple_struct<data_name>
 // ::reflection::content::exposed::simple( )

#include "../direct/simple.hpp"
#include "../mutate/simple.hpp"


#include "./basic.hpp"

namespace reflection
 {
  namespace content
   {
    namespace exposed
     {

      template
       <
         typename data_name
        ,typename original_name  = data_name &
        ,typename model_name     = data_name const&
       >
       struct simple_struct
        : public ::reflection::content::direct::simple_struct< data_name,original_name >
        , public ::reflection::content::mutate::simple_struct< data_name, model_name >
        {
         public:
           typedef   data_name       data_type;
           typedef  original_name   model_type;
           typedef  model_name      image_type;

           typedef  data_name  storage_type;     //!< By design

           typedef ::reflection::property::direct::simple_struct< data_name,original_name>   direct_type;
           typedef ::reflection::property::mutate::simple_struct< data_name,model_name >             mutate_type;

           typedef typename direct_type::extractor_type  extractor_type;
           typedef typename mutate_type::retriever_type retriever_type;

           typedef ::reflection::content::exposed::basic_class<data_name,original_name,model_name,storage_type,extractor_type,retriever_type > typedef_type;

           static typedef_type make( void )                 { return typedef_type( ); }
           static typedef_type make( data_type const& value_param ){ return typedef_type( value_param ); }
        };

      /*template
       <
       >
       struct simple_struct<void>
        //: S_storage::GC_simple<data_name>::T_direct
        {
         //! @todo
         //typedef void     data_type;

         //static typedef_type make( void ){ return typedef_type(); }
        };*/

      template
       <
         typename data_name
        ,typename original_name  =  data_name &
        ,typename model_name     =  data_name const&
       >
       inline
       typename ::reflection::content::exposed::simple_struct<data_name, original_name, model_name >::typedef_type
       simple()
        {
         typedef ::reflection::content::exposed::simple_struct<data_name, original_name, model_name > simple_type;
         return simple_type::make();
        }

      template
       <
         typename data_name
        ,typename original_name  =  data_name &
        ,typename model_name     =  data_name const&
       >
       inline
       typename ::reflection::content::exposed::simple_struct<data_name, original_name, model_name >::typedef_type
       simple( data_name const& data_param )
        {
         typedef ::reflection::content::exposed::simple_struct<data_name, original_name, model_name > simple_type;
         return simple_type::make( data_param );
        }

     }
   }
 }

#endif

