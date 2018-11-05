#include <iostream>
#include <iomanip>
#include <string>
#include <functional>

#include "reflection/reflection.hpp"

class MyClassOriginal
 {
  public:

    MyClassOriginal()
     :m_int( 123)
     ,m_float( 456)
     ,m_string("Test comment.")
     {
     }

    // Do some processing, expect assigning
    bool  writer_integer(  int         const& i ){ std::cout<< __FUNCTION__ << std::endl;  m_int    = i; return true; }
    bool  writer_float(    float       const& f ){ std::cout<< __FUNCTION__ << std::endl;  m_float  = f; return true; }
    bool  writer_string(   std::string const& s ){ std::cout<< __FUNCTION__ << std::endl;  m_string = s; return true; }

  private: // And private members
    int          m_int;
    float        m_float;
    std::string  m_string;
 };

// Reflect to reflection
reflection__CLASS_BEGIN_inherit( MyClassReflection, public, MyClassOriginal )

 reflection__CLASS_MEMBER_mutate( "integer",          MyClassOriginal, writer_integer  )
 reflection__CLASS_MEMBER_mutate( "float-point",      MyClassOriginal, writer_float    )
 reflection__CLASS_MEMBER_mutate( "standard-string",  MyClassOriginal, writer_string   )

reflection__CLASS_END_inherit( MyClassReflection, MyClassOriginal );


int main( int argc, char *argv[] )
 {
  MyClassReflection r;  //!< Reflection of Original

  std::cout << ::reflection::property::mutate::process<  int          const& >( r.get("integer"), 2424 ) << std::endl;
  std::cout << ::reflection::property::mutate::process<  float        const& >( r.get("float-point"), 2424.0 ) << std::endl;
  std::cout << ::reflection::property::mutate::process<  std::string  const& >( r.get("standard-string"), "asdasas" ) << std::endl;

  return EXIT_SUCCESS;
 }
