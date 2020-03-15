#ifndef FACE_H
#define FACE_H

#include <Edge.hpp>


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

#endif