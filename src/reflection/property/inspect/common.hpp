#ifndef reflection_property_inspect_common
 #define reflection_property_inspect_common

// ::reflection::property::inspect::common_struct<image_name,class_name,storage_name>

 #include "./base.hpp"

namespace reflection
 {
  namespace property
   {
    namespace inspect
     {

      template
       <
         typename    data_name
        ,typename   image_name
        ,typename   class_name
       >
       struct common_struct
        {
         typedef data_name       data_type;
         typedef image_name     image_type;
         typedef class_name     class_type;
         typedef data_name*   storage_type;

         typedef class retriever_class
          {
           public:
             explicit retriever_class( )
              {
              }
             image_type operator()( storage_type const& carrier_param )const
              {
               return *carrier_param;
              }
          } retriever_type;

         typedef ::reflection::property::inspect::base_class<image_name,storage_type,retriever_type>      typedef_type;

         static typedef_type make( storage_type const& carrier_param )
          {
           return typedef_type( carrier_param );
          }

        };

      template
       <
         typename   class_name
        ,typename    data_name
        ,typename   image_name = data_name const &
       >
       inline
       typename ::reflection::property::inspect::common_struct<data_name,image_name,class_name>::typedef_type
       common
        (
          data_name     *carrier_param
        )
        {
         typedef ::reflection::property::inspect::common_struct<data_name,image_name,class_name> common_type;
         return common_type::make( carrier_param );
        }

     }
   }
 }

#endif
