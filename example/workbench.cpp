#include <iostream>
#include <iomanip>
#include <string>
#include <functional>

#include "reflection/reflection.hpp"

class MyFirstClassOriginal //!< Original condition. Not bloated with any other code.
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


class MyBaseClass //!< Original condition. Not bloated with any other code.
 {
  public:
    MyBaseClass():m_float(98765){ }

    void a(){ }
    float      &  traitor(){ return m_float; }
    float const&  reader()const{ return m_float; }
    bool          writer( float const& a ){ m_float = a; return true; }

  private: // And private member
    float m_float;
 };

class MyMainClass //!< Original condition. Not bloated with any other code.
 : public MyBaseClass
 {
  public:
    enum Enumerator{ enum1, enum2, enum10=10, enum11=150 };
    typedef std::array<float,2> MyTypDef;

    MyMainClass():m_int(123456){ }

    void a(){ }
    std::string const&  b1( float const& f ){ static std::string s;   return s; }
    void                b0( float const& f ){ static std::string s;   }
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
   static std::string m_static;
  private: // And private member
    int m_int;
    MyFirstClassOriginal m_subsider;
 };

std::string MyMainClass::m_static="blahblahfoofoo"; //!< TODO

reflection__CLASS_BEGIN_view( MyFirstClassReflectionView, public, MyFirstClassOriginal, MyFirstClassOriginal* )
   reflection__CLASS_MEMBER_exposed(   "number", MyFirstClassOriginal, traitor, writer )
reflection__CLASS_END_view( MyFirstClassReflectionView, MyFirstClassOriginal );


// Reflect to reflection
//template< typename someType_name >     // Yeah template.
reflection__CLASS_BEGIN_inherit( MyClassReflection, public, MyMainClass )

reflection__CLASS_BASE_inspect( "base-something", MyMainClass, public , MyClassBase );


  reflection__CLASS_TYPEDEF_member( "typedef-of-something", MyMainClass, public, MyTypDef );

  reflection__CLASS_ENUM_begin( "enum-for-something", MyMainClass::Enumerator );
    reflection__CLASS_ENUM_value( "enum1",  MyMainClass::enum1 )
    reflection__CLASS_ENUM_value( "enum2",  MyMainClass::enum2 )
    reflection__CLASS_ENUM_value( "enum10", MyMainClass::enum10 )
    reflection__CLASS_ENUM_value( "enum11", MyMainClass::enum11 )
   reflection__CLASS_ENUM_end( MyMainClass::Enumerator )
 
  reflection__CLASS_MEMBER_mutate(    "asasd3",  MyMainClass, writer  )
  reflection__CLASS_MEMBER_direct(    "asasd4",  MyMainClass, traitor  )
  reflection__CLASS_MEMBER_inspect(   "asasd5",  MyMainClass, reader   )
 
  reflection__CLASS_MEMBER_variable(  "asasd1",  MyMainClass, traitor, reader )
  reflection__CLASS_MEMBER_guarded(   "asasd2",  MyMainClass, writer, reader  )

  //reflection__CLASS_FUNCTION_member( "f10", MyMainClass, b0 )
  reflection__CLASS_FUNCTION_member( "f11", MyMainClass, b1 )

  reflection__CLASS_FUNCTION_member( "f2", MyMainClass, c )
  reflection__CLASS_FUNCTION_member( "f3", MyMainClass, d )

  reflection__CLASS_FUNCTION_static( "my_static", MyMainClass, some_static_function )

  //reflection__CLASS_SUBSIDER_direct( "subsider", MyMainClass, MyFirstClassOriginal, MyFirstClassReflectionView, subsider_traitor )

  reflection__CLASS_FIELD_direct(  "some-field-doubleD", MyMainClass, public, m_public )
  reflection__CLASS_FIELD_mutate(  "some-field-doubleM", MyMainClass, public, m_public )
  reflection__CLASS_FIELD_inspect( "some-field-doubleI", MyMainClass, public, m_public )

  reflection__CLASS_FIELD_exposed(  "some-field-doubleE", MyMainClass, public, m_public )
  reflection__CLASS_FIELD_guarded(  "some-field-doubleG", MyMainClass, public, m_public )
  reflection__CLASS_FIELD_variable( "some-field-doubleV", MyMainClass, public, m_public )

  reflection__CLASS_FIELD_trinity( "some-field-doubleT", MyMainClass, public, m_public )

 reflection__CLASS_STATIC_direct(  "some-common-stringD", MyMainClass, public, m_static )
 reflection__CLASS_STATIC_inspect( "some-common-stringI", MyMainClass, public, m_static )
 reflection__CLASS_STATIC_mutate(  "some-common-stringM", MyMainClass, public, m_static )

 reflection__CLASS_STATIC_variable( "some-common-stringV", MyMainClass, public, m_static )
 reflection__CLASS_STATIC_guarded(  "some-common-stringG", MyMainClass, public, m_static )
 reflection__CLASS_STATIC_exposed(  "some-common-stringE", MyMainClass, public, m_static )

 reflection__CLASS_STATIC_trinity( "some-common-stringT", MyMainClass,public,  m_static )

  reflection__CLASS_MEMBER_exposed(   "asasd2", MyMainClass, traitor,  writer )

