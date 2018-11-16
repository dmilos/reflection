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

    int return_int_accept_int( int i )
     {
      std::cout << __FUNCTION__ << std::endl;
      std::cout << i << std::endl;
      return 10;
     }

 };

// Reflect to reflection
reflection__CLASS_BEGIN_inherit( MyClassReflection, public, MyClassOriginal )

    reflection__CLASS_FUNCTION_member( "return_int_accept_int", MyClassOriginal, public, return_int_accept_int )

reflection__CLASS_END_inherit( MyClassReflection, MyClassOriginal );


int main( int argc, char *argv[] )
 {
  MyClassReflection r;  //!< Reflection of Original

  // Classic "direct" call where c++ take care about arguments type
  ::reflection::property::function::execute<int,int>(    r.get( "return_int_accept_int"), 10  );

  ::reflection::content::function::argument_struct<std::string>::container_type argument;

  auto p0 = ::reflection::content::trinity::simple<std::string,int>( 1024 );
  argument.push_back( &p0 );

  auto p1 = ::reflection::content::trinity::simple<std::string,int>( 1024 );
  argument.push_back( &p1 );

  std::cout << p0.present() << std::endl;
  ::reflection::content::function::execute<std::string>( r.get("return_int_accept_int"), argument );
  std::cout << p0.present() << std::endl;

  return EXIT_SUCCESS;
 }
