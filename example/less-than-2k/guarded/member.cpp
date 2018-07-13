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
    bool  writter_integer(  int         const& i ) {  m_int    = i; return true; }
    bool  writter_float(    float       const& f ){  m_float  = f; return true; }
    bool  writter_string(   std::string const& s ){  m_string = s; return true; }

    // Traitors. return reference to member it self
    int         const&  reader_int()   const{ return m_int; }
    float       const&  reader_float() const{ return m_float; }
    std::string const&  reader_string()const{ return m_string; }

  private: // And private members
    int          m_int;
    float        m_float;
    std::string  m_string;
 };

// Reflect to reflection
reflection__CLASS_BEGIN_inherit( MyClassReflection, public, MyClassOriginal )

  reflection__CLASS_MEMBER_guarded(   "integer",          MyClassOriginal, writter_integer,  reader_int      )
  reflection__CLASS_MEMBER_guarded(   "float-point",      MyClassOriginal, writter_float ,   reader_float    )
  reflection__CLASS_MEMBER_guarded(   "standard-string",  MyClassOriginal, writter_string,   reader_string   )

reflection__CLASS_END( MyClassReflection, MyClassOriginal );


int main( int argc, char *argv[] )
 {
  MyClassReflection r;  //!< Reflection of Original

  std::cout <<  ::reflection::property::inspect::present< int const& >( r.get("integer") ) << std::endl;
  ::reflection::property::mutate::process<                int const& >( r.get("integer"), 2424 );
  std::cout <<  ::reflection::property::inspect::present< int const& >( r.get("integer") ) << std::endl;

  std::cout <<  ::reflection::property::inspect::present< float const& >( r.get("float-point") ) << std::endl;
  ::reflection::property::mutate::process<                float const& >( r.get("float-point"), 7890 );
  std::cout <<  ::reflection::property::inspect::present< float const& >( r.get("float-point") ) << std::endl;

  std::cout <<  ::reflection::property::inspect::present< std::string const& >( r.get("standard-string") ) << std::endl;
  ::reflection::property::mutate::process<                std::string const& >( r.get("standard-string"), "asasdasd" );
  std::cout <<  ::reflection::property::inspect::present< std::string const& >( r.get("standard-string") ) << std::endl;


  return EXIT_SUCCESS;
 }
