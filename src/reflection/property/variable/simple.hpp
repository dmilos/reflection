#ifndef reflection_property_variable_simple_hpp
#define reflection_property_variable_simple_hpp
 // ::reflection::property::variable::simple_struct<data_name>
 // ::reflection::property::variable::simple( )

#include "../direct/simple.hpp"
#include "../inspect/simple.hpp"


#include "./basic.hpp"

namespace reflection
 {
  namespace property
   {
    namespace variable
     {

      template
       <
         typename data_name
        ,typename original_name  = data_name &
        ,typename image_name     = data_name const&
       >
       struct simple_struct
        : public ::reflection::property::direct::simple_struct< data_name,original_name >
        , public ::reflection::property::inspect::simple_struct< data_name, image_name >
        {
         public:
           typedef   data_name       data_type;
           typedef  original_name   model_type;
           typedef  image_name      image_type;

           typedef  data_name  storage_type;     //!< By design

           typedef ::reflection::property::direct::simple_struct< data_name,original_name>   direct_type;
           typedef ::reflection::property::inspect::simple_struct< data_name,image_name >             inspect_type;

           typedef typename direct_type::extractor_type  extractor_type;
           typedef typename inspect_type::retriever_type retriever_type;

           typedef ::reflection::property::variable::basic_class<original_name,image_name,storage_type,extractor_type,retriever_type > typedef_type;

           static typedef_type make( void )                 { return typedef_type(); }
           static typedef_type make( data_type const& value_param )
            {
             return typedef_type( value_param ); 
            }
        };

      template
       <
         typename data_name
        ,typename original_name  =  data_name &
        ,typename image_name     =  data_name const&
       >
       inline
       typename ::reflection::property::variable::simple_struct<data_name, original_name, image_name >::typedef_type
       simple()
        {
         typedef ::reflection::property::variable::simple_struct<data_name, original_name, image_name > simple_type;
         return simple_type::make( );
        }

      template
       <
         typename data_name
        ,typename original_name  =  data_name &
        ,typename image_name     =  data_name const&
       >
       inline
       typename ::reflection::property::variable::simple_struct<data_name, original_name, image_name >::typedef_type
       simple( data_name const& data_param )
        {
         typedef ::reflection::property::variable::simple_struct<data_name, original_name, image_name > simple_type;
         return simple_type::make( data_param );
        }

     }
   }
 }

#endif

