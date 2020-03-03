#include <stdio.h>
#include <stdlib.h>
#include<armadillo>
#include <math.h>
#include<iostream>

using namespace std;

int main( int argc, char ** argv)
{
    //curvas de hermite.
    arma::fmat MH = {{2.0, -2.0, 1.0, 1.0},
                     {-3.0, 3.0, -2.0, -1.0},
                     {0.0, 0.0, 1.0, 0.0},
                     {1.0, 0.0, 0.0, 0.0}
                     };

    arma:: fmat GH = {{0.0, 0.0, 0.0}, //P1
                      {6.0,11.0,-3.0}, //P4
                      {2.0, 3.0, 1.0}, //R1
                      {5.0, -1.0, 2.0} //R4
                      };

    //cout << MH << endl;
    //cout << GH << endl;

    float dt = 0.01;

    for(float t = 0.0; t<= 1.0; t+= dt)
    {
        arma::frowvec T = {powf(t,3),powf(t,2),t,1.0};
        arma :: fmat Qt  = T * MH * GH;
        cout<<Qt<<endl;
    }
    


    

    return 0;
}