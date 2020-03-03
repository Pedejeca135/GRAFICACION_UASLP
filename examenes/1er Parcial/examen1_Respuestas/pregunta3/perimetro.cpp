float edgeDistancia(Edge edge)
{
    float d = 0;
    float X = vertices[edge.viF].x - vertices[edge.viI].x;
    float Y = vertices[edge.viF].y - vertices[edge.viI].y;
    float Z = vertices[edge.viF].z - vertices[edge.viI].z;

    d= pow( pow(X,2) + pow(Y,2) + pow(Z,2),0.5);
    return d;
}//

void printEdgeDistancia(Edge edge)
{
    float X = vertices[edge.viF].x - vertices[edge.viI].x;
    float Y = vertices[edge.viF].y - vertices[edge.viI].y;
    float Z = vertices[edge.viF].z - vertices[edge.viI].z;

    cout<< "D:"<< pow( pow(X,2) + pow(Y,2) + pow(Z,2),0.5);
}

void printFacePerimetro(Object object)
{
    float peri = 0;

for(int j= 0 ; j< object.faces.size(); j++)
{
    for(int i = 0 ; i< object.faces[j].AristasVerticesIndexed.size() ; i++)
    {
        peri += edgeDistancia(AristasVerticesIndexed[i]);
	printEdgeDistancia(AristasVerticesIndexed[i]));
    }
}

}//