reflection__CLASS_END_inherit( MyClassReflection, MyMainClass );


int main( int argc, char *argv[] )
 {
  std::cout << __FUNCTION__ << std::endl;
  // Some typedefs
  typedef ::reflection::operation::transfer::observe_class<std::ostream> observe_type;
  typedef ::reflection::operation::transfer::xml_struct<std::ostream> xml_type;
  typedef ::reflection::operation::transfer::json_struct<std::ostream> json_type;
  typedef ::reflection::operation::transfer::cpp_struct<std::ostream> cpp_type;
  typedef ::reflection::operation::transfer::yaml_struct<std::ostream> yaml_type;
  typedef ::reflection::operation::transfer::protobuf_struct<std::ostream> protobuf_type;
  typedef ::reflection::operation::transfer::ini_struct<std::ostream> ini_type;

  MyMainClass o;
  MyClassReflection   r;  //!< Reflection of Original, with pointing to some instance
  //MyClassReflection<int>   r0;  //!< Reflection of Original, with pointing to some instance
  //MyClassReflection<float> r1( &o );  //!< Reflection of Original, with pointing to same instance

  observe_type observe;

  cpp_type cpp( observe );// CPPize for example
  observe.view( std::cout, r );

  observe.clear();
  { xml_type xml( observe ); } // XMLize
  observe.view( std::cout, r );

  observe.clear();
  { json_type json( observe ); } // JSONize
  observe.view( std::cout, r );

  observe.clear();
  { yaml_type yaml( observe ); } // YAMLize
  observe.view( std::cout, r );

  observe.clear();
  { protobuf_type protobuf( observe ); } // Protobufferize
  observe.view( std::cout, r );

  observe.clear();
  { ini_type ini( observe ); } // INIrize
  observe.view( std::cout, r );

  //for( auto & v: r )
  // {
  //  std::cout << ::reflection::content::category::pure<std::string>( *v.second ).identifier() << "  ";
  //  std::cout << v.first  <<";";
  //  std::cout << std::endl;
  // }

 ::reflection::property::direct::field_class<int, int const&,MyClassReflection,MyClassReflection*>   aa0(  nullptr,nullptr);
 ::reflection::property::mutate::field_class<int, int const&,MyClassReflection,MyClassReflection*,bool>   aa1(  nullptr,nullptr);

 ::reflection::property::inspect::field_class<int, int const&,MyClassReflection,MyClassReflection*>   aa2(  nullptr,nullptr);
 ::reflection::property::variable::field_class<int, int const&,int const&,MyClassReflection,MyClassReflection*>   aa3(  nullptr,nullptr);
 ::reflection::property::guarded::field_class<int, int const&,int const&,MyClassReflection,MyClassReflection*,bool>   aa4(  nullptr,nullptr);

 ::reflection::property::exposed::field_class<int, int &,int const&,MyClassReflection,MyClassReflection*,bool>   aa5(  nullptr,nullptr);
 ::reflection::property::trinity::field_class<int, int &,int const&,int const&,MyClassReflection,MyClassReflection*,bool>   aa6(  nullptr,nullptr);
  return EXIT_SUCCESS;
 }
