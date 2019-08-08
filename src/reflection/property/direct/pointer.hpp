#ifndef reflection_property_direct_pointer
#define reflection_property_direct_pointer

// ::reflection::property::direct::pointer_class<data_name, storage_name>

#include "./basic.hpp"
#include "../../type/functor/asterisk.hpp"


namespace reflection
 {
  namespace property
   {
    namespace direct
     {

      namespace _internal
       {

        template
         <
          typename original_name
         ,typename storage_name // = Anything that have: operator original_name*, Can be smart pointer too.
         >
         struct pointer_struct
          {
           typedef original_name     original_type;
           typedef storage_name       storage_type;

           typedef ::reflection::type::functor::asterisk< original_type, storage_name >          extractor_type; //!< By design

           typedef ::reflection::property::direct::basic_class<original_type,storage_type,extractor_type>      typedef_type;

           static typedef_type make( ){ return typedef_type( ); }
           static typedef_type make( storage_type const& storage_param )
            {
             return typedef_type( storage_param, extractor_type{} );
            }
          };

       }

      template
       <
         typename original_name
        ,typename storage_name //!< Anything that have: operator original_name*, Can be smart pointer too.
       >
       class pointer_class
        : public ::reflection::property::direct::_internal::pointer_struct<original_name,storage_name>::typedef_type
        {
         public:
           typedef typename ::reflection::property::direct::_internal::pointer_struct<original_name,storage_name>  basic_type;
           typedef typename basic_type::typedef_type  base_type;

           typedef typename basic_type::extractor_type extractor_type;
           typedef typename basic_type::storage_type     storage_type;

           explicit pointer_class( storage_type   const& storage_param )
            : base_type( storage_param, extractor_type() )
            {
            }

          using base_type::disclose;
        };

      template
       <
          typename   data_name
         ,typename   original_name = data_name &
         ,typename   storage_name  = data_name *
       >
       inline
       typename ::reflection::property::direct::pointer_class<original_name, storage_name>
       pointer
        (
          storage_name const & storage_param
        )
        {
         typedef original_name   original_type;
         typedef storage_name     storage_type;

         typedef ::reflection::property::direct::pointer_class<original_type, storage_type> pointer_type;
         return pointer_type( storage_param );
        }

      }
    }
  }

#endif
