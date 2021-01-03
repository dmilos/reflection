#ifndef reflection_utility_function_overload
#define reflection_utility_function_overload

// ::reflection::utility::function::overload_class<return_name,first_name,second_name,third_name,fourth_name,fifth_name>

#include "./_pure.hpp"


namespace reflection
 {
  namespace utility
   {
    namespace function
     {

      template
       <
         typename return_name  = void
        ,typename first_name   = void
        ,typename second_name  = void
        ,typename third_name   = void
        ,typename fourth_name  = void
        ,typename fifth_name   = void
       >
       class overload_class
       : virtual public ::reflection::utility::function::pure_class<return_name>
       , virtual public ::reflection::utility::function::pure_class<return_name,first_name>
       , virtual public ::reflection::utility::function::pure_class<return_name,first_name,second_name>
       , virtual public ::reflection::utility::function::pure_class<return_name,first_name,second_name,third_name>
       , virtual public ::reflection::utility::function::pure_class<return_name,first_name,second_name,third_name,fourth_name>
       , virtual public ::reflection::utility::function::pure_class<return_name,first_name,second_name,third_name,fourth_name,fifth_name>
       {
        public:
          typedef ::reflection::utility::function::pure_class<return_name> generator_type;
          typedef ::reflection::utility::function::pure_class<return_name,first_name> unary_type;
          typedef ::reflection::utility::function::pure_class<return_name,first_name,second_name> binary_type;
          typedef ::reflection::utility::function::pure_class<return_name,first_name,second_name,third_name> ternary_type;
       };

      template
       <
         typename return_name
        ,typename  first_name
        ,typename second_name
        ,typename  third_name
        ,typename fourth_name
       >
       class overload_class< return_name, first_name, second_name, third_name, fourth_name, void >
       : virtual public ::reflection::utility::function::pure_class<return_name>
       , virtual public ::reflection::utility::function::pure_class<return_name,first_name>
       , virtual public ::reflection::utility::function::pure_class<return_name,first_name,second_name>
       , virtual public ::reflection::utility::function::pure_class<return_name,first_name,second_name,third_name>
       , virtual public ::reflection::utility::function::pure_class<return_name,first_name,second_name,third_name,fourth_name>
       {
        public:
          typedef ::reflection::utility::function::pure_class<return_name> generator_type;
          typedef ::reflection::utility::function::pure_class<return_name,first_name> unary_type;
          typedef ::reflection::utility::function::pure_class<return_name,first_name,second_name> binary_type;
          typedef ::reflection::utility::function::pure_class<return_name,first_name,second_name,third_name> ternary_type;
          typedef ::reflection::utility::function::pure_class<return_name,first_name,second_name,third_name,fourth_name> forthary_type;
       };

      template
       <
         typename return_name
        ,typename  first_name
        ,typename second_name
        ,typename third_name
       >
       class overload_class< return_name, first_name, second_name, third_name, void, void >
       : virtual public ::reflection::utility::function::pure_class<return_name>
       , virtual public ::reflection::utility::function::pure_class<return_name,first_name>
       , virtual public ::reflection::utility::function::pure_class<return_name,first_name,second_name>
       , virtual public ::reflection::utility::function::pure_class<return_name,first_name,second_name,third_name>
       {
        public:
          typedef ::reflection::utility::function::pure_class<return_name> generator_type;
          typedef ::reflection::utility::function::pure_class<return_name,first_name> unary_type;
          typedef ::reflection::utility::function::pure_class<return_name,first_name,second_name> binary_type;
          typedef ::reflection::utility::function::pure_class<return_name,first_name,second_name,third_name> ternary_type;
       };

      template
       <
         typename return_name
        ,typename  first_name
        ,typename second_name
       >
       class overload_class< return_name, first_name, second_name, void, void, void >
       : virtual public ::reflection::utility::function::pure_class<return_name>
       , virtual public ::reflection::utility::function::pure_class<return_name,first_name>
       , virtual public ::reflection::utility::function::pure_class<return_name,first_name,second_name>
       {
        public:
          typedef ::reflection::utility::function::pure_class<return_name> generator_type;
          typedef ::reflection::utility::function::pure_class<return_name,first_name> unary_type;
          typedef ::reflection::utility::function::pure_class<return_name,first_name,second_name> binary_type;
       };

      template
       <
         typename return_name
        ,typename  first_name
       >
       class overload_class< return_name, first_name, void, void, void, void >
       : virtual public ::reflection::utility::function::pure_class<return_name>
       , virtual public ::reflection::utility::function::pure_class<return_name,first_name>
       {
        public:
          typedef ::reflection::utility::function::pure_class<return_name> generator_type;
          typedef ::reflection::utility::function::pure_class<return_name,first_name> unary_type;
       };

      template
       <
         typename return_name
       >
       class overload_class< return_name, void, void, void, void, void >
       : virtual public ::reflection::utility::function::pure_class<return_name>
       {
        public:
          typedef ::reflection::utility::function::pure_class<return_name> generator_type;
       };

     }
   }
 }

#endif
