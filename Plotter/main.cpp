//#include <Object.hpp> 
#include <Plotter.hpp>
#include <GLFW/glfw3.h>
#include <armadillo>


using namespace std;

int main(void)
{


  /*  Vertex P1 = Vertex(3.0,4.0,5.0);
    Vertex P2 = Vertex(6.0,7.0,8.0);

    vector<float> p1 = P1.getValues();
    arma::fmat T = {{1.0,0.0,0.0,- p1[0]},
                    {0.0,1.0,0.0,- p1[1]},
                    {0.0,0.0,1.0,- p1[2]},
                    {0.0,0.0,0.0,1.0}
};
    
    //cout << T << endl;
    //cout << P1.getHomg();
    //cout << P2.getHomg();}

    arma::fcolvec P1p = T*P1.getHomg();
    arma:: fcolvec P2p = T * P2.getHomg();

    cout << P1p << endl;
    cout << P2p << endl; 
*/

	GLFWwindow* window;
	std::vector<Object> firstFile = readObjFile("../Models/suzzane3.obj");
    float escalacion= 0.31;
	

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

		draw(firstFile,escalacion,Color3f(0.3,0.9,0.0));
		plotWireFrame(firstFile,escalacion,Color3f(0.8,0.5,0.7));
		
        
        glfwSwapBuffers(window);

        glfwPollEvents();
    } while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
           glfwWindowShouldClose(window) == 0 );

    glfwTerminate();


}
