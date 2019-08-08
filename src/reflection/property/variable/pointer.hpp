#ifndef reflection_property_pointer_simple_hpp
#define reflection_property_pointer_simple_hpp
 // ::reflection::property::pointer::simple_struct<data_name>
 // ::reflection::property::pointer::pointer( )

#include "../direct/pointer.hpp"
#include "../inspect/pointer.hpp"


#include "./basic.hpp"

namespace reflection
 {
  namespace property
   {
    namespace variable
     {

      template
       <
          typename original_name
         ,typename image_name
         ,typename storage_name // = Anything that have: operator original_name*, Can be smart pointer too.
       >
       struct pointer_struct
        : public ::reflection::property::direct::_internal::pointer_struct< original_name,storage_name >
        , public ::reflection::property::inspect::_internal::pointer_struct< image_name, image_name >
        {
         public:
           typedef  original_name    original_type;
           typedef     image_name       image_type;
           typedef   storage_name     storage_type;

           typedef ::reflection::property::direct::_internal::pointer_struct< original_name,storage_name>   direct_type;
           typedef ::reflection::property::inspect::_internal::pointer_struct< image_name,storage_name >   inspect_type;

           typedef typename direct_type::extractor_type  extractor_type;
           typedef typename inspect_type::retriever_type retriever_type;

           typedef ::reflection::property::variable::basic_class<original_name,image_name,storage_type,extractor_type,retriever_type > typedef_type;

           static typedef_type make( void )                 { return typedef_type(); }
           static typedef_type make( storage_type const& storage_param )
            {
             return typedef_type( storage_param );
            }
        };

      template
       <
         typename data_name
        ,typename original_name  =  data_name &
        ,typename image_name     =  data_name const&
        ,typename storage_name   = data_name *
       >
       inline
       typename ::reflection::property::variable::pointer_struct<original_name, image_name, storage_name >::typedef_type
       pointer()
        {
         typedef ::reflection::property::variable::pointer_struct< original_name, image_name, storage_name > pointer_type;
         return pointer_type::make( );
        }

      template
       <
         typename data_name
        ,typename original_name  =  data_name &
        ,typename image_name     =  data_name const&
        ,typename storage_name   = data_name *
       >
       inline
       typename ::reflection::property::variable::pointer_struct< original_name, image_name, storage_name >::typedef_type
       pointer        
        (
          storage_name const & storage_param
        )
        {
         typedef ::reflection::property::variable::pointer_struct< original_name, image_name, storage_name > pointer_type;
         return pointer_type::make( storage_param );
        }

     }
   }
 }

#endif
