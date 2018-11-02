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

  int member_int_int_string_float( int i, std::string const& s, float &f )
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

    reflection__CLASS_FUNCTION_member( "member_int_int_string_float", MyClassOriginal, member_int_int_string_float )

reflection__CLASS_END_inherit( MyClassReflection, MyClassOriginal );


int main( int argc, char *argv[] )
 {
  MyClassReflection r;  //!< Reflection of Original

  float f = 42;

  // Classic "direct" call where c++ take care about arguments type
  ::reflection::property::function::execute<int, int, std::string const&, float &>( r.get( "member_int_int_string_float" ), 10, "asdasd", f );
  std::cout << f << std::endl;

  ::reflection::content::function::argument_struct<std::string>::container_type argument;

  auto p0 = ::reflection::content::trinity::simple<std::string,int>( 1024 );
  argument.push_back( &p0 );

  auto p1 = ::reflection::content::trinity::simple<std::string,int>( 1024 );
  argument.push_back( &p1 );

  auto p2 = ::reflection::content::trinity::simple<std::string,std::string>( "test-string" );
  argument.push_back( &p2 );

  auto p3 = ::reflection::content::trinity::simple<std::string,float>( 42 );
  argument.push_back( &p3 );

  std::cout << p1.present() << std::endl;
  std::cout << p2.present() << std::endl;
  ::reflection::content::function::execute<std::string>( r.get("member_int_int_string_float"), argument );
  std::cout << p1.present() << std::endl;
  std::cout << p2.present() << std::endl;

  return EXIT_SUCCESS;
 }
