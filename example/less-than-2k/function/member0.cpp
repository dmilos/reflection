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

    void return_void_function()
    {
     std::cout << __FUNCTION__ << std::endl;
    }
 };

// Reflect to reflection
reflection__CLASS_BEGIN_inherit( MyClassReflection, public, MyClassOriginal )

    reflection__CLASS_FUNCTION_member( "return_void_function", MyClassOriginal, return_void_function )

reflection__CLASS_END_inherit( MyClassReflection, MyClassOriginal );


int main( int argc, char *argv[] )
 {
  MyClassReflection r;  //!< Reflection of Original

  // Classic "direct" call where c++ take care about arguments type
  ::reflection::property::function::execute<void>(        r.get( "return_void_function" ) );

  return EXIT_SUCCESS;
 }
