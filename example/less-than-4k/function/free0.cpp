#include <iostream>
#include <iomanip>
#include <string>

#include "reflection/reflection.hpp"


class MyClassOriginal
 {
  public:

    MyClassOriginal(): m_int( 5 )
     {
     }

    bool  writer_int(    int       const& i )
     {
      std::cout << __FUNCTION__ << std::endl;
      m_int  = i; 
      return true; 
     }
    int       const&  reader_int() const{ return m_int; }
  private:
    int m_int;
 };

void free_void()
 {
  std::cout << __FUNCTION__ << std::endl;
 }


// Reflect to reflection
reflection__CLASS_BEGIN_inherit( MyClassReflection, public, MyClassOriginal )

    reflection__CLASS_FUNCTION_free( "free_void", free_void )

  reflection__CLASS_MEMBER_guarded(   "int-point",      MyClassOriginal, writer_int ,   reader_int    )

reflection__CLASS_END_inherit( MyClassReflection, MyClassOriginal );


int main( int argc, char *argv[] )
 {
  MyClassReflection r;  //!< Reflection of Original

  int i=20;

  // Classic "direct" call where c++ take care about arguments type check

  ::reflection::property::function::execute<void>( r.get( "free_void" ) );
  std::cout << i << std::endl;



  auto a1 = ::reflection::content::direct::void_class<std::string>          {} ;

  auto a5 = ::reflection::content::mutate::void_class<std::string,bool >    {} ;
  auto a4 = ::reflection::content::inspect::void_class<std::string >        {} ;
  auto a2 = ::reflection::content::exposed::void_class<std::string,bool >   {} ;
  auto a3 = ::reflection::content::guarded::void_class<std::string,bool >   {} ;
  auto a7 = ::reflection::content::variable::void_class<std::string>        {} ;
  auto a6 = ::reflection::content::trinity::void_class<std::string,bool>    {} ;
  auto a8 = ::reflection::content::void_class<std::string >                 {} ;
  auto at = ::reflection::property::void_class                              {} ;
  auto a9 = ::reflection::property::direct::void_class                      {} ;
  auto ae = ::reflection::property::mutate::void_class< bool >              {} ;
  auto aw = ::reflection::property::inspect::void_class                     {} ;
  auto a0 = ::reflection::property::exposed::void_class<bool>               {} ;
  auto aq = ::reflection::property::guarded::void_class<bool>               {} ;
  auto ar = ::reflection::property::variable::void_class                    {} ;
  auto ay = ::reflection::property::trinity::void_class<bool>               {} ;

  ::reflection::content::function::argument_struct<std::string>::container_type argument;
  argument.resize(1);

  auto p0v = ::reflection::content::trinity::void_class<std::string,bool> {} ;

  argument[0]= &p0v;
  ::reflection::content::function::execute<std::string>( r.get("free_void"), argument );


  return EXIT_SUCCESS;
 }
