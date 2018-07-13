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
    int         &  traitor_int()   { return m_int; }
    float       &  traitor_float() { return m_float; }
    std::string &  traitor_string(){ return m_string; }

    // Do some processing, expect assigning
    bool  writter_integer(  int         const& i ) {  m_int    = i; return true; }
    bool  writter_float(    float       const& f ){  m_float  = f; return true; }
    bool  writter_string(   std::string const& s ){  m_string = s; return true; }

    // Traitors. return reference to member it self
    int         const&  reader_integert()   const{ return m_int; }
    float       const&  reader_float() const{ return m_float; }
    std::string const&  reader_string()const{ return m_string; }

  private: // And private members
    int          m_int;
    float        m_float;
    std::string  m_string;
 };

// Reflect to reflection
reflection__CLASS_BEGIN_inherit( MyClassReflection, public, MyClassOriginal )
  reflection__CLASS_MEMBER_trinity(   "integer",          MyClassOriginal, traitor_int   , writter_integer , reader_integert )
  reflection__CLASS_MEMBER_trinity(   "float-point",      MyClassOriginal, traitor_float , writter_float   , reader_float    )
  reflection__CLASS_MEMBER_trinity(   "standard-string",  MyClassOriginal, traitor_string, writter_string  , reader_string   )
reflection__CLASS_END( MyClassReflection, MyClassOriginal );

int main( int argc, char *argv[] )
 {
  std::cout << __FUNCTION__ << std::endl;
  // Some typedefs
  typedef ::reflection::operation::transfer::observe_class<std::ostream> observe_type;
  typedef ::reflection::operation::transfer::xml_struct<std::ostream> xml_type;

  MyClassReflection r;  //!< Reflection of Original

  // XMLize for example
  observe_type observe;
  xml_type xml( observe );

  observe.view( std::cout, r );

  return EXIT_SUCCESS;
 }
