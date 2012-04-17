files := $(wildcard *.cpp)
objs := $(files:.cpp=.so)

all:	$(objs)
$(objs):%.so:	%.cpp
	g++ $^ -shared -fPIC -lboost_python -I/usr/include/python2.7 -o $@
clean:
	rm -rf *.so
.PHONY:	all clean
