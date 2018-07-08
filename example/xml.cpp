#include <iostream>
#include <iomanip>
#include <string>
#include <functional>

#include "reflection/reflection.hpp"

#include "reflection/type/convert/convert.hpp"

#include "reflection/type/ptr/make.hpp"

class MyClass_XML_A
 : public ::reflection::content::class_class<MyClass_XML_A>
 {
  public:
    MyClass_XML_A(){ init(); }
  private:
   void init()
      {
       insert(  "extra1", item_type( ::memory::pointer::make( ::reflection::property::direct::simple<int>( 10 ) ) ) );
       insert(  "extra2", item_type( ::memory::pointer::make( ::reflection::content::guarded::simple<int>( 1024 ) ) ) );
       insert(  "extra3", item_type( ::memory::pointer::make( ::reflection::content::guarded::simple<float>( 1024 ) ) ) );
       insert(  "extra4", item_type( ::memory::pointer::make( ::reflection::content::guarded::simple<std::string>( "asdfg" ) ) ) );
      }

 };


class MyClass_XML_B
: public ::reflection::content::class_class<MyClass_XML_B>
 {
  public:
    typedef ::reflection::property::structure_class<> structure_type;

    MyClass_XML_B(){ init(); }


    int      &  traitor()
     {
      return m_int;
     }

    int const&  inspector()const
     {
      
      return m_int;
      }

    bool        mutator( int const& a )
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

    MyClass_XML_A m_sub;

  private:
     void init()
      {
        //insert(  "m1",      this, { &MyClass_XML_B::traitor }  );
        //insert(  "g1",      this{ &MyClass_XML_B::mutator, &MyClass_XML_B::inspector } );
        //insert(  "g1",      this{ &MyClass_XML_B::traitor, &MyClass_XML_B::inspector } );

        insert(  "m1",     item_type( ::memory::pointer::make( ::reflection::content::direct::member(  this, &MyClass_XML_B::traitor   ) ) ) );
        insert(  "m2",     item_type( ::memory::pointer::make( ::reflection::content::inspect::member( this, &MyClass_XML_B::inspector ) ) ) );
        insert(  "m3",     item_type( ::memory::pointer::make( ::reflection::content::mutate::member(  this, &MyClass_XML_B::mutator   ) ) ) );

        insert(  "mS",     item_type( ::memory::pointer::make( ::reflection::content::inspect::member( this, &MyClass_XML_B::structure_get ) ) ) );

        insert(  "g1",     item_type( ::memory::pointer::make( ::reflection::content::guarded::member( this, &MyClass_XML_B::mutator, &MyClass_XML_B::inspector ) ) ) );

        insert(  "extra1", item_type( ::memory::pointer::make( ::reflection::content::direct::simple<int>( 10 ) ) ) );
        insert(  "extra2", item_type( ::memory::pointer::make( ::reflection::content::guarded::simple<int>( 1024 ) ) ) );

        insert(  "v1",     item_type( ::memory::pointer::make( ::reflection::content::variable::member( this, &MyClass_XML_B::traitor, &MyClass_XML_B::inspector ) ) ) );
      }

 };


int main_xml( int argc, char *argv[] )
 {
  std::cout << "Hello World" << std::endl;

  MyClass_XML_B r;

  typedef ::reflection::operation::transfer::observe_class<std::ostream> observe_type;
  typedef ::reflection::operation::transfer::xml_struct<std::ostream> xml_type;
  typedef ::reflection::property::structure_class<> structure_type;

  observe_type observe;
  xml_type xml(observe);

  observe.view( std::cout, r );

 auto const& c = r.container();
 auto const& m = r.get("extra2");

  std::cin.get();
  return EXIT_SUCCESS;
 }
