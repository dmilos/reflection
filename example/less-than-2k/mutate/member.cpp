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

    // Traitors. return reference to member it self
    // Also do not care. Pass by value. Demonstration purpose. Recommended const&.
    bool  writter_integer(  int         const& i ) {  m_int    = i; return true; }
    bool  writter_float(    float       const& f ){  m_float  = f; return true; }
    bool  writter_string(   std::string const& s ){  m_string = s; return true; }

  private: // And private members
    int          m_int;
    float        m_float;
    std::string  m_string;
 };

// Reflect to reflection
reflection__CLASS_BEGIN_inherit( MyClassReflection, public, MyClassOriginal )

 reflection__CLASS_MEMBER_mutate( "integer",          MyClassOriginal, writter_integer  )
 reflection__CLASS_MEMBER_mutate( "float-point",      MyClassOriginal, writter_float    )
 reflection__CLASS_MEMBER_mutate( "standard-string",  MyClassOriginal, writter_string   )

reflection__CLASS_END( MyClassReflection, MyClassOriginal );


int main( int argc, char *argv[] )
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
