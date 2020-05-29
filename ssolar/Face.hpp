#ifndef FACE_H
#define FACE_H

#include <Edge.hpp>


class Face {

	public:
		int NumFace = 0;
        std :: vector<int> verticesIndex;// index of vertices of the face.
		std :: vector<Edge> AristasVerticesIndexed = std :: vector<Edge>();
		std :: vector<Edge> AristasVerticesDirect;
		//std::vector<Edge> vectorEdges = vector<Edge>() ;

        Face();
		
        Face(std::vector<int> _verticesIndex);
        Face(Face *other);
		Face(vector <Edge> fars,int NF);

		void edgeVectorDirect(std::vector<Edge> &llega);
		void Add(int i);    //for adding a new index.

		void AddAristasVerticesIndexed(int initial, int final );
		void AddAristasVerticesDirect(Vertex initial, Vertex final);

		
		std::string toString();
        void print();
};

#endif