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

  int member_int_int_string_float_bool( int i, std::string const& s, float &f, bool b )
     {
      std::cout << __FUNCTION__ << std::endl;
      std::cout << i << std::endl;
      std::cout << s << std::endl;
      std::cout << f << std::endl;
      f = 987;
      return 10;
     }
 };

// Reflect to reflection
reflection__CLASS_BEGIN_inherit( MyClassReflection, public, MyClassOriginal )

    reflection__CLASS_FUNCTION_member( "member_int_int_string_float_bool", MyClassOriginal, public, member_int_int_string_float_bool )

reflection__CLASS_END_inherit( MyClassReflection, MyClassOriginal );


int main( int argc, char *argv[] )
 {
  MyClassReflection r;  //!< Reflection of Original

  float f = 42;

  // Classic "direct" call where c++ take care about arguments type
  ::reflection::property::function::execute<int, int, std::string const&, float &>( r.get( "member_int_int_string_float_bool" ), 10, "asd", f, true );
  std::cout << f << std::endl;

  return EXIT_SUCCESS;
 }
