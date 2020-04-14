#ifndef EDGE_H
#define EDGE_H

#include <Vertex.hpp>

/*
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
*/

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