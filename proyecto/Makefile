CXX = g++
CXXFLAGS = -I./
LDFLAGS = -l glfw -l GLEW -l GL -l GLU -l armadillo


cppsrc = $(wildcard ./*.cpp) \
        $(wildcard ./common/*.cpp)
obj = $(cppsrc:.cpp=.o)

main: $(obj)
		${CXX} $^ -o $@ ${LDFLAGS} 

