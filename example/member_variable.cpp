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

    MyClass(){ init(); }

    int      &  traitor()
     {
      std::cout << __FUNCTION__ << std::endl;
      return m_int;
     }
     
     
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
        insert(  "m3",     item_type( ::memory::pointer::make( ::reflection::content::variable::member(  this, &MyClass::inspector, &MyClass::traitor   ) ) ) );
      }
 };

int main_mutate( int argc, char *argv[] )
 {
  std::cout << "Hello World" << std::endl;

  MyClass m;

  std::cout << ::reflection::property::variable::disclose<  int const& >( m.get("m3") );
  std::cout << ::reflection::property::variable::present<  int const& >(  m.get("m3") );

  std::cin.get();
  return EXIT_SUCCESS;
 }
