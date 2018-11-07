#include <iostream>
#include <iomanip>
#include <string>
#include <functional>

#include "reflection/reflection.hpp"

struct MyStructOriginal // Struct with several static members
 {
  public:
    static int          m_int;
    static float        m_float;
    static std::string  m_string;
 };

int          MyStructOriginal::m_int;
float        MyStructOriginal::m_float;
std::string  MyStructOriginal::m_string;


// Reflect to reflection
reflection__CLASS_BEGIN_inherit( MyStructReflection, public, MyStructOriginal )

  reflection__CLASS_COMMON_guarded(   "integer",          MyStructOriginal, m_int     )
  reflection__CLASS_COMMON_guarded(   "float-point",      MyStructOriginal, m_float   )
  reflection__CLASS_COMMON_guarded(   "standard-string",  MyStructOriginal, m_string  )

reflection__CLASS_END_inherit( MyStructReflection, MyStructOriginal );


int main( int argc, char *argv[] )
 {
  std::cout << __FUNCTION__ << std::endl;
  // Some typedefs
  typedef ::reflection::operation::transfer::observe_class<std::ostream> observe_type;
  typedef ::reflection::operation::transfer::xml_struct<std::ostream> xml_type;
  typedef ::reflection::operation::transfer::json_struct<std::ostream> json_type;

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
//TODO//TODO