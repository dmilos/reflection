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

    int  return_int_function(){std::cout << __FUNCTION__ << std::endl; return 1; }
 };

// Reflect to reflection
reflection__CLASS_BEGIN_inherit( MyClassReflection, public, MyClassOriginal )

    reflection__CLASS_FUNCTION_member( "return_int_function", MyClassOriginal, return_int_function )

reflection__CLASS_END( MyClassReflection, MyClassOriginal );


int main( int argc, char *argv[] )
 {
  MyClassReflection r;  //!< Reflection of Original

  ::reflection::property::function::execute<int>(         r.get( "return_int_function" ) ) ;

  return EXIT_SUCCESS;
 }
