#include <iostream>
#include <iomanip>
#include <string>
#include <functional>

#include "reflection/reflection.hpp"

class MyClassOriginal
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
    bool        writter( int const& a ){ m_int = a; return true; }

  private: // And private member
    int m_int;
 };

// Reflect to reflection
template< typename someType_name >     // Yeah template.
reflection__CLASS_BEGIN_view( MyClassReflection, public, MyClassOriginal, MyClassOriginal* )

  reflection__CLASS_TYPEDEF( "typedef-of-something", MyClassOriginal::MyTypDef );

  reflection__CLASS_ENUM_begin( "enum-for-something", MyClassOriginal::Enumerator );
    reflection__CLASS_ENUM_value( "enum1", MyClassOriginal::enum1 )
    reflection__CLASS_ENUM_value( "enum2", MyClassOriginal::enum2 )
    reflection__CLASS_ENUM_value( "enum10", MyClassOriginal::enum10 )
    reflection__CLASS_ENUM_value( "enum11", MyClassOriginal::enum11 )
   reflection__CLASS_ENUM_end( MyClassOriginal::Enumerator )

  reflection__CLASS_MEMBER_mutate(    "asasd3",  MyClassOriginal, writter  )
  reflection__CLASS_MEMBER_direct(    "asasd4",  MyClassOriginal, traitor  )
  reflection__CLASS_MEMBER_inspect(   "asasd5",  MyClassOriginal, reader   )

  reflection__CLASS_MEMBER_variable(  "asasd1",  MyClassOriginal, traitor, reader )
  reflection__CLASS_MEMBER_guarded(   "asasd2",  MyClassOriginal, writter, reader  )

  reflection__CLASS_FUNCTION_member( "f1", MyClassOriginal, b )
  reflection__CLASS_FUNCTION_member( "f2", MyClassOriginal, c )
  reflection__CLASS_FUNCTION_member( "f3", MyClassOriginal, d )

  //reflection__CLASS_SUBSIDER_direct( "sub0", MyClassOriginal, MySubSiderReflection, traitor )

   reflection__CLASS_MEMBER_exposed(   "asasd2", MyClassOriginal, traitor,  writter )

reflection__CLASS_END_view( MyClassReflection, MyClassOriginal );


int main( int argc, char *argv[] )
 {
  std::cout << __FUNCTION__ << std::endl;
  // Some typedefs
  typedef ::reflection::operation::transfer::observe_class<std::ostream> observe_type;
  typedef ::reflection::operation::transfer::xml_struct<std::ostream> xml_type;
  typedef ::reflection::operation::transfer::json_struct<std::ostream> json_type;

  MyClassOriginal o;
  MyClassReflection<int> r( &o );  //!< Reflection of Original, with pointing to some instance
  MyClassReflection<float> r1( &o );  //!< Reflection of Original, with pointing to same instance

  observe_type observe;

  xml_type xml( observe );// XMLize for example
  observe.view( std::cout, r );

  observe.clear();

  json_type json( observe ); // JSONize also
  observe.view( std::cout, r );

  return EXIT_SUCCESS;
 }
