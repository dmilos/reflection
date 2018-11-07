#ifndef reflection_property_direct_simple
#define reflection_property_direct_simple

// ::reflection::property::direct::simple_struct<data_name,original_name>

#include "./base.hpp"

namespace reflection
 {
  namespace property
   {
    namespace direct
     {

      template
       <
         typename data_name
        ,typename original_name =  data_name &
       >
       struct simple_struct
        {
         typedef data_name      data_type;
         typedef original_name  original_type;

         typedef data_name      storage_type;  //!< by design

         typedef class extractor_class
          {
           public:
             explicit extractor_class()
              {
              }

             original_type operator()( storage_type & carrier_param )const
              {
               return  carrier_param;
              }

          } extractor_type;

         typedef ::reflection::property::direct::base_class< original_type, storage_type, extractor_type > typedef_type;

         static typedef_type make( ){ return typedef_type( ); }
         static typedef_type make( storage_type const& storage_param ){ return typedef_type( storage_param ); }
        };

      template
       <
         typename data_name
        ,typename original_name = data_name & 
       >
       inline
       typename ::reflection::property::direct::simple_struct< data_name, original_name >::typedef_type
       simple()
        {
         typedef ::reflection::property::direct::simple_struct< data_name, original_name > simple_type;
         return simple_type::make();
        }

      template
       <
         typename data_name
        ,typename original_name = data_name & 
       >
       inline
       typename ::reflection::property::direct::simple_struct< data_name, original_name >::typedef_type
       simple( data_name const& data_param )
        {
         typedef ::reflection::property::direct::simple_struct< data_name, original_name > simple_type;
         return simple_type::make( data_param );
        }

      }
    }
  }

#endif
