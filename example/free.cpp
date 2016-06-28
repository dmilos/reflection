#include <iostream>
#include <iomanip>
#include <string>
#include <functional>

#include "reflection/reflection.hpp"
#include "reflection/type/convert/convert.hpp"

#include "reflection/type/ptr/make.hpp"

namespace 
 {

  void free_void_void()
   {
    std::cout << __FUNCTION__ << std::endl;
   }
  
  int free_int_void()
   {
    std::cout << __FUNCTION__ << std::endl;
    return 10;
   }
  
  int free_int_int( int )
   {
    std::cout << __FUNCTION__ << std::endl;
    return 10;
   }
  
  int free_int_int_string( int , std::string const& )
   {
    std::cout << __FUNCTION__ << std::endl;
    return 10;
   }
  
  int free_int_int_string_float( int , std::string const&, float )
   {
    std::cout << __FUNCTION__ << std::endl;
    return 10;
   }
  
  int free_int_int_string_float_bool( int , std::string const&, float, bool )
   {
    std::cout << __FUNCTION__ << std::endl;
    return 10;
   }

class MyClass
: public ::reflection::object::class_class<MyClass>
 {
  public:
    typedef ::reflection::object::structure_class<> structure_type;

    MyClass(){ init(); }

    int const&  inspector()const
     {
      std::cout << __FUNCTION__ << std::endl;
      return m_int;
      }

  private:
    int m_int;


  private:
     void init()
      {
       insert(  "f0",     item_type( ::memory::pointer::make( ::reflection::content::function::free( &free_void_void                 ) ) ) );
       insert(  "f1",     item_type( ::memory::pointer::make( ::reflection::content::function::free( &free_int_void                  ) ) ) );
       insert(  "f2",     item_type( ::memory::pointer::make( ::reflection::content::function::free( &free_int_int                   ) ) ) );
       insert(  "f3",     item_type( ::memory::pointer::make( ::reflection::content::function::free( &free_int_int_string            ) ) ) );
       insert(  "f4",     item_type( ::memory::pointer::make( ::reflection::content::function::free( &free_int_int_string_float      ) ) ) );
       insert(  "f5",     item_type( ::memory::pointer::make( ::reflection::content::function::free( &free_int_int_string_float_bool ) ) ) );
      }

 };

}

int main_free( int argc, char *argv[] )
 {
  std::cout << "Hello World" << std::endl;

  MyClass m;

  ::reflection::property::function::execute< void >( m.get("f0") );
  ::reflection::property::function::execute< int >(  m.get("f1") );
  ::reflection::property::function::execute< int, int >(  m.get("f2"), 10 );
  ::reflection::property::function::execute< int, int, std::string const& >( m.get("f3"), 10, "asdasd" );
  ::reflection::property::function::execute< int, int, std::string const&, float >(  m.get("f4"), 10, "asdasd", 42.0 );
  ::reflection::property::function::execute< int, int, std::string const&, float, bool >(  m.get("f5"), 10, "asdasd", 42.0, true );

  std::cin.get();
  return EXIT_SUCCESS;
 }
