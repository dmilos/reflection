#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>


#include "reflection/reflection.hpp"

class MySubClassOriginal //!< Original condition. Not bloated with any other code.
{
  public:
    MySubClassOriginal( int const& a = 6699 ){ m_int = a; }
    int const&  read_int()const{ return m_int; }
    bool        write_int( int const& a )
     {
      m_int = a;
      return true;
     }
  private: // And private member
    int m_int;

};

class MyFirstClassOriginal //!< Original condition. Not bloated with any other code.
 {
  public:
    MyFirstClassOriginal():m_float(98765),m_string("|<-----init----->|"),m_wstring(L"|<0---init---0>|"),m_integer(321){ }

  public:
    MySubClassOriginal const&  read_sub()const{ return m_sub; }
    bool          write_sub( MySubClassOriginal const& a )
     {  
      m_sub = a; 
      return true; 
     }
  private: // And private member
    MySubClassOriginal m_sub;

  public:
    float const&  read_float()const{ return m_float; }
    bool          write_float( float const& a )
     {  
      m_float = a; 
      return true; 
     }
  private: // And private member
    float m_float;

  public:
    int const&  read_int()const{ return m_integer; }
    bool          write_int( int const& a )
     {
      m_integer = a; 
      return true; 
     }
    int  m_integer;
  public:
    std::string const&  read_string()const{ return m_string; }
    bool          write_string( std::string const& a )
     {
      m_string = a; 
      return true; 
     }
    std::wstring const&  read_wstring()const{ return m_wstring; }
    bool          write_wstring( std::wstring const& a )
     {
      m_wstring = a; 
      return true; 
     }

    std::string  m_string;
    std::wstring  m_wstring;
 };

reflection__IDSPEC( std::string, "MyFirstClassOriginal",  MyFirstClassOriginal )
reflection__IDSPEC( std::string, "MySubClassOriginal",  MySubClassOriginal )

reflection__CLASS_BEGIN_view( MySubClassReflectionModify, public, MySubClassOriginal, MySubClassOriginal * )
   reflection__CLASS_MEMBER_guarded(   "INT",  MySubClassOriginal, write_int, read_int)
reflection__CLASS_END_view( MySubClassReflectionModify, MySubClassOriginal );

reflection__CLASS_BEGIN_view( MySubClassReflectionView, public, MySubClassOriginal, MySubClassOriginal const * )
   reflection__CLASS_MEMBER_inspect(   "INT", MySubClassOriginal, read_int    )
reflection__CLASS_END_view( MySubClassReflectionView, MySubClassOriginal );

reflection__CLASS_BEGIN_view( MyClassReflectionModify, public, MyFirstClassOriginal, MyFirstClassOriginal * )
   reflection__CLASS_MEMBER_guarded(   "sub",        MyFirstClassOriginal, write_sub, read_sub)
   reflection__CLASS_MEMBER_guarded(   "number",     MyFirstClassOriginal, write_float, read_float  )
   reflection__CLASS_MEMBER_guarded(   "integer",    MyFirstClassOriginal, write_int, read_int )
   reflection__CLASS_MEMBER_guarded(   "string",     MyFirstClassOriginal, write_string, read_string )
   reflection__CLASS_MEMBER_guarded(   "wstring",    MyFirstClassOriginal, write_wstring, read_wstring )
reflection__CLASS_END_view( MyClassReflectionModify, MyFirstClassOriginal );

reflection__CLASS_BEGIN_view( MyClassReflectionView, public, MyFirstClassOriginal, MyFirstClassOriginal const* )
   reflection__CLASS_MEMBER_inspect(   "sub",  MyFirstClassOriginal, read_sub )
   reflection__CLASS_MEMBER_inspect(   "number",  MyFirstClassOriginal, read_float  )
   reflection__CLASS_MEMBER_inspect(   "integer", MyFirstClassOriginal, read_int    )
   reflection__CLASS_MEMBER_inspect(   "string",   MyFirstClassOriginal, read_string )
   reflection__CLASS_MEMBER_inspect(   "wstring",   MyFirstClassOriginal, read_wstring )
reflection__CLASS_END_view( MyClassReflectionView, MyFirstClassOriginal );


void store( MyFirstClassOriginal const& instance, std::string const& fn )
 {
  std::cout << "enter: " << __FUNCTION__ << std::endl;
  // Some typedefs
  typedef ::reflection::operation::encode::observe_class<std::ostream> observe_type;
  typedef ::reflection::operation::transfer::tkv::serialize_struct<std::ostream> tlv_type;
  typedef ::reflection::operation::transfer::xml::print_struct<std::ostream> xml_type;
  typedef  ::reflection::operation::transfer::ini::print_struct<std::ostream> ini_type;
  MyClassReflectionView r( &instance );  //!< Reflection of Original

  observe_type observe;

  tlv_type tkv( observe );//TLVize for example
  observe.register_class<MySubClassOriginal, MySubClassReflectionView>();
  auto f1 = std::ofstream(  fn +  ".bin", std::ios_base::binary );
  observe.view( f1 , r );

  observe.clear();
  xml_type xml( observe );
  observe.register_class<MySubClassOriginal, MySubClassReflectionView>();

  auto f2 = std::ofstream( fn +  ".xml" );
  observe.view( f2, r );

  observe.clear();
  ini_type ini( observe );
  observe.register_class<MySubClassOriginal, MySubClassReflectionView>();

  auto f3 = std::ofstream( fn +  ".ini" );
  observe.view( f3, r );
 }

void load ( MyFirstClassOriginal & instance, std::string const& fn )
 {
  typedef  ::reflection::operation::transfer::tkv::scan_struct<std::istream,std::string,std::string> scan_type;
  typedef scan_type::parser_type  parser_type;

  parser_type parser;
  auto context = scan_type::context();
  scan_type scan( parser, context );

  scan_type::register_class< MySubClassOriginal,  MySubClassReflectionModify >( parser, context );

  MyClassReflectionModify r( & instance );

  auto f =  std::ifstream( fn, std::ios_base::binary );
  std::cout << "Parse result: " <<  parser.parse( r, f ) << std::endl;
 }

int main( int argc, char *argv[] )
 {
  std::cout << "Hello World" << std::endl;

// ::reflection::property::trinity::simple_struct<float> aa;
 auto d0 = ::reflection::property::direct::simple<float>( ); 
 auto d1 = ::reflection::property::guarded::simple<float>( ); 
 auto d2 = ::reflection::property::inspect::simple<float>( ); 

 auto d3 = ::reflection::property::variable::simple<float, float&, float const&>( ); 
 auto d4 = ::reflection::property::mutate::simple<float, bool>( ); 
 auto d5 = ::reflection::property::exposed::simple<float, float&, float const&, bool>( );
 auto d6 = ::reflection::property::trinity::simple<float>( ); 

  MyFirstClassOriginal original;

  store( original, "0-initial" );

  original.write_float(123456);
  original.write_int(123456);
  original.write_string("***change***");
  original.write_wstring(L"bb-change-bbb");
  original.write_sub( MySubClassOriginal( 9966 ) );

  store( original, "1-change" );

  load ( original, "0-initial.bin" );

  store( original, "2-load-initial" );

  std::cin.get();
  return EXIT_SUCCESS;
 }
