#ifndef reflection_content_direct_simple_hpp
#define reflection_content_direct_simple_hpp
 // ::reflection::content::direct::simple_class<data_name>
 // ::reflection::content::direct::simple( )

#include "../../property/direct/simple.hpp"

#include "./basic.hpp"

namespace reflection
 {
  namespace content
   {
    namespace direct
     {

      template
       <
         typename data_name
        ,typename original_name =  data_name &
       >
       struct simple_class
        : public ::reflection::property::direct::simple_class< data_name,original_name >
        {
         typedef data_name          data_type;
         typedef original_name  original_type;

         typedef ::reflection::property::direct::simple_class< data_name, original_name >  simple_type;

         typedef typename simple_type::extractor_type extractor_type;

         typedef ::reflection::content::direct::basic_class<data_name,original_type,data_name,extractor_type> typedef_type;

         static typedef_type make( void )                 { return typedef_type( ); }
         static typedef_type make( data_type const& value_param ){ return typedef_type( value_param ); }
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
       >
       inline
       typename ::reflection::content::direct::simple_class<data_name, data_name& >::typedef_type
       simple( data_name const& data_param )
        {
         typedef ::reflection::content::direct::simple_class<data_name, data_name& > simple_type;
         return simple_type::make( data_param );
        }

     }
   }
 }

#endif


