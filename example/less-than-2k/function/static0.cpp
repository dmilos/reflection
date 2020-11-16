#include <iostream>
#include <iomanip>
#include <string>

#include "reflection/reflection.hpp"


class MyClassOriginal
 {
  public:

    MyClassOriginal()
     {
     }
   static void static_void_void()
    {
     std::cout << __FUNCTION__ << std::endl;
    }
 };

// Reflect to reflection
reflection__CLASS_BEGIN_inherit( MyClassReflection, public, MyClassOriginal )

    reflection__CLASS_FUNCTION_static( "static_void_void", MyClassOriginal, public, static_void_void )

reflection__CLASS_END_inherit( MyClassReflection, MyClassOriginal );


int main( int argc, char *argv[] )
 {
  MyClassReflection r;  //!< Reflection of Original

    // Classic "direct" call where c++ take care about arguments type
   ::reflection::property::function::execute< void >( r.get("static_void_void") );

   ::reflection::utility::function::static_function ( &MyClassOriginal::static_void_void ).execute( );
   ::reflection::property::function::static_function( &MyClassOriginal::static_void_void ).execute( );
   //TODO ::reflection::content::function::static_function<std::string>( &MyClassOriginal::static_void_void ).execute( );

  return EXIT_SUCCESS;
 }
