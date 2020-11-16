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
       insert(  "extra1", item_type( ::memory::pointer::make( ::reflection::property::direct::simple<int>( 10 ) ) ) );
       insert(  "extra2", item_type( ::memory::pointer::make( ::reflection::content::guarded::simple<std::string,int>( 1024 ) ) ) );
       insert(  "extra3", item_type( ::memory::pointer::make( ::reflection::content::guarded::simple<std::string,float>( 1024 ) ) ) );
       insert(  "extra4", item_type( ::memory::pointer::make( ::reflection::content::guarded::simple<std::string,std::string>( "asdfg" ) ) ) );
      }
 };

void allvoid()
 {
  ::reflection::property::void_class           p1;
  ::reflection::property::direct::void_class   p2;
  ::reflection::property::exposed::void_class<bool>  p3;
  ::reflection::property::guarded::void_class<bool>  p4;
  ::reflection::property::inspect::void_class  p5;
  ::reflection::property::mutate::void_class<bool>   p6;
  ::reflection::property::trinity::void_class<bool>  p7;
  ::reflection::property::variable::void_class p8;
  
  ::reflection::content::void_class<std::string>           c1;
  ::reflection::content::direct::void_class<std::string>   c2;
  ::reflection::content::exposed::void_class<std::string,bool>  c3;
  ::reflection::content::guarded::void_class<std::string,bool>  c4;
  ::reflection::content::inspect::void_class<std::string>  c5;
  ::reflection::content::mutate::void_class<std::string,bool>   c6;
  ::reflection::content::trinity::void_class<std::string,bool>  c7;
  ::reflection::content::variable::void_class<std::string> c8;
 }

void free_void_void()
 {
  std::cout << __FUNCTION__ << std::endl;
 }

int free_int_void()
 {
  std::cout << __FUNCTION__ << std::endl;
  return 10;
 }

