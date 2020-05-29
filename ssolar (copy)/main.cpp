#include <stdio.h>
#include <stdlib.h>
#include <GL/glu.h>
#include <GLFW/glfw3.h>
#include <armadillo>
#include <Class_Object.cpp>
#include "Transform.hpp"


void DibujaPlanetas(vector<Vertex> vl);
vector <Vertex>  TranformaPlanetas(vector <Vertex> PlanetaVertices,arma::fmat transf);

int main( void )
{
    arma::frowvec eye = {0.0, 0.0, 10.0};
    arma::frowvec camera = {0.0, 0.0, 0.0};
    
    GLFWwindow* window;
    
       Object sol = Object();
    sol.init("roca.obj");

    Object mercurio = Object();
    mercurio.init("roca.obj");

    Object venus = Object();
    venus.init("roca.obj");

    Object tierra = Object();
    tierra.init("roca.obj");

    Object luna = Object();
    luna.init("roca.obj");

    Object marte = Object();
    marte.init("roca.obj");

    Object jupiter = Object();
    jupiter.init("roca.obj");

    Object saturno = Object();
    saturno.init("roca.obj");

    Object urano = Object();
    urano.init("roca.obj");

    Object neptuno = Object();
    neptuno.init("roca.obj");

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
	float m_angle = 0.0f;
	float v_angle = 40.0f;
	float t_angle = 80.0f;
	float l_angle = 120.0f;
	float mt_angle = 160.0f;
	float j_angle = 200.0f;
	float s_angle = 240.0f;
	float u_angle = 280.0f;
	float n_angle = 360.0f;

    
    do {
        glClear( GL_COLOR_BUFFER_BIT  | GL_DEPTH_BUFFER_BIT );

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluLookAt(eye[0], eye[1], eye[2], 
                camera[0], camera[1], camera[2], 
                0.0, 1.0, 0.0);


        // Dibujar el Sol
        arma::fmat transf = Tr.S(0.3, 0.3, 0.3);
        std::vector< Vertex > sol_vertices = TranformaPlanetas(sol.get_faces_verts(),transf); 
        glColor3f(1.0, 1.0, 0.0);
        DibujaPlanetas(sol_vertices);
        // Fin dibujado del Sol
	
	 // Dibujar la Mercurio
	arma::fmat transf_mercurio = Tr.S(0.06, 0.06, 0.06);
        m_angle = (t_angle < 360.0f) ? t_angle+1.0 : 0.0f;

        transf_mercurio = Tr.R(0.0f, 1.0f, 0.0f, t_angle) * Tr.T(-0.20, 0.0, 0.0) * Tr.S(0.06, 0.06, 0.06) * transf;
        
        
       std::vector< Vertex > Mercurio_vertices = TranformaPlanetas(venus.get_faces_verts(),transf_mercurio); 
        
        glColor3f(1.0, 0.5, 0.0);
      	 DibujaPlanetas(Mercurio_vertices);
        // Fin dibujado de Mercurio 
	 
	// Dibujar la Venus
	arma::fmat transf_Venus = Tr.S(0.08, 0.08, 0.08);
        v_angle = (t_angle < 360.0f) ? t_angle+1.6: 0.0f;

        transf_Venus = Tr.R(0.0f, 1.0f, 0.0f, t_angle) * Tr.T(-0.30, 0.0, 0.0) * Tr.S(0.08, 0.08, 0.08) * transf;
        
       std::vector< Vertex > venus_vertices = TranformaPlanetas(venus.get_faces_verts(),transf_Venus); 
        
        glColor3f(0.5, 0.5, 0.0);
      	 DibujaPlanetas(venus_vertices);
        // Fin dibujado de venus

	 // Dibujar la Tierra
	arma::fmat transf_Tierra = Tr.S(0.1, 0.1, 0.1);
        t_angle = (t_angle < 360.0f) ? t_angle+2.0 : 0.0f;

        transf_Tierra = Tr.R(0.0f, 1.0f, 0.0f, t_angle) * Tr.T(-0.40, 0.0, 0.0) * Tr.S(0.1, 0.1, 0.1) * transf;
        
       std::vector< Vertex > tierra_vertices = TranformaPlanetas(tierra.get_faces_verts(),transf_Tierra); 
        
        glColor3f(0.0, 0.0, 1.0);
      	 DibujaPlanetas(tierra_vertices);

        // Fin dibujado de la Tierra

	//Dibuja Luna
	    l_angle = (l_angle < 360.0f) ? l_angle + 12.8 : 0.0f;
           arma::fmat transf_luna = transf_Tierra* Tr.R(0.0, 1.0, 0.0, l_angle) * Tr.T(-0.6, 0.0, 0.0) * Tr.S(0.2, 0.2, 0.2);

        std::vector< Vertex >p_vertices = luna.get_faces_verts();
        std::vector< Vertex > luna_vertices;
        for (unsigned int i = 0; i < p_vertices.size(); i++) {
            arma::fcolvec v = p_vertices[i].getHomg();
            arma::fcolvec vp = transf_luna * v;
            Vertex rv =Vertex();
            rv.set_value2(arma::trans(vp));
            luna_vertices.push_back(rv);
        }
		glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_TRIANGLES);
        for (unsigned int i = 0; i < luna_vertices.size(); i++) {
            arma::frowvec vert = luna_vertices[i].get_value();
            glVertex3f(vert[0], vert[1], vert[2]);
        }
        glEnd();


	//fin dibuja luna 

        // Dibujar la Marte
	arma::fmat transf_Marte = Tr.S(0.08, 0.08, 0.08);
        mt_angle = (t_angle < 360.0f) ? t_angle+0.5: 0.0f;

        transf_Marte = Tr.R(0.0f, 1.0f, 0.0f, t_angle) * Tr.T(-0.55, 0.0, 0.0) * Tr.S(0.08, 0.08, 0.08) * transf;
        
       std::vector< Vertex > marte_vertices = TranformaPlanetas(marte.get_faces_verts(),transf_Marte); 
        
        glColor3f(1.0, 0.0, 0.0);
      	 DibujaPlanetas(marte_vertices);
        // Fin dibujado de la Marte
	

	 // Dibujar la Jupiter
	arma::fmat transf_Jupiter = Tr.S(0.5, 0.5, 0.5);
        j_angle = (t_angle < 360.0f) ? t_angle+0.082 : 0.0f;

        transf_Jupiter = Tr.R(0.0f, 1.0f, 0.0f, t_angle) * Tr.T(-0.68, 0.0, 0.0) * Tr.S(0.5, 0.5, 0.5) * transf;
        
       std::vector< Vertex > jupiter_vertices = TranformaPlanetas(jupiter.get_faces_verts(),transf_Jupiter); 
        
        glColor3f(1.0, 1.0, 0.5);
      	 DibujaPlanetas(jupiter_vertices);
        // Fin dibujado de la Jupiter


	 // Dibujar la Saturno
	arma::fmat transf_Saturno = Tr.S(0.30, 0.30, 0.30);
        s_angle = (t_angle < 360.0f) ? t_angle+0.0344 : 0.0f;

        transf_Saturno = Tr.R(0.0f, 1.0f, 0.0f, t_angle) * Tr.T(-0.83, 0.0, 0.0) * Tr.S(0.35, 0.35, 0.35) * transf;
        
       std::vector< Vertex > Saturno_vertices = TranformaPlanetas(saturno.get_faces_verts(),transf_Saturno); 
        
        glColor3f(0.2, 0.5, 0.2);
      	 DibujaPlanetas(Saturno_vertices);
        // Fin dibujado de la Saturno



	 // Dibujar la Urano
	arma::fmat transf_Urano = Tr.S(0.16, 0.16, 0.16);
        u_angle = (t_angle < 360.0f) ? t_angle+0.02 : 0.0f;

        transf_Urano = Tr.R(0.0f, 1.0f, 0.0f, t_angle) * Tr.T(-0.90, 0.0, 0.0) * Tr.S(0.16, 0.16, 0.16) * transf;
        
       std::vector< Vertex > Urano_vertices = TranformaPlanetas(urano.get_faces_verts(),transf_Urano); 
        
        glColor3f(1.0, 0.0, 0.5);
      	 DibujaPlanetas(Urano_vertices);
        // Fin dibujado de la urano
		
	 // Dibujar la Neptuno
	arma::fmat transf_Neptuno = Tr.S(0.16, 0.16, 0.16);
        n_angle = (t_angle < 360.0f) ? t_angle+0.01: 0.0f;

        transf = Tr.R(0.0f, 1.0f, 0.0f, t_angle) * Tr.T(-0.95, 0.0, 0.0) * Tr.S(0.16, 0.16, 0.16) * transf;
        
       std::vector< Vertex > Neptuno_vertices = TranformaPlanetas(neptuno.get_faces_verts(),transf); 
        
        glColor3f(0.0, 0.0, 0.8);
      	 DibujaPlanetas(Neptuno_vertices);
        // Fin dibujado de la Neptuno

















        glfwSwapBuffers(window);
        glfwPollEvents();

    } while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
           glfwWindowShouldClose(window) == 0 );

    glfwTerminate();

    return 0;
}
void DibujaPlanetas(vector <Vertex> vl){
   glBegin(GL_TRIANGLES);
        for ( unsigned int i=0; i<vl.size(); i++ ) {
            arma::frowvec vert = vl[i].get_value();
            glVertex3f(vert[0], vert[1], vert[2]);
        }
        glEnd();

}

	vector <Vertex> TranformaPlanetas(vector <Vertex> PlanetaVertices,arma::fmat transf){


 	std::vector< Vertex >planeta_vertices = PlanetaVertices;
        std::vector< Vertex > planeta_vertices_trans; 
        for ( unsigned int i=0; i<planeta_vertices.size(); i++ ) {
            arma::fcolvec v = planeta_vertices[i].getHomg();
            arma::fcolvec vp = transf * v;
            Vertex rv = Vertex();
           //rv.set_value(vp[0],vp[1],vp[2]);
		rv.set_value2(arma::trans(vp));
            planeta_vertices_trans.push_back(rv);
        }
        
return planeta_vertices_trans;
}

