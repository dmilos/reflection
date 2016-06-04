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

    MyClass(){ init(); }

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
        insert(  "m3",     item_type( ::memory::pointer::make( ::reflection::content::mutate::member(  this, &MyClass::mutator   ) ) ) );
      }
 };

int main_mutate( int argc, char *argv[] )
 {
  std::cout << "Hello World" << std::endl;

  MyClass m;

  ::reflection::property::mutate::process<  int const& >( m.get("m3"), 2424 );

  std::cin.get();
  return EXIT_SUCCESS;
 }
