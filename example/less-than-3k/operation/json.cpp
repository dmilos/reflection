#include <iostream>
#include <iomanip>
#include <string>
#include <functional>

#include "reflection/reflection.hpp"

#include "reflection/type/convert/convert.hpp"

#include "reflection/type/ptr/make.hpp"




class MySubsiderOriginal
 {
  public:

    MySubsiderOriginal()
     {
     }
    //Just nothing.
 };

// Reflect to reflection
reflection__CLASS_BEGIN_inherit( MySubsiderReflection, public, MySubsiderOriginal )
  reflection__CLASS_SIMPLE_guarded(   "integer",         int, 123  )
  reflection__CLASS_SIMPLE_guarded(   "float-point",     float, 456.0  )
  reflection__CLASS_SIMPLE_guarded(   "standard-string-name", std::string, "standard-string-content"  )
reflection__CLASS_END_inherit( MySubsiderReflection, MySubsiderOriginal );


class MyMainClass
 {
  public:
    typedef MySubsiderReflection::structure_type                        structure_type;


    MyMainClass(){  }

    int      &  traitor(){ return m_int; }

    int const&  inspector()const{ return m_int; }

    bool        mutator( int const& a ){ m_int = a; return true; }

    structure_type const&  structure_get()const{ return m_sub; }

  private:
    int m_int;

    MySubsiderReflection m_sub;
 };

reflection__CLASS_BEGIN_inherit( MyMainReflection, public, MyMainClass )

  reflection__CLASS_MEMBER_direct  (  "m1",  MyMainClass, traitor   )
  reflection__CLASS_MEMBER_inspect (  "m2",  MyMainClass, inspector )
  reflection__CLASS_MEMBER_mutate  (  "m3",  MyMainClass, mutator   )
  reflection__CLASS_MEMBER_inspect (  "subsider",  MyMainClass, structure_get )
  reflection__CLASS_MEMBER_guarded (  "g1",  MyMainClass, mutator, inspector )
  reflection__CLASS_MEMBER_variable(  "v1",  MyMainClass, traitor, inspector )
  reflection__CLASS_MEMBER_trinity(   "t1",  MyMainClass, traitor, mutator, inspector )

  reflection__CLASS_SIMPLE_direct(    "extra1",     int,  123  )
  reflection__CLASS_SIMPLE_guarded(   "extra2",     int, 1024  )


reflection__CLASS_END_inherit( MyMainReflection, MyMainClass );

int main( int argc, char *argv[] )
 {
  std::cout << "Hello World" << std::endl;

  MyMainReflection r;

  typedef ::reflection::operation::transfer::observe_class<std::ostream> observe_type;
  typedef ::reflection::operation::transfer::json::print_struct<std::ostream> json_type;

  observe_type observe;
  json_type json(observe);

  observe.view( std::cout, r );

  return EXIT_SUCCESS;
 }
