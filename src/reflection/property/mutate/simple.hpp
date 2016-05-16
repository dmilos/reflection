#ifndef reflection_property_mutate_simple
#define reflection_property_mutate_simple

// ::reflection::property::mutate::simple< data_name, model_name, report_name >

#include "./base.hpp"

namespace reflection
 {
  namespace property
   {
    namespace mutate
     {

      template
       <
         typename data_name
        ,typename model_name =  data_name const &
        ,typename report_name = bool
       >
       struct simple_struct
        {
         typedef data_name      data_type;
         typedef model_name    model_type;
         typedef report_name  report_type;

         typedef data_name      storage_type;  //!< by design

         typedef class assigner_class
          {
           public:
             explicit assigner_class()
              {
              }

             report_type operator()( storage_type & carrier_param, model_type model_param )const
              {
               carrier_param = model_param;
               return  true;
              }

          } assigner_type;

         typedef ::reflection::property::mutate::base_class< model_type, storage_type, assigner_type, report_name > typedef_type;

         static typedef_type make( ){ return typedef_type( ); }
         static typedef_type make( storage_type const& carrier_param ){ return typedef_type( carrier_param ); }
        };

       /*
      template
       <
       >
       struct simple_struct<void,void>
        {
         typedef void   data_type;
         typedef void   original_type;

         typedef void   storage_type;

         //TODO typedef std::original<data_name>  assigner_type;

         typedef ::reflection::property::mutate::base< void, void, assigner_type > typedef_type;

         static typedef_type make(  ){ return typedef_type( ); }
        };
       */

      template
       <
         typename data_name
        ,typename report_name
       >
       inline
       typename ::reflection::property::mutate::simple_struct< data_name, data_name const &, report_name >::typedef_type
       simple()
        {
         typedef ::reflection::property::mutate::simple_struct< data_name, data_name const& > simple_type;
         return simple_type::make( );
        }

      template
       <
         typename data_name
        ,typename report_name
       >
       inline
       typename ::reflection::property::mutate::simple_struct< data_name, data_name const &, report_name >::typedef_type
       simple( data_name const& data_param )
        {
         typedef ::reflection::property::mutate::simple_struct< data_name, data_name const& > simple_type;
         return simple_type::make( data_param );
        }

      }
    }
  }

#endif
