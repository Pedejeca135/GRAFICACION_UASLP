//#ifndef OBJECT_H
//#define OBJECT_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

class Vertex {
	public:
		float x;
		float y;
		float z;

        Vertex();
		Vertex(float _x, float _y, float _z);		
		Vertex(Vertex *other);
		std :: string toString();
        void print();
};

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
};

class Face {

	public:

        std :: vector<int> verticesIndex;// index of vertices of the face.
		std :: vector<Edge> AristasVerticesIndexed = std :: vector<Edge>();
		//std::vector<Edge> vectorEdges = vector<Edge>() ;

        Face();
		
        Face(std::vector<int> _verticesIndex);
        Face(Face *other);

		void edgeVectorDirect(std::vector<Edge> &llega);
		void Add(int i);    //for adding a new index.
		void AddAristasVerticesIndexed(int initial, int final );
		std::string toString();
        void print();
};


class Object {
	public:
		std::string name;			    // Name of the object.
		std::vector<Vertex> vertices;	// List of vertices.
		std::vector<Face> faces;		// List of faces.

		Object();
		Object(std::string _name);
		Object(Object *other);

		void AddVertex(Vertex v);
		void AddFace(Face f);      
		std :: string toString();
        void print();

		bool Validacion();
		float Object :: edgeDistancia(Edge edge);
		float Object :: facePerimetro(Face face);
		
};

std::vector<Object> readObjFile(std::string path);
std::vector<std::string> split (std::string str, std::string delimeter, int start);

//#endif