#include <iostream>
#include <vector>


using namespace std;


class Vertex
{
	private :
		float x,y,z;
	public  :
		Vertex(float x1, float y1, float z1)
		{
			x = x1;
			y = y1;
			z = z1;
		}
		Vertex()
		{
		}

};

class Edge
{
	private:
		Vertex vi,vf;
	public:
		Edge(Vertex v1, Vertex v2)
		{
			vi = v1;
			vf = v2;
		}
};

class Face
{
	private:
		vector <Edge> aristas;
	public:
		Face(vector<Edge> fars)
		{
			aristas = fars;
		}

};



int main()
{
	Vertex v1 = Vertex(0.0,0.0,0.0);
	Vertex v2 = Vertex(0.0,0.0,1.0);
	Vertex v3 = Vertex(0.0,1.0,0.0);
	Vertex v4 = Vertex(0.0,1.0,1.0);
	Vertex v5 = Vertex(1.0,0.0,0.0);
	Vertex v6 = Vertex(1.0,0.0,1.0);
	Vertex v7 = Vertex(1.0,1.0,0.0);
	Vertex v8 = Vertex(1.0,1.0,1.0);
	
	
	Edge e1 = Edge(v1,v2);
	Edge e2 = Edge(v2,v3);
	Edge e3 = Edge(v3,v4);
	Edge e4 = Edge(v4,v1);
	Edge e5 = Edge(v4,v1);
	Edge e6 = Edge(v4,v1);
	Edge e7 = Edge(v4,v1);
	Edge e8 = Edge(v4,v1);
	Edge e9 = Edge(v4,v1);
	Edge e10 = Edge(v4,v1);
	Edge e11 = Edge(v4,v1);
	Edge e12 = Edge(v4,v1);

	

	/*
	vector <float> flist;
	flist.push_back(1.0);
	flist.push_back(2.0);
	flist.push_back(3.0);

	for(int i= 0;i<flist.size(); i++)
	cout << flist[i] << endl;
	*/
	
	vector <Edge> edge_list;
	edge_list.push_back(e1);
	edge_list.push_back(e2);
	edge_list.push_back(e3);
	edge_list.push_back(e4);
	
	Face f1 = Face(edge_list);

}
