#include <iostream>
#include <iomanip>
#include <string>
#include <functional>

#include "reflection/reflection.hpp"
#include "reflection/type/convert/convert.hpp"

#include "reflection/type/ptr/make.hpp"

class MyClass
: public ::reflection::content::class_class<MyClass>
 {
  public:
    typedef ::reflection::property::structure_class<> structure_type;

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
       insert(  "m2",     item_type( ::memory::pointer::make( ::reflection::content::inspect::member( this, &MyClass::inspector ) ) ) );
      }

 };


int main_inspect( int argc, char *argv[] )
 {
  std::cout << "Hello World" << std::endl;

  MyClass m;

  std::cout <<  ::reflection::property::inspect::present< int const& >( m.get("m2") ) << std::endl;

  std::cin.get();
  return EXIT_SUCCESS;
 }
