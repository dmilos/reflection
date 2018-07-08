#include <iostream>
#include <iomanip>
#include <string>
#include <functional>

#include "reflection/reflection.hpp"

class MyClass_json_A
 : public ::reflection::content::class_class<MyClass_json_A>
 {
  public:
    MyClass_json_A(){ init(); }
  private:
   void init()
      {
       insert(  "extra1", item_type( ::memory::pointer::make( ::reflection::property::direct::simple<int>( 10 ) ) ) );
       insert(  "extra2", item_type( ::memory::pointer::make( ::reflection::content::guarded::simple<int>( 1024 ) ) ) );
       insert(  "extra3", item_type( ::memory::pointer::make( ::reflection::content::guarded::simple<float>( 1024 ) ) ) );
       insert(  "extra4", item_type( ::memory::pointer::make( ::reflection::content::guarded::simple<std::string>( "asdfg" ) ) ) );
      }

 };


class MyClass_json_B
: public ::reflection::content::class_class<MyClass_json_B>
 {
  public:
    typedef ::reflection::property::structure_class<> structure_type;

    MyClass_json_B(){ init(); }


    int      &  traitor()
     {
      return m_int;
     }

    int const&  inspector()const
     {
      
      return m_int;
      }

    bool        writter( int const& a )
     {
      m_int = a;
      return true;
     }

    structure_type const&  structure_get()const
     {
      return m_sub;
      }

  private:
    int m_int;

    MyClass_json_A m_sub;

  private:
     void init()
      {
        //insert(  "m1",      this, { &MyClass_json_B::traitor }  );
        //insert(  "g1",      this{ &MyClass_json_B::writter, &MyClass_json_B::inspector } );
        //insert(  "g1",      this{ &MyClass_json_B::traitor, &MyClass_json_B::inspector } );

        insert(  "m1",     item_type( ::memory::pointer::make( ::reflection::content::direct::member(  this, &MyClass_json_B::traitor   ) ) ) );
        insert(  "m2",     item_type( ::memory::pointer::make( ::reflection::content::inspect::member( this, &MyClass_json_B::inspector ) ) ) );
        insert(  "m3",     item_type( ::memory::pointer::make( ::reflection::content::mutate::member(  this, &MyClass_json_B::writter   ) ) ) );

        insert(  "mS",     item_type( ::memory::pointer::make( ::reflection::content::inspect::member( this, &MyClass_json_B::structure_get ) ) ) );

        insert(  "g1",     item_type( ::memory::pointer::make( ::reflection::content::guarded::member( this, &MyClass_json_B::writter, &MyClass_json_B::inspector ) ) ) );

        insert(  "extra1", item_type( ::memory::pointer::make( ::reflection::property::direct::simple<int>( 10 ) ) ) );
        insert(  "extra2", item_type( ::memory::pointer::make( ::reflection::content::guarded::simple<int>( 1024 ) ) ) );

        insert(  "v1",     item_type( ::memory::pointer::make( ::reflection::content::variable::member( this, &MyClass_json_B::traitor, &MyClass_json_B::inspector ) ) ) );
      }

 };


int main_json( int argc, char *argv[] )
 {
  std::cout << "Hello World" << std::endl;

  MyClass_json_B m;

  typedef ::reflection::operation::transfer::observe_class<std::ostream> observe_type;
  typedef ::reflection::operation::transfer::json_struct<std::ostream> json_type;

  observe_type observe;
  json_type json( observe );

  //observe.recover( observe_type::not_category_index  , std::bind( &json_type::recover, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3 )  );
  //observe.recover( observe_type::missing_action_index, std::bind( &json_type::recover, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3 )  ); 
  //observe.recover( observe_type::action_fail_index   , std::bind( &json_type::recover, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3 )  );

  observe.view( std::cout, m );

  std::cin.get();
  return EXIT_SUCCESS;
 }
