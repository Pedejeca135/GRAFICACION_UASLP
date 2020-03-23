CXX = g++
CXXFLAGS = -I./
LDFLAGS = -l glfw -l GLEW -l GL -l GLU -l armadillo


cppsrc = $(wildcard ./*.cpp) \
        $(wildcard ./common/*.cpp)
obj = $(cppsrc:.cpp=.o)

main: $(obj)
		${CXX} $^ -o $@ ${LDFLAGS} 

all: main

main: main.o Plotter.o
	g++ main.o Plotter.o -o main -framework GLUT -framework OpenGL -w

main.o: main.cpp
	g++ -c main.cpp -w

xWing.o: xWing.cpp
	g++ -c xWing.cpp -w

objects.o: objects.cpp
	g++ -c objects.cpp -w

timer.o: utils/timer.cpp
	g++ -c utils/timer.cpp -w

drawing.o: utils/drawing.cpp
	g++ -c utils/drawing.cpp

curves.o: utils/curves.cpp
	g++ -c utils/curves.cpp

transformations.o: utils/transformations.cpp
	g++ -c utils/transformations.cpp -w

heightMap.o: map/heightMap.cpp
	g++ -c map/heightMap.cpp -w

terrainMesh.o: map/terrainMesh.cpp
	g++ -c map/terrainMesh.cpp -w