int free_int_int( int )
 {
  std::cout << __FUNCTION__ << std::endl;
  return 10;
 }

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

    int const&  calc( float f )const
     {
      std::cout << __FUNCTION__ << std::endl;
      return m_int;
     }

    int const&  inspector()const
     {
      std::cout << __FUNCTION__ << std::endl;
      return m_int;
     }

    bool        writer( int const& a )
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
       ::reflection::property::direct::member( this, &MyClass::traitor );
       ::reflection::property::direct::simple( 1024 );
       ::reflection::property::direct::simple<float>();

       ::reflection::property::inspect::member( this, &MyClass::inspector );
       //::reflection::property::inspect::pretend::member< bool, ::reflection::type::convert::identity< bool, int > >( this, &MyClass::inspector );
       ::reflection::property::inspect::simple( 150 );
       ::reflection::property::inspect::simple<double>();

       ::reflection::property::mutate::member( this, &MyClass::writer );
       //::reflection::property::mutate::pretend::member< bool, ::reflection::type::convert::identity< bool, int > >( this, &MyClass::writer );
       ::reflection::property::mutate::simple< int, bool >( 512 );
       ::reflection::property::mutate::simple< int, bool >( );

       ::reflection::property::variable::member( this, &MyClass::traitor, &MyClass::inspector );
       ::reflection::property::variable::simple( 111 );
       ::reflection::property::variable::simple<int>( );

       ::reflection::property::guarded::member( this, &MyClass::writer, &MyClass::inspector );
       ::reflection::property::guarded::simple( 666 );
       ::reflection::property::guarded::simple<int>();
       ::reflection::property::big::block_class bigb;
       ::reflection::property::big::file_class<std::string>  bigf;
       ::reflection::property::big::vector_class  bigv;

       ::reflection::content::direct::member<std::string>( this, &MyClass::traitor );
       ::reflection::content::direct::simple<std::string>( 152 ).disclose() = 4242;
       ::reflection::content::direct::simple<std::string,float>( );

       ::reflection::content::inspect::member<std::string>( this, &MyClass::inspector );
       ::reflection::content::inspect::simple<std::string>( 1024 );
       ::reflection::content::inspect::simple<std::string,double>();

       ::reflection::content::mutate::member<std::string>( this, &MyClass::writer );
       ::reflection::content::mutate::simple<int>( 1024 );
       ::reflection::content::mutate::simple<std::string,double>();

       ::reflection::content::variable::member<std::string>( this, &MyClass::traitor, &MyClass::inspector );
       ::reflection::content::variable::simple<std::string,int>( 1024 );
       ::reflection::content::variable::simple<std::string,int>( );

       ::reflection::content::guarded::member<std::string>( this, &MyClass::writer, &MyClass::inspector );
       ::reflection::content::guarded::simple<std::string,int>( 1024 );
       ::reflection::content::guarded::simple<std::string,float>( );

       std::cout << "content::direct::identifier = " << ::reflection::content::direct::member<std::string>( this, &MyClass::traitor ).identifier() << std::endl;

       std::cout << "content::direct = " << ::reflection::content::direct::member<std::string>( this, &MyClass::traitor ).disclose() << std::endl;

       std::cout << "content::inspect = " << ::reflection::content::inspect::member<std::string>( this, &MyClass::inspector ).present() << std::endl;


       ::reflection::content::mutate::member<int>( this, &MyClass::writer ).process( 2424 );

       std::cout << "content::inspect = " << ::reflection::content::inspect::member<std::string>( this, &MyClass::inspector ).present() << std::endl;

       //::reflection::property::inspect::pretend::member< std::string, std::pointer_to_unary_function<int const&, std::string > >( this, &MyClass::inspector, std::pointer_to_unary_function <int const&, std::string >( []( int const& i )-> std::string{ return std::to_string( i ); } ) );

       ::reflection::property::function::member( this, &MyClass::a );
       ::reflection::property::function::member( this, &MyClass::executor );

       ::reflection::content::function::member<std::string>( this, &MyClass::a );
       ::reflection::content::function::member<std::string>( this, &MyClass::executor );
       ::reflection::content::function::member<std::string>( this, &MyClass::writer  );
       ::reflection::content::function::member<std::string>( this, &MyClass::d  );
     //::reflection::content::function::member<std::string>( this, &MyClass::calc );

       // TODO ::reflection::content::function::free<std::string>( &free_void_void ).execute();
       // TODO ::reflection::content::function::free<std::string>( &free_int_void  ).execute();
       // TODO ::reflection::content::function::free<std::string>( &free_int_int   ).execute( 10 );

       std::cout << ::reflection::property::direct::check<int&>(         ::reflection::property::direct::member(   this, &MyClass::traitor   ) ) << std::endl;
       std::cout << ::reflection::property::inspect::check<int const&>(  ::reflection::property::inspect::member(  this, &MyClass::inspector ) ) << std::endl;
       std::cout << ::reflection::property::mutate::check<int const&>(   ::reflection::property::mutate::member(   this, &MyClass::writer   ) ) << std::endl;

       std::cout << ::reflection::property::function::check<>(           ::reflection::property::function::member( this, &MyClass::a         ) ) << std::endl;
       std::cout << ::reflection::property::function::check<int>(        ::reflection::property::function::member( this, &MyClass::a         ) ) << std::endl;

        auto f0 = ::reflection::property::function::member( this, &MyClass::a ); ::reflection::property::function::execute<void>(        f0     );
        auto f1 = ::reflection::property::function::member( this, &MyClass::b ); ::reflection::property::function::execute<int>(         f1    ) ;
        auto f2 = ::reflection::property::function::member( this, &MyClass::c ); ::reflection::property::function::execute<void,int>(    f2  , 1  );
        auto f3 = ::reflection::property::function::member( this, &MyClass::d ); ::reflection::property::function::execute<int,int,int>( f3 , 1, 1 );

        auto x0 = ::reflection::property::direct::member( this, &MyClass::traitor );       ::reflection::property::direct::disclose<int&>( x0 ) = 6;

        ::reflection::property::inspect::present<int const&>( ::reflection::property::inspect::member( this, &MyClass::inspector ) );
       //::reflection::property::inspect::pretend::member< bool, ::reflection::type::convert::identity< bool, int > >( this, &MyClass::inspector ).present();
       {
        auto st =[]( int const& i )-> std::string
         {
          return std::to_string( i );
         };

        //std::cout << "Inspect::pretend = " <<  ::reflection::property::inspect::pretend::member< std::string, std::pointer_to_unary_function <int const&, std::string > >( this, &MyClass::inspector, std::pointer_to_unary_function <int const&, std::string >( st ) ).present() << std::endl;
       }


       ::reflection::property::variable::member( this, &MyClass::traitor, &MyClass::inspector ).disclose() = 44;

       ::reflection::property::guarded::member( this, &MyClass::writer, &MyClass::inspector );
       std::cout << "Inspect::guarded = " <<   ::reflection::property::guarded::member( this, &MyClass::writer, &MyClass::inspector ).present()  << std::endl;
       ::reflection::property::guarded::member( this, &MyClass::writer, &MyClass::inspector ).process( 46 );

        auto x2 = ::reflection::property::reset::member(  this, &MyClass::defaulter );  ::reflection::property::reset::process<void>(  x2 );

        auto x1 = ::reflection::property::mutate::member( this, &MyClass::writer );  ::reflection::property::mutate::process<int const&, bool>( x1, 10 );

       //::reflection::property::mutate::pretend::member< int, ::reflection::type::convert::identity< bool, int > >( this, &MyClass::writer ).process( 10 );
       {
        auto ts =[]( std::string const& s )-> int
         {
          return std::stoi( s );
         };

        //::reflection::property::mutate::pretend::member< std::string, std::pointer_to_unary_function <std::string const&, int > >( this, &MyClass::writer, std::pointer_to_unary_function <std::string const&, int>( ts ) ).process( "42" );
       }


       //::reflection::operation::execute<void,int>( this, "asd", 1 );
       //::reflection::operation::inspect<int>(      this, "asd" );
       //::reflection::operation::direct<int>(       this, "asd" );
       //::reflection::operation::reset<int>(        this, "asd" );
       //::reflection::operation::set<int>(          this, "asd", 20 );

        //auto x =  ::reflection::content::direct::member(  this, &MyClass::traitor   );
        //
        //reflection::property::direct::check< int& >( x );
        //reflection::property::inspect::check< int& >( x );
        //reflection::property::mutate::check< int& >( x );

        insert(  "f0", item_type( ::memory::pointer::make( ::reflection::property::function::member( this, &MyClass::a ) ) ) );
        insert(  "f1", item_type( ::memory::pointer::make( ::reflection::property::function::member( this, &MyClass::b ) ) ) );
        //insert(  "f2", item_type( ::reflection::property::function::member( this, &MyClass::c ) ) );
        //insert(  "f3", item_type( ::reflection::property::function::member( this, &MyClass::d ) ) );

        insert(  "m1",     item_type( ::memory::pointer::make( ::reflection::content::direct::member<std::string>(  this, &MyClass::traitor   ) ) ) );
        insert(  "m2",     item_type( ::memory::pointer::make( ::reflection::content::inspect::member<std::string>( this, &MyClass::inspector ) ) ) );
        insert(  "m3",     item_type( ::memory::pointer::make( ::reflection::content::mutate::member<std::string>(  this, &MyClass::writer   ) ) ) );

        insert(  "mS",     item_type( ::memory::pointer::make( ::reflection::content::inspect::member<std::string>( this, &MyClass::structure_get ) ) ) );

        insert(  "g1",     item_type( ::memory::pointer::make( ::reflection::content::guarded::member<std::string>( this, &MyClass::writer, &MyClass::inspector ) ) ) );

        insert(  "extra1", item_type( ::memory::pointer::make( ::reflection::property::direct::simple<            int>( 10 ) ) ) );
        insert(  "extra2", item_type( ::memory::pointer::make( ::reflection::content::guarded::simple<std::string,int>( 1024 ) ) ) );

        insert(  "v1",     item_type( ::memory::pointer::make( ::reflection::content::variable::member<std::string>( this, &MyClass::traitor, &MyClass::inspector ) ) ) );

        ::reflection::property::assign< int >( get( "v1" ), get( "g1" ) );

       exists(  "asd" );
       remove(  "asd" );

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

       std::cout << "category::check == " << ::reflection::ornament::category_class<std::string>::check( get("m3") )<< std::endl;

       std::cout << "category::identifier = " << dynamic_cast< ::reflection::ornament::category_class< std::string > const& >( get("m3") ).identifier()  << std::endl;

       std::cout << "guarded1::category::inspect::present== " << ::reflection::property::inspect::present< int const& >( get("g1") ) << std::endl;

       ::reflection::property::mutate::process<  int const& >( get("g1"), 10000 );
       std::cout << "guarded1::category::inspect::present == " << ::reflection::property::inspect::present< int const& >( get("g1") ) << std::endl;


       //::reflection::content::big::vector_class          bv;
       //::reflection::content::big::member_class<MyClass> bm;
       //::reflection::content::big::block_class           bb;
       //::reflection::content::big::file_class<std::string>            bf;
       //clear();
      }

 };


