#include <iostream>
#include <iomanip>
#include <string>
#include <functional>

#include "reflection/reflection.hpp"
#include "reflection/type/convert/convert.hpp"

#include "reflection/type/ptr/make.hpp"

class MyClass_XML_A
 : public ::reflection::object::class_class<MyClass_XML_A>
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
: public ::reflection::object::class_class<MyClass_XML_B>
 {
  public:
    typedef ::reflection::object::structure_class<> structure_type;

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
        insert(  "m1",     item_type( ::memory::pointer::make( ::reflection::content::direct::member(  this, &MyClass_XML_B::traitor   ) ) ) );
        insert(  "m2",     item_type( ::memory::pointer::make( ::reflection::content::inspect::member( this, &MyClass_XML_B::inspector ) ) ) );
        insert(  "m3",     item_type( ::memory::pointer::make( ::reflection::content::mutate::member(  this, &MyClass_XML_B::mutator   ) ) ) );

        insert(  "mS",     item_type( ::memory::pointer::make( ::reflection::content::inspect::member( this, &MyClass_XML_B::structure_get ) ) ) );

        insert(  "g1",     item_type( ::memory::pointer::make( ::reflection::content::guarded::member( this, &MyClass_XML_B::mutator, &MyClass_XML_B::inspector ) ) ) );

        insert(  "extra1", item_type( ::memory::pointer::make( ::reflection::property::direct::simple<int>( 10 ) ) ) );
        insert(  "extra2", item_type( ::memory::pointer::make( ::reflection::content::guarded::simple<int>( 1024 ) ) ) );

        insert(  "v1",     item_type( ::memory::pointer::make( ::reflection::content::variable::member( this, &MyClass_XML_B::traitor, &MyClass_XML_B::inspector ) ) ) );

        ::reflection::property::assign< int >( get( "v1" ), get( "g1" ) );
      }

 };


int main_xml( int argc, char *argv[] )
 {
  std::cout << "Hello World" << std::endl;

  MyClass_XML_B m;

  typedef ::reflection::object::observe_class<std::ostream> observe_type;
  typedef ::reflection::object::transfer::xml_class<std::ostream> xml_type;
  typedef ::reflection::object::structure_class<> structure_type;

  xml_type xml;
  observe_type observe;

  observe.recover( observe_type::not_category_index  , std::bind( &xml_type::recover, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3 )  );
  observe.recover( observe_type::missing_action_index, std::bind( &xml_type::recover, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3 )  ); 
  observe.recover( observe_type::action_fail_index   , std::bind( &xml_type::recover, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3 )  );

  observe.protocol().emplace( typeid( std::string    ).name(), std::bind( &xml_type::simple<std::string>, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3 ) ); 
  observe.protocol().emplace( typeid(       float    ).name(), std::bind( &xml_type::simple<float>,       std::placeholders::_1, std::placeholders::_2, std::placeholders::_3 ) ); 
  observe.protocol().emplace( typeid(         int    ).name(), std::bind( &xml_type::simple<int>,         std::placeholders::_1, std::placeholders::_2, std::placeholders::_3 ) ); 
  observe.protocol().emplace( typeid( structure_type ).name(), std::bind( &xml_type::structure,           std::ref( observe ), std::placeholders::_1, std::placeholders::_2, std::placeholders::_3 ) );

  observe.view( m, std::cout );

  std::cin.get();
  return EXIT_SUCCESS;
 }
