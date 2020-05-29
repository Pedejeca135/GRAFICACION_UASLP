#pragma once
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <armadillo>

using namespace std;

class Vertex
{
	// atributos
	double x, y, z;
	int indice;

public:
	Vertex() : x(0), y(0), z(0) {}
	Vertex(double X, double Y, double Z, int indi) : x(X), y(Y), z(Z), indice(indi) {}
	// métodos
	string print();
	int getIndice();
	double getX();
	double getY();
	double getZ();
	arma::dcolvec h();
	void set_value(arma::drowvec ver);
};


class Edge
{
	// atributos
	Vertex vi, vf;

public:
	Edge(Vertex Vi, Vertex Vf) : vi(Vi), vf(Vf) {}
	// métodos
	string print();
};


class Face
{
	// atributos
	std::vector<Edge> edgs;
	std::vector<Vertex> verts;
public:
	Face(std::vector<Vertex> vert, std::vector<Edge> edg) : verts(vert), edgs(edg) {}
	// métodos
	void print();
	Vertex getVert(int indice);
};


int Vertex::getIndice() {
	return indice;
}

double Vertex::getX() {
	return x;
}

double Vertex::getY() {
	return y;
}

double Vertex::getZ() {
	return z;
}



string Vertex::print() {
	std::ostringstream stm, stm2, stm3;
	stm << x;
	stm2 << y;
	stm3 << z;
	return stm.str() + "  " + stm2.str() + "  " + stm3.str();
}



string Edge::print() {
	std::ostringstream stm, stm2, stm3;
	stm << vi.getIndice();
	stm2 << vf.getIndice();
	return stm.str() + "  " + stm2.str() + "  ";
}

void Face::print() {
	for (int i = 0;i < verts.size();i++) {
		cout << verts[i].getIndice() << "  ";
	}
}

Vertex Face::getVert(int indice) {
	return verts[indice];
}


arma::dcolvec Vertex::h() {
	arma::dcolvec p = { {x},{y},{z},{1.0} };
	return p;
}

void Vertex::set_value(arma::drowvec ver)
{
	x = ver[0];
	y = ver[1];
	z = ver[2];
}