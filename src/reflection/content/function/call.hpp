#ifndef reflection_content_function_call
#define reflection_content_function_call

// ::reflection::content::function::unpack_struct<data_name>

#include "./unpack.hpp"
#include "../../property/function/_pure.hpp"


namespace reflection
 {
  namespace content
   {
    namespace function
     {

       template 
        <
          typename return_name   = void
         ,typename first_name    = void
         ,typename second_name   = void
         ,typename third_name    = void
         ,typename fourth_name   = void
         ,typename fifth_name    = void
        >
        struct call_struct
         {
          public:
            typedef ::reflection::property::function::pure_class<return_name,first_name,second_name,third_name,fourth_name,fifth_name>    function_type;

            typedef  ::reflection::content::function::unpack_struct<return_name>       u0_type;
            typedef  ::reflection::content::function::unpack_struct<first_name>        u1_type;
            typedef  ::reflection::content::function::unpack_struct<second_name>       u2_type;
            typedef  ::reflection::content::function::unpack_struct<third_name>        u3_type;
            typedef  ::reflection::content::function::unpack_struct<fourth_name>       u4_type;
            typedef  ::reflection::content::function::unpack_struct<fifth_name>        u5_type;

            typedef typename u0_type::return_type       p0_type;
            typedef typename u1_type::parameter_type    p1_type;
            typedef typename u2_type::parameter_type    p2_type;
            typedef typename u3_type::parameter_type    p3_type;
            typedef typename u4_type::parameter_type    p4_type;
            typedef typename u5_type::parameter_type    p5_type;

            static void process( function_type const&f, p0_type & p0, p1_type & p1, p2_type & p2, p3_type & p3, p4_type & p4, p4_type & p5 )
             {
              p0.disclose( f.execute( u1_type::value( p1 ), u1_type::value( p2 ), u1_type::value( p3 ), u1_type::value( p4 ), u1_type::value( p5 ) ) );
             }
         };

       template 
        <
          typename first_name   
         ,typename second_name  
         ,typename third_name   
         ,typename fourth_name  
         ,typename fifth_name   
        >
        struct call_struct< void,first_name,second_name,third_name,fourth_name,fifth_name >
         {
          public:
            typedef ::reflection::property::function::pure_class<void,first_name,second_name,third_name,fourth_name,fifth_name>    function_type;

            typedef  ::reflection::content::function::unpack_struct<void>              u0_type;
            typedef  ::reflection::content::function::unpack_struct<first_name>        u1_type;
            typedef  ::reflection::content::function::unpack_struct<second_name>       u2_type;
            typedef  ::reflection::content::function::unpack_struct<third_name>        u3_type;
            typedef  ::reflection::content::function::unpack_struct<fourth_name>       u4_type;
            typedef  ::reflection::content::function::unpack_struct<fifth_name>        u5_type;

            typedef typename u0_type::return_type       p0_type;
            typedef typename u1_type::parameter_type    p1_type;
            typedef typename u2_type::parameter_type    p2_type;
            typedef typename u3_type::parameter_type    p3_type;
            typedef typename u4_type::parameter_type    p4_type;
            typedef typename u5_type::parameter_type    p5_type;

            static void process( function_type const&f, p0_type & p0, p1_type & p1, p2_type & p2, p3_type & p3, p4_type & p4, p4_type & p5 )
             {
              f.execute( u1_type::value( p1 ), u2_type::value( p2 ), u3_type::value( p3 ), u4_type::value( p4 ), u5_type::value( p5 ) );
             }
         };


       template<   typename return_name, typename first_name, typename second_name, typename third_name, typename fourth_name >
        struct call_struct< return_name,          first_name,          second_name,          third_name,          fourth_name,void >
         {
          public:
            typedef ::reflection::property::function::pure_class<return_name,first_name,second_name,third_name,fourth_name,void>    function_type;

            typedef  ::reflection::content::function::unpack_struct<return_name>       u0_type;
            typedef  ::reflection::content::function::unpack_struct<first_name>        u1_type;
            typedef  ::reflection::content::function::unpack_struct<second_name>       u2_type;
            typedef  ::reflection::content::function::unpack_struct<third_name>        u3_type;
            typedef  ::reflection::content::function::unpack_struct<fourth_name>       u4_type;

            typedef typename u0_type::return_type       p0_type;
            typedef typename u1_type::parameter_type    p1_type;
            typedef typename u2_type::parameter_type    p2_type;
            typedef typename u3_type::parameter_type    p3_type;
            typedef typename u4_type::parameter_type    p4_type;

            static void process( function_type const&f, p0_type & p0, p1_type & p1, p2_type & p2, p3_type & p3, p4_type & p4)
             {
              p0.process( f.execute( u1_type::value( p1 ), u2_type::value( p2 ), u3_type::value( p3 ), u4_type::value( p4 ) ) );
             }
         };

       template<                         typename first_name, typename second_name, typename third_name, typename fourth_name >
        struct call_struct< void,                 first_name,          second_name,          third_name,          fourth_name,void >
         {
          public:
            typedef ::reflection::property::function::pure_class<void,first_name,second_name,third_name,fourth_name,void>    function_type;

            typedef  ::reflection::content::function::unpack_struct<void>              u0_type;
            typedef  ::reflection::content::function::unpack_struct<first_name>        u1_type;
            typedef  ::reflection::content::function::unpack_struct<second_name>       u2_type;
            typedef  ::reflection::content::function::unpack_struct<third_name>        u3_type;
            typedef  ::reflection::content::function::unpack_struct<fourth_name>       u4_type;

            typedef typename u0_type::return_type       p0_type;
            typedef typename u1_type::parameter_type    p1_type;
            typedef typename u2_type::parameter_type    p2_type;
            typedef typename u3_type::parameter_type    p3_type;
            typedef typename u4_type::parameter_type    p4_type;

            static void process( function_type const&f, p0_type & p0, p1_type & p1, p2_type & p2, p3_type & p3, p4_type & p4)
             {
              f.execute( u1_type::value( p1 ), u2_type::value( p2 ), u3_type::value( p3 ), u4_type::value( p4 ) );
             }
         };


       template<   typename return_name, typename first_name, typename second_name, typename third_name >
        struct call_struct< return_name,          first_name,          second_name,          third_name,void,void >
         {
          public:
            typedef ::reflection::property::function::pure_class<return_name,first_name,second_name,third_name,void,void>    function_type;

            typedef  ::reflection::content::function::unpack_struct<return_name>       u0_type;
            typedef  ::reflection::content::function::unpack_struct<first_name>        u1_type;
            typedef  ::reflection::content::function::unpack_struct<second_name>       u2_type;
            typedef  ::reflection::content::function::unpack_struct<third_name>        u3_type;

            typedef typename u0_type::return_type       p0_type;
            typedef typename u1_type::parameter_type    p1_type;
            typedef typename u2_type::parameter_type    p2_type;
            typedef typename u3_type::parameter_type    p3_type;

            static void process( function_type const&f, p0_type & p0, p1_type & p1, p2_type & p2, p3_type & p3 )
             {
              p0.process( f.execute( u1_type::value( p1 ), u2_type::value( p2 ), u3_type::value( p3 ) ) );
             }
         };

       template<                         typename first_name, typename second_name, typename third_name >
        struct call_struct< void,                 first_name,          second_name,          third_name,void,void >
         {
          public:
            typedef ::reflection::property::function::pure_class<void,first_name,second_name,third_name,void,void>    function_type;

            typedef  ::reflection::content::function::unpack_struct<void>              u0_type;
            typedef  ::reflection::content::function::unpack_struct<first_name>        u1_type;
            typedef  ::reflection::content::function::unpack_struct<second_name>       u2_type;
            typedef  ::reflection::content::function::unpack_struct<third_name>        u3_type;

            typedef typename u0_type::return_type       p0_type;
            typedef typename u1_type::parameter_type    p1_type;
            typedef typename u2_type::parameter_type    p2_type;
            typedef typename u3_type::parameter_type    p3_type;

            static void process( function_type const&f, p0_type & p0, p1_type & p1, p2_type & p2, p3_type & p3 )
             {
              f.execute( u1_type::value( p1 ), u2_type::value( p2 ), u3_type::value( p3 ) );
             }
         };


       template<   typename return_name, typename first_name, typename second_name >
        struct call_struct< return_name,          first_name,          second_name,void,void,void >
         {
          public:
            typedef ::reflection::property::function::pure_class<return_name,first_name,second_name,void,void,void>    function_type;

            typedef  ::reflection::content::function::unpack_struct<return_name>       u0_type;
            typedef  ::reflection::content::function::unpack_struct<first_name>        u1_type;
            typedef  ::reflection::content::function::unpack_struct<second_name>       u2_type;

            typedef typename u0_type::return_type       p0_type;
            typedef typename u1_type::parameter_type    p1_type;
            typedef typename u2_type::parameter_type    p2_type;

            static void process( function_type const&f, p0_type & p0, p1_type & p1, p2_type & p2 )
             {
              p0.process( f.execute( u1_type::value( p1 ), u2_type::value( p2 ) ) );
             }
         };

       template<                         typename first_name, typename second_name >
        struct call_struct< void,                 first_name,          second_name,void,void,void >
         {
          public:
            typedef ::reflection::property::function::pure_class<void,first_name,second_name,void,void,void>    function_type;

            typedef  ::reflection::content::function::unpack_struct<void>              u0_type;
            typedef  ::reflection::content::function::unpack_struct<first_name>        u1_type;
            typedef  ::reflection::content::function::unpack_struct<second_name>       u2_type;

            typedef typename u0_type::return_type       p0_type;
            typedef typename u1_type::parameter_type    p1_type;
            typedef typename u2_type::parameter_type    p2_type;

            static void process( function_type const&f, p0_type & p0, p1_type & p1, p2_type & p2 )
             {
              f.execute( u1_type::value( p1 ), u2_type::value( p2 ) );
             }
         };


       template<   typename return_name, typename first_name >
        struct call_struct< return_name,          first_name, void,void,void,void >
         {
          public:
            typedef ::reflection::property::function::pure_class<return_name,first_name,void,void,void,void>    function_type;

            typedef  ::reflection::content::function::unpack_struct<return_name>       u0_type;
            typedef  ::reflection::content::function::unpack_struct<first_name>        u1_type;

            typedef typename u0_type::return_type       p0_type;
            typedef typename u1_type::parameter_type    p1_type;

            static void process( function_type const&f, p0_type & p0, p1_type & p1 )
             {
              p0.process( f.execute( u1_type::value( p1 ) ) );
             }
         };

       template <                        typename first_name >
        struct call_struct<void,                  first_name,void,void,void,void>
         {
          public:
            typedef ::reflection::property::function::pure_class<void, first_name>    function_type;

            typedef typename ::reflection::type::trait<void>::image_type image_type;

            typedef typename ::reflection::content::function::unpack_struct<image_type>     u0_type;
            typedef typename ::reflection::content::function::unpack_struct<first_name>     u1_type;

            typedef typename u0_type::return_type       p0_type;
            typedef typename u1_type::parameter_type    p1_type;

            static void process( function_type const&f,  p0_type & p0 ,  p1_type & p1 )
             {
              f.execute( u1_type::value( p1 ) );
             }
         };


       template<   typename return_name >
        struct call_struct< return_name, void, void,void,void,void >
         {
          public:
            typedef ::reflection::property::function::pure_class<return_name,void,void,void,void,void>    function_type;

            typedef  ::reflection::content::function::unpack_struct<return_name>       u0_type;

            typedef typename u0_type::return_type       p0_type;

            static void process( function_type const&f, p0_type & p0 )
             {
              p0.process( f.execute() );
             }
         };

       template < >
        struct call_struct<void,void,void,void,void,void>
         {
          public:
            typedef ::reflection::property::function::pure_class<void, void,void,void,void,void>    function_type;

            typedef typename ::reflection::type::trait<void>::image_type image_type;

            typedef typename ::reflection::content::function::unpack_struct<image_type>     u0_type;

            typedef typename u0_type::return_type       p0_type;

            static void process( function_type const&f,  p0_type & p0 )
             {
              f.execute();
             }
         };

     }
   }
 }

#endif

