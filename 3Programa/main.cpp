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
	
	//base:
	Edge e1 = Edge(v1,v2);
	Edge e2 = Edge(v2,v6);
	Edge e3 = Edge(v6,v5);
	Edge e4 = Edge(v5,v1);

	//techo:
	Edge e5 = Edge(v3,v4);
	Edge e6 = Edge(v4,v8);
	Edge e7 = Edge(v8,v7);
	Edge e8 = Edge(v7,v3);

	//columnas:
	Edge e9  = Edge(v8,v6);	
	Edge e10 = Edge(v7,v5);
	Edge e11 = Edge(v3,v1);
	Edge e12 = Edge(v4,v2);

	

	/*
	vector <float> flist;
	flist.push_back(1.0);
	flist.push_back(2.0);
	flist.push_back(3.0);

	for(int i= 0;i<flist.size(); i++)
	cout << flist[i] << endl;
	*/
	
	//base:
	vector <Edge> base;
	base.push_back(e1);
	base.push_back(e2);
	base.push_back(e3);
	base.push_back(e4);

	Face fB = Face(base);


	//techo:
	vector <Edge> techo;
	techo.push_back(e5);
	techo.push_back(e6);
	techo.push_back(e7);
	techo.push_back(e8);

	Face fT = Face(techo);

	//cara1:
	vector <Edge> cara1;
	cara1.push_back(e2);
	cara1.push_back(e9);
	cara1.push_back(e6);
	cara1.push_back(e12);

	Face f1 = Face(cara1);

	//cara2:
	vector <Edge> cara2;
	cara2.push_back(e9);
	cara2.push_back(e3);
	cara2.push_back(e10);
	cara2.push_back(e7);

	Face f2 = Face(cara2);

	//cara3:
	vector <Edge> cara3;
	cara3.push_back(e4);
	cara3.push_back(e10);
	cara3.push_back(e8);
	cara3.push_back(e11);

	Face f3 = Face(cara3);
	
	//cara4:

	vector <Edge> cara4;
	cara4.push_back(e1);
	cara4.push_back(e11);
	cara4.push_back(e5);
	cara4.push_back(e12);

	Face f4 = Face(cara4);
	

}
