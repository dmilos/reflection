#include <iostream>
#include <iomanip>

#include "reflection/reflection.hpp"

class MyClass 
: public ::reflection::object_class
 {
  public:
    MyClass(){ init(); }

    void a(){}
    int  b(){ return 1; }
    void c( int a){}
    int  d( int a, int b){ return 1; }

    int      &  traitor(){ return m_int; }
    int const&  inspector()const{ return m_int; }
    bool        mutator( int const& a ){ return true; }

  private:
    int m_int;
     void init()
      {
       ::reflection::property::function::check<void>( ::reflection::property::function::member( this, &MyClass::a ) );
       ::reflection::property::function::execute<int>( ::reflection::property::function::member( this, &MyClass::b ) ) ;
       //::reflection::property::function::execute<void,int>( ::reflection::property::function::member( this, &MyClass::c ), 1  ) ;
       //::reflection::property::function::execute<int,int,int>( ::reflection::property::function::member( this, &MyClass::d ), 1,1 ) ;

       //::reflection::object::execute<void,int>( this, "asd", 1 );
       //::reflection::object::inspect<int>(      this, "asd" );
       //::reflection::object::direct<int>(       this, "asd" );
       //::reflection::object::reset<int>(        this, "asd" );
       //::reflection::object::set<int>(          this, "asd", 20 );

       insert(  "f0", item_type( ::reflection::property::function::member( this, &MyClass::a ) ) );
       insert(  "f1", item_type( ::reflection::property::function::member( this, &MyClass::b ) ) );
       insert(  "f2", item_type( ::reflection::property::function::member( this, &MyClass::c ) ) );
       insert(  "f3", item_type( ::reflection::property::function::member( this, &MyClass::d ) ) );

       insert(  "m1", item_type( ::reflection::property::direct::member( this, &MyClass::traitor ) ) );
       insert(  "m2", item_type( ::reflection::property::inspect::member( this, &MyClass::inspector ) ) );
       insert(  "m3", item_type( ::reflection::property::mutate::member( this, &MyClass::mutator ) ) );

       //insert(  "extra2", item_type( ::reflection::property::direct::simple<int>( 10 ) );

       exists(  "asd" );
       remove(  "asd" );
       clear();
       container();

       ::reflection::property::function::check<void>( get( "f0" ) );
       ::reflection::property::function::execute<void>( get( "f0" ) );
      }

 };


int main( int argc, char *argv[] )
 {
  std::cout << "Hello World" << std::endl;

  return EXIT_SUCCESS;
 }