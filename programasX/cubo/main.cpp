#include <stdio.h>
#include <stdlib.h>
#include <GLFW/glfw3.h>


int main( void )
{
    GLFWwindow* window;
	GLFWwindow* window2;

    if( !glfwInit() )
    {
        fprintf( stderr, "Fallo al inicializar GLFW\n" );
        getchar();
        return -1;
    }

    window = glfwCreateWindow(1024, 768, "Ventana 1 OpenGL", NULL, NULL);
    window2 = glfwCreateWindow(800, 600, "Ventana2 OpenGL", NULL, NULL);
    
    if( window == NULL  || window2 == NULL) {
        fprintf( stderr, "Fallo al abrir la ventana de GLFW.\n" );
        getchar();
        glfwTerminate();
        return -1;
    }    

    do {
        glfwMakeContextCurrent(window);
        glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClear( GL_COLOR_BUFFER_BIT );

//dibujar en la primera ventana.
        glColor3f(1.0, 0.0, 0.0);

        glBegin(GL_TRIANGLES);
            glVertex3f(0.0, 1.0, 0.0);
            glVertex3f(0.5, 0.0, 0.0);
            glVertex3f(-0.5, 0.0, 0.0);
        glEnd();

		  glColor3f(0.0, 1.0, 0.0);

        glBegin(GL_TRIANGLES);
            glVertex3f(-0.5, 0.0, 0.0);
            glVertex3f(0.0, -1.0, 0.0);
            glVertex3f(-1.0, -1.0, 0.0);
        glEnd();

		  glColor3f(0.0, 0.0, 1.0);

        glBegin(GL_TRIANGLES);
            glVertex3f(0.5, 0.0, 0.0);
            glVertex3f(1.0, -1.0, 0.0);
            glVertex3f(0.0, -1.0, 0.0);
        glEnd();
        
// dibujar en la segunda ventana. 
		 glfwMakeContextCurrent(window2);
        glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
         glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClear( GL_COLOR_BUFFER_BIT );

        glColor3f(1.0, 0.0, 0.0);

         glBegin(GL_TRIANGLES);
            glVertex3f(0.0,-1.0, 0.0);
            glVertex3f(0.5, 0.0, 0.0);
            glVertex3f(-0.5, 0.0, 0.0);
        glEnd();

		  glColor3f(0.0, 1.0, 0.0);

        glBegin(GL_TRIANGLES);
            glVertex3f(-0.5, 0.0, 0.0);
            glVertex3f(0.0, 1.0, 0.0);
            glVertex3f(-1.0, 1.0, 0.0);
        glEnd();

		  glColor3f(0.0, 0.0, 1.0);

        glBegin(GL_TRIANGLES);
            glVertex3f(0.5, 0.0, 0.0);
            glVertex3f(0.0, 1.0, 0.0);
            glVertex3f(1.0, 1.0, 0.0);
        glEnd();

        
        glfwSwapBuffers(window);
        glfwSwapBuffers(window2);

        glfwPollEvents();


    } while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
           glfwWindowShouldClose(window) == 0 );

    glfwTerminate();

    return 0;
}