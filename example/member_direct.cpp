#include <iostream>
#include <iomanip>
#include <string>
#include <functional>

#include "reflection/reflection.hpp"

class MyClass
: public ::reflection::content::class_class<MyClass>
 {
  public:

    MyClass(){ init(); }

    int const&  inspector()const
     {
      std::cout << __FUNCTION__ << std::endl;
      return m_int;
      }

    int &   traitor(  )
     {
      std::cout << __FUNCTION__ << std::endl;
      return m_int;
     }

  private:
    int m_int;

  private:
     void init()
      {
       insert(  "g1", item_type( ::memory::pointer::make( ::reflection::content::direct::member( this, &MyClass::traitor ) ) ) );
      }

 };

int main_direct( int argc, char *argv[] )
 {
  std::cout << "Hello World" << std::endl;

  MyClass m;

  std::cout <<  ::reflection::property::direct::disclose< int const& >( m.get("g1") ) << std::endl;
  ::reflection::property::mutate::process<  int const& >( m.get("g1"), 2424 );
  std::cout <<  ::reflection::property::direct::disclose< int const& >( m.get("g1") ) << std::endl;

  std::cin.get();
  return EXIT_SUCCESS;
 }
