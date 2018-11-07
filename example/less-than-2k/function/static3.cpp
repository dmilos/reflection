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
  static int static_int_int_string_float( int i, std::string const& s, float f )
   {
    std::cout << __FUNCTION__ << std::endl;
    std::cout << i << std::endl;
    std::cout << s << std::endl;
    std::cout << f << std::endl;
    return 10;
   }
 };



// Reflect to reflection
reflection__CLASS_BEGIN_inherit( MyClassReflection, public, MyClassOriginal )

    reflection__CLASS_FUNCTION_static( "static_int_int_string_float", MyClassOriginal, static_int_int_string_float )

reflection__CLASS_END_inherit( MyClassReflection, MyClassOriginal );


int main( int argc, char *argv[] )
 {
  MyClassReflection r;  //!< Reflection of Original

  // Classic "direct" call where c++ take care about arguments type
  std::cout << 
    ::reflection::property::function::execute< int, int, std::string const&, float >(  r.get("static_int_int_string_float"), 10, "asdasd", 42.0 ) 
    << std::endl;

  return EXIT_SUCCESS;
 }
