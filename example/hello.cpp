#include <iostream>
#include <iomanip>
#include <string>
#include <functional>

#include "reflection/reflection.hpp"
#include "reflection/type/convert/convert.hpp"

#include "reflection/type/ptr/make.hpp"

class MyClass
: public ::reflection::object::structure_class
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

    bool        mutator( int const& a )
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
     void init()
      {
       ::reflection::property::direct::member( this, &MyClass::traitor );
       ::reflection::property::direct::simple( 1024 );
       ::reflection::property::direct::simple<float>();

       ::reflection::property::inspect::member( this, &MyClass::inspector );
       ::reflection::property::inspect::pretend::member< bool, ::type::convert::identity< bool, int > >( this, &MyClass::inspector );
       ::reflection::property::inspect::simple( 150 );
       ::reflection::property::inspect::simple<double>();

       ::reflection::property::mutate::member( this, &MyClass::mutator );
       ::reflection::property::mutate::pretend::member< int, ::type::convert::identity< int, bool > >( this, &MyClass::mutator );
       ::reflection::property::mutate::simple< int, bool >( 512 );
       ::reflection::property::mutate::simple< int, bool >( );

       ::reflection::property::variable::member( this, &MyClass::traitor, &MyClass::inspector );
       ::reflection::property::variable::simple( 111 );
       ::reflection::property::variable::simple<int>( );

       ::reflection::property::guarded::member( this, &MyClass::mutator, &MyClass::inspector );
       ::reflection::property::guarded::simple( 666 );
       ::reflection::property::guarded::simple<int>();


       ::reflection::content::direct::member( this, &MyClass::traitor );
       ::reflection::content::direct::simple( 152 ).disclose() = 4242;
       ::reflection::content::direct::simple<float>( );

       ::reflection::content::inspect::member( this, &MyClass::inspector );
       ::reflection::content::inspect::simple( 1024 );
       ::reflection::content::inspect::simple<double>();

       ::reflection::content::mutate::member<int>( this, &MyClass::mutator );
       ::reflection::content::mutate::simple<int>( 1024 );
       ::reflection::content::mutate::simple<double>();

       ::reflection::content::variable::member( this, &MyClass::traitor, &MyClass::inspector );
       ::reflection::content::variable::simple<int>( 1024 );
       ::reflection::content::variable::simple<int>( );

       ::reflection::content::guarded::member( this, &MyClass::mutator, &MyClass::inspector );
       ::reflection::content::guarded::simple<int>( 1024 );
       ::reflection::content::guarded::simple<float>( );

       std::cout << "content::direct::type = " << ::type::category::type<std::string>( ::reflection::content::direct::member( this, &MyClass::traitor ) ) << std::endl;

       std::cout << "content::direct = " << ::reflection::content::direct::member( this, &MyClass::traitor ).disclose() << std::endl;

       std::cout << "content::inspect = " << ::reflection::content::inspect::member( this, &MyClass::inspector ).present() << std::endl;


       ::reflection::content::mutate::member<int>( this, &MyClass::mutator ).process( 2424 );

       std::cout << "content::inspect = " << ::reflection::content::inspect::member( this, &MyClass::inspector ).present() << std::endl;

       ::reflection::property::inspect::pretend::member< std::string, std::pointer_to_unary_function<int const&, std::string > >( this, &MyClass::inspector, std::pointer_to_unary_function <int const&, std::string >( []( int const& i )-> std::string{ return std::to_string( i ); } ) );

       ::reflection::property::function::member( this, &MyClass::a );
       ::reflection::property::function::member( this, &MyClass::executor );


       std::cout << ::reflection::property::direct::check<int&>(         ::reflection::property::direct::member(   this, &MyClass::traitor   ) ) << std::endl;
       std::cout << ::reflection::property::inspect::check<int const&>(  ::reflection::property::inspect::member(  this, &MyClass::inspector ) ) << std::endl;
       std::cout << ::reflection::property::mutate::check<int const&>(   ::reflection::property::mutate::member(   this, &MyClass::mutator   ) ) << std::endl;

       std::cout << ::reflection::property::function::check<>(           ::reflection::property::function::member( this, &MyClass::a         ) ) << std::endl;
       std::cout << ::reflection::property::function::check<int>(        ::reflection::property::function::member( this, &MyClass::a         ) ) << std::endl;

        auto f0 = ::reflection::property::function::member( this, &MyClass::a ); ::reflection::property::function::execute<void>(        f0     );
        auto f1 = ::reflection::property::function::member( this, &MyClass::b ); ::reflection::property::function::execute<int>(         f1    ) ;
        auto f2 = ::reflection::property::function::member( this, &MyClass::c ); ::reflection::property::function::execute<void,int>(    f2  , 1  );
        auto f3 = ::reflection::property::function::member( this, &MyClass::d ); ::reflection::property::function::execute<int,int,int>( f3 , 1, 1 );

        auto x0 = ::reflection::property::direct::member( this, &MyClass::traitor );       ::reflection::property::direct::disclose<int&>( x0 ) = 6;

        ::reflection::property::inspect::present<int const&>( ::reflection::property::inspect::member( this, &MyClass::inspector ) );
       ::reflection::property::inspect::pretend::member< bool, ::type::convert::identity< bool, int > >( this, &MyClass::inspector ).present();
       {
        auto st =[]( int const& i )-> std::string
         {
          return std::to_string( i );
         };

        std::cout << "Inspect::pretend = " <<  ::reflection::property::inspect::pretend::member< std::string, std::pointer_to_unary_function <int const&, std::string > >( this, &MyClass::inspector, std::pointer_to_unary_function <int const&, std::string >( st ) ).present() << std::endl;
       }


       ::reflection::property::variable::member( this, &MyClass::traitor, &MyClass::inspector ).disclose() = 44;

       ::reflection::property::guarded::member( this, &MyClass::mutator, &MyClass::inspector );
       std::cout << "Inspect::guarded = " <<   ::reflection::property::guarded::member( this, &MyClass::mutator, &MyClass::inspector ).present()  << std::endl;
       ::reflection::property::guarded::member( this, &MyClass::mutator, &MyClass::inspector ).process( 46 );

        auto x2 = ::reflection::property::reset::member(  this, &MyClass::defaulter );  ::reflection::property::reset::process<void>(  x2 );

        auto x1 = ::reflection::property::mutate::member( this, &MyClass::mutator );  ::reflection::property::mutate::process<int const&, bool>( x1, 10 );

       ::reflection::property::mutate::pretend::member< int, ::type::convert::identity< int, bool > >( this, &MyClass::mutator ).process( 10 );
       {
        auto ts =[]( std::string const& s )-> int
         {
          return std::stoi( s );
         };

        ::reflection::property::mutate::pretend::member< std::string, std::pointer_to_unary_function <std::string const&, int > >( this, &MyClass::mutator, std::pointer_to_unary_function <std::string const&, int>( ts ) ).process( "42" );
       }


       //::reflection::object::execute<void,int>( this, "asd", 1 );
       //::reflection::object::inspect<int>(      this, "asd" );
       //::reflection::object::direct<int>(       this, "asd" );
       //::reflection::object::reset<int>(        this, "asd" );
       //::reflection::object::set<int>(          this, "asd", 20 );

        //auto x =  ::reflection::content::direct::member(  this, &MyClass::traitor   );
        //
        //reflection::property::direct::check< int& >( x );
        //reflection::property::inspect::check< int& >( x );
        //reflection::property::mutate::check< int& >( x );

        insert(  "f0", item_type( ::memory::pointer::make( ::reflection::property::function::member( this, &MyClass::a ) ) ) );
        insert(  "f1", item_type( ::memory::pointer::make( ::reflection::property::function::member( this, &MyClass::b ) ) ) );
        //insert(  "f2", item_type( ::reflection::property::function::member( this, &MyClass::c ) ) );
        //insert(  "f3", item_type( ::reflection::property::function::member( this, &MyClass::d ) ) );

        insert(  "m1",     item_type( ::memory::pointer::make( ::reflection::content::direct::member(  this, &MyClass::traitor   ) ) ) );
        insert(  "m2",     item_type( ::memory::pointer::make( ::reflection::content::inspect::member( this, &MyClass::inspector ) ) ) );
        insert(  "m3",     item_type( ::memory::pointer::make( ::reflection::content::mutate::member(  this, &MyClass::mutator   ) ) ) );

        insert(  "g1",     item_type( ::memory::pointer::make( ::reflection::content::guarded::member( this, &MyClass::mutator, &MyClass::inspector ) ) ) );

        insert(  "extra1", item_type( ::memory::pointer::make( ::reflection::property::direct::simple<int>( 10 ) ) ) );

        insert(  "extra2", item_type( ::memory::pointer::make( ::reflection::content::guarded::simple<int>( 1024 ) ) ) );

       exists(  "asd" );
       remove(  "asd" );
       container();

       ::reflection::property::function::check<void>(   get( "f0" ) );
       ::reflection::property::function::execute<void>( get( "f0" ) );

       ::reflection::property::direct::disclose< int& >( get("m1") ) = 10;
       ::reflection::property::inspect::present< int const& >( get("m2") );
       ::reflection::property::mutate::process<  int const& >( get("m3"), 2424 );

       ::reflection::property::direct::disclose< int &  >( get("extra1") ) = 11;
       std::cout << "extra1::category::simple::direct::disclose == " << ::reflection::property::direct::disclose< int &  >( get("extra1") )<< std::endl;

       std::cout << "extra2::category::simple::inspect::present== " << ::reflection::property::inspect::present< int const& >( get("extra2") )<< std::endl;

       ::reflection::property::mutate::process<  int const& >( get("extra2"), 2424 );
       std::cout << "extra2::category::simple::inspect::present== " << ::reflection::property::inspect::present< int const& >( get("extra2") )<< std::endl;

       std::cout << "category::check == " << ::type::category::check< std::string >( get("m3") )<< std::endl;

       std::cout << "category::type = " << ::type::category::type< std::string >( dynamic_cast< ::type::category::pure_class< std::string > const& >( get("m3") ) )  << std::endl;

       std::cout << "guarded1::category::inspect::present== " << ::reflection::property::inspect::present< int const& >( get("g1") ) << std::endl;

       ::reflection::property::mutate::process<  int const& >( get("g1"), 10000 );
       std::cout << "guarded1::category::inspect::present == " << ::reflection::property::inspect::present< int const& >( get("g1") ) << std::endl;

       clear();
      }

 };


int main( int argc, char *argv[] )
 {
  std::cout << "Hello World" << std::endl;

  MyClass m;

  std::cin.get();
  return EXIT_SUCCESS;
 }
