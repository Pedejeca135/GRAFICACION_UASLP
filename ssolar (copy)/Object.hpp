#ifndef OBJECT_H
#define OBJECT_H

#include <Face.hpp>

#include <fstream>

class Object {
	public:
		std::string name;			    // Name of the object.
		std::vector<Vertex> vertices;	// List of vertices.
		std::vector<Face> faces;		// List of faces.

		Object();
		Object(std::string _name);
		Object(Object * other);

		void AddVertex(Vertex v);
		void AddFace(Face f);      
		std :: string toString();
        void print();

		bool Validacion();
		float edgeDistancia(Edge edge);
		float facePerimetro(Face face);
		void init(std::string path);
		std::vector< Vertex > get_faces_verts();
		
		
};

Object read_1_ObjFile(std::string path);
std::vector<Object> readObjFile(std::string path);
std::vector<std::string> split (std::string str, std::string delimeter, int start);

#endif