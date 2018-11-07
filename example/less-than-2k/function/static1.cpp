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
   static int static_int_void()
    {
     std::cout << __FUNCTION__ << std::endl;
     return 10;
    }
 };

// Reflect to reflection
reflection__CLASS_BEGIN_inherit( MyClassReflection, public, MyClassOriginal )

    reflection__CLASS_FUNCTION_static( "static_int_void", MyClassOriginal, static_int_void )

reflection__CLASS_END_inherit( MyClassReflection, MyClassOriginal );


int main( int argc, char *argv[] )
 {
  MyClassReflection r;  //!< Reflection of Original

  // Classic "direct" call where c++ take care about arguments type
  std::cout << ::reflection::property::function::execute< int >( r.get("static_int_void") ) << std::endl;


  return EXIT_SUCCESS;
 }
