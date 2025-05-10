#include <iostream>
#include <iomanip>
#include <string>
#include <functional>

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

class MyMainClass //!< Original condition. Not bloated with any other code.
 : public MyBaseClass
 {
  public:
    MyMainClass():m_int(123456){ }

    void                some_function( float const& f ){ m_int = (int)f;  }

    int const&  reader()const{ return m_int; }
    bool        writer( int const& a ){ m_int = a; return true; }

  private: // And private member
    int m_int;
 };

reflection__CLASS_BEGIN_pointer( MyBaseClasssReflectionView, public, MyBaseClass, MyBaseClass* )
   reflection__CLASS_MEMBER_exposed(   "number-float", MyBaseClass, traitor, writer )
reflection__CLASS_END_pointer( MyBaseClasssReflectionView, MyBaseClass );


// Reflect to reflection
reflection__CLASS_BEGIN_inherit( MyClassReflection, public, MyMainClass )

    reflection__CLASS_BASE_exposed(  "4base-something", MyMainClass, public, default, MyBaseClass );

    reflection__CLASS_MEMBER_guarded(   "integer",  MyMainClass, writer, reader  )

    reflection__CLASS_FUNCTION_member( "f10", MyMainClass, public, some_function )

reflection__CLASS_END_inherit( MyClassReflection, MyMainClass );


int main( int argc, char *argv[] )
 {
  std::cout << __FUNCTION__ << std::endl;
  // Some typedefs
  typedef ::reflection::operation::encode::observe_class<std::ostream> observe_type;
  typedef ::reflection::operation::transfer::xml::print_struct<std::ostream> xml_type;
  typedef ::reflection::operation::transfer::json::print_struct<std::ostream> json_type;
  typedef ::reflection::operation::transfer::cpp::print_struct<std::ostream> cpp_type;
  typedef ::reflection::operation::transfer::yaml::print_struct<std::ostream> yaml_type;
  typedef ::reflection::operation::transfer::protobuf::print_struct<std::ostream> protobuf_type;
  typedef ::reflection::operation::transfer::ini::print_struct<std::ostream> ini_type;

  MyClassReflection   r;  //!< Reflection of Original, with pointing to some instance

  observe_type observe; //!< Algorithm for observation AKA serialization

  { cpp_type cpp( observe ); //!< Fill observator how to serialize.
                    observe.register_class<MyBaseClass, MyBaseClasssReflectionView>( );
  }
  observe.view( std::cout, r ); // CPPize for example

  observe.clear();
  { xml_type xml( observe );//!< Fill observator how to serialize.
                  observe.register_class<MyBaseClass, MyBaseClasssReflectionView>( );
  }
  observe.view( std::cout, r ); // XMLize

  observe.clear();
  { json_type json( observe );//!< Fill observator how to serialize.
                    observe.register_class<MyBaseClass, MyBaseClasssReflectionView>( );
  }
  observe.view( std::cout, r ); // JSONize

  observe.clear();
  { yaml_type yaml( observe );//!< Fill observator how to serialize.
                    observe.register_class<MyBaseClass, MyBaseClasssReflectionView>( );
  }
  observe.view( std::cout, r ); // YAMLize

  observe.clear();
  { protobuf_type protobuf( observe );//!< Fill observator how to serialize.
                            observe.register_class<MyBaseClass, MyBaseClasssReflectionView>( );
  }
  observe.view( std::cout, r ); // Protobufferize

  observe.clear();
  { ini_type ini( observe );//!< Fill observator how to serialize.
                  observe.register_class<MyBaseClass, MyBaseClasssReflectionView>( );
  }
  observe.view( std::cout, r );  // INIrize

  return EXIT_SUCCESS;
 }

