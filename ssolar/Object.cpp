#include <Object.hpp>


using namespace std;

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

/*
string Object::toString(){

     std::string res;
    res = "Object: " + name + "\n";

	for(int i = 0; i < vertices.size(); i++)
			res = res + vertices[i].toString();

	for(int i = 0; i < faces.size(); i++)
			res = res + faces[i].toString();

            return res;
}
*/

void Object:: init(std::string path)
{
  *this = read_1_ObjFile(path); 
}




std::vector< Vertex > Object:: get_faces_verts()
{
    vector <Vertex> res;
    for(int i = 0; i < faces.size() ; i++)
    {
        for(int j = 0 ; j < faces[i].AristasVerticesIndexed.size() ; j++ )
        {
            res.push_back(vertices[faces[i].AristasVerticesIndexed[j].viI]);
            res.push_back(vertices[faces[i].AristasVerticesIndexed[j].viF]);
            /*
            for(int k = 0 ; k < faces[i].AristasVerticesIndexed[j].; k++)
            {
                res.push_back(vertices[faces[i].verticesIndex[j]]);
            }
            */
        }        
    }
    return res;
}
		

float Object :: edgeDistancia(Edge edge)
{
    float d = 0;
    float X = vertices[edge.viF].x - vertices[edge.viI].x;
    float Y = vertices[edge.viF].y - vertices[edge.viI].y;
    float Z = vertices[edge.viF].z - vertices[edge.viI].z;

    d= pow( pow(X,2) + pow(Y,2) + pow(Z,2),0.5);
    return d;
}

float Object :: facePerimetro(Face face)
{
    float peri = 0;
    for(int i = 0 ; i < face.AristasVerticesIndexed.size(); i++)
    {
        peri += edgeDistancia(face.AristasVerticesIndexed[i]);
    }
    return peri;
}


void Object::print()
{
    cout<<"Object: " << name << endl;

	for(int i = 0; i < vertices.size(); i++)
    {
            cout<< "Vertex " << "(" << i+1 <<")" <<"-> ";
			vertices[i] .print();
    }
	for(int i = 0; i < faces.size(); i++)
			faces[i].print();
}

/**************************************************************************************
 * 
 * Function to read .obj files.
 * This need the path of the file to return an object of the Object calss.
 * 
 * ************************************************************************************/
std::vector<Object> readObjFile(std::string path){

    std::vector<Object> objects;
    Object workingObj;
    int numOfObjects = 0 ;

    std :: string lineOfFile;
    std :: string space = " ";
    std :: string slash = "/";

    std :: ifstream file(path);

    const int vPos = 0;
    //const int vtPos =1;
    //const int vnPos = 2;

    while(getline(file, lineOfFile))
    {
            size_t limitPos = lineOfFile.find(space);
            std :: string typeStringPrefix = lineOfFile.substr(0,limitPos);           

            //is not an empty line.
            if(limitPos != std::string::npos) 
            {               

                std::vector<std::string> elementsOfLine ;
                elementsOfLine = split(lineOfFile,space,0);
			    elementsOfLine.erase(elementsOfLine.begin()); // remove the first element (prefix)


                if(typeStringPrefix == "o") //name of objects.
                {
                    workingObj = Object(elementsOfLine[0]);
                    objects.push_back(workingObj);
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
                    //continue;
                }
                 if(typeStringPrefix == "vt") //not needed jet.
                {
                    //continue;
                }
                  if(typeStringPrefix == "vp") //not needed jet.
                {
                    //continue;
                }
                if(typeStringPrefix == "f") //faces.
                {                   
                    if(objects.size() > 0) //at leat one object in the vector
                    {  
                        Face f;
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
                                    elementsOfString = split(elementsOfLine[i],slash,0);
                                    index_V = stoi(elementsOfString[vPos]);//(index = 0)->77/903/934                     
                                    //index_Vt = stoi(elementsOfString[vtPos]);
                                    //index_Vn = stoi(elementsOfString[vnPos]);
                                }
                                else
                                {                                 
                                     index_V = stoi(elementsOfLine[i]);                               
                                }

                                f.Add(index_V);                                
                                 
                                if(i == elementsOfLine.size() -1)
                                {
                                    initIndex = finIndex;
                                    finIndex = index_V; 

                                    //
                                    f.AddAristasVerticesIndexed(initIndex,finIndex);
                                    f.AddAristasVerticesDirect(workingObj.vertices[initIndex], workingObj.vertices[finIndex]);
                                           

                                    //Make the last conection between the last and first index                                    
                                    f.AddAristasVerticesIndexed(finIndex,firstOfAll);   
                                    f.AddAristasVerticesDirect(workingObj.vertices[finIndex], workingObj.vertices[firstOfAll]);
                                            
                                }
                                else
                                {                                   
                                     if (i == 0)
                                    {
                                        finIndex = firstOfAll = index_V;    
                                    } 
                                    else
                                    { 
                                        
                                            initIndex = finIndex;
                                            finIndex = index_V;  

                                            //    
                                            f.AddAristasVerticesIndexed(initIndex,finIndex); 
                                            f.AddAristasVerticesDirect(workingObj.vertices[initIndex], workingObj.vertices[finIndex]);
                                            initialOneB = true;                                        
                                    }          
                                }    
                            }//for loop.   
                            objects[objects.size()-1].AddFace(f);
                    }                  
                }//f
        }
    }
        file.close();
        return objects;
}//readObjFile function(END).

