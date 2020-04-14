#include "CelestialBody.hpp"

CelestialBody::CelestialBody()
{

}

CelestialBody:: CelestialBody(std::string name, Color3f color, float scale )
{
     //cout<<"hello"<<endl;
    this->name = name;
    this->color = color;
    this->scale = scale;  

    transf = Tr.S(scale, scale, scale);
    

    this->thisObject.init("roca.obj");

    this->fixedBool = true; 

    this->timePerCicle = timePerCicle;
    t_angle = 0.0f;
    angular_Velocity =  (2 * PI) / timePerCicle;
    float deltaTime = 0.0f; 

    t.Restart();


}

CelestialBody:: CelestialBody(std::string name, CelestialBody barycenter , float timePerCicle,  Color3f color, float scale, float distancia  )
{
     
    this->name = name;
    this->color = color;
    this->scale = scale;  
    

    this->thisObject.init("roca.obj");

    this->fixedBool = false; 
    this->timePerCicle = timePerCicle;
    t_angle = 0.0f;
    angular_Velocity =  (2 * PI) / timePerCicle;
    float deltaTime = 0.0f;
    this->rotationRadius = distancia;   

    t.Restart();

    

    baryCenterStruct.scale = barycenter.scale;
    baryCenterStruct.transf = barycenter.transf;
    transf = Tr.R(0.0f, 1.0f, 0.0f, t_angle) * Tr.T(- rotationRadius , 0.0, 0.0) * Tr.S(scale,scale,scale) * barycenter.transf;
}


CelestialBody:: CelestialBody(std::string name, CelestialBody *barycenter , float timePerCicle,  Color3f color, float scale, float distancia  )
{
     
    this->name = name;
    this->color = color;
    this->scale = scale;  
    aroundAnotherNotFixedBool = true;
    

    this->thisObject.init("roca.obj");

    this->fixedBool = false; 
    this->timePerCicle = timePerCicle;
    t_angle = 0.0f;
    angular_Velocity =  (2 * PI) / timePerCicle;
    float deltaTime = 0.0f;
    this->rotationRadius = distancia;   

    t.Restart();


    baryCenterStruct.scale = barycenter->scale;
    baryCenterStruct.transf = barycenter->transf;

    transf = Tr.R(0.0f, 1.0f, 0.0f, t_angle) * Tr.T(- rotationRadius , 0.0, 0.0) * Tr.S(scale,scale,scale) * barycenter->transf;
    baryCenterStruct.transformationPointer = &barycenter->transf;

    cout<<"dentro de " + this->name <<endl;
    cout<<baryCenterStruct.transformationPointer<<endl;    
    cout<<*baryCenterStruct.transformationPointer<<endl;
}

 void CelestialBody :: makeStep()
{

//cout<<"makestep" + this->name<< endl;
    if(this->fixedBool == false)//is arround another celestialBody
    {

        deltaAngle = this->t.Delta()  * angular_Velocity;

        this->t_angle = (this->t_angle < 360.0f) ? this->t_angle+deltaAngle : 0.0f;

        if(this->aroundAnotherNotFixedBool)
        {
            transf = (*(baryCenterStruct.transformationPointer))* Tr.R(0.0f, 1.0f, 0.0f, t_angle) * Tr.T(- rotationRadius , 0.0, 0.0) * Tr.S(scale,scale,scale)  ;
        }
        else 
        {
            transf = Tr.R(0.0f, 1.0f, 0.0f, t_angle) * Tr.T(- rotationRadius , 0.0, 0.0) * Tr.S(scale,scale,scale) * baryCenterStruct.transf;
        }

        
        
        
        std::vector<Vertex>  p_vertices = thisObject.get_faces_verts();
        std::vector< Vertex > draw_vertices;
        for ( unsigned int i=0; i<p_vertices.size(); i++ ) {
            arma::fcolvec v = p_vertices[i].getHomg();
            arma::fcolvec vp = transf * v;
            Vertex rv = Vertex();
            rv.set_value(arma::trans(vp));
            draw_vertices.push_back(rv);
        }
         draw(draw_vertices,color);  
    
        t.Restart();

    }// moving bodies END.
    else //is fixed. note : like the sun.
    {
         transf = Tr.S(scale, scale, scale);
        
        std::vector<Vertex> p_vertices = this->thisObject.get_faces_verts();
        std::vector<Vertex> draw_vertices;
        for ( unsigned int i=0; i<p_vertices.size(); i++ )
        {
            arma::fcolvec v = p_vertices[i].getHomg();
            
            arma::fcolvec vp = transf * v;
            Vertex rv = Vertex();            
            rv.set_value(arma::trans(vp));
            
            draw_vertices.push_back(rv);
        }
        draw(draw_vertices,color);       

    }//fixed bodies END.


}
   