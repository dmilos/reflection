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

       reflection__CLASS_MEMBER_direct(    "m1",     MyClass, traitor   );
       reflection__CLASS_MEMBER_inspect(   "m2",     MyClass, inspector );
       reflection__CLASS_MEMBER_mutate(    "m3",     MyClass, writter   );
       reflection__CLASS_MEMBER_inspect(   "mS",     MyClass, structure_get );
       reflection__CLASS_MEMBER_guarded(   "g1",     MyClass, writter, inspector );
       reflection__CLASS_SIMPLE_direct(    "extra1", int, 10   ) ;
       reflection__CLASS_SIMPLE_guarded(   "extra2", int, 1024 );
       reflection__CLASS_MEMBER_variable(  "v1",      MyClass, traitor, inspector );
       ::reflection::operation::reroute< MyClass* >( *this, this );

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

  return EXIT_SUCCESS;
 }
