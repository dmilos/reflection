#ifndef functor_asterisk
#define functor_asterisk





namespace reflection
 {
  namespace functor
   {

    template
     <
       typename result_name
      ,typename parameter_name
     >
     inline
     result_name
     asteriskF( parameter_name left_param )
      {
       return *left_param;
      }

    template
     <
       typename result_name
      ,typename parameter_name  //= qualify::pointer<result_name>::typedef_type
     >
     class asteriskC
      //: public functor::unaryC< result_name, parameter_name >
      {
       public:
         typedef  parameter_name parameter_type, T_1st,     argument_type;
         typedef  result_name    return_type,   result_type;

         result_type process( parameter_type left_param )const
          {
           return *left_param;
          }
      };

   }
 }

#endif
