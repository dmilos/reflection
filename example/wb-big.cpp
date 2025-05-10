#include <iostream>
#include <iomanip>
#include <string>
#include <functional>
#include <sstream>
#include <fstream>
#include <chrono>

#include "reflection/reflection.hpp"

class MyFirstClassOriginal //!< Original condition. Not bloated with any other code.
 {
  public:
    MyFirstClassOriginal():m_float(98765){ }

    void a(){ }
    float      &  traitor(){ return m_float; }
    float const&  reader()const{ return m_float; }
    bool          writer( float const& a ){ m_float = a; return true; }

  private: // And private member
    float m_float;
 };

class MySecondClassOriginal //!< Original condition. Not bloated with any other code.
{
public:
    MySecondClassOriginal() :m_float(565678) { }

    void a() { }
    float& traitor() { return m_float; }
    float const& reader()const { return m_float; }
    bool          writer(float const& a) { m_float = a; return true; }

private: // And private member
    float m_float;
};

class MyThirdClassOriginal //!< Original condition. Not bloated with any other code.
{
public:
    MyThirdClassOriginal() :m_float(565678) { }

    void a() { }
    float& traitor() { return m_float; }
    float const& reader()const { return m_float; }
    bool          writer(float const& a) { m_float = a; return true; }

private: // And private member
    float m_float;
};


class MyBaseClass //!< Original condition. Not bloated with any other code.
 {
  public:
    MyBaseClass():m_float(98765){ }

    void a(){ }
    float      &  traitor(){ return m_float; }
    float const&  reader()const{ return m_float; }
    bool          writer( float const& a ){ m_float = a; return true; }

  private: // And private member
    float m_float;
 };

class MyMainClass //!< Original condition. Not bloated with any other code.
 : public MyBaseClass
 {
  public:
    enum Enumerator{ enum1, enum2, enum10=10, enum11=150 };
    typedef std::array<float,2> MyTypDef;
    typedef std::vector<int> MyVectorType;

    MyMainClass():m_int(123456){ m_vector.resize(3,456); }

    void a(){ }
    void                b0( float const& f ){ static std::string s;   }
    std::string const&  b1( float const& f ){ static std::string s;   return s; }
    int  c( float const& f, std::string const& str ){  return 1; }
    int  d( float const& f, std::string const& str, bool const& b ){  return 1; }

    int      &  traitor(){ return m_int; }
    int const&  reader()const{ return m_int; }
    bool        writer( int const& a ){ m_int = a; return true; }
    bool        writerV( int const& a )volatile{ m_int = a; return true; }

    MyFirstClassOriginal      & subsider_traitor(){ return m_subsider; }
    MyFirstClassOriginal const& subsider_reader()const{ return m_subsider; }

    MyThirdClassOriginal      & subsider_the3rd_traitor(){ return m_3; }
    MyThirdClassOriginal const& subsider_the3rd_reader()const{ return m_3; }

    static int   some_static_function( float const&f ){ return 12; }

    Enumerator const&  enum_read()const{ return m_enum; }
    bool               enum_write( Enumerator const& a ){ m_enum = a; return true; }

    MyVectorType const&  vector_reader()const{ return m_vector; }
    MyVectorType      &  vector_traitor(){ return m_vector; }

  public:
    double m_public = 456;
    std::complex<float> m_complexF ={1,2};
    const double          m_const_public          = 123;
   volatile const double m_volatile_const_public = 456;
   volatile double       m_volatile_public       = 789;

  public:
   static std::string m_static;
  private: // And private member
    Enumerator m_enum = enum2;
    int m_int;
    volatile int m_cv;
    MyFirstClassOriginal m_subsider;
    MyThirdClassOriginal m_3;
    MyVectorType  m_vector;
 };

reflection__IDSPEC( std::string, "MyFirstClassOriginal",  MyFirstClassOriginal )
reflection__IDSPEC( std::string, "MyBaseClass",  MyBaseClass )
reflection__IDSPEC( std::string, "MyMainClass", MyMainClass)
reflection__IDSPEC( std::string, "MyThirdClassOriginal", MyThirdClassOriginal  )
reflection__IDSPEC( std::string, "MySecondClassOriginal", MySecondClassOriginal)


