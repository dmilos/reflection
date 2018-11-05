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

    bool  writer_int(    int       const& i )
     {
      std::cout << __FUNCTION__ << std::endl;
      m_int  = i; 
      return true; 
     }
    int       const&  reader_int() const{ return m_int; }
  private:
    int m_int;
 };

  int free_int_int_string( int i, std::string const& s )
   {
    std::cout << __FUNCTION__ << std::endl;
    std::cout << i << std::endl;
    std::cout << s << std::endl;
    return 10;
   }


// Reflect to reflection
reflection__CLASS_BEGIN_inherit( MyClassReflection, public, MyClassOriginal )

  reflection__CLASS_FUNCTION_free( "free_int_int_string", free_int_int_string )
  reflection__CLASS_MEMBER_guarded(   "int-point",      MyClassOriginal, writer_int ,   reader_int    )

reflection__CLASS_END_inherit( MyClassReflection, MyClassOriginal );


int main( int argc, char *argv[] )
 {
  MyClassReflection r;  //!< Reflection of Original

  int i=20;
  // Classic "direct" call where c++ take care about arguments type
  //std::cout <<
   ::reflection::property::function::execute< int, int, std::string const& >( r.get("free_int_int_string"), i, "aaa" )
  // << std::endl
  ;

  ::reflection::content::function::argument_struct<std::string>::container_type argument;

  //auto p0 = ::reflection::content::trinity::simple<std::string,int>( 1024 );
  argument.push_back( &r.get("int-point") );

  auto p1 = ::reflection::content::trinity::simple<std::string,int>( 1024 );
  argument.push_back( &p1 );

  auto p2 = ::reflection::content::trinity::simple<std::string,std::string>( "test-string" );
  argument.push_back( &p2 );

  //std::cout << p0.present() << std::endl;
  ::reflection::content::function::execute<std::string>( r.get("free_int_int_string"), argument );
  //std::cout << p0.present() << std::endl;

  return EXIT_SUCCESS;
 }
