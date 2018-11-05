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
    bool  writer_integer(  int         const& i ) {  m_int    = i; return true; }
    bool  writer_float(    float       const& f ){  m_float  = f; return true; }
    bool  writer_string(   std::string const& s ){  m_string = s; return true; }

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

  reflection__CLASS_MEMBER_exposed(   "integer",          MyClassOriginal, traitor_int   , writer_integer    )
  reflection__CLASS_MEMBER_exposed(   "float-point",      MyClassOriginal, traitor_float , writer_float      )
  reflection__CLASS_MEMBER_exposed(   "standard-string",  MyClassOriginal, traitor_string, writer_string     )

reflection__CLASS_END_inherit( MyClassReflection, MyClassOriginal );


int main( int argc, char *argv[] )
 {
  MyClassReflection r;  //!< Reflection of Original

  std::cout <<  ::reflection::property::direct::disclose< int      & >( r.get("integer") ) << std::endl;
                ::reflection::property::mutate::process<  int const& >( r.get("integer"), 2424 );
  std::cout <<  ::reflection::property::direct::disclose< int     & >( r.get("integer") ) << std::endl;

  std::cout <<  ::reflection::property::direct::disclose< float      & >( r.get("float-point") ) << std::endl;
                ::reflection::property::mutate::process<  float const& >( r.get("float-point"), 7890 );
  std::cout <<  ::reflection::property::direct::disclose< float      & >( r.get("float-point") ) << std::endl;

  std::cout <<  ::reflection::property::direct::disclose< std::string       & >( r.get("standard-string") ) << std::endl;
                ::reflection::property::mutate::process<  std::string const & >( r.get("standard-string"), "asasdasd" );
  std::cout <<  ::reflection::property::direct::disclose< std::string       & >( r.get("standard-string") ) << std::endl;

  std::cout << ::reflection::property::direct::disclose< int & >( r.get("integer") ) << std::endl;
               ::reflection::property::direct::disclose< int & >( r.get("integer") ) =  2424;
  std::cout << ::reflection::property::direct::disclose< int & >( r.get("integer") ) << std::endl;

  std::cout <<  ::reflection::property::direct::disclose< float& >( r.get("float-point") ) << std::endl;
                ::reflection::property::direct::disclose< float& >( r.get("float-point") ) =  2424;
  std::cout <<  ::reflection::property::direct::disclose< float& >( r.get("float-point") ) << std::endl;
  
  std::cout <<  ::reflection::property::direct::disclose< std::string& >( r.get("standard-string") ) << std::endl;
                ::reflection::property::direct::disclose< std::string& >( r.get("standard-string") ) =  "asdasdasdas";
  std::cout <<  ::reflection::property::direct::disclose< std::string& >( r.get("standard-string") ) << std::endl;

  return EXIT_SUCCESS;
 }
