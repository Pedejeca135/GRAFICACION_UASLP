#include <Object.hpp>

using namespace std;

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
    std :: ostringstream yS;
    std :: ostringstream zS;

	res << "Vertex -> ";
	res << "X: " ;
    res << res.str() << x << " ";
	res << "Y: " << y << " ";
	res << res.str() << "Z: "<< z;
    return res.str();
}

//print() the returned String of toString Method()
void Vertex :: print(){
     cout<<toString()<<endl;
}

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
void Face :: AddAristasVerticesIndexed(Edge e){
    AristasVerticesIndexed.push_back(e); 
}

string Face :: toString(){
    std::string res;
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
Object :: Object()
{

}

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

string Object::toString(){

     std::string res;
    res = "Object: " + name + "\n";

	for(int i = 0; i < vertices.size(); i++)
			res = res + vertices[i].toString();

	for(int i = 0; i < faces.size(); i++)
			res = res + faces[i].toString();
}

void Object::print(){
    cout<<"Object: " << name << endl;

	for(int i = 0; i < vertices.size(); i++)
			vertices[i] .print();

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
    Object workingObj();
    int numOfObjects = 0 ;

    std :: string lineOfFile;
    std :: string space = " ";
    std :: string slash = "/";

    std :: ifstream file(path);

    const int vPos = 0;
    const int vtPos =1;
    const int vnPos = 2;

    while(getline(file, lineOfFile))
    {
        cout<<"lineOfFile : "<< lineOfFile<<endl;
    
            size_t limitPos = lineOfFile.find(space);
            std :: string typeStringPrefix = lineOfFile.substr(0,limitPos);
            cout<< typeStringPrefix<<endl;

            //is not an empty line.
            if(limitPos != std::string::npos) {
                

                std::vector<std::string> elementsOfLine ;
                elementsOfLine = parseLine(lineOfFile,space,0);
			    elementsOfLine.erase(elementsOfLine.begin()); // remove the first element (prefix)


                if(typeStringPrefix == "o") //name of objects.
                {

                    objects.push_back(Object(elementsOfLine[0]));
                }

                if(typeStringPrefix == "v")//vertices.
                {                      

                            float x = stof(elementsOfLine[0]);
                            float y = stof(elementsOfLine[1]);
                            float z = stof(elementsOfLine[2]);                        
                                                
                        Vertex v(x, y, z);

                    if(objects.size() > 0) 
                    {                       
                        objects[objects.size() - 1].AddVertex(v);
                    }
                    else
                    {
                         objects.push_back(Object(path));
                         objects[0].AddVertex(v);
                    }                 
                }

                if(typeStringPrefix == "vn") //not needed jet.
                {
                    continue;
                }
                 if(typeStringPrefix == "vt") //not needed jet.
                {
                    continue;
                }
                  if(typeStringPrefix == "vp") //not needed jet.
                {
                    continue;
                }
                if(typeStringPrefix == "f") //faces.
                {
                  
                    if(objects.size() > 0) 
                    {  
                        Face f; 
                        Edge e;
                        int firstOfAll;
                        int initIndex;
                        int finIndex;
                        bool initialOneB = true; 
                        int index_V;                    
                        //int index_Vt ;
                        //int index_Vn ;  

                            for(int i = 0; i < elementsOfLine.size(); i++) 
                            {   
                                if(elementsOfLine[i].find(slash) != std::string::npos)
                                {
                                    std::vector<std::string> elementsOfString ; 
                                    elementsOfString = parseLine(elementsOfLine[i],slash,0);
                                    index_V = stoi(elementsOfString[vPos]);//(index = 0)->77/903/934 
                                                             
                                    //index_Vt = stoi(elementsOfString[vtPos]);
                                    //index_Vn = stoi(elementsOfString[vnPos]);
                                }
                                else
                                {
                                     index_V = stoi(elementsOfLine[i]);                                  
                                }

                                f.Add(index_V);                                
                                 
                                if(i >= elementsOfLine.size() - 1)
                                {
                                   e = Edge(firstOfAll,index_V);     
                                }
                                else
                                {                                    
                                     if (i == 0)
                                    {
                                        firstOfAll = index_V;
                                    }   

                                        
                                        if(initialOneB)
                                    {
                                        initIndex = index_V ;                                        
                                        initialOneB = false;
                                    }
                                    else
                                    {
                                        finIndex = index_V;
                                        Edge e = new Edge(initIndex,finIndex);
                                        initialOneB = true;
                                    }
                                }
                                f.AddAristasVerticesIndexed(e);     
                            } 
                            objects[objects.size()-1].AddFace(f);
                    } 
                }


            }
            
        }

        file.close();
        return objects;
}//readObjFile function(END).


std::vector<std::string> parseLine(std::string str, std::string delimeter, int start) {

    cout<<endl;
	size_t positionFound = 0;				// position of the element to find
	std::vector<std::string> res;	// vector that will be returned
	std::string element;				// the current element of the string

	// Loops trough all the slices of the string
	while
    ((positionFound = str.find(delimeter, start)) != std::string::npos) 
    {
         //cout<< "while parseLineFunction"<<endl;
		// extracts the substring
		element = str.substr(start, positionFound-start);

        cout<<"Element: "<< element<< endl;
		// Changes the start index
		start = positionFound + delimeter.length();

		res.push_back(element);
	}

    if(str.length() - positionFound > 0)//there is a last element.
    {
        element = str.substr(start, str.length());
        cout<<"Element: "<< element<< endl;
    }

    cout<< "delimeter:"<<delimeter<<"start:"<< start<<endl;

	// If there were elements, adds the last one
	if(res.size() > 0) {
		element = str.substr(start, str.length()-start);
		res.push_back(element);
	}

	return res;
}
 