#ifndef reflection_type_convert_dynamic
#define reflection_type_convert_dynamic

namespace reflection
 {
  namespace type
   {
    namespace convert
     {

      template
       <
         typename  left_name
        ,typename right_name
       >
       class dynamic
        {
         public:
           typedef  left_name  left_type;
           typedef right_name right_type;

           left_type operator ()( right_name right_param )const
            {
             return dynamic_cast< left_type >( right_param );
            }

        };

     }
   }
 }

#endif
