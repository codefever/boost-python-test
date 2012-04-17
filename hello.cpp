#include <boost/python.hpp>

char const *greet()
{
    return "hello world";
}

BOOST_PYTHON_MODULE(hello)
{
    namespace bpy = boost::python;
    bpy::def("greet", greet);
}

