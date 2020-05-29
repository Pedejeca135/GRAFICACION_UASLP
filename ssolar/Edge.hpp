#ifndef EDGE_H
#define EDGE_H

#include <Vertex.hpp>

class Edge
{
	public:
		Vertex vi,vf;
		int viI,viF;
		bool activatedVertex;
	public:
		Edge();
		Edge(int _viI, int _viF);
		Edge(bool activate);
		Edge(Vertex _vi, Vertex _vf);
        std :: string toString();
		void print();
        float longitud();



};

#endif