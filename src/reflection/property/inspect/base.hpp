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

      namespace _internal
       {

        template
         <
           typename    base_name
          ,typename derived_name
          ,typename storage_name
         >
         struct base_struct
          {
           public:
             typedef base_name              base_type;
             typedef derived_name        derived_type;
             typedef storage_name        storage_type;

           typedef base_name const&      image_type;

           typedef class retriever_class
            {
             public:
               retriever_class()
                {
                }
               image_type operator()( storage_type const& carrier_param )const
                {
                 return dynamic_cast< image_type >( *carrier_param );
                }

             private:
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
           typename base_name
          ,typename derived_name
          ,typename storage_name
         >
       class base_class
        : public ::reflection::property::base::distinctive_class<base_name,derived_name>
        , public ::reflection::property::inspect::_internal::base_struct<base_name,derived_name,storage_name>::typedef_type
        {
         public:
          typedef          ::reflection::property::base::distinctive_class<base_name,derived_name>                      distinctive_type;
          typedef typename ::reflection::property::inspect::_internal::base_struct<base_name,derived_name,storage_name>::typedef_type inspect_type;

          using inspect_type::inspect_type;

        };


        template
         <
           typename base_name
          ,typename derived_name
          ,typename storage_name
         >
         ::reflection::property::inspect::base_class<base_name,derived_name,storage_name>
         base( derived_name * carrier_param )
          {
           return ::reflection::property::inspect::base_class<base_name,derived_name,storage_name>( carrier_param );
          }


     }
   }
 }

#endif
