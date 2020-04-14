#include <stdio.h>
#include <stdlib.h>
#include<armadillo>
#include <math.h>
#include<iostream>
#include <obj.hpp>

using namespace std;

int main( int argc, char ** argv)
{

Vertex P1,P2;
Vertex pc1,pc2,pc3,pc4;

float  d;
float X,Y,Z;

    cout << "parametro P1" << endl;
	cin >>  X;
	cin >>  Y;
	cin >>  Z;
	P1 = Vertex(X,Y,Z);


    cout << "parametro P2"<< endl;
	cin >>  X;
	cin >>  Y;
	cin >>  Z;
	P2 = Vertex(X,Y,Z);

    d = P1.distancia(P2);

    pc2 = Vertex(P1.x,P1.y + (d/4),P1.z);
    pc3 = Vertex(P2.x-(d/4),P2.y ,P2.z);
    //para encontrar los puntos pc4 y pc1

    X = P2.x - P1.x;
    Y = P2.y - P1.y;
    Z = P2.z;

    pc1 = Vertex (P1.x - X,P1.y -Y, Z);
    pc4 = Vertex (P2.x + X,P2.y +Y, Z);

    //curvas de bezier.
    arma::fmat MH = {{-1.0, 3.0, -3.0, 1.0},
                     {3.0, -6.0, 3.0, 0.0},
                     {-3.0, 3.0, 0.0, 0.0},
                     {1.0, 0.0, 0.0, 0.0}
                     };

arma:: fmat GH = {{pc1.x, pc1.y, pc1.z}, //P1
                    {pc2.x, pc2.y, pc2.z}, //P2
                      {pc3.x, pc3.y, pc3.z}, //P3
                      {pc4.x, pc4.y, pc4.z} //P4
                      };

    //cout << MH << endl;
    //cout << GH << endl;

    float dt = 0.01;

cout<<"\n t\t "<< "" <<"X \t  \t Y \t \tZ \t \t" <<endl;

    for(float t = 0.0; t<= 1.0; t+= dt)
    {
        arma::frowvec T = {powf(t,3),powf(t,2),t,1.0};
        arma :: fmat Qt  = T * MH * GH;
        cout<<"t: "<< t <<" = " <<Qt<<endl;
    }

    return 0;
}
