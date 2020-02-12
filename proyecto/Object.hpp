//#ifndef OBJECT_H
//#define OBJECT_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Vertex {
	public:
		float x;
		float y;
		float z;

        Vertex();
		Vertex(float _x, float _y, float _z);		
		Vertex(Vertex *other);

		String toString();
        void print();
};

class Face {
	public:

        std :: vector<int> verticesIndex;// index of vertices of the face.

        Face();
        Face(Vector<int> _verticesIndex);
        Face(Face *other);

		void Add(int i);    //for adding a new index.
		String toString();
        void print();
};

class Object {
	public:
		std::string name;			    // Name of the object.
		std::vector<Vertex> vertices;	// List of vertices.
		std::vector<Face> faces;		// List of faces.

		Object(std::string _name);
		Object(Object *other);

		void AddVertex(Vertex v);
		void AddFace(Face f);      
		String toString();
        void print();
};

std::vector<Object> readObjFile(std::string path);

//#endif
