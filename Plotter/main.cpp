#include <Object.hpp> 
#include <Plotter.hpp>
#include <GLFW/glfw3.h>


using namespace std;

int main(void)
{
	GLFWwindow* window;
	std::vector<Object> firstFile = readObjFile("../Models/tareaUno.obj");
	

	 if( !glfwInit() )
    {
        fprintf( stderr, "Fallo al inicializar GLFW\n" );
        getchar();
        return -1;
    }

	 window = glfwCreateWindow(1024, 768, "Ventana 1 OpenGL", NULL, NULL);
    
	  do {
        glfwMakeContextCurrent(window);
        glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
        glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        glClear( GL_COLOR_BUFFER_BIT );

		plotWireFrame(firstFile);
        
        glfwSwapBuffers(window);

        glfwPollEvents();
    } while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
           glfwWindowShouldClose(window) == 0 );

    glfwTerminate();


}
