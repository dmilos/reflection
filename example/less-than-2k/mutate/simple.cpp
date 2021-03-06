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
  // Just nothing


 };

// Reflect to reflection
reflection__CLASS_BEGIN_inherit( MyClassReflection, public, MyClassOriginal )


  // This will inject members that are not member of original class

 reflection__CLASS_SIMPLE_mutate( "integer",           int, 123  )
 reflection__CLASS_SIMPLE_mutate( "float-point",       float, 456.0  )
 reflection__CLASS_SIMPLE_mutate( "standard-string",   std::string, "standard-string"  )

reflection__CLASS_END_inherit( MyClassReflection, MyClassOriginal );


int main( int argc, char *argv[] )
 {
  MyClassReflection r;  //!< Reflection of Original

  ::reflection::property::mutate::process<  int          const& >( r.get("integer"), 2424 );
  ::reflection::property::mutate::process<  float        const& >( r.get("float-point"), 2424.0 );
  ::reflection::property::mutate::process<  std::string  const& >( r.get("standard-string"), "asdasas" );

  return EXIT_SUCCESS;
 }
