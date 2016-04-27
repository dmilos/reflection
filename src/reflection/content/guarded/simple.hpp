#ifndef reflection_content_guarded_simple_hpp
#define reflection_content_guarded_simple_hpp
 // ::reflection::content::guarded::simple_class<data_name>
 // ::reflection::content::guarded::simple( )

#include "../mutate/simple.hpp"
#include "../inspect/simple.hpp"


#include "./basic.hpp"

namespace reflection
 {
  namespace content
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
       struct simple_class
        : public ::reflection::content::mutate::simple_class< data_name,model_name,report_name >
        , public ::reflection::content::inspect::simple_class< data_name,image_name >
        {
         public:
           typedef   data_name    data_type;
           typedef  model_name   model_type;
           typedef  image_name   image_type;
           typedef report_name  report_type;

           typedef  data_name  storage_type;     //!< By design

           typedef ::reflection::content::mutate::simple_class< data_name,model_name,report_name >  mutate_type;
           typedef ::reflection::content::inspect::simple_class< data_name,image_name >             inspect_type;

           typedef typename mutate_type::assigner_type  assigner_type;
           typedef typename inspect_type::retriever_type  retriever_type;

           typedef ::reflection::content::guarded::basic_class<data_name,image_name,model_name,storage_type,assigner_type, retriever_type, report_name  > typedef_type;

           static typedef_type make( void )                 { return typedef_type( ); }
           static typedef_type make( data_type const& value_param )
            {
             return typedef_type( value_param );
            }
        };

      /*template
       <
       >
       struct simple_class<void>
        //: S_storage::GC_simple<data_name>::T_direct
        {
         //! @todo
         //typedef void     data_type;

         //static typedef_type make( void ){ return typedef_type(); }
        };*/
      template
       <
         typename data_name
        ,typename model_name  =  data_name const&
        ,typename image_name  =  data_name const&
        ,typename report_name = bool
       >
       inline
       typename ::reflection::content::guarded::simple_class<data_name, model_name, image_name, report_name >::typedef_type
       simple()
        {
         typedef ::reflection::content::guarded::simple_class<data_name, model_name, image_name, report_name> simple_type;
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
       typename ::reflection::content::guarded::simple_class<data_name, model_name, image_name, report_name >::typedef_type
       simple( data_name const& data_param )
        {
         typedef ::reflection::content::guarded::simple_class<data_name, model_name, image_name, report_name> simple_type;
         return simple_type::make( data_param );
        }

     }
   }
 }

#endif

