#ifndef reflection_type_convert_identity
#define reflection_type_convert_identity

namespace reflection
 {
  namespace type
   {
    namespace convert
     {

      template
       <
         typename  left_name
        ,typename right_name  =  left_name
       >
       class identity
        {
         public:
           typedef  left_name  left_type;
           typedef right_name right_type;

           left_type operator ()( right_type right_param )const
            {
             return static_cast<left_type>( right_param );
            }

        };

     }
   }
 }

#endif
