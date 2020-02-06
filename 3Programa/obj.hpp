#include <iostream>
#include <vector>

using namespace std;

class Vertex
{
	private :
		float x,y,z;
	public  :
		Vertex(float x1, float y1, float z1);
		Vertex();
        void toString();
};

class Edge
{
	private:
		Vertex vi,vf;
	public:
		Edge(Vertex v1, Vertex v2);
        void toString();
};

class Face
{
	private:
		vector <Edge> aristas;
	public:
		Face(vector<Edge> fars);
		Face();
        void toString();
};

class Figure
{
	private:
	vector<Face> caras;
	public:
		Figure(vector<Face> faces);
		void toString();
};