#include <boost/python.hpp>
#include <string>

struct Num {
    Num() :v() {}

    float get() const
    {
        return v;
    }

    void set(float v)
    {
        this->v = v;
    }

    float v;
};

BOOST_PYTHON_MODULE(num)
{
    using namespace boost::python;

    class_<Num>("Num")
        .add_property("rovalue", &Num::get)
        .add_property("value", &Num::get, &Num::set);
}

