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
    typedef std::vector<int> MyVectorType;

    MyMainClass():m_int(123456){ m_vector.resize(3,456); }

    void a(){ }
    void                b0( float const& f ){ static std::string s;   }
    std::string const&  b1( float const& f ){ static std::string s;   return s; }
    int  c( float const& f, std::string const& str ){  return 1; }
    int  d( float const& f, std::string const& str, bool const& b ){  return 1; }

    int      &  traitor(){ return m_int; }
    int const&  reader()const{ return m_int; }
    bool        writer( int const& a ){ m_int = a; return true; }
    bool        writerV( int const& a )volatile{ m_int = a; return true; }

    MyFirstClassOriginal      & subsider_traitor(){ return m_subsider; }
    MyFirstClassOriginal const& subsider_reader()const{ return m_subsider; }

    static int   some_static_function( float const&f ){ return 12; }

    Enumerator const&  enum_read()const{ return m_enum; }
    bool               enum_write( Enumerator const& a ){ m_enum = a; return true; }

    MyVectorType const&  vector_reader()const{ return m_vector; }
    MyVectorType      &  vector_traitor(){ return m_vector; }

  public:
   double m_public = 456;
   const double          m_const_public          = 123;
   volatile const double m_volatile_const_public = 456;
   volatile double       m_volatile_public       = 789;

  public:
   static std::string m_static;
  private: // And private member
    Enumerator m_enum = enum2;
    int m_int;
    volatile int m_cv;
    MyFirstClassOriginal m_subsider;
    MyVectorType  m_vector;
 };

std::string MyMainClass::m_static="blahblahfoofoo"; //!< TODO

reflection__CLASS_BEGIN_view( MyFirstClassReflectionView, public, MyFirstClassOriginal, MyFirstClassOriginal* )
   reflection__CLASS_MEMBER_exposed(   "number", MyFirstClassOriginal, traitor, writer )
reflection__CLASS_END_view( MyFirstClassReflectionView, MyFirstClassOriginal );

reflection__CLASS_BEGIN_view( MyBaseClasssReflectionView, public, MyBaseClass, MyBaseClass* )
   reflection__CLASS_MEMBER_exposed(   "number-float", MyBaseClass, traitor, writer )
reflection__CLASS_END_view( MyBaseClasssReflectionView, MyBaseClass );


// Reflect to reflection
//template< typename someType_name >     // Yeah template.
reflection__CLASS_BEGIN_inherit( MyClassReflection, public, MyMainClass )

    reflection__CLASS_BASE_direct(  "1base-something", MyMainClass, public, default, MyBaseClass );
    reflection__CLASS_BASE_inspect( "2base-something", MyMainClass, public, default, MyBaseClass );
    reflection__CLASS_BASE_mutate(  "3base-something", MyMainClass, public, default, MyBaseClass );

    reflection__CLASS_BASE_exposed(  "4base-something", MyMainClass, public, default, MyBaseClass );
    reflection__CLASS_BASE_variable( "5base-something", MyMainClass, public, default, MyBaseClass );
    reflection__CLASS_BASE_guarded(  "6base-something", MyMainClass, public, default, MyBaseClass );

    reflection__CLASS_BASE_trinity(  "7base-something", MyMainClass, public, default, MyBaseClass );

  reflection__CLASS_TYPEDEF_member( "typedef-of-something", MyMainClass, public, MyTypDef );
  reflection__CLASS_TYPEDEF_member( "typedef-of-vector", MyMainClass, public, MyVectorType );

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

   reflection__CLASS_MEMBER_guarded(   "00enum",  MyMainClass, enum_write, enum_read  )

     reflection__CLASS_FUNCTION_member( "traitor", MyMainClass, public, traitor )
     reflection__CLASS_FUNCTION_member( "reader", MyMainClass, public, reader  )
   //reflection__CLASS_FUNCTION_member( "writerV", MyMainClass, public, writerV)
     reflection__CLASS_FUNCTION_member( "writer", MyMainClass, public, writer  )

  reflection__CLASS_FUNCTION_member( "f10", MyMainClass, public, b0 )
  reflection__CLASS_FUNCTION_member( "f11", MyMainClass, public, b1 )

  reflection__CLASS_FUNCTION_member( "f2", MyMainClass, public, c )
  reflection__CLASS_FUNCTION_member( "f3", MyMainClass, public, d )

  reflection__CLASS_FUNCTION_static( "my_static", MyMainClass, public, some_static_function )

   reflection__CLASS_MEMBER_variable(  "0subsider-traitor", MyMainClass, subsider_traitor, subsider_reader )
   reflection__CLASS_MEMBER_variable(  "my-vector", MyMainClass, vector_traitor, vector_reader )

  reflection__CLASS_FIELD_direct(  "some-field-doubleD", MyMainClass, public, m_public )
  reflection__CLASS_FIELD_direct(  "some-const-field-doubleD", MyMainClass, public, m_const_public )
  reflection__CLASS_FIELD_direct(  "some-const-volatile-field-doubleD", MyMainClass, public, m_volatile_const_public )
  reflection__CLASS_FIELD_direct(  "some-volatile-field-doubleD", MyMainClass, public, m_volatile_public )


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

 reflection__CLASS_STATIC_trinity( "some-common-stringT", MyMainClass, public, m_static )

  reflection__CLASS_MEMBER_exposed(   "asasd2", MyMainClass, traitor,  writer )

reflection__CLASS_END_inherit( MyClassReflection, MyMainClass );


int main( int argc, char *argv[] )
 {
  std::cout << __FUNCTION__ << std::endl;

  MyMainClass o;
  MyClassReflection   r;  //!< Reflection of Original, with pointing to some instance

  ::reflection::operation::transfer::observe_class<std::ostream> observe;

  { 
   typedef ::reflection::operation::transfer::xml::print_struct<std::ostream> xml_type;
   auto xml_context = xml_type::context();
   xml_type xml( observe, xml_context );

    //xml_type::register_class<MyFirstClassOriginal, MyFirstClassReflectionView>( observe, xml_context );
    //xml_type::register_class<MyBaseClass, MyBaseClasssReflectionView>( observe, xml_context ); 
    //xml_type::register_enum<MyMainClass::Enumerator>( observe, xml_context ); 
    //xml_type::register_container< std::vector<int > >( observe, xml_context );
  }
  observe.view( std::cout, r ); // XMLize

  return EXIT_SUCCESS;
 }


