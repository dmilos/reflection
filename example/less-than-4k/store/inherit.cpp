#include <iostream>
#include <iomanip>
#include <string>
#include <functional>

#include "reflection/reflection.hpp"

class MyClassOriginal
 {
  public:
    MyClassOriginal():m_int(123456){ }

    void a(){ }

    int      &  traitor(){ return m_int; }
    int const&  reader()const{ return m_int; }
    bool        writer( int const& a ){ m_int = a; return true; }

  private: // And private member
    int m_int;
 };

void myFunction( MyClassOriginal &instance )
 {
  instance.writer( 12 );
 }


// Reflect to reflection
reflection__CLASS_BEGIN_inherit( MyClassReflection, public, MyClassOriginal )

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

  myFunction( r );


  observe_type observe;

  xml_type xml( observe );// XMLize for example
  observe.view( std::cout, r );

  observe.clear();

  json_type json( observe ); // JSONize also
  observe.view( std::cout, r );

  return EXIT_SUCCESS;
 }
