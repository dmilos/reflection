# C++ Reflection

Status
- In progress

Description
 - Yet another implementation of reflection in C++. \
   Link: https://en.wikipedia.org/wiki/Reflection_%28computer_programming%29

Key features:
 - Headers only
 - No additional binaries
 - No third parties
 - Out of the box ready
  - No need to recompile or start some install process.
 - One file to include to start the fun
 - Strong type check
 - Obey existing encapsulation
 - No bloat of existing code and require no change aether.
 - Extra: serialize to XML and JSON

Example:
```c++

#include <iostream>
#include <iomanip>
#include <string>
#include <functional>

#include "reflection/reflection.hpp"

class MyClassOriginal //!< Original condition. Not bloated with any other code.
 {
  public:
    enum Enumerator{ enum1, enum2, enum10=10, enum11=150 };
    typedef std::array<float,2> MyTypDef;

    MyClassOriginal():m_int(123456){ }

    void a(){ }
    std::string const&  b( float const& f ){ static std::string s;   return s; }
    int  c( float const& f, std::string const& str ){  return 1; }
    int  d( float const& f, std::string const& str, bool const& b ){  return 1; }

    int      &  traitor(){ return m_int; }
    int const&  reader()const{ return m_int; }
    bool        writer( int const& a ){ m_int = a; return true; }

  public:
   double m_public = 456;
  private: // And private member
    int m_int;
 };

// Reflect to reflection
reflection__CLASS_BEGIN_inherit( MyClassReflection, public, MyClassOriginal )
  reflection__CLASS_TYPEDEF( "typedef-of-something", MyClassOriginal::MyTypDef );

  reflection__CLASS_ENUM_begin( "enum-for-something", MyClassOriginal::Enumerator );
    reflection__CLASS_ENUM_value( "enum1",  MyClassOriginal::enum1 )
    reflection__CLASS_ENUM_value( "enum2",  MyClassOriginal::enum2 )
    reflection__CLASS_ENUM_value( "enum10", MyClassOriginal::enum10 )
    reflection__CLASS_ENUM_value( "enum11", MyClassOriginal::enum11 )
  reflection__CLASS_ENUM_end(MyClassOriginal::Enumerator)

  reflection__CLASS_MEMBER_mutate(   "asasd3",  MyClassOriginal, writer  )
  reflection__CLASS_MEMBER_direct(   "asasd4",  MyClassOriginal, traitor  )
  reflection__CLASS_MEMBER_inspect(  "asasd5",  MyClassOriginal, reader   )

  reflection__CLASS_MEMBER_variable( "asasd1",  MyClassOriginal, traitor, reader )
  reflection__CLASS_MEMBER_guarded(  "asasd2",  MyClassOriginal, writer, reader  )

  reflection__CLASS_FUNCTION_member( "f1", MyClassOriginal, b )
  reflection__CLASS_FUNCTION_member( "f2", MyClassOriginal, c )
  reflection__CLASS_FUNCTION_member( "f3", MyClassOriginal, d )

  reflection__CLASS_FIELD_guarded(  "some-doubleG", MyClassOriginal, m_public )
  reflection__CLASS_MEMBER_exposed(   "asasd2", MyClassOriginal, traitor,  writer )

reflection__CLASS_END_inherit( MyClassReflection, MyClassOriginal );


int main( int argc, char *argv[] )
 {
  std::cout << __FUNCTION__ << std::endl;
  // Some typedefs
  typedef ::reflection::operation::transfer::observe_class<std::ostream> observe_type;
  typedef ::reflection::operation::transfer::xml_struct<std::ostream> xml_type;
  typedef ::reflection::operation::transfer::json_struct<std::ostream> json_type;

  MyClassReflection r;  //!< Reflection of Original

  observe_type observe;

  xml_type xml( observe ); // XMLize for example
  observe.view( std::cout, r );

  observe.clear();

  json_type json( observe ); // JSONize also
  observe.view( std::cout, r );

  std::cin.get();
  return EXIT_SUCCESS;
 }

 ```
