#include <stdio.h>
#include <stdlib.h>
#include <GL/glu.h>
#include <GLFW/glfw3.h>
#include <armadillo>
#include "Object.hpp"
#include "Transform.hpp"
#include "Plotter.hpp"
#include "CelestialBody.hpp"

int main( void )
{
    arma::frowvec eye = {0.0, 0.0, 10.0};
    arma::frowvec camera = {0.0, 0.0, 0.0};
    
    GLFWwindow* window;

    float timeDelay = 4.0f;

//creacion del sol fijo.
    CelestialBody sol = CelestialBody( "sol", Color3f(1.0,1.0,0.0) , 0.3 );
//creacion de los planetas:
    CelestialBody mercurio = CelestialBody( "mercurio", sol , 5*timeDelay, Color3f(0.9,0.2,0.0) , 0.020 ,0.2);
    CelestialBody venus = CelestialBody( "venus", sol , 13*timeDelay, Color3f(0.55,0.5,0.509) , 0.040 ,0.25);
    CelestialBody tierra = CelestialBody( "tierra", sol , 21*timeDelay, Color3f(0.0,0.5,1.0) , 0.05 ,0.35);
    CelestialBody marte = CelestialBody( "marte", sol , 40*timeDelay, Color3f(1.0,0.0,0.0) , 0.025 ,0.4);
    CelestialBody jupiter = CelestialBody( "jupiter", sol , 240*timeDelay, Color3f(0.78,0.56,0.223) , 0.5 ,0.5);
    CelestialBody saturno = CelestialBody( "saturno", sol , 600*timeDelay, Color3f(0.9,0.84,0.72) , 0.42 ,0.6);
    CelestialBody urano = CelestialBody( "urano", sol , 1500*timeDelay, Color3f(0.3,0.3,1.0) , 0.175 ,0.8);
    CelestialBody neptuno = CelestialBody( "neptuno", sol , 3000*timeDelay, Color3f(0.01,0.01,1.0) , 0.160 ,1.0);


    CelestialBody luna = CelestialBody( "luna", &tierra , 2*timeDelay, Color3f(1.0,1.0,1.0) , 0.55 ,0.80);

    CelestialBody lunaJ1 = CelestialBody("luna",&jupiter,2.5*timeDelay , Color3f(1.0,1.0,1.0), 0.10, 0.65);
    CelestialBody lunaJ2 = CelestialBody("luna",&jupiter,1.534234*timeDelay , Color3f(1.0,1.0,1.0), 0.15, 0.7);
    CelestialBody lunaJ3 = CelestialBody("luna",&jupiter,2.5453*timeDelay , Color3f(1.0,1.0,1.0), 0.13, 0.8);
    //cout<<"afuera "<<&tierra.transf<<endl;


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

    glClearColor(0.8f, 0.8f, 1.0f, 0.5f);

//  Proyecciones
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    int width, height;
    glfwGetFramebufferSize(window, &width, &height);

    float ar = width / height; 

//  Proyección en paralelo
    glViewport(0, 0, width, height);
    glOrtho(-ar, ar, -1.0, 1.0, -20.0, 20.0) ;

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
        gluLookAt(eye[0], eye[1], eye[2], 
                camera[0], camera[1], camera[2], 
                0.0, 1.0, 0.0);

//impresion y movimiento de los cuerpos celestes.
sol.makeStep();
mercurio.makeStep();
venus.makeStep();
tierra.makeStep();
marte.makeStep();
jupiter.makeStep();
saturno.makeStep();
urano.makeStep();
neptuno.makeStep();

//impresion y movimiento de lunas.
luna.makeStep();
lunaJ1.makeStep();
lunaJ2.makeStep();
lunaJ3.makeStep();


        glfwSwapBuffers(window);
        glfwPollEvents();

    } while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
           glfwWindowShouldClose(window) == 0 );

    glfwTerminate();

    return 0;
}