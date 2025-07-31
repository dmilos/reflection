#ifndef reflection_content_function_signature
#define reflection_content_function_signature

// ::reflection::content::function::signature_struct<identificator_name>

#include <type_traits>

#include "./parameter.hpp"

namespace reflection
 {
  namespace content
   {
    namespace function
     {

      template
       <
         typename identifier_name
      //,typename name_name
       >
       class signature_struct
        {
         public:
           typedef identifier_name identifier_type;

           typedef ::reflection::content::function::parameter_class<identifier_type> parameter_type;
           typedef ::reflection::type::name::identificatorX< identifier_type > identificator_type;

           typedef std::vector< parameter_type >   container_type;

           typedef ::reflection::content::function::signature_struct<identifier_name>   this_type;

         public:
           template < typename first_name, typename ... args_name >
            struct iterate
             {
              public:
                iterate( container_type & container )
                 {
                  typedef typename std::remove_cv< typename std::remove_reference< first_name >::type >::type type_type;
                  auto const& original = identificator_type::template get< first_name >();
                  auto const& instance = identificator_type::template get< type_type >();
                  container.push_back( parameter_type( original, instance ) );
                  iterate< args_name... > dummy( container );
                 }
             };

           template < typename last_name >
            struct iterate<last_name>
             {
              public:
                iterate( container_type & container )
                 {
                  typedef typename std::remove_cv< typename std::remove_reference< last_name >::type >::type type_type;
                  auto const& original = identificator_type::template get< last_name >();
                  auto const& instance = identificator_type::template get< type_type >();
                  container.push_back( parameter_type( original, instance) );
                 }
             };

           template < typename ... args_name >
            static void construct( container_type & container )
             {
              iterate< args_name... > dummy( container );
             }
        };

     }
   }
 }

#endif
