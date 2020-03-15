#include <Face.hpp>

/*****************************************************************
 * 
 * ||||||||||||||||||  Constructors of Face ||||||||||||||||||||
 * 
 * ***************************************************************/

Face::Face(){

}

Face::Face(vector<int> _vertexIndex){
    verticesIndex = _vertexIndex;    
}

Face::Face(Face *other){
    verticesIndex = other -> verticesIndex;
}

//methods of Face.
void Face::Add(int i){
	verticesIndex.push_back(i);
}
void Face :: AddAristasVerticesIndexed( int initial, int final)
{   
    Edge e = Edge(initial,final);
    AristasVerticesIndexed.push_back(e); 
}

void Face :: edgeVectorDirect(vector<Edge> &llega)
{
    AristasVerticesIndexed = llega;
}

/*
string Face :: toString(){

    std :: ostringstream res;

    res << "Face: ";
    //cout<<"verticesIndex.size(): " <<verticesIndex.size() <<endl;
	for(int i = 0; i < verticesIndex.size(); i++)
	res<<verticesIndex[i]<<", ";

    cout<<"AristasVerticesIndexed.size()" <<verticesIndex.size() <<endl;
    for(int j = 0 ; AristasVerticesIndexed.size();j++)
    res<<AristasVerticesIndexed[j].toString();
    
    return res.str();
}
*/

void Face :: print(){
  
    cout<<endl << "Face: ";
   for(int i = 0; i < verticesIndex.size(); i++)
	cout<<verticesIndex[i]<<", ";

    cout<<endl;

    for(int j = 0 ; j< AristasVerticesIndexed.size();j++)
        AristasVerticesIndexed[j].print();
}
