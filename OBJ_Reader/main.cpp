#include <Object.hpp> 
#include <iostream>
#include <vector>


using namespace std;

int main()
{
	std::vector<Object> firstFile = readObjFile("../Models/tareaUno.obj");
	//cout<<"despuesde leerlo"<<endl;
	for(int i = 0 ; i<firstFile.size();i++)
	{
		firstFile[i].print();
	}
}
