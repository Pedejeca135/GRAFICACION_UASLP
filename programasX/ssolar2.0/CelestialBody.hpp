
#ifndef CELE_BODY_H
#define CELE_BODY_H

#include "Plotter.hpp"
#include "Transform.hpp"
#include "UtilComm.hpp"

typedef struct
{
    float scale;
    arma::fmat transf;
    arma::fmat *transformationPointer;
}B_CENTER;


class CelestialBody
{
    private:
    //common atributes.
     std::string name;     
     Color3f color;
     float scale; 
     bool fixedBool = false; 
     bool aroundAnotherNotFixedBool = false;
    
    //just for the non fixed
    //float barycenterscale;
    //Object baryCenterObj;
    B_CENTER baryCenterStruct;
    float timePerCicle;     
    float deltaAngle;
    float deltaTime; 
    Timer t = Timer();
    double angular_Velocity = 0;
    float t_angle;
    
    public:
    
    Object thisObject = Object();
    Transform Tr = Transform();
    arma::fmat transf;  
    float rotationRadius;

    /*******************************
     * 
     * 
     *              CONSTRUCTORES (begin).
     * 
     * 
     * ***********************************/
    CelestialBody();
    CelestialBody(std::string name,  Color3f color, float scale  );
    CelestialBody(std::string name, CelestialBody barycenter , float timePerCicle,  Color3f color, float scale, float distancia  );
    CelestialBody(std::string name, CelestialBody *barycenter , float timePerCicle,  Color3f color, float scale,float distancia);
    

    void rota();
    void makeStep();

};

#endif