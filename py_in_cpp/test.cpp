#include <boost/python.hpp>
#include <iostream>
using namespace boost::python;

object f(object x, object y)
{
    if (y == "foo")
        x.slice(3, 7) = "bar";
    else
        x.attr("items") += y(3,x);
    return x;
}

int main(int argc, const char *argv[])
{
    Py_Initialize();

    object main_module = import("__main__");
    object main_namespace = main_module.attr("__dict__");
    object ignored = exec("result = 5 ** 2", main_namespace);
    int five_squared = extract<int>(main_namespace["result"]);

    printf("%d\n", five_squared);
    return 0;
}
