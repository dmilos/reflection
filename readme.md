# C++ Reflection

Status
- In progress

Description
 - Yet another implementation of reflection in C++.
 Link: https://en.wikipedia.org/wiki/Reflection_%28computer_programming%29

Key features:
 - Headers only
 - No additional binaries 
 - No third parties
 - Out of the box ready
  - No need to recompile or start some install process.
 - One file to include to start the fun
 - Strong type check


Example:
```c++

#include <iostream>
#include <iomanip>
#include <string>
#include <functional>

#include "reflection/reflection.hpp"

class MyClassOriginal
 {
  public:

    MyClassOriginal(){ }

    void a(){ }
    std::string const&  b( float const& f ){  return "asd"; }
    int  c( float const& f, std::string const& str ){  return 1; }
    int  d( float const& f, std::string const& str, bool const& b ){  return 1; }

    int      &  traitor(){ return m_int; }
    int const&  reader()const{ return m_int; }
    bool        writter( int const& a ){ m_int = a; return true; }

  private: // And private member
    int m_int;
 };

// Reflect to reflection
reflection__CLASS_BEGIN_inherit( MyClassReflection, public, MyClassOriginal )

  reflection__CLASS_MEMBER_mutate(    "asasd3",  MyClassOriginal, writter  )
  reflection__CLASS_MEMBER_direct(    "asasd4",  MyClassOriginal, traitor  )
  reflection__CLASS_MEMBER_inspect(   "asasd5",  MyClassOriginal, reader   )

  reflection__CLASS_MEMBER_variable(  "asasd1",  MyClassOriginal, traitor, reader )
  reflection__CLASS_MEMBER_guarded(   "asasd2",  MyClassOriginal, writter, reader  )

  reflection__CLASS_FUNCTION_member( "f1", MyClassOriginal, b )
  reflection__CLASS_FUNCTION_member( "f2", MyClassOriginal, c )
  reflection__CLASS_FUNCTION_member( "f3", MyClassOriginal, d )

reflection__CLASS_END( MyClassReflection, MyClassOriginal );


int main_readme( int argc, char *argv[] )
 {
  std::cout << __FUNCTION__ << std::endl;
  // Some typedefs
  typedef ::reflection::operation::transfer::observe_class<std::ostream> observe_type;
  typedef ::reflection::operation::transfer::xml_struct<std::ostream> xml_type;
  typedef ::reflection::property::structure_class<> structure_type;

  MyClassReflection r;  //!< Reflection of Original

  // XMLize for example
  observe_type observe;
  xml_type xml( observe );

  observe.view( std::cout, r );

  std::cin.get();
  return EXIT_SUCCESS;
 }


 ```

TODO:
 - TODO
