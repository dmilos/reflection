#ifndef type_convert_dynamic
#define type_convert_dynamic

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

         right_type operator ()( left_name left_param )const
          {
           return dynamic_cast< right_type >( left_param );
          }

      };

   }
 }

#endif
