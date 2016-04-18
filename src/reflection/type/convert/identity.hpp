#ifndef type_convert_identity
#define type_convert_identity

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

         left_type operator ()( right_name right_param )const
          {
           return right_param;
          }

      };

   }
 }

#endif