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

  typedef ::reflection::operation::transfer::factory_class<> factory_type;
  
  factory_type f;
  
  f.register_data<double>();
  auto aaa = f.create<int>( );

  return EXIT_SUCCESS;
 }
