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
    //Just nothing.
 };

int free_int_int_string_float_bool( int i , std::string const& s, float & f, bool b )
 {
  std::cout << __FUNCTION__ << std::endl;
  std::cout << i << std::endl;
  std::cout << s << std::endl;
  std::cout << f << std::endl;
  f = 987;
  std::cout << b << std::endl;
  return 10;
 }

// Reflect to reflection
reflection__CLASS_BEGIN_inherit( MyClassReflection, public, MyClassOriginal )

    reflection__CLASS_FUNCTION_free( "free_int_int_string_float_bool", free_int_int_string_float_bool )

reflection__CLASS_END_inherit( MyClassReflection, MyClassOriginal );


int main( int argc, char *argv[] )
 {
  MyClassReflection r;  //!< Reflection of Original

  float f = 42; 

  std::cout << 
   ::reflection::property::function::execute< int, int, std::string const&, float &, bool >( r.get("free_int_int_string_float_bool"), 10, "asdasd", f, 20 )

;

  return EXIT_SUCCESS;
 }
