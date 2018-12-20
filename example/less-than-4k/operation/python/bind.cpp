#include <iostream>
#include <iomanip>
#include <string>
#include <functional>

// By including this before reflection.hpp you will enable python bind support

#ifdef _WIN32
#ifdef _DEBUG
#undef _DEBUG
#include <Python.h>
#define _DEBUG
#else
#include <Python.h>
#endif
#endif

#ifdef __GNUC__
#include <python2.7\Python.h>
#endif

#include "reflection/reflection.hpp"

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

class MyFoundationClass //!< Original condition. Not bloated with any other code.
 {
  public:
    MyFoundationClass():m_float(98765){ }
    virtual ~MyFoundationClass(){ }

    void a(){ }
    float      &  traitor(){ return m_float; }
    float const&  reader()const{ return m_float; }
    bool          writer( float const& a ){ m_float = a; return true; }

  private: // And private member
    float m_float;
 };

class MyFirstClassOriginal //!< Original condition. Not bloated with any other code.
 : public MyBaseClass
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

class MyMainClass //!< Original condition. Not bloated with any other code.
 : public MyBaseClass 
 , public MyFoundationClass
 {
  public:
    enum Enumerator{ enum1, enum2, enum10=10, enum11=150 };
    typedef std::array<float,2> MyTypDef;
    typedef std::vector<int> MyVectorType;
    typedef std::set<int>              MySetType;
    typedef std::list<int>             MyListType;
    typedef std::map<int, std::string> MyMapType;

    MyMainClass():m_int(123456)
    {
     m_vector.resize(3,456);
     m_set.insert(456); m_set.insert(1456);
     m_list.push_back(12456); m_list.push_back(987);
     m_map[1]="q"; m_map[3]="f"; m_map[4]="d";
    }

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

    static int   some_static_function( float const&f ){ return 12; }
    static int   another_static_function( double const&f ){ return 12; }

    Enumerator const&  enum_read()const{ return m_enum; }
    bool               enum_write( Enumerator const& a ){ m_enum = a; return true; }

    MyVectorType const&  vector_reader()const{ return m_vector; }
    MyVectorType      &  vector_traitor(){ return m_vector; }

    MySetType const&  set_reader()const{ return m_set; }
    MySetType      &  set_traitor()    { return m_set; }

    MyListType const&  list_reader()const{ return m_list; }
    MyListType      &  list_traitor()    { return m_list; }

    MyMapType const&  map_reader()const{ return m_map; }
    MyMapType      &  map_traitor()    { return m_map; }

  public:
   double m_public = 456;
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
    MyVectorType  m_vector;
    MySetType     m_set;
    MyListType    m_list;
    MyMapType     m_map;
 };

std::string MyMainClass::m_static="blahblahfoofoo";

reflection__IDSPEC( std::string, "MyBaseClass", MyBaseClass );

reflection__CLASS_BEGIN_view( MyBaseClassReflectionView, public, MyBaseClass, MyBaseClass* )
   reflection__CLASS_MEMBER_exposed(   "number-float", MyBaseClass, traitor, writer )
reflection__CLASS_END_view( MyBaseClassReflectionView, MyBaseClass );


reflection__IDSPEC( std::string, "MyFoundationClass", MyFoundationClass );

reflection__CLASS_BEGIN_view( MyFoundationClassReflectionView, public, MyFoundationClass, MyFoundationClass* )
   reflection__CLASS_MEMBER_exposed(   "number-float", MyFoundationClass, traitor, writer )
reflection__CLASS_END_view( MyFoundationClassReflectionView, MyFoundationClass );


reflection__IDSPEC( std::string, "MyFirstClassOriginal", MyFirstClassOriginal );

reflection__CLASS_BEGIN_view( MyFirstClassReflectionView, public, MyFirstClassOriginal, MyFirstClassOriginal* )

   reflection__CLASS_BASE_direct(  "1base-something", MyFirstClassOriginal, public, default, MyBaseClass );
   reflection__CLASS_MEMBER_exposed(   "number", MyFirstClassOriginal, traitor, writer )

reflection__CLASS_END_view( MyFirstClassReflectionView, MyFirstClassOriginal );


