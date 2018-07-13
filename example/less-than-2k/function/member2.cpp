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

    void return_void_accept_int( int a ){std::cout << __FUNCTION__ << std::endl;}
 };

// Reflect to reflection
reflection__CLASS_BEGIN_inherit( MyClassReflection, public, MyClassOriginal )

    reflection__CLASS_FUNCTION_member( "return_void_accept_int", MyClassOriginal, return_void_accept_int )

reflection__CLASS_END( MyClassReflection, MyClassOriginal );


int main( int argc, char *argv[] )
 {
  MyClassReflection r;  //!< Reflection of Original

  ::reflection::property::function::execute<void,int>(    r.get( "return_void_accept_int"), 1  );

  return EXIT_SUCCESS;
 }
