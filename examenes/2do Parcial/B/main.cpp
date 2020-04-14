#include <stdio.h>
#include <stdlib.h>
#include <armadillo>
#include "Object.hpp"
#include "Transform.hpp"

int main( void )
{
    Object cuboUnitario = readFirstObjFile("cube.obj");

    Transform Tr = Transform();
    float t_angle = 0.0f;

 cout << "antes de la transformacion"<<endl;
for (int  i = 0; i < cuboUnitario.vertices.size(); i++)
{
cuboUnitario.vertices[i].print();
}


    cout<<"introduzca el angulo de la tranformacion"<<endl;
    cin >> t_angle;    
    
        arma::fmat transf ;
   
        std::vector< Vertex > aux_vertices = cuboUnitario.vertices;
        std::vector< Vertex > cubo_vertices;



//las primeras dos multiplicaciones funcionan para llevar la diagonal principal del cubo al eje Y
//despues se rota con respecto al eje Y y finalmente se regresa la diagonal principal a su lugar,. Esto para dar el efecto de rotacion
//sobre la diagonal principal del cubo

//traslacion del eje del cubo al eje Y
transf = Tr.R(1.0f, 0.0f, 0.0f, -45.0) * Tr.R(0.0f, 0.0f, 1.0f, 45.0) ;
//rotacion con respecto del eje Y
transf = transf * Tr.R(0.0f, 1.0f, 0.0f ,t_angle );
//retorno del cubo a su lugar con respecto a la diagonal princiál del mismo.
transf = transf * Tr.R(0.0f, 0.0f, 1.0f, -45.0)* Tr.R(1.0f, 0.0f, 0.0f, 45.0) ;

        for ( unsigned int i = 0; i< aux_vertices.size(); i++ ) 
        {
               
            arma::fcolvec v = aux_vertices[i].getHomg();            
            arma::fcolvec vp = transf * v;
            Vertex rv = Vertex();
            rv.set_value(arma::trans(vp));            
            cubo_vertices.push_back(rv);
        }

         cout << "Despues de la transformacion"<<endl;
//se supone que si la rotacion es 0 y 360 grados los puntos deben marcar loo mismo que antes de la rotacion.
for (int  i = 0; i < cuboUnitario.vertices.size(); i++)
{
    cubo_vertices[i].print();
}

    return 0;
    
}