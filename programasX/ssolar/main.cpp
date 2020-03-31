#include <stdio.h>
#include <stdlib.h>
#include <GL/glu.h>
#include <GLFW/glfw3.h>
#include <armadillo>
#include "Object.hpp"
#include "Transform.hpp"
#include "Plotter.hpp"

int main( void )
{
    arma::frowvec eye = {0.0, 0.0, 10.0};
    arma::frowvec camera = {0.0, 0.0, 0.0};
    
    GLFWwindow* window;
    
    //Object sol = Object();
    //sol.init("roca.obj");
    Object sol = readFirstObjFile("roca.obj");
   
    //Object tierra = Object();
    //tierra.init("roca.obj");
    Object tierra = readFirstObjFile("roca.obj");

    if( !glfwInit() )
    {
        fprintf( stderr, "Fallo al inicializar GLFW\n" );
        getchar();
        return -1;
    }

    window = glfwCreateWindow(1024, 768, "Sistema Solar", NULL, NULL);
    if( window == NULL ) {
        fprintf( stderr, "Fallo al abrir la ventana de GLFW.\n" );
        getchar();
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

//  Proyecciones
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    int width, height;
    glfwGetFramebufferSize(window, &width, &height);

    float ar = width / height;

//  Proyección en paralelo
    glViewport(0, 0, width, height);
    glOrtho(-ar, ar, -1.0, 1.0, -20.0, 20.0);

//  Proyección en perspectiva
//    glFrustum(-ar, ar, -ar, ar, 2.0, 4.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    Transform Tr = Transform();
    float t_angle = 0.0f;
    
    do {
        glClear( GL_COLOR_BUFFER_BIT  | GL_DEPTH_BUFFER_BIT );

    

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
       /* gluLookAt(eye[0], eye[1], eye[2], 
                camera[0], camera[1], camera[2], 
                0.0, 1.0, 0.0);*/

//draw(sol,0.6,Color3f(0.3,0.9,0.0));
        // Dibujar el Sol
        arma::fmat transf = Tr.S(0.6, 0.6, 0.6);
     
        std::vector< Vertex > p_vertices = sol.vertices;
        std::vector< Vertex > sol_vertices;
        for ( unsigned int i = 0; i<p_vertices.size(); i++ ) 
        {
            arma::fcolvec v = p_vertices[i].getHomg();
            arma::fcolvec vp = transf * v;
            Vertex rv = Vertex();
            rv.set_value(/*arma::trans(*/vp/*)*/);
            sol_vertices.push_back(rv);
        }
     

for(int f = 0; f < sol.faces.size(); f++) 
    {
		Face face = sol.faces[f];        
		    glColor3f(1.0, 1.0, 0.0);
		    glBegin(GL_TRIANGLES);
		    for(int v = 0; v < face.verticesIndex.size(); v++) {
			    Vertex vertex = sol_vertices[face.verticesIndex[v]];
			    glVertex3f(vertex.x, vertex.y, vertex.z);
		    }
		    glEnd();
        
	}


/*
        glColor3f(1.0, 1.0, 0.0);
        glBegin(GL_TRIANGLES);
        for ( unsigned int i=0; i<sol_vertices.size(); i++ ) {
            arma::frowvec vert = sol_vertices[i].get_value();
            glVertex3f(vert[0], vert[1], vert[2]);
        }
        glEnd();*/

        // Fin dibujado del Sol

        // Dibujar la Tierra
        t_angle = (t_angle < 360.0f) ? t_angle+5.0 : 0.0f;

        transf = Tr.R(0.0f, 1.0f, 0.0f, t_angle) * Tr.T(-0.7, 0.0, 0.0) * Tr.S(0.4, 0.4, 0.4) * transf;
        
        p_vertices = tierra.vertices;
        std::vector< Vertex > tierra_vertices;
        for ( unsigned int i=0; i<p_vertices.size(); i++ ) {
            arma::fcolvec v = p_vertices[i].getHomg();
            arma::fcolvec vp = transf * v;
            Vertex rv = Vertex();
            rv.set_value(vp);
            tierra_vertices.push_back(rv);
        }
        

        /*
        glColor3f(0.0, 0.0, 1.0);
        glBegin(GL_TRIANGLES);
        for ( unsigned int i=0; i<tierra_vertices.size(); i++ ) {
            arma::frowvec vert = tierra_vertices[i].get_value();
            glVertex3f(vert[0], vert[1], vert[2]);
        }
        glEnd();
        */

        for(int f = 0; f < tierra.faces.size(); f++) 
    {
		Face face = tierra.faces[f];        
		    glColor3f(0.0, 0.0, 1.0);
		    glBegin(GL_TRIANGLES);
		    for(int v = 0; v < face.verticesIndex.size(); v++) {
			    Vertex vertex = tierra_vertices[face.verticesIndex[v]];
			    glVertex3f(vertex.x, vertex.y, vertex.z);
		    }
		    glEnd();
        
	}
        // Fin dibujado de la Tierra

        glfwSwapBuffers(window);
        glfwPollEvents();

if(glfwGetKey(window, GLFW_KEY_P ) == GLFW_PRESS)
{
    glfwSwapBuffers(window);
    glfwPollEvents();
    while (glfwGetKey(window, GLFW_KEY_K ) != GLFW_PRESS)
    {
        if(glfwGetKey(window, GLFW_KEY_K ) == GLFW_PRESS)
        {
            glfwSwapBuffers(window);
            glfwPollEvents();
            break;
        }
    }
    
}
        

    } while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
           glfwWindowShouldClose(window) == 0 );

    glfwTerminate();

    return 0;
}