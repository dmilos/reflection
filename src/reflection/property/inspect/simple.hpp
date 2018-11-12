#ifndef reflection_property_inspect_simple
#define reflection_property_inspect_simple

// ::reflection::property::inspect::simple_struct<data_name,image_name>
// ::reflection::property::inspect::simple<data_name>( data_name const& )

#include "./basic.hpp"

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
       struct simple_struct
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

         typedef ::reflection::property::inspect::basic_class< image_type, storage_type, retriever_type > typedef_type;

         static typedef_type make( ){ return typedef_type( ); }
         static typedef_type make( storage_type const& storage_param ){ return typedef_type( storage_param ); }
        };

      template
       <
         typename data_name
       >
       inline
       typename ::reflection::property::inspect::simple_struct< data_name, data_name const& >::typedef_type
       simple()
        {
         typedef ::reflection::property::inspect::simple_struct< data_name, data_name const& > simple_type; 
         return simple_type::make();
        }

      template
       <
         typename data_name
       >
       inline
       typename ::reflection::property::inspect::simple_struct< data_name, data_name const& >::typedef_type
       simple( data_name const& data_param )
        {
         typedef ::reflection::property::inspect::simple_struct< data_name, data_name const& >simple_type;
         return simple_type::make( data_param );
        }

      }
    }
  }

#endif
