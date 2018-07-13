#include <iostream>
#include <iomanip>
#include <string>
#include <functional>

#include "reflection/reflection.hpp"

class MyClassA
 : public ::reflection::content::class_class<MyClassA>
 {
  public:
    MyClassA(){ init(); }
  private:
   void init()
      {
       reflection__CLASS_SIMPLE_direct(   "extra1",         int, 123  )
       reflection__CLASS_SIMPLE_guarded(   "extra2",         int, 123  )
       reflection__CLASS_SIMPLE_guarded(   "extra3",         float, 123  )
       reflection__CLASS_SIMPLE_guarded(   "extra4",         std::string, "asdfg"  )
      }
 };


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
        insert(  "m1",     item_type( ::memory::pointer::make( ::reflection::content::direct::member(  this, &MyClass::traitor   ) ) ) );
        insert(  "m2",     item_type( ::memory::pointer::make( ::reflection::content::inspect::member( this, &MyClass::inspector ) ) ) );
        insert(  "m3",     item_type( ::memory::pointer::make( ::reflection::content::mutate::member(  this, &MyClass::writter   ) ) ) );

        insert(  "mS",     item_type( ::memory::pointer::make( ::reflection::content::inspect::member( this, &MyClass::structure_get ) ) ) );

        insert(  "g1",     item_type( ::memory::pointer::make( ::reflection::content::guarded::member( this, &MyClass::writter, &MyClass::inspector ) ) ) );

        insert(  "extra1", item_type( ::memory::pointer::make( ::reflection::property::direct::simple<int>( 10 ) ) ) );
        insert(  "extra2", item_type( ::memory::pointer::make( ::reflection::content::guarded::simple<int>( 1024 ) ) ) );

        insert(  "v1",     item_type( ::memory::pointer::make( ::reflection::content::variable::member( this, &MyClass::traitor, &MyClass::inspector ) ) ) );

      }

 };


int main( int argc, char *argv[] )
 {
  std::cout << "Hello World" << std::endl;

  MyClass m;
  MyClass q;

  ::reflection::property::assign< int >( m.get( "v1" ), q.get( "g1" ) );

  typedef ::reflection::operation::transfer::assign_struct< >     assign_type;

  assign_type::observe_type observe_assign;

  assign_type assign( observe_assign );

  observe_assign.view( m, q );

  std::cin.get();
  return EXIT_SUCCESS;
 }
