#ifndef reflection_property_inspect_common
 #define reflection_property_inspect_common

// ::reflection::property::inspect::common_struct<image_name,class_name,storage_name>

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

           typedef ::reflection::property::inspect::basic_class<image_name,storage_type,retriever_type>      typedef_type;

           static typedef_type make( storage_type const& carrier_param )
            {
             return typedef_type( carrier_param );
            }

          };

       }


      template
       <
         typename    data_name
        ,typename   image_name
        ,typename   class_name
       >
       class common_class
        : public ::reflection::ornament::relation_class
        , public ::reflection::ornament::accessibility_class
        , public ::reflection::ornament::linkage_class
        , public ::reflection::property::inspect::_internal::common_struct<data_name,image_name,class_name>::typedef_type
        {
         public:
          typedef ::reflection::ornament::relation_class relation_type;
          typedef ::reflection::ornament::accessibility_class accessibility_type;
          typedef ::reflection::ornament::linkage_class linkage_type;

          typedef ::reflection::property::inspect::_internal::common_struct<data_name,image_name,class_name>  basic_type;
          typedef typename basic_type::typedef_type  base_type;

          typedef typename basic_type::retriever_type retriever_type;
          typedef typename basic_type::storage_type     storage_type;

          explicit common_class( storage_type   const& storage_param )
            : relation_type( relation_type::member_index )
            , accessibility_type( accessibility_type::default_index )
            , linkage_type( linkage_type::static_index )
            , base_type( storage_param, retriever_type() )
          {
            }

          using base_type::present;
        };


      template
       <
         typename   class_name
        ,typename    data_name
        ,typename   image_name = data_name const &
       >
       inline
       typename ::reflection::property::inspect::common_class<data_name,image_name,class_name>
       common
        (
          data_name     *carrier_param
        )
        {
         typedef ::reflection::property::inspect::common_class<data_name,image_name,class_name> common_type;
         return common_type( carrier_param );
        }

     }
   }
 }

#endif
