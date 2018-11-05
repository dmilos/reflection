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

 };
 
typedef std::array<float,2> MyGlobalTypeDef;

// Reflect to reflection
reflection__CLASS_BEGIN_inherit( MyClassReflection, public, MyClassOriginal )

  reflection__CLASS_TYPEDEF( "injected-global-typedef-of-something", MyGlobalTypeDef );

reflection__CLASS_END_inherit( MyClassReflection, MyClassOriginal );


int main( int argc, char *argv[] )
 {
  std::cout << __FUNCTION__ << std::endl;
  // Some typedefs
  typedef ::reflection::operation::transfer::observe_class<std::ostream> observe_type;
  typedef ::reflection::operation::transfer::xml_struct<std::ostream> xml_type;
  typedef ::reflection::operation::transfer::json_struct<std::ostream> json_type;

  MyClassOriginal o;
  MyClassReflection r;  //!< Reflection of Original, with pointing to some instance

  observe_type observe;

  xml_type xml( observe );// XMLize for example
  observe.view( std::cout, r );

  observe.clear();

  json_type json( observe ); // JSONize also
  observe.view( std::cout, r );

  return EXIT_SUCCESS;
 }
