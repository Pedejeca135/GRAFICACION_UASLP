
#include <Vertex.hpp>

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

vector <float> Vertex::getValues(){
    vector<float> v = {x,y,z};
    return (v);
    }

arma::fcolvec Vertex::getHomg(){
    arma::fcolvec vh ={{x},{y},{z},{1.0}};
    return (vh);
}

arma::frowvec Vertex::get_value(){
    arma::frowvec vh ={{x},{y},{z}};
    return (vh);
}
void Vertex :: set_value(arma::frowvec trans)
{
    x = trans[0];
    y = trans[1];
    z = trans[2];
}

void Vertex:: set_value(float transx,float transy,float transz)
{
	x = transx;
	y = transy;
	z = transz;	
}