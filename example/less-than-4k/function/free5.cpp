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

    void none()
     {
     }

    void one( int i )
     {
     }

    void two( int i, std::string const& s)
    {
    }

    int       const&  reader_int() const{ return m_int; }
  private:
    int m_int;
 };

void free_void_int_string_float_bool( int &i , std::string const& s, float & f, bool b )
 {
  std::cout << __FUNCTION__ << std::endl;
  std::cout << i << std::endl;
  i = 12345;
  std::cout << s << std::endl;
  std::cout << f << std::endl;
  f = 987;
  std::cout << b << std::endl;
 }

    int  free_int_int_string_float_bool( int &i , std::string const& s, float & f, bool b )
     {
      std::cout << __FUNCTION__ << std::endl;
      std::cout << i << std::endl;
      i = 98765;
      std::cout << s << std::endl;
      std::cout << f << std::endl;
      f = 987;
      std::cout << b << std::endl;
      return 10;
     }



// Reflect to reflection
reflection__CLASS_BEGIN_inherit( MyClassReflection, public, MyClassOriginal )

    reflection__CLASS_FUNCTION_free( "free_void_int_string_float_bool", free_void_int_string_float_bool )
    reflection__CLASS_FUNCTION_free( "free_int_int_string_float_bool",  free_int_int_string_float_bool )

  reflection__CLASS_MEMBER_guarded(   "int-point",      MyClassOriginal, writer_int ,   reader_int    )

reflection__CLASS_END_inherit( MyClassReflection, MyClassOriginal );


void test_none()
{
    std::cout << __FUNCTION__ << std::endl;
}
void test_one( int i )
{
    std::cout << __FUNCTION__ << std::endl;
}
void test_two( float f, std::string const s )
{
    std::cout << __FUNCTION__ << std::endl;
}

void test_standard( )
 { 
    using namespace std::placeholders;
    std::function< void( ) > f0 = std::bind(&test_none);
    auto s0 = ::reflection::utility::function::standard( f0 );
    s0.execute();

    using namespace std::placeholders;
    std::function< void( int ) > f1 = std::bind(&test_one, _1 );
    auto s1 = ::reflection::utility::function::standard( f1 );
    s1.execute(1);

    using namespace std::placeholders;
    std::function< void(float f, std::string const s) > f2 = std::bind(&test_two, _1, _2 );
    auto s2 = ::reflection::utility::function::standard( f2 );
    s2.execute(1, "" );


 }
void test_member( )
 { 
    //  reflection::property::function::member( storage_param , member_function )
    MyClassOriginal instance;

    auto s0 = ::reflection::utility::function::member<MyClassOriginal>( &instance, &MyClassOriginal::none );
    s0.execute();

    auto s1 = ::reflection::utility::function::member( &instance, &MyClassOriginal::one );
    s1.execute(1);

    auto s2 = ::reflection::utility::function::member(&instance, &MyClassOriginal::two);
    s2.execute(1, "" );
 }

int main( int argc, char *argv[] )
 {
  test_standard();
  test_member();
  MyClassReflection r;  //!< Reflection of Original

  int i=20;
  float f = 42; 

  // Classic "direct" call where c++ take care about arguments type check

  std::cout << f << ", "<< i << std::endl;
  ::reflection::property::function::execute<int, int&, std::string const&, float &, bool>( r.get( "free_int_int_string_float_bool" ), i, "asdasd", f, true );
  std::cout << f << ", "<< i << std::endl;

  ::reflection::property::function::execute<void, int&, std::string  const&, float &, bool>( r.get( "free_void_int_string_float_bool" ), i, "asdasd", f, true );
  std::cout << f << ", "<< i << std::endl;


  ::reflection::content::function::argument_struct<std::string>::container_type argument;
  argument.resize(5);

  auto p0i = ::reflection::content::trinity::simple<std::string,int>( 100 );
  auto p0v = ::reflection::content::trinity::void_class<std::string,bool> {} ;

  auto p1 = ::reflection::content::trinity::simple<std::string,int>( 1024 );
  auto p2 = ::reflection::content::trinity::simple<std::string,std::string>( "asaaaaa" );
  auto p3 = ::reflection::content::trinity::simple<std::string,float>( 128.0 );
  auto p4 = ::reflection::content::trinity::simple<std::string,bool>( true );

  argument[0]= &p0v;
  argument[1]= &p1;
  argument[2]= &p2;
  argument[3]= &p3;
  argument[4]= &p4;

  std::cout << p1.present() << std::endl;
  ::reflection::content::function::execute<std::string>( r.get("free_void_int_string_float_bool"), argument );
  std::cout << p1.present() << std::endl;

  argument[0]= &r.get("int-point");
  p1.disclose() = 4567;
  std::cout << p1.present() << std::endl;
  ::reflection::content::function::execute<std::string>( r.get("free_int_int_string_float_bool"), argument );
  std::cout << p1.present() << std::endl;

  return EXIT_SUCCESS;
 }
