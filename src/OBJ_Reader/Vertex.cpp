
#include <../OBJ_Reader/Vertex.hpp>

/*****************************************************************
 * 
 * ||||||||||||||||||  Constructors of Vertex ||||||||||||||||||||
 * 
 * ***************************************************************/

//default contructor initializes every coordenate at 0.0.
Vertex :: Vertex(){
    x = 0.0;
    y = 0.0;
    z = 0.0;
}
//Constructor of Vertex given all its coordenates.
Vertex :: Vertex(float _x, float _y, float _z){
    x = _x;
    y = _y;
    z = _z;
}
//Constructor if Vertex given another Vertex.
Vertex :: Vertex(Vertex *other){
    x = other->x;
	y = other->y;
	z = other->z;
}

//methods of Vertex.
//toString() return a String representing the Vertex.
std :: string Vertex :: toString(){
    //std::string res;
    std :: ostringstream res;

	//res << "Vertex -> ";
	res << "X: " ;
    res << x << " ";
	res << "Y: " << y << " ";
	res << "Z: "<< z;
    return res.str();
}

//print() the returned String of toString Method()
void Vertex :: print(){
     cout<<toString()<<endl;
}
