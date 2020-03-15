#include <Plotter.hpp>

void plotWireFrame(Object obj){

	for(int f = 0; f < obj.faces.size(); f++) 
    {
		Face face = obj.faces[f];        
		    glColor3f(1.0, 1.0, 1.0);
		    glBegin(GL_LINE_LOOP);
		    for(int v = 0; v < face.verticesIndex.size(); v++) {
			    Vertex vertex = obj.vertices[face.verticesIndex[v]];
			    glVertex3f(vertex.x*0.1, vertex.y*0.1, vertex.z*0.1);
		    }
		    glEnd();
        
	}
}

void plotWireFrame(vector<Object> objs){
    
    for(int i= 0 ; i< objs.size(); i++)
    {
        plotWireFrame(objs[i]);
    }
}