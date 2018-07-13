#include <iostream>
#include <iomanip>
#include <string>
#include <functional>

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

  // This will inject members that are not member of original class
  reflection__CLASS_SIMPLE_trinity(   "integer",          int, 123  )
  reflection__CLASS_SIMPLE_trinity(   "float-point",      float, 456.0  )
  reflection__CLASS_SIMPLE_trinity(   "standard-string",  std::string, "standard-string"  )

reflection__CLASS_END( MyClassReflection, MyClassOriginal );


int main( int argc, char *argv[] )
 {
  MyClassReflection r;  //!< Reflection of Original

  std::cout << ::reflection::property::direct::disclose< int      & >( r.get("integer") ) << std::endl;
  std::cout << ::reflection::property::inspect::present< int const& >( r.get("integer") ) << std::endl;
               ::reflection::property::mutate::process<  int const& >( r.get("integer"), 2424 );

  std::cout << ::reflection::property::direct::disclose< float      & >( r.get("float-point") ) << std::endl;
  std::cout << ::reflection::property::inspect::present< float const& >( r.get("float-point") ) << std::endl;
               ::reflection::property::mutate::process<  float const& >( r.get("float-point"), 2424 );

  std::cout << ::reflection::property::direct::disclose< std::string      & >( r.get("standard-string") ) << std::endl;
  std::cout << ::reflection::property::inspect::present< std::string const& >( r.get("standard-string") ) << std::endl;
               ::reflection::property::mutate::process<  std::string const& >( r.get("standard-string"), "asdasas" );

  return EXIT_SUCCESS;
 }
