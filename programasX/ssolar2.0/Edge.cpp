#include <Edge.hpp>

/*****************************************************************
 * 
 * ||||||||||||||||||  Constructors of Edge ||||||||||||||||||||
 * 
 * ***************************************************************/
Edge :: Edge()
{
    activatedVertex = false;
}
Edge ::Edge(int _viI, int _viF)
{
    viI = _viI;
    viF = _viF;
    activatedVertex = false;
}
Edge ::Edge(bool activate)
{
    activatedVertex = activate;
}
Edge ::Edge(Vertex _vi, Vertex _vf)
{
    activatedVertex = true;
}

/*
string Edge :: toString(){

    std :: ostringstream res;

    res << "Edge: ";
	res<<endl<<" indice vi :" << viI << endl << " indice vf :" << viF;
    return res.str();
}
*/


float Edge :: longitud()
{
    float res = 0;
    float X = vf.x  - vi.x;
    float Y = vf.y  - vi.y;
    float Z = vf.z  - vi.z;


    res = pow( pow(X,2) + pow(Y,2) + pow(Z,2),0.5);
 
    return res;
}
void Edge :: print(){
      
    cout << " Edge: ";
	cout<<endl<<"  indice vi :" << viI << endl << "  indice vf :" << viF<<endl;
    
}