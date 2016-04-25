#ifndef reflection_property_inspect_simple
#define reflection_property_inspect_simple

// reflection::property::inspect::simple_class<data_name,image_name>
// reflection::property::inspect::simple<data_name>( data_name const& )

#include "./base.hpp"

namespace reflection
 {
  namespace property
   {
    namespace inspect
     {

      template
       <
         typename data_name
        ,typename image_name =  data_name const&
       >
       struct simple_class
        {
         typedef data_name      data_type;
         typedef image_name  image_type;

         typedef data_name    storage_type;  //!< by design

         typedef class retriever_class
          {
           public:
             explicit retriever_class( )
              {
              }

             image_type operator()( storage_type const& storage_param )const
              {
               return  storage_param;
              }

          } retriever_type;

         typedef ::reflection::property::inspect::base_class< image_type, storage_type, retriever_type > typedef_type;

         static typedef_type make( storage_type const& storage_param ){ return typedef_type( storage_param ); }
        };

       /*
      template
       <
       >
       struct simple_class<void,void>
        {
         typedef void   data_type;
         typedef void   image_type;

         typedef void   storage_type;

         //TODO typedef std::original<data_name>  retriever_type;

         typedef ::reflection::property::inspect::base< void, void, retriever_type > typedef_type;

         static typedef_type make(  ){ return typedef_type( ); }
        };
       */


      template
       <
         typename data_name
       >
       inline
       typename ::reflection::property::inspect::simple_class< data_name, data_name const& >::typedef_type
       simple( data_name const& data_param )
        {
         return ::reflection::property::inspect::simple_class< data_name, data_name const& >::make( data_param );
        }

      }
    }
  }

#endif
