#include <iostream>
#include <iomanip>

#include "reflection/reflection.hpp"

class MyClass 
: public ::reflection::object
 {
  public:
    MyClass(){ init(); }

    void a(){}
    int  b(){ return 1; }
    void c( int a){}
    int  d( int a, int b){ return 1; }

    int      &  traitor(){ return m_int; }
    int const&  inspector()const{ return m_int; }

  private:
    int m_int;
     void init()
      {
       ::reflection::property::function::make( this, &MyClass::a );
       ::reflection::property::function::check<void>( ::reflection::property::function::make( this, &MyClass::a ) );
       ::reflection::property::function::execute<int>( ::reflection::property::function::make( this, &MyClass::b ) ) ;
       //::reflection::property::function::execute<void,int>( ::reflection::property::function::make( this, &MyClass::c ), 1  ) ;
       //::reflection::property::function::execute<int,int,int>( ::reflection::property::function::make( this, &MyClass::d ), 1,1 ) ;

     //::reflection::property::inspect::member( this, &MyClass::inspector ).get() ;

       ::reflection::property::direct::member( this, &MyClass::traitor ).get() = 10;
     //::reflection::property::direct::simple<int>( 10 ).get() = 10;
     //::reflection::property::direct::reference<int>( m_int ).get() = 10;

       //::reflection::object::execute<void,int>( this, "asd", 1 );
       //::reflection::object::inspect<int>(      this, "asd" );
       //::reflection::object::direct<int>(       this, "asd" );
       //::reflection::object::reset<int>(        this, "asd" );
       //::reflection::object::set<int>(          this, "asd", 20 );

       //::reflection::object::insert(  this, "asd", ::reflection::property::function::make( this, &MyClass::a ) );
       //::reflection::object::exists(  this, "asd" );
       //::reflection::object::remove(  this, "asd" );
       //::reflection::object::clear(  this );
       //::reflection::object::container( this );
      }

 };


int main( int argc, char *argv[] )
 {
  std::cout << "Hello World" << std::endl;

  return EXIT_SUCCESS;
 }