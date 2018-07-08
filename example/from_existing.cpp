#include <iostream>
#include <iomanip>
#include <string>
#include <functional>

#include "reflection/reflection.hpp"


class MyClassOriginal
 {
  public:

    MyClassOriginal(){ }

    void a(){std::cout << __FUNCTION__ << std::endl;}
    int  b(){std::cout << __FUNCTION__ << std::endl; return 1; }
    void c( int a){std::cout << __FUNCTION__ << std::endl;}
    int  d( int a, int b){std::cout << __FUNCTION__ << std::endl; return 1; }

    int      &  traitor()
     {
      std::cout << __FUNCTION__ << std::endl;
      return m_int;
     }

    int const&  calc( float f )const
     {
      std::cout << __FUNCTION__ << std::endl;
      return m_int;
     }

    int const&  reader()const
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
  private:
    int m_int;
 };

reflection__CLASS_BEGIN_inherit( MyClassReflection, public, MyClassOriginal )

  reflection__CLASS_MEMBER_mutate(    "asasd3",  MyClassOriginal, writter  )
  reflection__CLASS_MEMBER_direct(    "asasd4",  MyClassOriginal, traitor  )
  reflection__CLASS_MEMBER_inspect(   "asasd5",  MyClassOriginal, reader   )

  reflection__CLASS_MEMBER_variable(  "asasd1", MyClassOriginal, traitor, reader    )
  reflection__CLASS_MEMBER_guarded(   "asasd2", MyClassOriginal, writter, reader    )
//reflection__CLASS_MEMBER_<TODO>(    "asasd2", MyClassOriginal, traitor, writter   )

reflection__CLASS_END( MyClassReflection, MyClassOriginal );


int main_from_existing( int argc, char *argv[] )
 {
  typedef ::reflection::operation::transfer::observe_class<std::ostream> observe_type;
  typedef ::reflection::operation::transfer::xml_struct<std::ostream> xml_type;
  typedef ::reflection::property::structure_class<> structure_type;

  MyClassReflection r;

  observe_type observe;
  xml_type xml(observe);

  observe.view( std::cout, r );


  std::cin.get();
  return EXIT_SUCCESS;
 }
