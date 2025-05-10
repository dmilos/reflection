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
           template < typename return_name, typename first_name, typename second_name, typename third_name, typename fourth_name, typename fifth_name >
            static void construct( container_type & container )
             {
              typedef typename std::remove_cv< typename std::remove_reference< fifth_name >::type >::type type_type;
              auto const& original = identificator_type::template get< fifth_name >();
              auto const& instance = identificator_type::template get< type_type >();
              container.insert( container.begin(), parameter_type( original, instance ) );
              this_type:: template construct< return_name, first_name, second_name, third_name, fourth_name >( container );
              return;
             }

           template < typename return_name, typename first_name, typename second_name, typename third_name, typename fourth_name >
            static void construct( container_type & container )
             {
              typedef typename std::remove_cv< typename std::remove_reference< fourth_name >::type >::type type_type;
              auto const& original = identificator_type::template get< fourth_name >();
              auto const& instance = identificator_type::template get< type_type >();

              container.insert( container.begin(), parameter_type( original, instance ) );
              this_type:: template construct< return_name, first_name, second_name, third_name >( container );
              return;
             }

           template < typename return_name, typename first_name, typename second_name, typename third_name >
            static void construct( container_type & container )
             {
              typedef typename std::remove_cv< typename std::remove_reference< third_name >::type >::type type_type;
              auto const& original = identificator_type::template get< third_name >();
              auto const& instance = identificator_type::template get< type_type >();

              container.insert( container.begin(), parameter_type( original, instance ) );
              this_type:: template construct< return_name, first_name, second_name >( container );
              return;
             }

           template < typename return_name, typename first_name, typename second_name >
            static void construct( container_type & container )
             {
              typedef typename std::remove_cv< typename std::remove_reference< second_name >::type >::type type_type;
              auto const& original = identificator_type::template get< second_name >();
              auto const& instance = identificator_type::template get< type_type >();
              container.insert( container.begin(), parameter_type( original, instance ) );
              this_type:: template construct< return_name, first_name >( container );
              return;
             }

           template <typename return_name, typename first_name >
            static void construct( container_type & container )
             {
              typedef typename std::remove_cv< typename std::remove_reference< first_name >::type >::type type_type;
              auto const& original = identificator_type::template get< first_name >();
              auto const& instance = identificator_type::template get< type_type >();
              container.insert( container.begin(), parameter_type( original, instance ) );
              this_type:: template construct< return_name >( container );
              return;
             }

           template <typename return_name >
            static void construct( container_type & container )
             {
              typedef typename std::remove_cv< typename std::remove_reference< return_name >::type >::type type_type;
              auto const& original = identificator_type::template get< return_name >();
              auto const& instance = identificator_type::template get< type_type >();
              container.insert( container.begin(), parameter_type( original, instance ) );
              this_type:: template construct( container );
              return;
             }
            static void construct( container_type & container )
             {
             }

        };

     }
   }
 }

#endif
