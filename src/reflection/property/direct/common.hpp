#ifndef reflection_property_direct_common
#define reflection_property_direct_common

// ::reflection::property::direct::common_struct<original_name,class_name,storage_name>

 #include "./base.hpp"

namespace reflection
 {
  namespace property
   {
    namespace direct
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

         typedef ::reflection::property::direct::base_class< original_type, storage_type, extractor_type >      typedef_type;

         static typedef_type make( storage_type const& carrier_param )
          {
           return typedef_type( carrier_param, extractor_type() );
          }

        };

      template
       <
         typename class_name
        ,typename data_name
        ,typename original_name = data_name &
       >
       inline
       typename ::reflection::property::direct::common_struct<data_name,original_name,class_name>::typedef_type
       common
        (
          data_name      *carrier_param
        )
        {
         typedef ::reflection::property::direct::common_struct<data_name,original_name,class_name> common_type;
         return common_type::make( carrier_param );
        }

     }
   }
 }

#endif
