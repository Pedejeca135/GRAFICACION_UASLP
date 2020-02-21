#include <iostream>

using namespace std;

class Vertex{
	private:
		float x,y,z;
	public:
		Vertex(float x1, float y1, float z1)
		{
			x = x1;
			y = y1;
			z = z1;

		}
};

int main ()
{
	Vertex v1 = Vertex(0.0 , 0.0 , 1.0);
}