//function to split a string. Return a vector of strings.
std::vector<std::string> split(std::string str, std::string delimeter, int start) {

	size_t positionFound = 0;				// position of the element to find
	std::vector<std::string> res;	// vector that will be returned
	std::string element;				// the current element of the string

	// Loops trough all the slices of the string
	while
    ((positionFound = str.find(delimeter, start)) != std::string::npos) 
    {
		// extracts the substring
		element = str.substr(start, positionFound-start);

		// Changes the start index
		start = positionFound + delimeter.length();

		res.push_back(element);
	}

    if(str.length() - positionFound > 0)//there is a last element.
    {
        element = str.substr(start, str.length());
    }


	// If there were elements, adds the last one
	if(res.size() > 0) {
		element = str.substr(start, str.length()-start);
		res.push_back(element);
	}

	return res;
}
 



 /**************************************************************************************
 * 
 * Function to read .obj files.
 * This need the path of the file to return an object of the Object calss.
 * 
 * ************************************************************************************/
 Object read_1_ObjFile(std::string path){

    std::vector<Object> objects = readObjFile(path);
   
        return objects[0];
}//read_One_ObjFile function(END).

/*

typedef struct{
	float v1;
	float v2;
	float v3;
}Vert;

typedef struct{
	int c1[3];
	int c2[3];
	int c3[3];
}Cara;

 class Lector_Archivo
 {
	public:
	
	//string nombreArchivo="/home/pacheco/OpenGL/models/sofa.obj";
	ifstream fe;
	int contv=0;
	int contc=0;

	vector <Vert> ListaV;
	vector <Cara> ListaC;

	
 void LeeVertices(string nombreArchivo)
	{		
	
	string cadena;
	ifstream fe;
	fe.open(nombreArchivo);
 
	while(!fe.eof()){
		fe >> cadena;
  		if(cadena == "v"){
		Vert v;
		fe>>v.v1;
 		fe>>v.v2;
		fe>>v.v3;
		ListaV.push_back(v);
		 contv++;
		}	
	
	}
	fe.close();
		
	}

	void LeeCaras(string nombreArchivo)
	{
	int ban = 0;
	string cadena;
	ifstream fe;
	fe.open(nombreArchivo);
	
	while(!fe.eof())
	{
		
		Cara c;
		fe >> cadena;
  		if(cadena == "f")
		{
		fe>>c.c1[0];
		fe>>c.c2[0];
		fe>>c.c3[0];
		ListaC.push_back(c);	
		contc++;
		
		}	
	
	}
	contc--;
	fe.close();
	}


};
*/
