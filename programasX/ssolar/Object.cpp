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


void Object::init(std::string path)
{
    //*this = readObjFile(path)[0];
    //= readObjFile(path);
    *this = readFirstObjFile(path);
}

/**************************************************************************************
 * 
 * Function to read .obj files.
 * This need the path of the file to return an object of the Object calss.
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
                    if(objects.size() > 0) 
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

                                    //Make the last conection between the last and first index                                    
                                    f.AddAristasVerticesIndexed(finIndex,firstOfAll);    
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
Object readFirstObjFile(std::string path){

    std::vector<Object> objects;
    Object workingObj();
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
                    if(objects.size()>0)
                    {
                        return objects[0];
                    }
                    else
                    {                       
                    
                    objects.push_back(Object(elementsOfLine[0]));
                    }
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
                    if(objects.size() > 0) 
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

                                    //Make the last conection between the last and first index                                    
                                    f.AddAristasVerticesIndexed(finIndex,firstOfAll);    
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
        return objects[0];
}//readObjFile function(END).