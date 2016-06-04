#include <iostream>
#include <iomanip>
#include <string>
#include <functional>

#include "reflection/reflection.hpp"
#include "reflection/type/convert/convert.hpp"

#include "reflection/type/ptr/make.hpp"

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

    bool        mutator( int const& a )
     {
      std::cout << __FUNCTION__ << "::a = " << a <<std::endl;
      m_int = a;
      return true;
     }

  private:
    int m_int;

  private:
     void init()
      {
       insert(  "g1", item_type( ::memory::pointer::make( ::reflection::content::guarded::member( this, &MyClass::mutator, &MyClass::inspector ) ) ) );
      }

 };

int main_guarded( int argc, char *argv[] )
 {
  std::cout << "Hello World" << std::endl;

  MyClass m;

  std::cout <<  ::reflection::property::inspect::present< int const& >( m.get("g1") ) << std::endl;
  ::reflection::property::mutate::process<  int const& >( m.get("g1"), 2424 );
  std::cout <<  ::reflection::property::inspect::present< int const& >( m.get("g1") ) << std::endl;

  std::cin.get();
  return EXIT_SUCCESS;
 }
