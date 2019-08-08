#ifndef functor_asterisk
#define functor_asterisk

// ::reflection::type::functor::asterisk<result, pointer>



namespace reflection
 {
  namespace type
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
       class asterisk
        //: public functor::unaryC< result_name, parameter_name >
        {
         public:
           typedef  parameter_name parameter_type, T_1st,     argument_type;
           typedef  result_name    return_type,   result_type;

           result_type operator()( parameter_type left_param )const
            {
             return *left_param; //!< by design
            }

           result_type process( parameter_type left_param )const
            {
             return *left_param; //!< by design
            }
        };

     }
   }
 }

#endif
