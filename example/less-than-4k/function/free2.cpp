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

void free_void_int( int &i )
 {
  std::cout << __FUNCTION__ << std::endl;
  std::cout << i << std::endl;
  i = 12345;
 }

int  free_int_int( int &i  )
 {
  std::cout << __FUNCTION__ << std::endl;
  std::cout << i << std::endl;
  i = 98765;
  return 10;
 }

// Reflect to reflection
reflection__CLASS_BEGIN_inherit( MyClassReflection, public, MyClassOriginal )

    reflection__CLASS_FUNCTION_free( "free_void_int", free_void_int )
    reflection__CLASS_FUNCTION_free( "free_int_int",  free_int_int )
  reflection__CLASS_MEMBER_guarded(   "int-point",      MyClassOriginal, writer_int ,   reader_int    )

reflection__CLASS_END_inherit( MyClassReflection, MyClassOriginal );


int main( int argc, char *argv[] )
 {
  MyClassReflection r;  //!< Reflection of Original

  int i=20;

  // Classic "direct" call where c++ take care about arguments type check

  std::cout <<  i << std::endl;
  ::reflection::property::function::execute<int, int& >( r.get( "free_int_int" ), i );
  std::cout << i << std::endl;

  ::reflection::property::function::execute<void, int&>( r.get( "free_void_int" ), i );
  std::cout << i << std::endl;


  ::reflection::content::function::argument_struct<std::string>::container_type argument;
  argument.resize(2);

  auto p0i = ::reflection::content::trinity::simple<std::string,int>( 100 );
  auto p0v = ::reflection::content::trinity::void_class<std::string,bool> {} ;

  auto p1 = ::reflection::content::trinity::simple<std::string,int>( 1024 );

  argument[0]= &p0v;
  argument[1]= &p1;

  std::cout << p1.present() << std::endl;
  ::reflection::content::function::execute<std::string>( r.get("free_void_int"), argument );
  std::cout << p1.present() << std::endl;

  argument[0]= &r.get("int-point");
  p1.disclose() = 4567;
  std::cout << p1.present() << std::endl;
  ::reflection::content::function::execute<std::string>( r.get("free_int_int"), argument );
  std::cout << p1.present() << std::endl;

  return EXIT_SUCCESS;
 }