reflection__IDSPEC( std::string, "MyMainClass", MyMainClass);
// Reflect to reflection
//template< typename someType_name >     // Yeah template.
reflection__CLASS_BEGIN_inherit( MyClassReflection, public, MyMainClass )

    reflection__CLASS_friend(  "friend-class", MyMainClass, MyBaseClass );

    reflection__CLASS_BASE_direct(  "foundation-something", MyMainClass, protected, virtual, MyFoundationClass );

    reflection__CLASS_BASE_direct(  "1base-something", MyMainClass, public, virtual, MyBaseClass );
    reflection__CLASS_BASE_inspect( "2base-something", MyMainClass, public, default, MyBaseClass );
    reflection__CLASS_BASE_mutate(  "3base-something", MyMainClass, public, default, MyBaseClass );

    reflection__CLASS_BASE_exposed(  "4base-something", MyMainClass, public, default, MyBaseClass );
    reflection__CLASS_BASE_variable( "5base-something", MyMainClass, public, default, MyBaseClass );
    reflection__CLASS_BASE_guarded(  "6base-something", MyMainClass, public, default, MyBaseClass );

    reflection__CLASS_BASE_trinity(  "7base-something", MyMainClass, public, default, MyBaseClass );

  reflection__CLASS_TYPEDEF_member( "typedef-of-something", MyMainClass, public, MyTypDef );
  reflection__CLASS_TYPEDEF_member( "typedef-of-vector", MyMainClass, public, MyVectorType );
  reflection__CLASS_TYPEDEF_member( "typedef-of-set", MyMainClass, public, MySetType );
  reflection__CLASS_TYPEDEF_member( "typedef-of-list", MyMainClass, public, MyListType );
  reflection__CLASS_TYPEDEF_member( "typedef-of-map", MyMainClass, public, MyMapType );

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
  reflection__CLASS_FUNCTION_static( "my_other_static", MyMainClass, public, another_static_function )

   reflection__CLASS_MEMBER_variable(  "0subsider-traitor", MyMainClass, subsider_traitor, subsider_reader )
   reflection__CLASS_MEMBER_variable(  "my-vector", MyMainClass, vector_traitor, vector_reader )
   reflection__CLASS_MEMBER_variable(  "my-set",    MyMainClass,    set_traitor,    set_reader )
   reflection__CLASS_MEMBER_variable(  "my-list",   MyMainClass, list_traitor,     list_reader )
   reflection__CLASS_MEMBER_variable(  "my-map",    MyMainClass,    map_traitor,    map_reader )

  reflection__CLASS_FIELD_direct(  "some-field-doubleD", MyMainClass, public, m_public )
  reflection__CLASS_FIELD_direct(  "some-const-field-doubleD", MyMainClass, public, m_const_public )
  reflection__CLASS_FIELD_direct(  "some-const-volatile-field-doubleD", MyMainClass, public, m_volatile_const_public )
  reflection__CLASS_FIELD_direct(  "some-volatile-field-doubleD", MyMainClass, public, m_volatile_public )


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

#define MODULE_NAME_SYMBOLIC Spam
#define MODULE_NAME_STRING   "Spam"


#if 2 == PY_MAJOR_VERSION
#define INIT_FUNCTION(module_name) init##module_name
#endif
#if 3 == PY_MAJOR_VERSION
#define INIT_FUNCTION(module_name) PyInit_##module_name
#endif


typedef ::reflection::operation::transfer::python::bind::process_struct<> bind_type;

typedef bind_type::output_type output_type;

void populate( output_type & output )
 {
  MyClassReflection               r0;
  MyFirstClassReflectionView      r2;
  MyFoundationClassReflectionView rf;
  MyBaseClassReflectionView       r1;
  {
   ::reflection::operation::transfer::observe_class<bind_type::output_type> observe;
   {
    auto bind_context = bind_type::context();
    bind_type bind( observe, bind_context );
   }
   //Generate list
   observe.view( output, r0 );
   observe.view( output, r2 );
   observe.view( output, r1 );
   observe.view( output, rf);
  }

  output.interface().methodDefA();
 }

#define MODULE_NAME   "Spam"
#define MODULE_DOC    "Spam module"

static output_type g_output;

#if 3 == PY_MAJOR_VERSION
static struct PyModuleDef g_PyModuleDef = {
  PyModuleDef_HEAD_INIT,
  MODULE_NAME,
  MODULE_DOC,
  -1,
  NULL,
};
#endif

#if 0 == PY_MAJOR_VERSION
#define int main( int argc, char *argv[] )
#endif

