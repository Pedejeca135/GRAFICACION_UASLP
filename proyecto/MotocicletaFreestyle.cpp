#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "Components.h"
#include <vector>
#include "Object.h"
#include <fstream>
#include <string>
#include "Transform.hpp"

#include <GL/glu.h>
#include <GLFW/glfw3.h>
#include <armadillo>

//Vectors that will be used as auxiliaries to send them to the figures.
vector <Vertex> verts;
vector<Edge> edgs;
vector<Face>fcs;
vector<Object> models;

//function prototypes
void readFile(string* nombre, string* archivo, string enter);
int paintModels2();
int inicializacion(GLFWwindow* window);
vector <Vertex> bezier(double x);
int main(int argc, char** argv)
{
	//Variables that will be used as auxiliaries to temporarily save the data and then send them to the figures
	string nombre;
	string archivo;
	readFile(&nombre, &archivo, "BMX.obj");
	Object model = Object(nombre, archivo, verts, edgs, fcs);
	models.push_back(model);
	nombre = "";archivo = "";verts.clear();edgs.clear();fcs.clear();
	paintModels2();
	
	return 0;
}//main (END).

/*The following function reads the data of the obj file receiving as parameters nombre and archivo these are by reference and
  an enter string that is the name of the file to read this goes by value.*/
void readFile(string* nombre, string* archivo, string enter) {
	char cadena[500];
	float a, b, c;
	int d, e, f, aux = 0;
	string dcadena, ecadena, fcadena;
	int indiVer = 1;
	ifstream fe(enter);
	fe >> cadena;
	//Assign the file name to the archivo variable
	*archivo = cadena;
	fe >> cadena;
	fe >> cadena;
	fe >> cadena;
	//Assign the name to the nombre variable
	*nombre = cadena;
	//While not end of file
	while (!fe.eof()) {
		fe >> cadena;
		//Verify that only vertices are read
		if (cadena[1] != 'n' && fe.eof() == 0 && cadena[0] == 'v') {
			fe >> cadena;
			a = atof(cadena);
			fe >> cadena;
			b = atof(cadena);
			fe >> cadena;
			c = atof(cadena);
			//A temporary vertex is created and added to the array of vertices.
			Vertex v(a, b, c, indiVer);
			verts.push_back(v);
			indiVer++;
		}
		//Verify that only the faces are read.
		else if (cadena[1] != 'n' && fe.eof() == 0 && cadena[0] == 'f') {
			vector<Vertex> vertic;
			vector<Edge> edgaux;
			fe >> cadena;
			d = atof(cadena);
			vertic.push_back(verts[d - 1]);
			fe >> cadena;
			e = atof(cadena);
			vertic.push_back(verts[e - 1]);
			fe >> cadena;
			f = atof(cadena);
			vertic.push_back(verts[f - 1]);
			//The three edges are deducted and added to the edge vector.
			Edge j(verts[d - 1], verts[e - 1]);
			Edge k(verts[e - 1], verts[f - 1]);
			Edge l(verts[f - 1], verts[d - 1]);
			edgs.push_back(j);
			edgs.push_back(k);
			edgs.push_back(l);
			//Those same edges are sent to the edgaux temporary vector that will be sent to the face that will be formed by a vector of vertices and one of edges.
			edgaux.push_back(j);
			edgaux.push_back(k);
			edgaux.push_back(l);
			Face fac(vertic, edgaux);
			fcs.push_back(fac);
		}
		else
		{
			fe >> cadena;
			fe >> cadena;
			fe >> cadena;
		}
	}
	fe.close();
}



