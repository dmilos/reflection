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

void free_void()
   {
    std::cout << __FUNCTION__ << std::endl;
   }

int  free_int()
 {
  std::cout << __FUNCTION__ << std::endl;
  return 10;
 }

// Reflect to reflection
reflection__CLASS_BEGIN_inherit( MyClassReflection, public, MyClassOriginal )

    reflection__CLASS_FUNCTION_free( "free_void", free_void )
    reflection__CLASS_FUNCTION_free( "free_int",  free_int )
  reflection__CLASS_MEMBER_guarded(   "int-point",      MyClassOriginal, writer_int ,   reader_int    )

reflection__CLASS_END_inherit( MyClassReflection, MyClassOriginal );


int main( int argc, char *argv[] )
 {
  MyClassReflection r;  //!< Reflection of Original

  int i=20;

  // Classic "direct" call where c++ take care about arguments type check

  std::cout <<  i << std::endl;
  ::reflection::property::function::execute<int >( r.get( "free_int" ) );
  std::cout << i << std::endl;

  ::reflection::property::function::execute<void>( r.get( "free_void" ) );
  std::cout << i << std::endl;


  ::reflection::content::function::argument_struct<std::string>::container_type argument;
  argument.resize(1);

  auto p0i = ::reflection::content::trinity::simple<std::string,int>( 100 );
  auto p0v = ::reflection::content::trinity::void_class<std::string,bool> {} ;


  argument[0]= &p0v;

  ::reflection::content::function::execute<std::string>( r.get("free_void"), argument );

  argument[0]= &r.get("int-point");
  ::reflection::content::function::execute<std::string>( r.get("free_int"), argument );

  return EXIT_SUCCESS;
 }
