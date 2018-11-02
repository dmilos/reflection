#ifndef reflection_content_function_unpack
#define reflection_content_function_unpack

// ::reflection::content::function::unpack_struct<data_name>

#include "../../property/_pure.hpp"
#include "../../property/inspect/_pure.hpp"
#include "../../property/direct/_pure.hpp"


namespace reflection
 {
  namespace content
   {
    namespace function
     {

      template < typename data_name >
        struct unpack_struct
         {
          typedef data_name data_type;
          typedef data_name  specialization_type;

          typedef ::reflection::property::pure_class property_type;
          typedef data_name const& image_type;
          typedef ::reflection::property::inspect::pure_class<image_type>  result_type;

          typedef ::reflection::content::function::unpack_struct<specialization_type> this_type;

          static result_type *get( property_type & property_instance )
           {
            return dynamic_cast<result_type*>(&property_instance);
           }

          static image_type value( property_type & property_instance )
           {
            return this_type::get( property_instance )->present();
           }
         };

        template <  >
        struct unpack_struct< void >
         {
          typedef void data_type;
          typedef void  specialization_type;

          typedef ::reflection::property::pure_class property_type;
          typedef ::reflection::property::inspect::pure_class<void>  result_type;

          typedef ::reflection::content::function::unpack_struct<specialization_type> this_type;

          static result_type *get( property_type & property_instance )
           {
            return dynamic_cast<result_type*>(&property_instance);
           }

          static data_type value( property_type & property_instance )
           {
            return this_type::get( property_instance )->present();
           }

        };


       template < typename data_name >
        struct unpack_struct< data_name const >
         {
          typedef data_name  data_type;
          typedef data_name const  specialization_type;

          typedef ::reflection::property::pure_class property_type;
          typedef data_name const& image_type;
          typedef ::reflection::property::inspect::pure_class<image_type>  result_type;

          typedef ::reflection::content::function::unpack_struct<specialization_type> this_type;

          static result_type *get( property_type & property_instance )
           {
            return dynamic_cast<result_type*>(&property_instance);
           }

          static image_type value( property_type & property_instance )
           {
            return this_type::get( property_instance )->present();
           }

         };

       template < typename data_name >
        struct unpack_struct< data_name const& >
         {
          typedef data_name  data_type;
          typedef data_name const& specialization_type;

          typedef ::reflection::property::pure_class property_type;
          typedef data_name const& image_type;
          typedef ::reflection::property::inspect::pure_class<image_type>  result_type;

          typedef ::reflection::content::function::unpack_struct<specialization_type> this_type;

          static result_type *get( property_type & property_instance )
           {
            return dynamic_cast<result_type*>(&property_instance);
           }

          static image_type value( property_type & property_instance )
           {
            return this_type::get( property_instance )->present();
           }

         };

       template < typename data_name >
        struct unpack_struct< data_name & >
         {
          typedef data_name  data_type;
          typedef data_name &  specialization_type;

          typedef ::reflection::property::pure_class property_type;
          typedef data_name & original_type;
          typedef ::reflection::property::direct::pure_class< original_type > result_type;

          typedef ::reflection::content::function::unpack_struct<specialization_type> this_type;

          static result_type *get( property_type & property_instance )
           {
            return dynamic_cast<result_type*>(&property_instance);
           }

          static original_type value( property_type & property_instance )
           {
            return this_type::get( property_instance )->disclose();
           }

         };

     }
   }
 }

#endif

