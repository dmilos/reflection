#include <iostream>
#include <iomanip>
#include <string>
#include <functional>

#include "reflection/reflection.hpp"

class MyClassA
 {
  public:
    MyClassA(){}
  private:
 };

 class MyClassB
 {
  public:
    MyClassB(){}
  private:
 };


int main( int argc, char *argv[] )
 {
  std::cout << "Hello World" << std::endl;

  MyClassA m;
  MyClassB q;

  typedef ::reflection::operation::factory::facility_class<> factory_type;

  factory_type f;

  //TODO f.register_data<double>( );
  //TODO auto aaa = f.create<int>( 10 );

  return EXIT_SUCCESS;
 }
