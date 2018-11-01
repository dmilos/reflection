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
     ,m_string( "Test comment.")
     {
     }

    // Traitors. return reference to member it self
    int         &  traitor_int()   { return m_int; }
    float       &  traitor_float() { return m_float; }
    std::string &  traitor_string(){ return m_string; }

  private: // And private members
    int          m_int;
    float        m_float;
    std::string  m_string;
 };

// Reflect to reflection
reflection__CLASS_BEGIN_inherit( MyClassReflection, public, MyClassOriginal )

  reflection__CLASS_MEMBER_direct(   "integer",          MyClassOriginal, traitor_int      )
  reflection__CLASS_MEMBER_direct(   "float-point",      MyClassOriginal, traitor_float    )
  reflection__CLASS_MEMBER_direct(   "standard-string",  MyClassOriginal, traitor_string   )

reflection__CLASS_END_inherit( MyClassReflection, MyClassOriginal );


int main( int argc, char *argv[] )
 {
  MyClassReflection r;  //!< Reflection of Original

  std::cout <<  ::reflection::property::direct::disclose< int & >( r.get("integer") ) << std::endl;
  ::reflection::property::direct::disclose< int & >( r.get("integer") ) =  2424;
  std::cout <<  ::reflection::property::direct::disclose< int& >( r.get("integer") ) << std::endl;

  std::cout <<  ::reflection::property::direct::disclose< float& >( r.get("float-point") ) << std::endl;
  ::reflection::property::direct::disclose< float& >( r.get("float-point") ) =  2424;
  std::cout <<  ::reflection::property::direct::disclose< float& >( r.get("float-point") ) << std::endl;
  
  std::cout <<  ::reflection::property::direct::disclose< std::string& >( r.get("standard-string") ) << std::endl;
  ::reflection::property::direct::disclose< std::string& >( r.get("standard-string") ) =  "asdasdasdas";
  std::cout <<  ::reflection::property::direct::disclose< std::string& >( r.get("standard-string") ) << std::endl;

  return EXIT_SUCCESS;
 }
