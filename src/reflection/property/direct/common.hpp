#ifndef reflection_property_direct_common
#define reflection_property_direct_common

// ::reflection::property::direct::common_struct<original_name,class_name,storage_name>

 #include "./basic.hpp"

 #include "../../ornament/relation.hpp"
 #include "../../ornament/accessibility.hpp"
 #include "../../ornament/linkage.hpp"



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
           typename     data_name
          ,typename original_name // = data_name &
          ,typename    class_name
         >
         struct common_struct
          {
           typedef data_name            data_type;
           typedef original_name    original_type;
           typedef class_name          class_type;
           typedef data_type *       storage_type;

           typedef data_type         *pointer_type; //!< By design

           typedef class extractor_class
            {
             public:
               explicit extractor_class()
                {
                }

               original_type operator()( storage_type & carrier_param )const
                {
                 return  *carrier_param;
                }

             private:
            } extractor_type;

           typedef ::reflection::property::direct::basic_class< original_type, storage_type, extractor_type >      typedef_type;

           static typedef_type make( storage_type const& carrier_param )
            {
             return typedef_type( carrier_param, extractor_type() );
            }

          };

       }

      template
       <
         typename     data_name
        ,typename  original_name // = data_name &
        ,typename    class_name
       >
       class common_class
        : public ::reflection::ornament::relation_class
        , public ::reflection::ornament::accessibility_class
        , public ::reflection::ornament::linkage_class
        , public ::reflection::property::direct::_internal::common_struct<data_name,original_name,class_name>::typedef_type
        {
         public:
          typedef ::reflection::ornament::relation_class relation_type;
          typedef ::reflection::ornament::accessibility_class accessibility_type;

          typedef typename ::reflection::property::direct::_internal::common_struct<data_name,original_name,class_name>  basic_type;
          typedef typename basic_type::typedef_type  base_type;

          typedef typename basic_type::extractor_type extractor_type;
          typedef typename basic_type::storage_type     storage_type;

          explicit common_class( storage_type   const& storage_param )
            : relation_type( relation_type::member_index )
            , accessibility_type( accessibility_type::default_index )
            , base_type( storage_param, extractor_type() )
            {
            }

          using base_type::disclose;
        };


      template
       <
         typename class_name
        ,typename data_name
        ,typename original_name = data_name &
       >
       inline
       typename ::reflection::property::direct::common_class<data_name,original_name,class_name>
       common
        (
          data_name      *carrier_param
        )
        {
         typedef ::reflection::property::direct::common_class<data_name,original_name,class_name> common_type;
         return common_type( carrier_param );
        }

     }
   }
 }

#endif
