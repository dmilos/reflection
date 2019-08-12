#include <iostream>
#include <iomanip>
#include <string>
#include <functional>

#include "reflection/reflection.hpp"


int          number_integer;
float        number_float;
std::string some_name;

int main( int argc, char *argv[] )
 {
  auto pi = ::reflection::content::direct::pointer<std::string,int>( & number_integer );
  auto pf = ::reflection::content::direct::pointer<std::string,float>( & number_float );
  auto ps = ::reflection::content::direct::pointer<std::string,std::string>( & some_name );

  std::cout <<  ::reflection::property::direct::disclose< int & >( pi ) << std::endl;
  ::reflection::property::direct::disclose< int & >(  pi ) =  2424;
  std::cout <<  ::reflection::property::direct::disclose< int& >( pi ) << std::endl;

  std::cout <<  ::reflection::property::direct::disclose< float& >( pf ) << std::endl;
  ::reflection::property::direct::disclose< float& >( pf ) =  1234.5678f;
  std::cout <<  ::reflection::property::direct::disclose< float& >( pf ) << std::endl;
  
  std::cout <<  ::reflection::property::direct::disclose< std::string& >( ps ) << std::endl;
  ::reflection::property::direct::disclose< std::string& >( ps ) =  "asdasdasdas";
  std::cout <<  ::reflection::property::direct::disclose< std::string& >( ps ) << std::endl;

  return EXIT_SUCCESS;
 }
