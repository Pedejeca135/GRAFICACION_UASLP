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

Figure :: Figure(vector<Face> faces)
{
	caras = faces;
}

void Figure :: toString()
{
	for(int i = 0; i < caras.size(); i++)
		{
			cout<<"cara numero "<< i << ":"<<endl;

			caras[i].toString();
		}
}

void Face :: toString()
{
			for(int j = 0; j < aristas.size() ; j++ )
			{
				cout<<"arista numero"<< j << ":"<<endl;

                aristas[j].toString();                
                
			}
        		
}

void Edge :: toString()
{
			cout<<"vertice I"<< ":"<<endl;
            vi.toString();
            cout<<"vertice F"<< ":"<<endl;
            vf.toString();        		
}

void Vertex :: toString()
{
        	cout<<"X"<< ":"<< x <<endl;
            cout<<"Y"<< ":"<< y <<endl;
            cout<<"Z"<< ":"<< z <<endl;	
}