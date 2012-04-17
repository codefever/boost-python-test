#include <boost/python.hpp>
#include <string>

struct Bye
{
};

struct World
{
    World(std::string msg)
        : msg(msg)
    {}

    void set(std::string msg)
    {
        this->msg = msg;
    }
    
    std::string greet()
    {
        return msg;
    }

    std::string msg;
};

BOOST_PYTHON_MODULE(world)
{
    using namespace boost::python;

    class_<World>("World", init<std::string>())
        .def("greet", &World::greet)
        .def("set", &World::set)
    ;

    class_<Bye>("Bye", no_init);
}