std::string MyMainClass::m_static="blahblahfoofoo"; //!< TODO

reflection__CLASS_BEGIN_inherit( MyFirstClassReflectionInherit, public, MyFirstClassOriginal )
   reflection__CLASS_MEMBER_exposed("number-1", MyFirstClassOriginal, traitor, writer)
   reflection__CLASS_MEMBER_exposed("number-2", MyFirstClassOriginal, traitor, writer)
   reflection__CLASS_MEMBER_exposed("number-3", MyFirstClassOriginal, traitor, writer)
reflection__CLASS_END_inherit(MyFirstClassReflectionInherit, MyFirstClassOriginal );

reflection__CLASS_BEGIN_pointer( MySecondClassReflectionPointer, public, MySecondClassOriginal, MySecondClassOriginal*)
   reflection__CLASS_MEMBER_exposed("number-1", MySecondClassOriginal, traitor, writer)
   reflection__CLASS_MEMBER_exposed("number-2", MySecondClassOriginal, traitor, writer)
   reflection__CLASS_MEMBER_exposed("number-3", MySecondClassOriginal, traitor, writer)
reflection__CLASS_END_pointer(MySecondClassReflectionPointer, MySecondClassOriginal );

reflection__CLASS_BEGIN_reference(MyThirdClassReflectionReferenceConst, public, MyThirdClassOriginal, MyThirdClassOriginal  const& )
    reflection__CLASS_MEMBER_inspect("number-1", MyThirdClassOriginal, reader )
    reflection__CLASS_MEMBER_inspect("number-2", MyThirdClassOriginal, reader )
    reflection__CLASS_MEMBER_inspect("number-3", MyThirdClassOriginal, reader )
reflection__CLASS_END_reference(MyThirdClassReflectionReferenceConst, MyThirdClassOriginal);

reflection__CLASS_BEGIN_reference(MyThirdClassReflectionReferenceMutable, public, MyThirdClassOriginal, MyThirdClassOriginal &)
    reflection__CLASS_MEMBER_exposed("number-1", MyThirdClassOriginal, traitor, writer)
    reflection__CLASS_MEMBER_exposed("number-2", MyThirdClassOriginal, traitor, writer)
    reflection__CLASS_MEMBER_exposed("number-3", MyThirdClassOriginal, traitor, writer)
reflection__CLASS_END_reference(MyThirdClassReflectionReferenceMutable, MyThirdClassOriginal);


reflection__CLASS_BEGIN_pointer(MyThirdClassReflectionPointerConst, public, MyThirdClassOriginal, MyThirdClassOriginal*)
    reflection__CLASS_MEMBER_inspect("number-1", MyThirdClassOriginal, reader)
    reflection__CLASS_MEMBER_inspect("number-2", MyThirdClassOriginal, reader)
    reflection__CLASS_MEMBER_inspect("number-3", MyThirdClassOriginal, reader)
reflection__CLASS_END_pointer(MyThirdClassReflectionPointerConst, MyThirdClassOriginal);

reflection__CLASS_BEGIN_pointer(MyThirdClassReflectionPointerMutable, public, MyThirdClassOriginal, MyThirdClassOriginal*)
    reflection__CLASS_MEMBER_exposed("number-1", MyThirdClassOriginal, traitor, writer)
    reflection__CLASS_MEMBER_exposed("number-2", MyThirdClassOriginal, traitor, writer)
    reflection__CLASS_MEMBER_exposed("number-3", MyThirdClassOriginal, traitor, writer)
reflection__CLASS_END_pointer(MyThirdClassReflectionPointerMutable, MyThirdClassOriginal);


reflection__CLASS_BEGIN_pointer( MyBaseClasssReflectionPointer, public, MyBaseClass, MyBaseClass*)
    reflection__CLASS_MEMBER_inspect("number-float-inspect", MyBaseClass, reader )
    //reflection__CLASS_MEMBER_exposed("number-float", MyBaseClass, traitor, writer)
reflection__CLASS_END_pointer( MyBaseClasssReflectionPointer, MyBaseClass );

reflection__CLASS_BEGIN_reference(MyBaseClasssReflectionReference, public, MyBaseClass, MyBaseClass const&)
    //reflection__CLASS_MEMBER_exposed("number-float", MyBaseClass, traitor, writer)
    reflection__CLASS_MEMBER_inspect("number-float-inspect", MyBaseClass, reader)
