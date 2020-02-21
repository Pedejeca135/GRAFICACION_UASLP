#include <obj.hpp> 
#include <iostream>
#include <vector>


using namespace std;

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

	vector <Face> paraCubo;	
	paraCubo.push_back(fB);
	paraCubo.push_back(fT);
	paraCubo.push_back(f1);
	paraCubo.push_back(f2);
	paraCubo.push_back(f3);
	paraCubo.push_back(f4);

	Figure cubo1 = Figure(paraCubo,"CUBO");

	/********************************************************************************************************************************************
	*
	*||||||||||||||||||||||||||||||||||||||||||||||||||||    PIRAMIDE    |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||
	*
	**********************************************************************************************************************************************/	


	Vertex vp1 = Vertex(0.0,0.0,0.0);
	Vertex vp2 = Vertex(1.0,0.0,0.0);
	Vertex vp3 = Vertex(1.0,0.0,1.0);
	Vertex vp4 = Vertex(0.0,0.0,1.0);
	Vertex vp5 = Vertex(0.5,1.0,0.5);
	
	//base:
	Edge ep1 = Edge(vp1,vp2);
	Edge ep2 = Edge(vp2,vp3);
	Edge ep3 = Edge(vp3,vp4);
	Edge ep4 = Edge(vp4,vp1);
	
	//others
	Edge ep5 = Edge(vp1,vp5);
	Edge ep6 = Edge(vp2,vp5);
	Edge ep7 = Edge(vp3,vp5);
	Edge ep8 = Edge(vp4,vp5);

	//base:
	vector <Edge> baseP;
	baseP.push_back(ep1);
	baseP.push_back(ep2);
	baseP.push_back(ep3);
	baseP.push_back(ep4);

	Face fpB = Face(baseP);


	//cara1:
	vector <Edge> caraP1;
	caraP1.push_back(ep3);
	caraP1.push_back(ep7);
	caraP1.push_back(ep8);

	Face fp1 = Face(caraP1);

	//cara2:
	vector <Edge> caraP2;
	caraP2.push_back(ep7);
	caraP2.push_back(ep2);
	caraP2.push_back(ep6);

	Face fp2 = Face(caraP2);

	//cara3:
	vector <Edge> caraP3;
	caraP3.push_back(ep6);
	caraP3.push_back(ep1);
	caraP3.push_back(ep5);

	Face fp3 = Face(caraP3);

	//cara4:
	vector <Edge> caraP4;
	caraP4.push_back(ep5);
	caraP4.push_back(ep4);
	caraP4.push_back(ep8);

	Face fp4 = Face(caraP4);

	vector <Face> paraPiramide;	
	paraCubo.push_back(fpB);
	paraCubo.push_back(fp1);
	paraCubo.push_back(fp2);
	paraCubo.push_back(fp3);
	paraCubo.push_back(fp4);

	Figure piramide1 = Figure(paraPiramide,"PIRAMIDE");

	cubo1.toString();
	cout<< "y ahora"<< endl;
	piramide1.toString();
}
