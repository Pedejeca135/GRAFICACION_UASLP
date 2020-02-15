#include <Object.hpp> 
#include <iostream>
#include <vector>


using namespace std;

int main()
{
	std::vector<Object> firstFile = readObjFile("../modelos/tareaUno.obj");
	firstFile[0].print();
}
