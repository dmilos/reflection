#include <iostream>
#include <iomanip>
#include <string>
#include <functional>

#include "reflection/reflection.hpp"

struct MyStructOriginal
 {
  public:
    int          m_int;
    float        m_float;
    std::string  m_string;
 };

// Reflect to reflection
reflection__CLASS_BEGIN_inherit( MyStructReflection, public, MyStructOriginal )

  reflection__CLASS_FIELD_direct(   "integer",          MyStructOriginal, public, m_int     )
  reflection__CLASS_FIELD_direct(   "float-point",      MyStructOriginal, public, m_float   )
  reflection__CLASS_FIELD_direct(   "standard-string",  MyStructOriginal, public, m_string  )

reflection__CLASS_END_inherit( MyStructReflection, MyStructOriginal );

reflection__IDSPEC(std::string, "MyStructOriginal", MyStructOriginal);


int main( int argc, char *argv[] )
 {
  std::cout << __FUNCTION__ << std::endl;
  // Some typedefs
  typedef ::reflection::operation::encode::observe_class<std::ostream> observe_type;
  typedef ::reflection::operation::transfer::xml::print_struct<std::ostream> xml_type;
  typedef ::reflection::operation::transfer::json::print_struct<std::ostream> json_type;

  MyStructOriginal o;
  MyStructReflection   r;

  observe_type observe;

  xml_type xml( observe );// XMLize for example
  observe.view( std::cout, r );

  observe.clear();

  json_type json( observe ); // JSONize also
  observe.view( std::cout, r );

  return EXIT_SUCCESS;
 }
//TODO