#include <Object.hpp>

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
    x = v->x;
	y = v->y;
	z = v->z;
}

//methods of Vertex.
//toString() return a String representing the Vertex.
String Vertex :: toString(){
    std::String res;
	res = "Vertex -> ";
	res += "X: " + x + " ";
	res += "Y: " + y + " ";
	res += "Z: " + z ;
    return res;
}

//print() the returned String of toString Method()
void Vertex :: print(){
    cout<<toString()<<endl;
}

/*****************************************************************
 * 
 * ||||||||||||||||||  Constructors of Face ||||||||||||||||||||
 * 
 * ***************************************************************/

Face::Face(){

}

Face::Face(Vector<int> _vertexIndex){
    vertexIndex = _vertexIndex;    
}

Face::Face(Face *other){
    vertexIndex = other -> vertexIndex;
}

//methods of Face.
void Face::Add(int i){
	vertices.push_back(i);
}

String Face :: toString(){
    std::String res;
    res = "Face: ";
	for(int i = 0; i < verticesIndex.size(); i++)
	res += verticesIndex[i] + ", ";
    return res;
}

void Face :: print(){
    cout<<toString()<<endl;
}

/*****************************************************************
 * 
 * ||||||||||||||||||  Constructors of Object ||||||||||||||||||||
 * 
 * ***************************************************************/

Object :: Object(std::string _name){
    name = _name;
}

Object :: Object(Object *other){
	name = other->name;
	for(int i = 0; i < other->vertices.size(); i++)
		vertices.push_back(other->vertices[i]);
	for(int i = 0; i < other->faces.size(); i++)
		faces.push_back(other->faces[i]);
}

//methods of Object.
void Object::AddVertex(Vertex v){
    vertices.push_back(v);
}

void Object::AddFace(Face f){
    faces.push_back(f);
}

String Object::toString(){

     std::String res;
    res = "Object: " + name + "\n";

	for(int i = 0; i < vertices.size(); i++)
			res + = vertices[i].toString();

	for(int i = 0; i < faces.size(); i++)
			res + = faces[i].toString();
}

void Object::print(){
    cout<<"Object: " << name << endl;

	for(int i = 0; i < vertices.size(); i++)
			vestices[i].print();

	for(int i = 0; i < faces.size(); i++)
			faces[i].print();
}

/**************************************************************************************
 * 
 * Function to read .obj files.
 * This need the pat of the file to return an object of the Object calss.
 * 
 * ************************************************************************************/
std::vector<Object> readObjFile(std::string path){

    std::vector<Object> objects;
    Object workingObj;
    int numOfObjects = 0 ;

    std :: String lineOfFile;
    std :: String space = " ";
    std :: String slash = "/";

    std :: ifstream file(path);

    while(getline(file, file_line)) {

            size_t limitPos = lineOfFile.find(space);
            std:: String typeString = lineOfFile.substr(0,limitPos);

            if(limitPos != std::string::npos) {
                
                

                if(typeString == "o") {

                    std::vector<std::string> nameOfObj;
                }

                if(typeString == "v") {
                    if(objects.size() > 0) {
                        float x = stof([0]);
                        float y = stof([1]);
                        float z = stof([3]);

                        Vertex v(x, y, z);
                        objects[objects.size() - 1].AddVertex(v);
                    }
                }

                if(typeString == "vn") {
                    continue();
                }

                 if(typeString == "vt") {
                    continue();
                }
                  if(typeString == "vp") {
                    continue();
                }


                if(typeString == "f") {

                    if(objects.size() > 0) {
                        Face f;                

                        objects[objects.size()-1].AddFace(f);
                    }
                }
            }
           
        }

}//readObjFile function(END).
