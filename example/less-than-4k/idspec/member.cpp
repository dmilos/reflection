#include <iostream>
#include <iomanip>
#include <string>
#include <array>
#include <functional>

#include "reflection/reflection.hpp"

class MyClassOriginal
 {
  public:

    MyClassOriginal()
     {
     }
     
     typedef std::array<float,2> PointType;

    // Do some processing, expect assigning
    bool  writer_point(  PointType         const& i ){ std::cout<< __FUNCTION__ << std::endl;  m_point  = i; return true; }

    // Traitors. return reference to member it self
    PointType         const&  reader_point()   const{ std::cout<< __FUNCTION__ << std::endl; return m_point; }

    // Traitors. return reference to member it self
    PointType         &  traitor_point()   { std::cout<< __FUNCTION__ << std::endl; return m_point; }

  private: // And private members
    PointType          m_point;
 };

// Reflect to reflection
reflection__CLASS_BEGIN_inherit( MyClassReflection, public, MyClassOriginal )

  reflection__CLASS_MEMBER_trinity(   "point",          MyClassOriginal,  traitor_point   , writer_point ,reader_point     )

reflection__CLASS_END_inherit( MyClassReflection, MyClassOriginal );

reflection__IDSPEC( std::string, "$POINT", MyClassOriginal::PointType )



int main( int argc, char *argv[] )
 {
  std::cout << __FUNCTION__ << std::endl;
  // Some typedefs
  typedef ::reflection::operation::transfer::observe_class<std::ostream> observe_type;
  typedef ::reflection::operation::transfer::xml::print_struct<std::ostream> xml_type;
  typedef ::reflection::operation::transfer::json::print_struct<std::ostream> json_type;

  MyClassReflection r;  //!< Reflection of Original

  observe_type observe;

  xml_type xml( observe );// XMLize for example
  observe.view( std::cout, r );

  observe.clear();

  json_type json( observe ); // JSONize also
  observe.view( std::cout, r );

  return EXIT_SUCCESS;
 }
