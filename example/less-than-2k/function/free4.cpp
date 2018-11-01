#include <iostream>
#include <iomanip>
#include <string>

#include "reflection/reflection.hpp"


  int free_int_int_string_float_bool( int , std::string const&, float, bool )
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

    reflection__CLASS_FUNCTION_free( "free_int_int_string_float_bool", free_int_int_string_float_bool )

reflection__CLASS_END_inherit( MyClassReflection, MyClassOriginal );


int main( int argc, char *argv[] )
 {
  MyClassReflection r;  //!< Reflection of Original

  std::cout << ::reflection::property::function::execute< int, int, std::string const&, float, bool >( r.get("free_int_int_string_float_bool"), 10, "asdasd", 42.0, true );

  return EXIT_SUCCESS;
 }