reflection__CLASS_END_reference(MyBaseClasssReflectionReference, MyBaseClass);


// Reflect to reflection
//template< typename someType_name >     // Yeah template.
reflection__CLASS_BEGIN_inherit( MyClassReflection, public, MyMainClass )

     reflection__CLASS_BASE_direct(  "1base-something", MyMainClass, public, default, MyBaseClass );
     reflection__CLASS_BASE_inspect( "2base-something", MyMainClass, public, default, MyBaseClass );
     reflection__CLASS_BASE_mutate(  "3base-something", MyMainClass, public, default, MyBaseClass );

     reflection__CLASS_BASE_exposed(  "4base-something", MyMainClass, public, default, MyBaseClass );
     reflection__CLASS_BASE_variable( "5base-something", MyMainClass, public, default, MyBaseClass );
     reflection__CLASS_BASE_guarded(  "6base-something", MyMainClass, public, default, MyBaseClass );

     reflection__CLASS_BASE_trinity(  "7base-something", MyMainClass, public, default, MyBaseClass );

   reflection__CLASS_TYPEDEF_member( "typedef-of-something", MyMainClass, public, MyTypDef );
   reflection__CLASS_TYPEDEF_member( "typedef-of-vector", MyMainClass, public, MyVectorType );
 
   reflection__CLASS_ENUM_begin( "enum-for-something", MyMainClass::Enumerator );
     reflection__CLASS_ENUM_value( "enum1",  MyMainClass::enum1 )
     reflection__CLASS_ENUM_value( "enum2",  MyMainClass::enum2 )
     reflection__CLASS_ENUM_value( "enum10", MyMainClass::enum10 )
     reflection__CLASS_ENUM_value( "enum11", MyMainClass::enum11 )
   reflection__CLASS_ENUM_end( MyMainClass::Enumerator )
 
   reflection__CLASS_MEMBER_mutate(    "asasd3",  MyMainClass, writer  )
   reflection__CLASS_MEMBER_direct(    "asasd4",  MyMainClass, traitor  )
   reflection__CLASS_MEMBER_inspect(   "asasd5",  MyMainClass, reader   )
  
   reflection__CLASS_MEMBER_variable(  "asasd1",  MyMainClass, traitor, reader )
   reflection__CLASS_MEMBER_guarded(   "asasd2",  MyMainClass, writer, reader  )
 
    reflection__CLASS_MEMBER_guarded(   "00enum",  MyMainClass, enum_write, enum_read  )
 
      reflection__CLASS_FUNCTION_member( "traitor", MyMainClass, public, traitor )
      reflection__CLASS_FUNCTION_member( "reader", MyMainClass, public, reader  )
    //reflection__CLASS_FUNCTION_member( "writerV", MyMainClass, public, writerV)
      reflection__CLASS_FUNCTION_member( "writer", MyMainClass, public, writer  )
 
   reflection__CLASS_FUNCTION_member( "f10", MyMainClass, public, b0 )
   reflection__CLASS_FUNCTION_member( "f11", MyMainClass, public, b1 )
 
   reflection__CLASS_FUNCTION_member( "f2", MyMainClass, public, c )
   reflection__CLASS_FUNCTION_member( "f3", MyMainClass, public, d )
 
   reflection__CLASS_FUNCTION_static( "my_static", MyMainClass, public, some_static_function )

   reflection__CLASS_MEMBER_inspect("0subsider-inspect", MyMainClass,  subsider_reader )

    reflection__CLASS_MEMBER_variable(  "0subsider-traitor", MyMainClass, subsider_traitor, subsider_reader )
    reflection__CLASS_MEMBER_variable(  "my-vector", MyMainClass, vector_traitor, vector_reader )
    reflection__CLASS_MEMBER_variable(  "0subsider-traitor-3", MyMainClass, subsider_the3rd_traitor, subsider_the3rd_reader )

   reflection__CLASS_FIELD_direct(  "some-field-doubleD", MyMainClass, public, m_public )
   reflection__CLASS_FIELD_direct(  "some-const-field-doubleD", MyMainClass, public, m_const_public )
   reflection__CLASS_FIELD_direct(  "some-const-volatile-field-doubleD", MyMainClass, public, m_volatile_const_public )
   reflection__CLASS_FIELD_direct(  "some-volatile-field-doubleD", MyMainClass, public, m_volatile_public )

     reflection__CLASS_FIELD_direct(  "some-field-complexF", MyMainClass, public, m_complexF )

   reflection__CLASS_FIELD_mutate(  "some-field-doubleM", MyMainClass, public, m_public )
   reflection__CLASS_FIELD_inspect( "some-field-doubleI", MyMainClass, public, m_public )

   reflection__CLASS_FIELD_exposed(  "some-field-doubleE", MyMainClass, public, m_public )
   reflection__CLASS_FIELD_guarded(  "some-field-doubleG", MyMainClass, public, m_public )
   reflection__CLASS_FIELD_variable( "some-field-doubleV", MyMainClass, public, m_public )
 
   reflection__CLASS_FIELD_trinity( "some-field-doubleT", MyMainClass, public, m_public )

  reflection__CLASS_STATIC_direct(  "some-common-stringD", MyMainClass, public, m_static )
  reflection__CLASS_STATIC_inspect( "some-common-stringI", MyMainClass, public, m_static )
  reflection__CLASS_STATIC_mutate(  "some-common-stringM", MyMainClass, public, m_static )

 reflection__CLASS_STATIC_variable( "some-common-stringV", MyMainClass, public, m_static )
 reflection__CLASS_STATIC_guarded(  "some-common-stringG", MyMainClass, public, m_static )
 reflection__CLASS_STATIC_exposed(  "some-common-stringE", MyMainClass, public, m_static )

  reflection__CLASS_STATIC_trinity( "some-common-stringT", MyMainClass, public, m_static )
 
   reflection__CLASS_MEMBER_exposed(   "asasd2", MyMainClass, traitor,  writer )

