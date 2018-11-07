#include <iostream>
#include <iomanip>
#include <string>
#include <functional>

#include "reflection/reflection.hpp"

class MyFirstClassOriginal
 {
  public:
    MyFirstClassOriginal():m_float(98765){ }

    void a(){ }
    float      &  traitor(){ return m_float; }
    float const&  reader()const{ return m_float; }
    bool          writer( float const& a ){ m_float = a; return true; }

  private: // And private member
    float m_float;
 };

class MyClassOriginal //!< Original condition. Not bloated with any other code.
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
    bool        writer( int const& a ){ m_int = a; return true; }

    MyFirstClassOriginal & subsider_traitor(){ return m_subsider; }

    static int   some_static_function( float const&f ){ return 12; }

  public:
   double m_public = 456;
  public:
   static double m_static;
  private: // And private member
    int m_int;
    MyFirstClassOriginal m_subsider;
 };

double MyClassOriginal::m_static; //!< TODO

reflection__CLASS_BEGIN_view( MyFirstClassReflectionView, public, MyFirstClassOriginal, MyFirstClassOriginal* )
   reflection__CLASS_MEMBER_exposed(   "number", MyFirstClassOriginal, traitor, writer )
reflection__CLASS_END_view( MyFirstClassReflectionView, MyFirstClassOriginal );


// Reflect to reflection
//template< typename someType_name >     // Yeah template.
reflection__CLASS_BEGIN_view( MyClassReflection, public, MyClassOriginal, MyClassOriginal* )

  reflection__CLASS_TYPEDEF( "typedef-of-something", MyClassOriginal::MyTypDef );
 
  reflection__CLASS_ENUM_begin( "enum-for-something", MyClassOriginal::Enumerator );
    reflection__CLASS_ENUM_value( "enum1",  MyClassOriginal::enum1 )
    reflection__CLASS_ENUM_value( "enum2",  MyClassOriginal::enum2 )
    reflection__CLASS_ENUM_value( "enum10", MyClassOriginal::enum10 )
    reflection__CLASS_ENUM_value( "enum11", MyClassOriginal::enum11 )
   reflection__CLASS_ENUM_end( MyClassOriginal::Enumerator )
 
  reflection__CLASS_MEMBER_mutate(    "asasd3",  MyClassOriginal, writer  )
  reflection__CLASS_MEMBER_direct(    "asasd4",  MyClassOriginal, traitor  )
  reflection__CLASS_MEMBER_inspect(   "asasd5",  MyClassOriginal, reader   )
 
  reflection__CLASS_MEMBER_variable(  "asasd1",  MyClassOriginal, traitor, reader )
  reflection__CLASS_MEMBER_guarded(   "asasd2",  MyClassOriginal, writer, reader  )
 
  reflection__CLASS_FUNCTION_member( "f1", MyClassOriginal, b )
  reflection__CLASS_FUNCTION_member( "f2", MyClassOriginal, c )
  reflection__CLASS_FUNCTION_member( "f3", MyClassOriginal, d )

  reflection__CLASS_FUNCTION_static( "my_static", MyClassOriginal, some_static_function )

  //reflection__CLASS_SUBSIDER_direct( "subsider", MyClassOriginal, MyFirstClassOriginal, MyFirstClassReflectionView, subsider_traitor )

  reflection__CLASS_FIELD_direct(  "some-doubleD", MyClassOriginal, m_public )
  reflection__CLASS_FIELD_mutate(  "some-doubleM", MyClassOriginal, m_public )
  reflection__CLASS_FIELD_inspect( "some-doubleI", MyClassOriginal, m_public )

  reflection__CLASS_FIELD_exposed(  "some-doubleE", MyClassOriginal, m_public )
  reflection__CLASS_FIELD_guarded(  "some-doubleG", MyClassOriginal, m_public )
  reflection__CLASS_FIELD_variable( "some-doubleV", MyClassOriginal, m_public )

  reflection__CLASS_FIELD_trinity( "some-doubleT", MyClassOriginal, m_public )

 reflection__CLASS_COMMON_direct( "some-common-doubleD", MyClassOriginal, m_static )
 reflection__CLASS_COMMON_inspect( "some-common-doubleI", MyClassOriginal, m_static )
 reflection__CLASS_COMMON_mutate( "some-common-doubleM", MyClassOriginal, m_static )

 reflection__CLASS_COMMON_variable( "some-common-doubleV", MyClassOriginal, m_static )
 reflection__CLASS_COMMON_guarded( "some-common-doubleG", MyClassOriginal, m_static )
 reflection__CLASS_COMMON_exposed( "some-common-doubleE", MyClassOriginal, m_static )

 reflection__CLASS_COMMON_trinity( "some-common-doubleT", MyClassOriginal, m_static )

  reflection__CLASS_MEMBER_exposed(   "asasd2", MyClassOriginal, traitor,  writer )

reflection__CLASS_END_view( MyClassReflection, MyClassOriginal );


int main( int argc, char *argv[] )
 {
  std::cout << __FUNCTION__ << std::endl;
  // Some typedefs
  typedef ::reflection::operation::transfer::observe_class<std::ostream> observe_type;
  typedef ::reflection::operation::transfer::xml_struct<std::ostream> xml_type;
  typedef ::reflection::operation::transfer::json_struct<std::ostream> json_type;
  typedef ::reflection::operation::transfer::cpp_struct<std::ostream> cpp_type;

  MyClassOriginal o;
  MyClassReflection   r( &o );  //!< Reflection of Original, with pointing to some instance
  //MyClassReflection<int>   r0;  //!< Reflection of Original, with pointing to some instance
  //MyClassReflection<float> r1( &o );  //!< Reflection of Original, with pointing to same instance

  observe_type observe;

  cpp_type cpp( observe );// CPPize for example
  observe.view( std::cout, r );

  observe.clear();
  xml_type xml( observe );// XMLize for example
  observe.view( std::cout, r );

  observe.clear();
  json_type json( observe ); // JSONize also
  observe.view( std::cout, r );

  for( auto & v: r )
   {
    std::cout << ::reflection::content::category::pure<std::string>( *v.second).identifier() << "  ";
    std::cout << v.first  <<";";
    std::cout << std::endl;
   }

  return EXIT_SUCCESS;
 }
