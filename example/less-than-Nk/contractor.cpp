#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>


#include "reflection/reflection.hpp"

class MyFirstClassOriginal //!< Original condition. Not bloated with any other code.
 {
  public:
    MyFirstClassOriginal():m_float(98765),m_string("---------------"),m_integer(321){ }

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
    std::string  m_string;
 };

reflection__IDSPEC( std::string, "MyFirstClassOriginal",  MyFirstClassOriginal )

reflection__CLASS_BEGIN_view( MyClassReflectionModify, public, MyFirstClassOriginal, MyFirstClassOriginal * )
   reflection__CLASS_MEMBER_guarded(   "number",  MyFirstClassOriginal, write_float, read_float  )
   reflection__CLASS_MEMBER_guarded(   "integer", MyFirstClassOriginal, write_int, read_int )
   reflection__CLASS_MEMBER_guarded(   "niska",   MyFirstClassOriginal, write_string, read_string )
reflection__CLASS_END_view( MyClassReflectionModify, MyFirstClassOriginal );

reflection__CLASS_BEGIN_view( MyClassReflectionView, public, MyFirstClassOriginal, MyFirstClassOriginal const* )
   reflection__CLASS_MEMBER_inspect(   "number",  MyFirstClassOriginal, read_float  )
   reflection__CLASS_MEMBER_inspect(   "integer", MyFirstClassOriginal, read_int    )
   reflection__CLASS_MEMBER_inspect(   "niska",   MyFirstClassOriginal, read_string )
reflection__CLASS_END_view( MyClassReflectionView, MyFirstClassOriginal );


void store( MyFirstClassOriginal const& instance, std::string const& fn )
 {
  std::cout << "enter: " << __FUNCTION__ << std::endl;
  // Some typedefs
  typedef ::reflection::operation::encode::observe_class<std::ostream> observe_type;
  typedef ::reflection::operation::transfer::tlv::serialize_struct<std::ostream> tlv_type;
  typedef ::reflection::operation::transfer::xml::print_struct<std::ostream> xml_type;

  MyClassReflectionView r( &instance );  //!< Reflection of Original

  observe_type observe;

  tlv_type tlv( observe );//TLVize for example
  auto f1 = std::ofstream(  fn +  ".bin", std::ios_base::binary );
  observe.view( f1 , r );

  observe.clear();
  xml_type xml( observe );
  auto f2 = std::ofstream(fn +  ".xml", std::ios_base::binary );
  observe.view( f2, r );
 }

void load ( MyFirstClassOriginal & instance, std::string const& fn )
 {
  typedef  ::reflection::operation::transfer::tlv::scan_struct<std::istream,std::string,std::string> scan_tlv_type;
  typedef scan_tlv_type::contractor_type  contractor_tlv_type;

  contractor_tlv_type c;
  scan_tlv_type stlv( c );

  MyClassReflectionModify r( & instance );

  auto f =  std::ifstream( fn, std::ios_base::binary );
  std::cout <<  c.parse( r, f ) << std::endl;
 }

int main( int argc, char *argv[] )
 {
  std::cout << "Hello World" << std::endl;
  MyFirstClassOriginal original;
  store( original, "0-initial" );

  original.write_float(123456);
  original.write_int(123456);
  original.write_string("**********");

  store( original, "1-change" );

  load ( original, "0-initial.bin" );

  store( original, "2-load-initial" );

  std::cin.get();
  return EXIT_SUCCESS;
 }

