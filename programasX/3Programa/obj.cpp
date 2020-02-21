#include <obj.hpp>




Vertex :: Vertex(float x1, float y1, float z1)
{
	x = x1;
	y = y1;
	z = z1;
}
Vertex :: Vertex()
{
}

Edge :: Edge(Vertex v1, Vertex v2)
{
	vi = v1;
	vf = v2;
}

Face :: Face(vector<Edge> fars)
{
	aristas = fars;
}

Face :: Face()
{			
}

Figure :: Figure(vector<Face> faces, char *figuraNombre)
{
	caras = faces;
    nombre = figuraNombre;
}

string Figure :: toString()
{
    string resString;
    //cout<< "Figura:" << nombre << endl;
    resString = "Figura:";
    resString += nombre;
    resString += "\n";

	for(int i = 0; i < caras.size(); i++)
		{
			//cout<<"cara numero "<< i << ":"<<endl;
            resString = "cara numero ";
            resString += i;
            resString += ":\n";
			//caras[i].toString();
            resString += caras[i].toString();
		}
        return resString;
}

string Face :: toString()
{
    string resString;
			for(int j = 0; j < aristas.size() ; j++ )
			{
				//cout<<"arista numero"<< j << ":"<<endl;
                resString = "arista numero";
                resString += j;
                resString += ":\n";

                //aristas[j].toString();                 
                resString += aristas[j].toString();               
                
			}        
            return resString;		
}

string Edge :: toString()
{
    string resString;
			//cout<<"vertice I"<< ":"<<endl;
            //vi.toString();
            resString = "vertice I:";
            resString += vi.toString();
            //cout<<"vertice F"<< ":"<<endl;
            //vf.toString(); 
            resString = "vertice F:";
            resString += vf.toString();       		
}

string Vertex :: toString()
{
    string resString= "";
        	/*cout<<"X"<< ":"<< x <<endl;
            cout<<"Y"<< ":"<< y <<endl;
            cout<<"Z"<< ":"<< z <<endl;	
            */
           resString = "(" + x +"," + y +"," + z +")";
}