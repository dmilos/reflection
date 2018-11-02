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

  int free_int_void()
   {
    std::cout << __FUNCTION__ << std::endl;
    return 10;
   }


// Reflect to reflection
reflection__CLASS_BEGIN_inherit( MyClassReflection, public, MyClassOriginal )

    reflection__CLASS_FUNCTION_free( "free_int_void", free_int_void )

reflection__CLASS_END_inherit( MyClassReflection, MyClassOriginal );


int main( int argc, char *argv[] )
 {
  MyClassReflection r;  //!< Reflection of Original

  // Classic "direct" call where c++ take care about arguments type
  std::cout << ::reflection::property::function::execute< int >( r.get("free_int_void") ) << std::endl;

  ::reflection::content::function::argument_struct<std::string>::container_type argument;

  auto p1 = ::reflection::content::trinity::simple<std::string,int>( 1024 );
  argument.push_back( &p1 );

  std::cout << p1.present() << std::endl;
  ::reflection::content::function::execute<std::string>( r.get("free_int_void"), argument );
  std::cout << p1.present() << std::endl;

  return EXIT_SUCCESS;
 }
