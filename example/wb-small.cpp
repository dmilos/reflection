#include <iostream>
#include <iomanip>
#include <string>
#include <functional>
#include <sstream>
#include <fstream>
#include <chrono>

#include "reflection/reflection.hpp"


class MyBaseClass //!< Original condition. Not bloated with any other code.
{
public:
    MyBaseClass() :m_float(98765) { }

    void a() { }
    float& traitor() { return m_float; }
    float const& reader()const { return m_float; }
    bool          writer(float const& a) { m_float = a; return true; }

private: // And private member
    float m_float;
};

class MyMainClass //!< Original condition. Not bloated with any other code.
    : public MyBaseClass
{
public:
    MyMainClass() {  }
};

reflection__IDSPEC(std::string, "MyMainClass", MyMainClass)
reflection__IDSPEC(std::string, "MyBaseClass", MyBaseClass )

reflection__CLASS_BEGIN_pointer(MyBaseClasssReflectionPointer, public, MyBaseClass, MyBaseClass*)
    reflection__CLASS_MEMBER_inspect("number-float-inspect", MyBaseClass, reader)
    reflection__CLASS_MEMBER_exposed("number-float", MyBaseClass, traitor, writer)
    reflection__CLASS_END_pointer(MyBaseClasssReflectionPointer, MyBaseClass);

reflection__CLASS_BEGIN_reference(MyBaseClasssReflectionReference, public, MyBaseClass, MyBaseClass const&)
    // NOPE reflection__CLASS_MEMBER_exposed("number-float", MyBaseClass, traitor, writer)
    reflection__CLASS_MEMBER_inspect("some-member", MyBaseClass, reader)
reflection__CLASS_END_reference(MyBaseClasssReflectionReference, MyBaseClass);


// Reflect to reflection
//template< typename someType_name >     // Yeah template.


class MyClassReflection
    : public MyMainClass
    , public ::reflection::content::class_class<MyMainClass>
{
private:
    typedef ::reflection::content::class_class<MyMainClass> private_base_type;
public:
    typedef MyMainClass original_type;
    typedef MyMainClass* pointer_type;

public:
    explicit MyClassReflection(original_type const& original)
        :original_type(original) {

        this->init();
    }

    MyClassReflection()
    {
        this->init();
    }

private:
    void init()
    {

        reflection__CLASS_BASE_inspect("2base-something", MyMainClass, public, default, MyBaseClass);

        ::reflection::operation::reroute::set< MyMainClass* >(*this, this );
        return;
    }
};


int main(int argc, char* argv[])
{
    auto now = std::chrono::system_clock::now();
    auto now1 = std::chrono::steady_clock::now();
    auto now2 = std::chrono::high_resolution_clock::now();
    //auto now3 = std::chrono::utc_clock::now();

    auto hour = std::chrono::duration_cast<std::chrono::hours>(std::chrono::time_point_cast<std::chrono::hours>(now).time_since_epoch()) % 24;
    auto minute = std::chrono::duration_cast<std::chrono::minutes>(std::chrono::time_point_cast<std::chrono::minutes>(now).time_since_epoch()) % 60;
    auto seconds = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::time_point_cast<std::chrono::seconds>(now).time_since_epoch()) % 60;

    std::ofstream ofs(std::to_string(hour.count()) + "-" + std::to_string(minute.count()) + "-" + std::to_string(seconds.count()) + ".txt");

    std::cout << __FUNCTION__ << std::endl;
    // Some typedefs
    typedef ::reflection::operation::encode::observe_class<std::ostream> observe_type;

    typedef ::reflection::operation::transfer::cpp::print_struct<std::ostream> cpp_type;
    typedef ::reflection::operation::transfer::yaml::print_struct<std::ostream> yaml_type;
    typedef ::reflection::operation::transfer::protobuf::print_struct<std::ostream> protobuf_type;
    typedef ::reflection::operation::transfer::ini::print_struct<std::ostream> ini_type;

    MyBaseClass base;
    MyBaseClasssReflectionReference r_base(  base );
    MyBaseClasssReflectionPointer   ptr_base( &base );
    MyMainClass o;
    MyClassReflection   r;  //!< Reflection of Original, with pointing to some instance

    ::reflection::operation::encode::observe_class<std::ostream> observe; //!< Have algorithm for observation(serialize/...) of instance

    observe.clear();
    { cpp_type cpp(observe);
     observe.register_class_pointer<MyBaseClass, MyBaseClasssReflectionPointer>();
     //observe.register_class_reference<MyBaseClass, MyBaseClasssReflectionReference>();
    }
    observe.view(ofs, ptr_base ); // CPPize for example

    return EXIT_SUCCESS;
}

