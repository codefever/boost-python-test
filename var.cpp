#include <boost/python.hpp>
#include <string>

struct Var {
    Var(std::string name) :name(name), value() {}
    std::string const name;
    float value;
};

BOOST_PYTHON_MODULE(var)
{
    using namespace boost::python;

    class_<Var>("Var", init<std::string>())
        .def_readonly("name", &Var::name)
        .def_readwrite("value", &Var::value);
}

