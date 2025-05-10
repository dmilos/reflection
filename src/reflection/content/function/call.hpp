#ifndef reflection_content_function_call
#define reflection_content_function_call

// ::reflection::content::function::unpack_struct<data_name>

#include "../../property/function/_pure.hpp"

#include "../../property/dispatch.hpp"
#include "../../property/retrieve.hpp"


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

            typedef ::reflection::property::pure_class  property_type;
            typedef ::reflection::property::dispatch_class<return_name>          result_type;
            typedef ::reflection::content::function::retrieve_class<first_name>      g1_type;
            typedef ::reflection::content::function::retrieve_class<second_name>     g2_type;
            typedef ::reflection::content::function::retrieve_class<third_name>      g3_type;
            typedef ::reflection::content::function::retrieve_class<fourth_name>     g4_type;
            typedef ::reflection::content::function::retrieve_class<fifth_name>      g5_type;

            static bool process( function_type const&f, property_type& p0, property_type& p1, property_type& p2, property_type& p3, property_type& p4, property_type& p5 )
             {
              result_type result( p0 ); if( false == result.valid() ) return false;
                      g1_type r1( p1 ); if( false ==     r1.valid() ) return false;
                      g2_type r2( p2 ); if( false ==     r2.valid() ) return false;
                      g3_type r3( p3 ); if( false ==     r3.valid() ) return false;
                      g4_type r4( p4 ); if( false ==     r4.valid() ) return false;
                      g5_type r5( p5 ); if( false ==     r5.valid() ) return false;

              result.set( f.execute(  r1.get(), r2.get(), r3.get(), r4.get(), r5.get() ) );
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

            typedef ::reflection::property::pure_class  property_type;
            typedef ::reflection::property::dispatch_class<void>          result_type;
            typedef ::reflection::content::function::retrieve_class<first_name>      g1_type;
            typedef ::reflection::content::function::retrieve_class<second_name>     g2_type;
            typedef ::reflection::content::function::retrieve_class<third_name>      g3_type;
            typedef ::reflection::content::function::retrieve_class<fourth_name>     g4_type;
            typedef ::reflection::content::function::retrieve_class<fifth_name>      g5_type;

            static bool process( function_type const&f, property_type& p0, property_type& p1, property_type& p2, property_type& p3, property_type& p4, property_type& p5 )
             {
              result_type result( p0 ); if( false == result.valid() ) return false;
                      g1_type r1( p1 ); if( false ==     r1.valid() ) return false;
                      g2_type r2( p2 ); if( false ==     r2.valid() ) return false;
                      g3_type r3( p3 ); if( false ==     r3.valid() ) return false;
                      g4_type r4( p4 ); if( false ==     r4.valid() ) return false;
                      g5_type r5( p5 ); if( false ==     r5.valid() ) return false;

               f.execute(  r1.get(), r2.get(), r3.get(), r4.get(), r5.get() ); result.set();
             }
         };

       template<   typename return_name, typename first_name, typename second_name, typename third_name, typename fourth_name >
        struct call_struct< return_name,          first_name,          second_name,          third_name,          fourth_name,void >
         {
          public:
            typedef ::reflection::property::function::pure_class<return_name,first_name,second_name,third_name,fourth_name>    function_type;

            typedef ::reflection::property::pure_class  property_type;
            typedef ::reflection::property::dispatch_class<return_name>          result_type;
            typedef ::reflection::content::function::retrieve_class<first_name>      g1_type;
            typedef ::reflection::content::function::retrieve_class<second_name>     g2_type;
            typedef ::reflection::content::function::retrieve_class<third_name>      g3_type;
            typedef ::reflection::content::function::retrieve_class<fourth_name>     g4_type;

            static bool process( function_type const&f, property_type& p0, property_type& p1, property_type& p2, property_type& p3, property_type& p4 )
             {
              result_type result( p0 ); if( false == result.valid() ) return false;
                      g1_type r1( p1 ); if( false ==     r1.valid() ) return false;
                      g2_type r2( p2 ); if( false ==     r2.valid() ) return false;
                      g3_type r3( p3 ); if( false ==     r3.valid() ) return false;
                      g4_type r4( p4 ); if( false ==     r4.valid() ) return false;

              result.set( f.execute(  r1.get(), r2.get(), r3.get(), r4.get() ) );
              return true;
             }
         };

       template<                         typename first_name, typename second_name, typename third_name, typename fourth_name >
        struct call_struct< void,                 first_name,          second_name,          third_name,          fourth_name,void >
         {
          public:
            typedef ::reflection::property::function::pure_class<void,first_name,second_name,third_name,fourth_name>    function_type;

            typedef ::reflection::property::pure_class  property_type;
            typedef ::reflection::property::dispatch_class<void>          result_type;
            typedef ::reflection::content::function::retrieve_class<first_name>      g1_type;
            typedef ::reflection::content::function::retrieve_class<second_name>     g2_type;
            typedef ::reflection::content::function::retrieve_class<third_name>      g3_type;
            typedef ::reflection::content::function::retrieve_class<fourth_name>     g4_type;

            static bool process( function_type const&f, property_type& p0, property_type& p1, property_type& p2, property_type& p3, property_type& p4 )
             {
              result_type result( p0 ); if( false == result.valid() ) return false;
                      g1_type r1( p1 ); if( false ==     r1.valid() ) return false;
                      g2_type r2( p2 ); if( false ==     r2.valid() ) return false;
                      g3_type r3( p3 ); if( false ==     r3.valid() ) return false;
                      g4_type r4( p4 ); if( false ==     r4.valid() ) return false;

              f.execute(  r1.get(), r2.get(), r3.get(), r4.get() ); result.set();
              return true;
             }
         };

       template<   typename return_name, typename first_name, typename second_name, typename third_name >
        struct call_struct< return_name,          first_name,          second_name,          third_name,void,void >
         {
          public:
            typedef ::reflection::property::function::pure_class<return_name,first_name,second_name,third_name>    function_type;

            typedef ::reflection::property::pure_class  property_type;
            typedef ::reflection::property::dispatch_class<return_name>          result_type;
            typedef ::reflection::content::function::retrieve_class<first_name>  g1_type;
            typedef ::reflection::content::function::retrieve_class<second_name> g2_type;
            typedef ::reflection::content::function::retrieve_class<third_name>  g3_type;

            static bool process( function_type const&f, property_type& p0, property_type& p1, property_type& p2, property_type& p3 )
             {
              result_type result( p0); if( false == result.valid() ) return false;
                      g1_type r1( p1); if( false ==     r1.valid() ) return false;
                      g2_type r2( p2); if( false ==     r2.valid() ) return false;
                      g3_type r3( p3); if( false ==     r3.valid() ) return false;

              result.set( f.execute(  r1.get(), r2.get(), r3.get() ) );
              return true;
             }
         };

       template<                         typename first_name, typename second_name, typename third_name >
        struct call_struct< void,                 first_name,          second_name,          third_name,void,void >
         {
          public:
            typedef ::reflection::property::function::pure_class<void,first_name,second_name,third_name>    function_type;

            typedef ::reflection::property::pure_class  property_type;
            typedef ::reflection::property::dispatch_class<void>                 result_type;
            typedef ::reflection::content::function::retrieve_class<first_name>      g1_type;
            typedef ::reflection::content::function::retrieve_class<second_name>     g2_type;
            typedef ::reflection::content::function::retrieve_class<third_name>      g3_type;

            static bool process( function_type const&f, property_type& p0, property_type& p1, property_type& p2, property_type& p3 )
             {
              result_type result( p0); if( false == result.valid() ) return false;
                      g1_type r1( p1); if( false ==     r1.valid() ) return false;
                      g2_type r2( p2); if( false ==     r2.valid() ) return false;
                      g3_type r3( p3); if( false ==     r3.valid() ) return false;

              f.execute(  r1.get(), r2.get(), r3.get() );result.set();
              return true;
             }

         };

       template<   typename return_name, typename first_name, typename second_name >
        struct call_struct< return_name,          first_name,          second_name,void,void,void >
         {
          public:
            typedef ::reflection::property::function::pure_class<return_name,first_name,second_name>    function_type;

            typedef ::reflection::property::pure_class  property_type;
            typedef ::reflection::property::dispatch_class<return_name>          result_type;
            typedef ::reflection::content::function::retrieve_class<first_name>  g1_type;
            typedef ::reflection::content::function::retrieve_class<second_name> g2_type;

            static bool process( function_type const&f, property_type& p0, property_type& p1, property_type& p2 )
             {
              result_type result( p0); if( false == result.valid() ) return false;
                      g1_type r1( p1); if( false ==     r1.valid() ) return false;
                      g2_type r2( p2); if( false ==     r2.valid() ) return false;

              result.set( f.execute(  r1.get(), r2.get() ) );
              return true;
             }
         };

       template<                         typename first_name, typename second_name >
        struct call_struct< void,                 first_name,          second_name,void,void,void >
         {
          public:
            typedef ::reflection::property::function::pure_class<void,first_name,second_name>    function_type;

            typedef ::reflection::property::pure_class  property_type;
            typedef ::reflection::property::dispatch_class<void>                 result_type;
            typedef ::reflection::content::function::retrieve_class<first_name>      g1_type;
            typedef ::reflection::content::function::retrieve_class<second_name>     g2_type;

            static bool process( function_type const&f, property_type& p0, property_type& p1, property_type& p2 )
             {
              result_type result( p0 ); if( false == result.valid() ) return false;
                      g1_type r1( p1 ); if( false ==     r1.valid() ) return false;
                      g2_type r2( p2 ); if( false ==     r2.valid() ) return false;

              f.execute(  r1.get(), r2.get() );  result.set();
              return true;
             }

         };

       template<   typename return_name, typename first_name >
        struct call_struct< return_name,          first_name, void,void,void,void >
         {
          public:
            typedef ::reflection::property::function::pure_class<return_name,first_name>    function_type;

            typedef ::reflection::property::pure_class  property_type;
            typedef ::reflection::property::dispatch_class<return_name>          result_type;
            typedef ::reflection::content::function::retrieve_class<first_name>  g1_type;

            static bool process( function_type const&f, property_type& p0, property_type& p1 )
             {
              result_type result( p0); if( false == result.valid() ) return false;
                      g1_type r1( p1); if( false ==     r1.valid() ) return false;

              result.set( f.execute(  r1.get() ) );
              return true;
             }
         };

       template <                        typename first_name >
        struct call_struct<void,                  first_name,void,void,void,void>
         {
          public:
            typedef ::reflection::property::function::pure_class<void, first_name>    function_type;

            typedef ::reflection::property::pure_class  property_type;
            typedef    ::reflection::property::dispatch_class<void>                 result_type;
            typedef    ::reflection::content::function::retrieve_class<first_name>      g1_type;

            static bool process( function_type const&f, property_type& p0, property_type& p1 )
             {
              result_type result( p0); if( false == result.valid() ) return false;
                      g1_type r1( p1); if( false ==     r1.valid() ) return false;

              f.execute( r1.get() );result.set();
              return true;
             }

         };

       template<   typename return_name >
        struct call_struct< return_name, void, void,void,void,void >
         {
          public:
            typedef ::reflection::property::function::pure_class<return_name>    function_type;

            typedef ::reflection::property::pure_class  property_type;
            typedef ::reflection::property::dispatch_class<return_name>          result_type;

            static bool process( function_type const&f, property_type& p0 )
             {
              result_type result( p0); if( false == result.valid() ) return false;

              result.set( f.execute( ) );
              return true;
             }

         };

       template < >
        struct call_struct<void,void,void,void,void,void>
         {
          public:
            typedef ::reflection::property::function::pure_class<void>    function_type;

            typedef ::reflection::property::pure_class  property_type;
            typedef ::reflection::property::dispatch_class<void>                 result_type;

            static bool process( function_type const&f, property_type& p0 )
             {
              result_type result( p0); if( false == result.valid() ) return false;

              f.execute(); result.set();
              return true;
             }

         };

     }
   }
 }

#endif

