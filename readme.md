# C++ Reflection

### Status
- In progress.

### Description
 - Yet another implementation of reflection in C++. \
   Link: https://en.wikipedia.org/wiki/Reflection_%28computer_programming%29

### Key features:
 - General:
    * Headers only
    * No additional binaries
    * No third parties
    * Out of the box ready
    * No need to recompile or start some install process.
    * One file to include to start the fun
    * Strong type check
 - Specific:
    * Obey existing encapsulation
    * No bloat of existing code and require no change aether.
    * Add or remove properties in run-time.
    * Track: friends, accessibility, enums, typedefs, (static/const/volatile)data members, member/static/const functions
    * Extra: 
        - Serializations to XML, JSON, YAML and INI.
        - Bind to Python
        - Reflect to CPP, Python and Java

### Example:
```c++

#include <iostream>
#include <iomanip>
#include <string>
#include <functional>

#include "reflection/reflection.hpp"

class MyClassOriginal //!< In original condition. Not bloated with any other code.
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

    static int   some_static_function( float const&f ){ return 12; }

  public:
   double m_public = 456;
  public:
   static std::string m_static;
  private:
    int m_int;
 };

int  free_int_int_string( int &i , std::string const& s )
 {
  std::cout << __FUNCTION__ << std::endl;
  std::cout << i << std::endl;
  i = 98765;
  std::cout << s << std::endl;
  return 10;
 }

std::string MyClassOriginal::m_static;

// Reflect to reflection
reflection__CLASS_BEGIN_inherit( MyClassReflection, public, MyClassOriginal )
  reflection__CLASS_TYPEDEF_member( "typedef-of-something", MyClassOriginal, public, MyTypDef );

  reflection__CLASS_ENUM_begin( "enum-for-something", MyClassOriginal::Enumerator );
    reflection__CLASS_ENUM_value( "enum1",  MyClassOriginal::enum1 )
    reflection__CLASS_ENUM_value( "enum2",  MyClassOriginal::enum2 )
    reflection__CLASS_ENUM_value( "enum10", MyClassOriginal::enum10 )
    reflection__CLASS_ENUM_value( "enum11", MyClassOriginal::enum11 )
  reflection__CLASS_ENUM_end( MyClassOriginal::Enumerator )

  reflection__CLASS_MEMBER_mutate(   "asasd1",  MyClassOriginal, writer   )//!< Access to member by using only writer
  reflection__CLASS_MEMBER_direct(   "asasd2",  MyClassOriginal, traitor  )//!< Access to member by using only traitor
  reflection__CLASS_MEMBER_inspect(  "asasd5",  MyClassOriginal, reader   )//!< Access to member by using only reader

  reflection__CLASS_MEMBER_variable( "asasd3",  MyClassOriginal, traitor, reader ) //!< Access to member by using traitor and reader
  reflection__CLASS_MEMBER_guarded(  "asasd4",  MyClassOriginal, writer, reader  ) //!< Access to member by using writer  and reader
  reflection__CLASS_MEMBER_exposed(  "asasd5",  MyClassOriginal, traitor, writer ) //!< Access to member by using traitor and writer

  reflection__CLASS_FUNCTION_member( "f1", MyClassOriginal, public, b ) //!< Member function
  reflection__CLASS_FUNCTION_member( "f2", MyClassOriginal, public, c ) //!< Member function
  reflection__CLASS_FUNCTION_member( "f3", MyClassOriginal, public, d ) //!< Member function

  reflection__CLASS_FUNCTION_free( "free_int_int_string",  free_int_int_string ) //!< Inject non-member function.

  reflection__CLASS_FUNCTION_static(  "my_static",           MyClassOriginal, public, some_static_function )

  reflection__CLASS_FIELD_guarded(    "some-doubleG",        MyClassOriginal, public, m_public   )
  reflection__CLASS_STATIC_mutate(    "some-common-stringI", MyClassOriginal, public, m_static   )

reflection__CLASS_END_inherit( MyClassReflection, MyClassOriginal );


int main( int argc, char *argv[] )
 {
  std::cout << __FUNCTION__ << std::endl;
  // Some typedefs
  typedef ::reflection::operation::transfer::observe_class<std::ostream> observe_type;
  typedef ::reflection::operation::transfer::xml::print_struct<std::ostream> xml_type;
  typedef ::reflection::operation::transfer::json::print_struct<std::ostream> json_type;

  MyClassReflection r;  //!< Reflection of Original

  observe_type observe; //!< Have generalized serialization algorithm

  xml_type xml( observe ); //!< Fill them with specific things about XML
  observe.view( std::cout, r );//!< XMLize

  observe.clear();

  json_type json( observe ); //!< Fill them with specific thing about JSON
  observe.view( std::cout, r );//!< JSONize also

  std::cin.get();
  return EXIT_SUCCESS;
 }

 ```
### Install:
1. Clone this Repository: \
  Examples:
    - Windows : git clone https://github.com/dmilos/reflection.git c:\my-work-folder\my-git-folder\reflection
    - Linux   : git clone https://github.com/dmilos/reflection.git /home/my-user-name/my-work-folder/my-git-folder/reflection
2. Inform compiler where to find headers: \
  Examples:
   - MSVC : /Ic:\my-work-folder\my-git-folder\reflection\src
   - gcc  : -I/home/my-user-name/my-work-folder/my-git-folder/reflection/src


### Note:
Tested against :
 - gcc 6.4.0
 - gcc 7.3.0
 - MSVC 2015 14.0 Update 3
 - MSVC 2017 15.5.6