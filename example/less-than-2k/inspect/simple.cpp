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

// Reflect to reflection
reflection__CLASS_BEGIN_inherit( MyClassReflection, public, MyClassOriginal )

  // This will inject member that are not member of original class
  reflection__CLASS_SIMPLE_inspect(   "integer",         int, 123  )
  reflection__CLASS_SIMPLE_inspect(   "float-point",     float, 456.0  )
  reflection__CLASS_SIMPLE_inspect(   "standard-string", std::string, "standard-string"  )

reflection__CLASS_END_inherit( MyClassReflection, MyClassOriginal );


int main( int argc, char *argv[] )
 {
  MyClassReflection r;  //!< Reflection of Original
  std::cout <<  ::reflection::property::inspect::present< int         const& >( r.get( "integer"         ) ) << std::endl;
  std::cout <<  ::reflection::property::inspect::present< float       const& >( r.get( "float-point"     ) ) << std::endl;
  std::cout <<  ::reflection::property::inspect::present< std::string const& >( r.get( "standard-string" ) ) << std::endl;

  return EXIT_SUCCESS;
 }
