#include <iostream>
#include <iomanip>
#include <string>
#include <functional>

#include "reflection/reflection.hpp"

class MyClassOriginal
 {
  public:
   enum Enumerator{ enum1, enum2, enum10=10, enum11=150 };

    MyClassOriginal()
     :m_enum( enum1 )
     {
     }

    Enumerator  &  traitor_enum()   { return m_enum; }

  private: // And private members
    Enumerator          m_enum;
 };

// Reflect to reflection
reflection__CLASS_BEGIN_inherit( MyClassReflection, public, MyClassOriginal )

 reflection__CLASS_ENUM_begin( "enum-for-something", MyClassOriginal, MyClassOriginal::Enumerator );
  reflection__CLASS_ENUM_value( "asdasdas1", MyClassOriginal::enum1 )
  reflection__CLASS_ENUM_value( "asdasdas2", MyClassOriginal::enum2 )
  reflection__CLASS_ENUM_value( "asdasdas10", MyClassOriginal::enum10 )
  reflection__CLASS_ENUM_value( "asdasdas11", MyClassOriginal::enum11 )
 reflection__CLASS_ENUM_end(MyClassOriginal::Enumerator)

reflection__CLASS_END_inherit( MyClassReflection, MyClassOriginal );


int main( int argc, char *argv[] )
 {
  typedef ::reflection::operation::transfer::observe_class<std::ostream> observe_type;
  typedef ::reflection::operation::transfer::xml_struct<std::ostream> xml_type;

  MyClassReflection r;  //!< Reflection of Original

  observe_type observe;
  xml_type xml( observe ); // XMLize for example

  observe.view( std::cout, r );

  return EXIT_SUCCESS;
}
