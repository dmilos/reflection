#ifndef reflection_property_inspect_simple
#define reflection_property_inspect_simple

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
        ,typename original_name =  data_name &
       >
       struct simple_class
        {
         typedef data_name      data_type;
         typedef original_name  original_type;

         typedef data_name const&     carrier_type;  //!< by design

         typedef class convert_class
          {
           public:
             explicit convertor_class( )
              {
              }

             original_type operator()( carrier_type const& carrier_param )const
              {
               return  carrier_param;
              }

          } convert_type;

         typedef ::reflection::property::inspect::base< original_type, carrier_type, convert_type > typedef_type;

         static typedef_type make( carrier_type const& P_carrier ){ return typedef_type( P_carrier ); }
        };

       /*
      template
       <
       >
       struct simple_class<void,void>
        {
         typedef void   data_type;
         typedef void   original_type;

         typedef void   carrier_type;

         //TODO typedef std::original<data_name>  convert_type;

         typedef ::reflection::property::inspect::base< void, void, convert_type > typedef_type;

         static typedef_type make(  ){ return typedef_type( ); }
        };
       */


      template
       <
         typename data_name
       >
       inline
       typename ::reflection::property::inspect::simple_class< data_name, data_name & >::typedef_type
       simple( data_name const& P_data )
        {
         return ::reflection::property::inspect::simple_class< data_name, data_name & >::make( P_data );
        }

      }
    }
  }

#endif