int paintModels2() {
	arma::frowvec eye = { 0.0, 0.0, 10.0 };
	arma::frowvec camera = { 0.0, 0.0, 0.0 };

	if (!glfwInit())
	{
		fprintf(stderr, "Fallo al inicializar GLFW\n");
		getchar();
		return -1;
	}
	GLFWwindow* window;
	window = glfwCreateWindow(1024, 768, "Motocicleta Freestyle", NULL, NULL);
	if (window == NULL) {
		fprintf(stderr, "Fallo al abrir la ventana de GLFW.\n");
		getchar();
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetInputMode(window, GLFW_STICKY_KEYS,GL_TRUE);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

	//  Proyecciones
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	float ar = width / height;

	//  Proyecci�n en paralelo
	glViewport(0, 0, width, height);
	glOrtho(-ar, ar, -1.0, 1.0, -20.0, 20.0);
	//  Proyecci�n en perspectiva
	//    glFrustum(-ar, ar, -ar, ar, 2.0, 4.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	Transform Tr = Transform();
	double t_angle = 0.0f;
	int cont = 0;
	int bcont = 0;
	double dt = 13.0;
	std::vector< Vertex > p_vertices;
	for (int f = 0; f < models[0].getSizevectorface();f++) {
		//Cycle to pass each vertex
		for (int v = 0;v < 3;v++) {
			p_vertices.push_back(models[0].getFace(f).getVert(v));
		}
	}
	
	vector <Vertex> vet = bezier(1.0);
	do {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		/*gluLookAt(eye[0], eye[1], eye[2],
			camera[0], camera[1], camera[2],
			0.0, 1.0, 0.0);*/

	    // Dibujar la moto
		arma::dmat transd;
		if (dt > 1) {
			transd = Tr.S(0.05, 0.05, 0.05) * Tr.R(0.0, 0.5, 0.0, 180.0) * Tr.T(dt, 0.0, 0.0);
			dt -= 0.3;
		}
		else{
			if (bcont < 20)
			{
				transd = Tr.S(0.05, 0.05, 0.05) * Tr.R(0.0, 0.5, 0.0, 180.0) * Tr.T(vet[bcont].getX(), vet[bcont].getY(), vet[bcont].getZ());
				dt = vet[bcont].getX();
				bcont++;
			}
			else {

				transd = Tr.S(0.05, 0.05, 0.05) * Tr.R(0.0, 0.5, 0.0, 180.0) * Tr.T(dt, 0.0, 0.0);
				dt -= 0.3;
			}
		}
			
		
		std::vector< Vertex > moto_vertices;
		for (unsigned int i = 0; i < p_vertices.size(); i++) {
			arma::dcolvec v = p_vertices[i].h();
			arma::dcolvec vp = transd * v;
			Vertex rv = Vertex();
			rv.set_value(arma::trans(vp));
			moto_vertices.push_back(rv);
		}
		glColor3f(1.0, 1.0, 0.0);
		glBegin(GL_TRIANGLES);
		for (unsigned int i = 0; i < moto_vertices.size(); i++) {
			glVertex3d(moto_vertices[i].getX(), moto_vertices[i].getY(), moto_vertices[i].getZ());
		}
		glEnd();

		glfwSwapBuffers(window);
		glfwPollEvents();

	} while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(window) == 0);

	glfwTerminate();
	return 0;
}

vector <Vertex> bezier(double x) {

	vector<Vertex> vertic;
	arma::dmat MB = { {-1.0, 3.0, -3.0, 1.0},
				  {3.0, -6.0, 3.0, 0.0},
				  {-3.0, 3.0, 0.0, 0.0},
				  {1.0, 0.0, 0.0, 0.0} };
	//MH.print();

	//cout << endl;

	arma::dmat GH = { {x, 0.0, 0.0},
					  {-1.0, 5.0, 0.0},
					  {-3.0,4.0,0.0},
					  {-5.0, 0.0, 0.0} };
	//GH.print();

	double dt = 0.05;
	arma::dmat Qt;
	for (double t = 0.0; t <= 1.0 + dt; t += dt) {
		arma::drowvec T = { powf(t, 3.0), powf(t,2.0), t, 1.0 };
		Qt = T * MB * GH;
		Qt.print();
		Vertex vert(Qt[0], Qt[1], Qt[2], 1.0);
		vertic.push_back(vert);
	}
	return vertic;
}
