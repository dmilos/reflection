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

    int  some_processing( int a, int b ){ std::cout << __FUNCTION__ << std::endl; return 1; }
 };

// Reflect to reflection
reflection__CLASS_BEGIN_inherit( MyClassReflection, public, MyClassOriginal )

    reflection__CLASS_FUNCTION_member( "some_processing", MyClassOriginal, some_processing )

reflection__CLASS_END_inherit( MyClassReflection, MyClassOriginal );


int main( int argc, char *argv[] )
 {
  MyClassReflection r;  //!< Reflection of Original

  ::reflection::property::function::execute<int,int,int>( r.get( "some_processing" ), 1, 1 );

  return EXIT_SUCCESS;
 }