#if 2 == PY_MAJOR_VERSION
PyMODINIT_FUNC INIT_FUNCTION(Spam)(void)
#endif
#if 3 == PY_MAJOR_VERSION
PyMODINIT_FUNC INIT_FUNCTION(Spam)( void )
#endif
 {
  std::cout << "---" << std::endl;

  g_output.module_name( MODULE_NAME_STRING );

  populate( g_output );

 for( auto const& m : g_output.interface().methodDefA() )
  {
   if( NULL == m.ml_name)
    {
     continue;
    }
   std::cout << m.ml_name << std::endl;
  }

 for( auto const& d : g_output.interface().memberDefA() )
  {
   if(  nullptr == d.name )
    {
     continue;
    }
   std::cout << "   doc:" << d.doc    << std::endl;
   std::cout << " flags:" << d.flags  << std::endl;
   std::cout << "  name:" << d.name   << std::endl;
   std::cout << "offset:" << d.offset << std::endl;
   std::cout << "  type:" << d.type   << std::endl;
  }

  for( auto const& typeName: g_output.geneaology().all() )
   {
    std::cout << "" << typeName << ":" << std::endl;

    auto & theType = g_output.typeObject().find( typeName )->second;

    std::cout << "    I am left:" << std::endl;
    std::cout << "        " ;
    for( auto const& derived : g_output.geneaology().right( typeName) )
     {
      std::cout << derived.first << "-> ";
      auto & rightType = g_output.typeObject().find( derived.first )->second;
      switch( derived.second )
       {
        case( ::reflection::ornament::relation_class::base_index    ): std::cout << "base";      theType.subClass(    derived.first, &rightType ); break;
        case( ::reflection::ornament::relation_class::derived_index ): std::cout << "derived";   theType.superClass(  derived.first, &rightType ); break;
       }
      std::cout << ", ";
     } std::cout << std::endl;

    std::cout << "    I am right:" << std::endl;
    std::cout << "        " ;
    for( auto const& base : g_output.geneaology().left( typeName ) )
     {
      std::cout << base.first << " -> ";
      auto leftType = g_output.typeObject().find( base.first )->second;
      switch( base.second )
       {
        case( ::reflection::ornament::relation_class::base_index    ): std::cout << "base";    theType.superClass(   base.first, &leftType ); break;
        case( ::reflection::ornament::relation_class::derived_index ): std::cout << "derived"; theType.subClass(     base.first, &leftType ); break;
       }
      std::cout << ", ";
     } std::cout << std::endl;

   }

  for( auto const& item: g_output.typeObject() )
   {
    item.second.build_1st();
   }

  for( auto const& item: g_output.typeObject() )
   {
    item.second.build_2nd();
   }

#if 2 == PY_MAJOR_VERSION
  PyObject *module = Py_InitModule( MODULE_NAME_STRING, const_cast<PyMethodDef*>( g_output.interface().methodDefA().data() ) );
#endif

#if 3 == PY_MAJOR_VERSION
  g_PyModuleDef.m_methods = const_cast<PyMethodDef*>( g_output.interface().methodDefA().data() );
  PyObject *module = PyModule_Create( &g_PyModuleDef );
#endif

  
  if (module == NULL)
   {
    std::cout << "module is NULL" << std::endl;
#if 2 == PY_MAJOR_VERSION
    return;
#endif

#if 3 == PY_MAJOR_VERSION
    return  nullptr;
#endif
   }


  for( auto const& item: g_output.typeObject() )
   {
    PyTypeObject *object = const_cast<PyTypeObject *>( item.second.handle().getT() );
    auto readiness = PyType_Ready(object);
    if ( readiness < 0 ) 
     {
      continue;
     }
    Py_INCREF(object);
    if( 0 != PyModule_AddObject(module, item.first.data(), reinterpret_cast<PyObject *>( object ) ) )
     { 
       Py_DECREF(object);
     }
    std::cout << object->tp_name << std::endl;
   }

  for( auto const item: g_output.interface().constDefX() )
   {
    PyModule_AddIntConstant( module, item.m_name.data(), item.m_value );
    std::cout <<  item.m_name.data() << std::endl;
   }

#if 0 == PY_MAJOR_VERSION
  return EXIT_SUCCESS;
#endif


#if 2 == PY_MAJOR_VERSION
  return;
#endif

#if 3 == PY_MAJOR_VERSION
  return  module;
#endif
 }

#if defined( _WIN32 )  || defined ( _WIN64 )
#include <Windows.h>

BOOL APIENTRY DllMain( HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved )
{
  switch (ul_reason_for_call)
  {
  case DLL_PROCESS_ATTACH:
  case DLL_THREAD_ATTACH:
  case DLL_THREAD_DETACH:
  case DLL_PROCESS_DETACH:
    break;
  }
  return TRUE;
}
#endif
