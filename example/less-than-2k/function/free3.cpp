#include <iostream>
#include <iomanip>
#include <string>

#include "reflection/reflection.hpp"


  int free_int_int_string_float( int , std::string const&, float )
   {
    std::cout << __FUNCTION__ << std::endl;
    return 10;
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

    reflection__CLASS_FUNCTION_free( "free_int_int_string_float", free_int_int_string_float )

reflection__CLASS_END( MyClassReflection, MyClassOriginal );


int main( int argc, char *argv[] )
 {
  MyClassReflection r;  //!< Reflection of Original

  std::cout << ::reflection::property::function::execute< int, int, std::string const&, float >(  r.get("free_int_int_string_float"), 10, "asdasd", 42.0 );

  return EXIT_SUCCESS;
 }
