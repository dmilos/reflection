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

  static int static_int_int_string( int i , std::string const& s )
   {
    std::cout << __FUNCTION__ << std::endl;
    std::cout << i << std::endl;
    std::cout << s << std::endl;
    return 10;
   }

 };

// Reflect to reflection
reflection__CLASS_BEGIN_inherit( MyClassReflection, public, MyClassOriginal )

    reflection__CLASS_FUNCTION_static( "static_int_int_string", MyClassOriginal, public, static_int_int_string )

reflection__CLASS_END_inherit( MyClassReflection, MyClassOriginal );


int main( int argc, char *argv[] )
 {
  MyClassReflection r;  //!< Reflection of Original

  int i=20;
  // Classic "direct" call where c++ take care about arguments type
  //std::cout <<
  ::reflection::property::function::execute< int, int, std::string const& >( r.get("static_int_int_string"), i, "aaa" )
  // << std::endl
  ;


  return EXIT_SUCCESS;
 }
