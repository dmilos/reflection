#include <iostream>
#include <iomanip>
#include <string>

#include "reflection/reflection.hpp"


class MyClassOriginal
 {
  public:

    MyClassOriginal()
     {
     }

    bool  writter_int(    int       const& i )
     {
      std::cout << __FUNCTION__ << std::endl;
      m_int  = i; 
      return true; 
     }
    int       const&  reader_int() const{ return m_int; }
  private:
    int m_int;
 };

int free_int_int_string_float_bool( int i , std::string const& s, float & f, bool b )
 {
  std::cout << __FUNCTION__ << std::endl;
  std::cout << i << std::endl;
  std::cout << s << std::endl;
  std::cout << f << std::endl;
  f = 987;
  std::cout << b << std::endl;
  return 10;
 }


// Reflect to reflection
reflection__CLASS_BEGIN_inherit( MyClassReflection, public, MyClassOriginal )

    reflection__CLASS_FUNCTION_free( "free_int_int_string_float_bool", free_int_int_string_float_bool )
  reflection__CLASS_MEMBER_guarded(   "int-point",      MyClassOriginal, writter_int ,   reader_int    )

reflection__CLASS_END_inherit( MyClassReflection, MyClassOriginal );


int main( int argc, char *argv[] )
 {
  MyClassReflection r;  //!< Reflection of Original

  int i=20;
  float f = 42; 

  // Classic "direct" call where c++ take care about arguments type
  std::cout << 
    ::reflection::property::function::execute< int, int, std::string const&, float &, bool >( r.get("free_int_int_string_float_bool"), i, "asdasd", f, true )

;
  std::cout << f << std::endl;

  ::reflection::content::function::argument_struct<std::string>::container_type argument;

  //auto p0 = ::reflection::content::trinity::simple<std::string,int>( 1024 );
  argument.push_back( &r.get("int-point") );

  auto p1 = ::reflection::content::trinity::simple<std::string,int>( 1024 );
  argument.push_back( &p1 );

  auto p2 = ::reflection::content::trinity::simple<std::string,std::string>( "test-string" );
  argument.push_back( &p2 );

  auto p3 = ::reflection::content::trinity::simple<std::string,float>( 42 );
  argument.push_back( &p3 );

  auto p4 = ::reflection::content::trinity::simple<std::string,bool>( true );
  argument.push_back( &p4 );

  std::cout << p1.present() << std::endl;
  std::cout << p2.present() << std::endl;
  ::reflection::content::function::execute<std::string>( r.get("free_int_int_string_float_bool"), argument );
  std::cout << p1.present() << std::endl;
  std::cout << p2.present() << std::endl;

  return EXIT_SUCCESS;
 }
