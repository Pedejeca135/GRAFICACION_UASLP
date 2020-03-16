//#include <Object.hpp> 
#include <Plotter.hpp>
#include <GLFW/glfw3.h>


using namespace std;

int main(void)
{
	GLFWwindow* window;
	std::vector<Object> firstFile = readObjFile("../Models/chinese_coin.obj");
    float escalacion= 0.01;
	

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

		draw(firstFile,escalacion,Color3f(0.3,0.2,0.9));
		plotWireFrame(firstFile,escalacion,Color3f(0.8,0.5,0.7));
		
        
        glfwSwapBuffers(window);

        glfwPollEvents();
    } while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
           glfwWindowShouldClose(window) == 0 );

    glfwTerminate();


}
