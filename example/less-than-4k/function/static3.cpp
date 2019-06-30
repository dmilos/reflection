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

  public:
    bool  writer_int(    int       const& i )
     {
      std::cout << __FUNCTION__ << std::endl;
      m_int  = i; 
      return true; 
     }
    int       const&  reader_int() const{ return m_int; }
  private:
    int m_int;

  public:
    static void static_void_int_string( int &i , std::string const& s )
     {
      std::cout << __FUNCTION__ << std::endl;
      std::cout << i << std::endl;
      i = 12345;
      std::cout << s << std::endl;
     }

  private:
    static int  static_int_int_string( int &i , std::string const& s )
     {
      std::cout << __FUNCTION__ << std::endl;
      std::cout << i << std::endl;
      i = 98765;
      std::cout << s << std::endl;
      return 10;
     }

 };

// Reflect to reflection
reflection__CLASS_BEGIN_inherit( MyClassReflection, public, MyClassOriginal )

    reflection__CLASS_FUNCTION_static( "static_void_int_string", MyClassOriginal, public,  static_void_int_string )
  //reflection__CLASS_FUNCTION_static( "static_int_int_string",  MyClassOriginal, private, static_int_int_string  )

  reflection__CLASS_MEMBER_guarded(   "int-point",      MyClassOriginal, writer_int ,   reader_int    )

reflection__CLASS_END_inherit( MyClassReflection, MyClassOriginal );


int main( int argc, char *argv[] )
 {
  MyClassReflection r;  //!< Reflection of Original

  int i=20;
  float f = 42; 

  // Classic "direct" call where c++ take care about arguments type check

  std::cout << f << ", "<< i << std::endl;
  ::reflection::property::function::execute<int, int&, std::string const&>( r.get( "static_int_int_string" ), i, "asdasd", f, true );
  std::cout << f << ", "<< i << std::endl;

  ::reflection::property::function::execute<void, int&, std::string  const&>( r.get( "static_void_int_string" ), i, "asdasd", f, true );
  std::cout << f << ", "<< i << std::endl;


  ::reflection::content::function::argument_struct<std::string>::container_type argument;
  argument.resize(3);

  auto p0i = ::reflection::content::trinity::simple<std::string,int>( 100 );
  auto p0v = ::reflection::content::trinity::void_class<std::string,bool> {} ;

  auto p1 = ::reflection::content::trinity::simple<std::string,int>( 1024 );
  auto p2 = ::reflection::content::trinity::simple<std::string,std::string>( "asaaaaa" );

  argument[0]= &p0v;
  argument[1]= &p1;
  argument[2]= &p2;

  std::cout << p1.present() << std::endl;
  ::reflection::content::function::execute<std::string>( r.get("static_void_int_string"), argument );
  std::cout << p1.present() << std::endl;

  argument[0]= &r.get("int-point");
  p1.disclose() = 4567;
  std::cout << p1.present() << std::endl;
  ::reflection::content::function::execute<std::string>( r.get("static_int_int_string"), argument );
  std::cout << p1.present() << std::endl;

  return EXIT_SUCCESS;
 }
