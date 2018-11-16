#ifndef reflection_property_inspect_base
 #define reflection_property_inspect_base

// ::reflection::property::inspect::base_struct<image_name,class_name,storage_name>

 #include "./basic.hpp"

namespace reflection
 {
  namespace property
   {
    namespace inspect
     {

      template
       <
         typename    base_name
        ,typename derived_name
        ,typename storage_name
       >
       struct base_struct
        {
         typedef base_name              data_type;
         typedef base_name const&      image_type;
         typedef derived_name          class_type;
         typedef storage_name*       storage_type;

         typedef class retriever_class
          {
           public:
             explicit retriever_class()
              {
              }
             image_type operator()( storage_type const& carrier_param )const
              {
               return (image_type)(*carrier_param);
              }

           private:
          } retriever_type;

         typedef ::reflection::property::inspect::basic_class<image_type,storage_type,retriever_type>      typedef_type;

         static typedef_type make( storage_type const& carrier_param )
          {
           return typedef_type( carrier_param, retriever_type( pointer_param ) );
          }

        };

     }
   }
 }

#endif
