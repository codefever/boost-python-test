#include <boost/python.hpp>
#include <string>

int foo(int a, char b = 1, unsigned c = 2, double d = 3)
{
    return a;
}

struct george
{
    george(int a, char b = 'D', std::string c = "constructor", double d = 0.0)
    {
    }

    void wack_em(int a, int b = 0, char c = 'x')
    {
    }
};

BOOST_PYTHON_FUNCTION_OVERLOADS(foo_overloads, foo, 1, 4)
BOOST_PYTHON_MEMBER_FUNCTION_OVERLOADS(george_overloads, wack_em, 1, 3)

BOOST_PYTHON_MODULE(func)
{
    using namespace boost::python;

    def("foo", foo, foo_overloads());

    class_<george>("george", no_init)
        .def(init<int, optional<char, std::string, double> >())
        .def("wack_em", &george::wack_em, george_overloads())
    ;
}

