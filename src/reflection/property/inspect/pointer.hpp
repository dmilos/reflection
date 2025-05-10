#ifndef reflection_property_inspect_pointer
 #define reflection_property_inspect_pointer

// ::reflection::property::inspect::pointer_struct<image_name,storage_name>

#include "./basic.hpp"
#include "../../type/functor/asterisk.hpp"


namespace reflection
 {
  namespace property
   {
    namespace inspect
     {

      namespace _internal
       {

        template
         <
           typename image_name
          ,typename storage_name // = Anything that have: operator image_name*, Can be smart pointer too.
         >
         struct pointer_struct
          {
           typedef image_name           image_type;
           typedef storage_name       storage_type;

           typedef ::reflection::type::functor::asterisk< image_type, storage_name >          retriever_type; //!< By design

           typedef ::reflection::property::inspect::basic_class<image_type,storage_type,retriever_type>      typedef_type;

           static typedef_type make( ){ return typedef_type( ); }
           static typedef_type make( storage_type const& carrier_param )
            {
             return typedef_type( carrier_param, retriever_type{} );
            }
          };

       }

      template
       <
         typename image_type
        ,typename storage_name //!< Anything that have: operator image_type*, Can be smart pointer too.
       >
       class pointer_class
        : public ::reflection::property::inspect::_internal::pointer_struct<image_type,storage_name>::typedef_type
        {
         public:
           typedef typename ::reflection::property::inspect::_internal::pointer_struct< image_type,storage_name>  basic_type;
           typedef typename basic_type::typedef_type  base_type;

           typedef typename basic_type::retriever_type retriever_type;
           typedef typename basic_type::storage_type     storage_type;

           explicit pointer_class( storage_type   const& storage_param )
            : base_type( storage_param, retriever_type() )
            {
            }

          using base_type::present;
        };

      template
       <
         typename   data_name
        ,typename   image_name    = data_name const& // Expected model
        ,typename   storage_name  = data_name const* // Expected model
       >
       inline
       typename ::reflection::property::inspect::pointer_class< image_name, storage_name>::typedef_type
       pointer
        (
          storage_name  const & storage_param
        )
        {
         typedef image_name   image_type;
         typedef storage_name storage_type;

         typedef ::reflection::property::inspect::pointer_class< image_type, storage_type> pointer_type;
         return pointer_type( storage_param );
        }

     }
   }
 }

#endif
