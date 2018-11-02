#include <iostream>
#include <iomanip>
#include <string>
#include <functional>

#include "reflection/reflection.hpp"
#include "reflection/type/convert/convert.hpp"

#include "reflection/type/ptr/make.hpp"

class MyClassA
 : public ::reflection::content::class_class<MyClassA>
 {
  public:
    MyClassA(){ init(); }
  private:
   void init()
      {
       reflection__CLASS_SIMPLE_direct(   "extra1",         int, 123  )
       reflection__CLASS_SIMPLE_guarded(  "extra2",         int, 123  )
       reflection__CLASS_SIMPLE_guarded(  "extra3",         float, 123  )
       reflection__CLASS_SIMPLE_guarded(  "extra4",         std::string, "asdfg"  )
       ::reflection::operation::reroute< MyClassA* >( *this, this );
      }
 };


class MyClass
: public ::reflection::content::class_class<MyClass>
 {
  public:
    MyClass(){ init(); }

    void a(){std::cout << __FUNCTION__ << std::endl;}
    int  b(){std::cout << __FUNCTION__ << std::endl; return 1; }
    void c( int a){std::cout << __FUNCTION__ << std::endl;}
    int  d( int a, int b){std::cout << __FUNCTION__ << std::endl; return 1; }

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

    bool        writter( int const& a )
     {
      std::cout << __FUNCTION__ << "::a = " << a <<std::endl;
      m_int = a;
      return true;
     }

    void defaulter()
     {
      std::cout << __FUNCTION__ << std::endl;
      m_int = 100;
     }

    bool        executor( )
     {
      std::cout << __FUNCTION__ << std::endl;
      return true;
     }

    structure_type const&  structure_get()const
     {
      std::cout << __FUNCTION__ << std::endl;
      return m_sub;
      }

  private:
    int m_int;

    MyClassA m_sub;

  private:
     void init()
      {

        insert(  "f0", item_type( ::memory::pointer::make( ::reflection::property::function::member( this, &MyClass::a ) ) ) );
        insert(  "f1", item_type( ::memory::pointer::make( ::reflection::property::function::member( this, &MyClass::b ) ) ) );
        insert(  "f2", item_type( ::memory::pointer::make( ::reflection::property::function::member( this, &MyClass::c ) ) ) );
        insert(  "f3", item_type( ::memory::pointer::make( ::reflection::property::function::member( this, &MyClass::d ) ) ) );

       reflection__CLASS_MEMBER_direct(    "m1",     MyClass, traitor   );
       reflection__CLASS_MEMBER_inspect(   "m2",     MyClass, inspector );
       reflection__CLASS_MEMBER_mutate(    "m3",     MyClass, writter   );
       reflection__CLASS_MEMBER_inspect(   "mS",     MyClass, structure_get );
       reflection__CLASS_MEMBER_guarded(   "g1",     MyClass, writter, inspector );
       reflection__CLASS_SIMPLE_direct(    "extra1", int, 10   ) ;
       reflection__CLASS_SIMPLE_guarded(   "extra2", int, 1024 );
       reflection__CLASS_MEMBER_variable(  "v1",      MyClass, traitor, inspector );

    ::reflection::operation::reroute< MyClass* >( *this, this );


        ::reflection::property::assign< int >( get( "v1" ), get( "g1" ) );
      }

 };


int main( int argc, char *argv[] )
 {
  std::cout << "Hello World" << std::endl;

  MyClass m;

  ::reflection::operation::transfer::observe_class<int> observe;

  int i;
  observe.insert( typeid(                             std::string ).name(), [](         int &,   std::string const& name, ::reflection::property::pure_class const&  )  { std::cout << "string - " << __FUNCTION__ << std::endl; return true; } ); 
  observe.insert( typeid(                                   float ).name(), [](         int &,   std::string const& name, ::reflection::property::pure_class const&  )        { std::cout << "float  - " << __FUNCTION__ << std::endl; return true; } );
  observe.insert( typeid(                                     int ).name(), [](         int &,   std::string const& name, ::reflection::property::pure_class const&  )        { std::cout << "int    - " << __FUNCTION__ << std::endl; return true; } );
  observe.insert( typeid( ::reflection::property::structure_class<> ).name(), [&observe]( int & i, std::string const& name, ::reflection::property::pure_class const& p )
   {
    std::cout << "struct - " << __FUNCTION__ << std::endl; 
    observe.view( i, ::reflection::property::inspect::present< ::reflection::property::structure_class<> const& >( p ) );
    return true; 
   } );

  observe.view( i, m );

  return EXIT_SUCCESS;
 }