int main( int argc, char *argv[] )
 {
  std::cout << "Hello World" << std::endl;

  MyClass m;
  MyClass q;

  ::reflection::operation::encode::observe_class<int> observe;

  int i;
  observe.insert( typeid(                             std::string ).name(),         []( int &  , std::string const& name, ::reflection::property::pure_class const&    )  { std::cout << "string - " << __FUNCTION__ << std::endl; return true; } );
  observe.insert( typeid(                                   float ).name(),         []( int &  , std::string const& name, ::reflection::property::pure_class const&    )  { std::cout << "float  - " << __FUNCTION__ << std::endl; return true; } );
  observe.insert( typeid(                                     int ).name(),         []( int &  , std::string const& name, ::reflection::property::pure_class const&    )  { std::cout << "int    - " << __FUNCTION__ << std::endl; return true; } );
  observe.insert( typeid( ::reflection::property::structure_class<> ).name(), [&observe]( int & i, std::string const& name, ::reflection::property::pure_class const& p  )
   {
    std::cout << "struct - " << __FUNCTION__ << std::endl;
    observe.view( i, ::reflection::property::inspect::present< ::reflection::property::structure_class<> const& >( p ) );
    return true;
   } );

  observe.view( i, m );

  typedef ::reflection::operation::transfer::assign_struct<std::string >     assign_type;
  typedef ::reflection::property::structure_class<std::string>                        structure_type;

  ::reflection::operation::encode::observe_class< structure_type, std::string, std::string, assign_type::error_enum > observe_assign;

  observe_assign.insert( typeid( std::string ).name(),  assign_type::process<std::string> );
  observe_assign.insert( typeid( int ).name(),          assign_type::process<int> );

  observe_assign.view( m, q );

  return EXIT_SUCCESS;
 }
