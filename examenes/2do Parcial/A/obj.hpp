#include <iostream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

class Vertex
{
	//private :
		//float x,y,z;
	public  :
	float x,y,z;
		Vertex(float x1, float y1, float z1);
		Vertex();
		float distancia(Vertex other);
        string toString();
};

class Edge
{
	private:
		Vertex vi,vf;
	public:
		Edge(Vertex v1, Vertex v2);
        string toString();
};

class Face
{
	private:
		vector <Edge> aristas;
	public:
		Face(vector<Edge> fars);
		Face();
        string toString();
};

class Figure
{
	private:
	vector<Face> caras;
    char *nombre;
	public:
		Figure(vector<Face> faces, char *figuraNombre);
		Figure();

		string toString();
};