#pragma once
#include <iostream>
#include "Components.h"
using namespace std;
class Object
{
	// atributos
	vector<Vertex> v;
	vector<Edge> e;
	vector<Face> f;
	string name;
	string archivo;

public:
	Object(string n, string a, vector<Vertex> ver, vector<Edge> ed, vector<Face> fac) : name(n), archivo(a), v(ver), e(ed), f(fac) {}
	// m�todos
	void print();
	int getSizevectorface();
	Face getFace(int num);
};

void Object::print() 
{

	cout << archivo << "\n";
	cout << name << "\n";
	for (int i = 0;i < v.size();i++) {
		cout << "v" << i + 1 << "\t" << v[i].print() << endl;
	}

	cout << "\n";

	for (int i = 0;i < e.size();i++) {
		cout << "e" << i + 1 << "\t" << e[i].print() << endl;
	}

	for (int i = 0;i < f.size();i++) {
		cout << "\n" << "f" << "\t";
		f[i].print();
	}
	cout << "\n";
}

int Object::getSizevectorface() 
{
	return f.size();
}

Face Object::getFace(int num)
{
	return f[num];
}