#ifndef VERTEX_H
#define VERTEX_H

#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <iostream>
#include <math.h>
#include <sstream>
#include <armadillo>

using namespace std;



class Vertex {
	public:
		float x;
		float y;
		float z;

        Vertex();
		Vertex(float _x, float _y, float _z);		
		Vertex(Vertex *other);
		std::vector <float> getValues();
		std :: string toString();
        void print();
		arma::fcolvec getHomg();

};

#endif