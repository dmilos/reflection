#ifndef reflection_property_direct_simple
#define reflection_property_direct_simple

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
       struct simple_class
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

         typedef ::reflection::property::direct::base< original_type, storage_type, extractor_type > typedef_type;

         static typedef_type make( storage_type const& P_carrier ){ return typedef_type( P_carrier ); }
        };

       /*
      template
       <
       >
       struct simple_class<void,void>
        {
         typedef void   data_type;
         typedef void   original_type;

         typedef void   storage_type;

         //TODO typedef std::original<data_name>  extractor_type;

         typedef ::reflection::property::direct::base< void, void, extractor_type > typedef_type;

         static typedef_type make(  ){ return typedef_type( ); }
        };
       */


      template
       <
         typename data_name
       >
       inline
       typename ::reflection::property::direct::simple_class< data_name, data_name & >::typedef_type
       simple( data_name const& P_data )
        {
         return ::reflection::property::direct::simple_class< data_name, data_name & >::make( P_data );
        }

      }
    }
  }

#endif
