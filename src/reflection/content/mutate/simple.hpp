#ifndef reflection_content_mutate_simple_hpp
#define reflection_content_mutate_simple_hpp
 // ::reflection::content::mutate::simple_struct<data_name, model_name,class_name,storage_name>
 // ::reflection::content::mutate::simple( )

#include "../../property/mutate/simple.hpp"

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
        ,typename model_name =  data_name const &
        ,typename report_name = bool
       >
       struct simple_struct
        : public ::reflection::property::mutate::simple_struct< data_name, model_name, report_name >
        {
         typedef data_name      data_type;
         typedef model_name    model_type;
         typedef report_name  report_type;

         typedef data_name  storage_name; //!< By design

         typedef ::reflection::property::mutate::simple_struct< data_name, model_name, report_name >  simple_type;

         typedef typename simple_type::assigner_class assigner_type;

         typedef ::reflection::content::mutate::basic_class<identifier_name,data_name,model_name,storage_name,assigner_type,report_name> typedef_type;

         static typedef_type make( void )                 { return typedef_type( ); }
         static typedef_type make( data_type const& value_param ){ return typedef_type( value_param ); }
        };

      /*template
       <
       >
       struct simple_struct<void>
        //: S_storage::GC_simple<data_name>::T_inspect
        {
         //! @todo
         //typedef void     data_type;

         //static typedef_type make( void ){ return typedef_type(); }
        };*/
      template
       <
         typename identifier_name = std::string
        ,typename data_name
       >
       inline
       typename ::reflection::content::mutate::simple_struct<identifier_name,data_name, data_name const& >::typedef_type
       simple()
        {
         typedef ::reflection::content::mutate::simple_struct<identifier_name,data_name, data_name const& > simple_type;
         return simple_type::make();
        }

      template
       <
         typename identifier_name = std::string
        ,typename data_name
       >
       inline
       typename ::reflection::content::mutate::simple_struct<identifier_name,data_name, data_name const& >::typedef_type
       simple( data_name const& data_param )
        {
         typedef ::reflection::content::mutate::simple_struct<identifier_name,data_name, data_name const& > simple_type;
         return simple_type::make( data_param );
        }

     }
   }
 }

#endif


