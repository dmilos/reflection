#ifndef reflection_property_inspect_pointer
 #define reflection_property_inspect_pointer

// ::reflection::property::inspect::pointer_struct<image_name,storage_name>

 #include "./basic.hpp"

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
           typename      data_name
         >
         struct pointer_struct
          {
           typedef data_name            data_type;
           typedef data_name const&    image_type;
           typedef data_name const *  storage_type;

           typedef class retriever_class
            {
             public:
               explicit retriever_class()
                {
                }
               image_type operator()( storage_type const& carrier_param )const
                {
                 return *carrier_param;
                }

            } retriever_type;

           typedef ::reflection::property::inspect::basic_class<image_type,storage_type,retriever_type>      typedef_type;

           static typedef_type make( storage_type const& carrier_param )
            {
             return typedef_type( carrier_param, retriever_type() );
            }
          };

       }

      template
       <
         typename    data_name
       >
       class pointer_class
        : public ::reflection::property::inspect::_internal::pointer_struct<data_name>::typedef_type
        {
         public:

          typedef typename ::reflection::property::inspect::_internal::pointer_struct<data_name>  basic_type;
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
       >
       inline
       typename ::reflection::property::inspect::pointer_class<data_name>::typedef_type
       pointer
        (
          data_name           const* carrier_param
        )
        {
         typedef ::reflection::property::inspect::pointer_class<data_name> pointer_type;
         return pointer_type::make( carrier_param );
        }

     }
   }
 }

#endif
