#include <LectorOBJ.hpp> 
#include <iostream>
#include <vector>


using namespace std;

int main()
{
	Lector lector = Lector();
	lector.leeArchivo("./chinese_coin.obj");
	cout<<"main acaba"<<endl;
}
