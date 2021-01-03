#ifndef reflection_utility_function_std_overload
#define reflection_utility_function_std_overload

// ::reflection::utility::function::std_overload_class<return_name, first_name>

#include "./std.hpp"
#include "./overload.hpp"

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
       >
       class std_overload_class
       : virtual public ::reflection::utility::function::overload_class<return_name,first_name,second_name,third_name>
       ,         public ::reflection::utility::function::std_class<return_name>
       ,         public ::reflection::utility::function::std_class<return_name,first_name>
       ,         public ::reflection::utility::function::std_class<return_name,first_name,second_name>
       ,         public ::reflection::utility::function::std_class<return_name,first_name,second_name,third_name>
       {
        public:
          typedef ::reflection::utility::function::std_class<return_name>  generator_type;
          typedef ::reflection::utility::function::std_class<return_name,first_name >unary_type;
          typedef ::reflection::utility::function::std_class<return_name,first_name,second_name >binary_type;
          typedef ::reflection::utility::function::std_class<return_name,first_name,second_name,third_name >ternary_type;

        public:
          std_overload_class( ):generator_type(nullptr), unary_type(nullptr), binary_type(nullptr), ternary_type(nullptr){ }
          std_overload_class( typename generator_type::function_type function ):generator_type(function),unary_type(nullptr){ }
          std_overload_class( typename unary_type::function_type     function ):generator_type(nullptr),unary_type(function){ }
          std_overload_class( typename binary_type::function_type    function ):generator_type(nullptr),unary_type(function){ }
          std_overload_class( typename ternary_type::function_type   function ):generator_type(nullptr),unary_type(function){ }
         ~std_overload_class( ){ }
       };

      template
       <
         typename return_name
       >
       class std_overload_class< return_name, void, void, void >
       : virtual public ::reflection::utility::function::overload_class<return_name>
       ,         public ::reflection::utility::function::std_class<return_name>
       {
        public:
          typedef ::reflection::utility::function::std_class<return_name>  generator_type;

        public:
          std_overload_class( ):generator_type(nullptr){ }
          std_overload_class( typename generator_type::function_type function ):generator_type(function){ }
         ~std_overload_class( ){ }
       };

      template
       <
         typename return_name
        ,typename first_name 
       >
       class std_overload_class< return_name, first_name, void, void >
       : virtual public ::reflection::utility::function::overload_class<return_name,first_name>
       ,         public ::reflection::utility::function::std_class<return_name>
       ,         public ::reflection::utility::function::std_class<return_name,first_name>
       {
        public:
          typedef ::reflection::utility::function::std_class<return_name>  generator_type;
          typedef ::reflection::utility::function::std_class<return_name,first_name >unary_type;

        public:
          std_overload_class( ):generator_type(nullptr),unary_type(nullptr){ }
          std_overload_class( typename generator_type::function_type function ):generator_type(function),unary_type(nullptr){ }
          std_overload_class( typename unary_type::function_type     function ):generator_type(nullptr),unary_type(function){ }
         ~std_overload_class( ){ }
       };

      template
       <
         typename return_name
        ,typename first_name 
        ,typename second_name
       >
       class std_overload_class< return_name, first_name, second_name, void >
       : virtual public ::reflection::utility::function::overload_class<return_name,first_name,second_name,void,void>
       ,         public ::reflection::utility::function::std_class<return_name>
       ,         public ::reflection::utility::function::std_class<return_name,first_name>
       ,         public ::reflection::utility::function::std_class<return_name,first_name,second_name>
       {
        public:
          typedef ::reflection::utility::function::std_class<return_name>  generator_type;
          typedef ::reflection::utility::function::std_class<return_name,first_name >unary_type;
          typedef ::reflection::utility::function::std_class<return_name,first_name,second_name >binary_type;

        public:
          std_overload_class( ):generator_type(nullptr),unary_type(nullptr),binary_type(nullptr){ }
          std_overload_class( typename generator_type::function_type  function ):generator_type(function),unary_type(nullptr),binary_type(nullptr){ }
          std_overload_class( typename unary_type::function_type      function ):generator_type(nullptr),unary_type(function),binary_type(nullptr){ }
          std_overload_class( typename binary_type::function_type     function ):generator_type(nullptr),unary_type(function),binary_type(nullptr){ }
         ~std_overload_class( ){ }
       };

     }
   }
 }

#endif
