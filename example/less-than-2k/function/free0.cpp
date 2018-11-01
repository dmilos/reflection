#include <iostream>
#include <iomanip>
#include <string>

#include "reflection/reflection.hpp"


void free_void_void()
 {
  std::cout << __FUNCTION__ << std::endl;
 }

class MyClassOriginal
 {
  public:

    MyClassOriginal()
     {
     }
    //Just nothing.
 };

// Reflect to reflection
reflection__CLASS_BEGIN_inherit( MyClassReflection, public, MyClassOriginal )

    reflection__CLASS_FUNCTION_free( "free_void_void", free_void_void )

reflection__CLASS_END_inherit( MyClassReflection, MyClassOriginal );


int main( int argc, char *argv[] )
 {
  MyClassReflection r;  //!< Reflection of Original

  ::reflection::property::function::execute< void >( r.get("free_void_void") );

  return EXIT_SUCCESS;
 }
