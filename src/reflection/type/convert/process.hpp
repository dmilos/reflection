#ifndef reflection_type_convert_processor
#define reflection_type_convert_processor

namespace reflection
 {
  namespace type
   {
    namespace convert
     {

      template
       <
         typename return_name
        ,typename parameter_name = return_name
        ,typename processor_name = ::reflection::type::convert::identity<return_name, parameter_name>
       >
       class process
        {
         public:
          typedef  return_name  return_type;
          typedef parameter_name parameter_type;

          return_type operator ()( parameter_type parameter_param )const
           {
            return processor_name()( parameter_param );
           }

        };

     }
   }
 }
 
#endif
