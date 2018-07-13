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

    // Traitors. return reference to member it self
    int         const&  reader_int()   const{ std::cout<< __FUNCTION__ << std::endl; return m_int; }
    float       const&  reader_float() const{ std::cout<< __FUNCTION__ << std::endl; return m_float; }
    std::string const&  reader_string()const{ std::cout<< __FUNCTION__ << std::endl; return m_string; }

    // Traitors. return reference to member it self
    int         &  traitor_int()   { std::cout<< __FUNCTION__ << std::endl; return m_int; }
    float       &  traitor_float() { std::cout<< __FUNCTION__ << std::endl; return m_float; }
    std::string &  traitor_string(){ std::cout<< __FUNCTION__ << std::endl; return m_string; }

  private: // And private members
    int          m_int;
    float        m_float;
    std::string  m_string;
 };

// Reflect to reflection
reflection__CLASS_BEGIN_inherit( MyClassReflection, public, MyClassOriginal )

  reflection__CLASS_MEMBER_variable(   "integer",          MyClassOriginal,  traitor_int    , reader_int     )
  reflection__CLASS_MEMBER_variable(   "float-point",      MyClassOriginal,  traitor_float  , reader_float   )
  reflection__CLASS_MEMBER_variable(   "standard-string",  MyClassOriginal,  traitor_string , reader_string  )

reflection__CLASS_END( MyClassReflection, MyClassOriginal );


int main( int argc, char *argv[] )
 {
  MyClassReflection r;  //!< Reflection of Original

  std::cout << ::reflection::property::direct::disclose< int & >( r.get("integer") ) << std::endl;
  std::cout << ::reflection::property::inspect::present<  int const& >(  r.get("integer") ) << std::endl;

  std::cout << ::reflection::property::direct::disclose< float & >( r.get("float-point") ) << std::endl;
  std::cout << ::reflection::property::inspect::present<  float const& >(  r.get("float-point") ) << std::endl;

  std::cout << ::reflection::property::direct::disclose< std::string & >( r.get("standard-string") ) << std::endl;
  std::cout << ::reflection::property::inspect::present< std::string const& >(  r.get("standard-string") ) << std::endl;

  return EXIT_SUCCESS;
 }
