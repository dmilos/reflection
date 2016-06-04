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
    //typedef ::reflection::object::structure_class<> structure_type;

    MyClass(){ init(); }

    void a(){std::cout << __FUNCTION__ << std::endl;}
    int  b(){std::cout << __FUNCTION__ << std::endl; return 1; }
    void c( int a){std::cout << __FUNCTION__ << std::endl;}
    int  d( int a, int b){std::cout << __FUNCTION__ << std::endl; return 1; }

  private:
     void init()
      {
       insert(  "f0", item_type( ::memory::pointer::make( ::reflection::property::function::member( this, &MyClass::a ) ) ) );
       insert(  "f1", item_type( ::memory::pointer::make( ::reflection::property::function::member( this, &MyClass::b ) ) ) );
       insert(  "f2", item_type( ::memory::pointer::make( ::reflection::property::function::member( this, &MyClass::c ) ) ) );
       insert(  "f3", item_type( ::memory::pointer::make( ::reflection::property::function::member( this, &MyClass::d ) ) ) );
      }

 };

int main_function( int argc, char *argv[] )
 {
  std::cout << "Hello World" << std::endl;

  MyClass m;

  ::reflection::property::function::execute<void>(        m.get( "f0") );
  ::reflection::property::function::execute<int>(         m.get( "f1") ) ;
  ::reflection::property::function::execute<void,int>(    m.get( "f2"), 1  );
  ::reflection::property::function::execute<int,int,int>( m.get( "f3"), 1, 1 );

  std::cin.get();
  return EXIT_SUCCESS;
 }
