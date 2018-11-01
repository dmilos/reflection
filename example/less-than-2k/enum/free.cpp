#include <iostream>
#include <iomanip>
#include <string>
#include <functional>

#include "reflection/reflection.hpp"

enum Enumerator{ enum1, enum2, enum10=10, enum11=150 };

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

 reflection__CLASS_ENUM_begin( "enum-for-something", MyClassOriginal, Enumerator );
  reflection__CLASS_ENUM_value( "asdasdas1",  enum1 )
  reflection__CLASS_ENUM_value( "asdasdas2",  enum2 )
  reflection__CLASS_ENUM_value( "asdasdas10", enum10 )
  reflection__CLASS_ENUM_value( "asdasdas11", enum11 )
 reflection__CLASS_ENUM_end(Enumerator)

reflection__CLASS_END( MyClassReflection, MyClassOriginal );


int main( int argc, char *argv[] )
 {
  std::cout << __FUNCTION__ << std::endl;
  // Some typedefs
  typedef ::reflection::operation::transfer::observe_class<std::ostream> observe_type;
  typedef ::reflection::operation::transfer::json_struct<std::ostream> json_type;

  MyClassReflection r;  //!< Reflection of Original

                        // XMLize for example
  observe_type observe;
  json_type json( observe );

  observe.view( std::cout, r );

  std::cin.get();
  return EXIT_SUCCESS;
}
