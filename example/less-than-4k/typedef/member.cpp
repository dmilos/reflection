#include <iostream>
#include <iomanip>
#include <string>
#include <functional>

#include "reflection/reflection.hpp"

class MyClassOriginal
 {
  public:
    typedef std::array<float,2> MyTypeDef;

    MyClassOriginal()
     {
     }

 };

// Reflect to reflection
reflection__CLASS_BEGIN_pointer( MyClassReflection, public, MyClassOriginal, MyClassOriginal* )

  reflection__CLASS_TYPEDEF_member( "typedef-of-something", MyClassOriginal, public, MyTypeDef );

reflection__CLASS_END_pointer( MyClassReflection, MyClassOriginal );


int main( int argc, char *argv[] )
 {
  std::cout << __FUNCTION__ << std::endl;
  // Some typedefs
  typedef ::reflection::operation::encode::observe_class<std::ostream> observe_type;
  typedef ::reflection::operation::transfer::xml::print_struct<std::ostream> xml_type;
  typedef ::reflection::operation::transfer::json::print_struct<std::ostream> json_type;

  MyClassOriginal o;
  MyClassReflection r( &o );  //!< Reflection of Original, with pointing to some instance

  observe_type observe;

  xml_type xml( observe );// XMLize for example
  observe.view( std::cout, r );

  observe.clear();

  json_type json( observe ); // JSONize also
  observe.view( std::cout, r );

  return EXIT_SUCCESS;
 }
