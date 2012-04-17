#include <boost/python.hpp>
#include <iostream>
#include <string>

using namespace std;

struct Base {

    virtual ~Base() {}

    virtual const char* whoami()
    {
        return "base";
    }
};

struct Derived : public Base {

#if 0
    virtual const char* whoami()
    {
        return "derived";
    }
#endif

};

void b(Base* o)
{
    cout << "b: " << o->whoami() << endl;
}

void d(Derived* o)
{
    cout << "d: " << o->whoami() << endl;
}

Base* factory()
{
    return new Derived;
}

BOOST_PYTHON_MODULE(inherit)
{
    using namespace boost::python;

    class_<Base>("Base")
        .def("whoami", &Base::whoami)
    ;

    class_<Derived, bases<Base> >("Derived")
        /* sth */
    ;

    def("b", b);
    def("d", d);
    def("factory", factory,
            return_value_policy<manage_new_object>());
}