reflection__CLASS_END_inherit( MyClassReflection, MyMainClass );


int main( int argc, char *argv[] )
 {
    int i;
    ::reflection::property::_internal::proxy_class<int>        aaa1;    aaa1.valid();
    ::reflection::property::_internal::proxy_class<int*>       aaa2;    aaa2.valid();
    ::reflection::property::_internal::proxy_class<int const*> aaa3;    aaa3.valid();
    //::reflection::property::_internal::proxy_class<int *const> aaa4;  aaa4.valid();
    ::reflection::property::_internal::proxy_class<int&>       aaa5( i ); aaa5.valid();
    ::reflection::property::_internal::proxy_class<int const&> aaa6( i ); aaa6.valid();

  auto now = std::chrono::system_clock::now();
  auto now1 = std::chrono::steady_clock::now();
  auto now2 = std::chrono::high_resolution_clock::now();
  //auto now3 = std::chrono::utc_clock::now();

  auto hour    = std::chrono::duration_cast<std::chrono::hours>(   std::chrono::time_point_cast<std::chrono::hours>(   now ).time_since_epoch() ) % 24;
  auto minute  = std::chrono::duration_cast<std::chrono::minutes>( std::chrono::time_point_cast<std::chrono::minutes>( now ).time_since_epoch() ) % 60;
  auto seconds = std::chrono::duration_cast<std::chrono::seconds>( std::chrono::time_point_cast<std::chrono::seconds>( now ).time_since_epoch() ) % 60;

  std::ofstream ofs( std::to_string( hour.count() ) + "-" + std::to_string(minute.count()) + "-" + std::to_string( seconds.count()) + ".txt");

  std::cout << __FUNCTION__ << std::endl;
  // Some typedefs
  typedef ::reflection::operation::encode::observe_class<std::ostream> observe_type;
  typedef ::reflection::operation::transfer::cpp::print_struct<std::ostream> cpp_type;
  typedef ::reflection::operation::transfer::yaml::print_struct<std::ostream> yaml_type;
  typedef ::reflection::operation::transfer::protobuf::print_struct<std::ostream> protobuf_type;
  typedef ::reflection::operation::transfer::ini::print_struct<std::ostream> ini_type;

  MyMainClass o;
  MyClassReflection   r;  //!< Reflection of Original, with pointing to some instance
  //MyClassReflection<int>   r0;  //!< Reflection of Original, with pointing to some instance
  //MyClassReflection<float> r1( &o );  //!< Reflection of Original, with pointing to same instance

  ::reflection::operation::encode::observe_class<std::ostream> observe; //!< Have algorithm for observation(serialize/...) of instance

  observe.clear();
  {
      typedef ::reflection::operation::transfer::json::print_struct<std::ostream> json_type;
      json_type json(observe);
      observe.register_class_inherit<MyFirstClassOriginal, MyFirstClassReflectionInherit>();
      observe.register_class<MyBaseClass, MyBaseClasssReflectionPointer>();
  }
  observe.view(ofs, r); // JSONize
  observe.clear();

  {
   typedef ::reflection::operation::transfer::xml::print_struct<std::ostream> xml_type;
   auto xml_context = xml_type::context();
   //xml_context->m_tabulator="\t";
   xml_type xml( observe, xml_context );

    xml_type::register_class_inherit<    MyFirstClassOriginal, MyFirstClassReflectionInherit>( observe, xml_context );

  //xml_type::register_class_pointer<   MyBaseClass,           MyBaseClasssReflectionPointer >( observe, xml_context );
    xml_type::register_class_reference< MyThirdClassOriginal,  MyThirdClassReflectionReferenceConst   >( observe, xml_context );
    //xml_type::register_class_reference< MyThirdClassOriginal,  MyThirdClassReflectionReferenceMutable >(observe, xml_context );
    //xml_type::register_class_pointer< MyThirdClassOriginal,    MyThirdClassReflectionPointerConst     >( observe, xml_context );
    //xml_type::register_class_pointer< MyThirdClassOriginal,    MyThirdClassReflectionPointerMutable   >(observe, xml_context );

    xml_type::register_enum<MyMainClass::Enumerator>( observe, xml_context ); 
     xml_type::register_container< std::vector<int> >( observe, xml_context );
     xml_type::register_container< std::map<int,std::string> >( observe, xml_context );
     xml_type::register_map< int,int >( observe, xml_context );
     xml_type::register_complex< float >( observe, xml_context );

     MyThirdClassOriginal original;
     MyThirdClassReflectionReferenceConst     rc( original );
     MyThirdClassReflectionReferenceMutable   rm( original );

  }
  observe.view( ofs, r ); // XMLize
  observe.clear();
 

  { cpp_type cpp( observe );
                  observe.register_class_inherit<MyFirstClassOriginal, MyFirstClassReflectionInherit>( );
                  //observe.register_class_pointer<MyBaseClass,          MyBaseClasssReflectionPointer>( );
                  //observe.register_class_reference<MyBaseClass,       MyBaseClasssReflectionReference>( );
  }
  observe.view( ofs, r ); // CPPize for example


  observe.clear();
  { yaml_type yaml( observe );
                    observe.register_class_inherit<MyFirstClassOriginal, MyFirstClassReflectionInherit>();
                    observe.register_class<MyBaseClass, MyBaseClasssReflectionPointer>();
  }
  observe.view( ofs, r ); // YAMLize

  observe.clear();
  { protobuf_type protobuf( observe ); 
                            observe.register_class_inherit<MyFirstClassOriginal, MyFirstClassReflectionInherit>();
                            observe.register_class<MyBaseClass, MyBaseClasssReflectionPointer>();
  }
  observe.view( ofs, r ); // Protobufferize

  observe.clear();
  { ini_type ini( observe );  
                  observe.register_class_inherit<MyFirstClassOriginal, MyFirstClassReflectionInherit>();
                  observe.register_class<MyBaseClass, MyBaseClasssReflectionPointer>();
  }
  observe.view( ofs, r );  // INIrize
  
  ofs << "--------- simple iteration" << std::endl;
  for( auto & v: r )  //! Iterate over the members
   {
    typedef ::reflection::content::pure_class<std::string> content_type;
    ofs << dynamic_cast<content_type const&>( *v.second ).identifier() << "  ";
    ofs << v.first  <<";";
    ofs << std::endl;
   }

  // TODO int i;
  // TODO ::reflection::execute< int, int, std::string const& >( r.get("free_int_int_string"), i, "aaa" );

  return EXIT_SUCCESS;
 }

