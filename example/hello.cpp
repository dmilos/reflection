#include <iostream>
#include <iomanip>

#include "reflection/reflection.hpp"

class MyClass : public ::reflection::object
 {
  public:
    MyClass(){ init(); }

    void a(){}
    int  b(){}
    void c( int a){}
    int  d( int a, int b){}

  private:
     void init()
      {
       ::reflection::property::function::make( this, &MyClass::a );
       ::reflection::property::function::check<void>( ::reflection::property::function::make( this, &MyClass::a ) );
       ::reflection::property::function::execute<int>( ::reflection::property::function::make( this, &MyClass::b ) ) ;
       //::reflection::property::function::execute<void,int>( ::reflection::property::function::make( this, &MyClass::c ), 1  ) ;
       //::reflection::property::function::execute<int,int,int>( ::reflection::property::function::make( this, &MyClass::d ), 1,1 ) ;
      }

 };


int main( int argc, char *argv[] )
 {
  std::cout << "Hello World" << std::endl;

  return EXIT_SUCCESS;
 }