#ifndef PLOTTER_H
#define PLOTTER_H

#include <Object.hpp>
#include <GLFW/glfw3.h>

class Color3f
{
    public:
    Color3f();//for white color.
    Color3f(float i); // for black color.
    Color3f(float _r, float _g, float _b);

    float r;
    float g;
    float b;
};


void plotWireFrame(Object obj);
void plotWireFrame(vector<Object> objs);
void plotWireFrame(vector<Object> objs, float scale);
void plotWireFrame(Object obj, float scale);
void draw(Object obj);
void draw(vector<Object> objs);
void draw(vector<Object> objs, float scale);
void draw(Object obj, float scale);

/***************************************************
*
*            for passing the color.
*
****************************************************/

void plotWireFrame(Object obj, Color3f color);
void plotWireFrame(vector<Object> objs, Color3f color);
void plotWireFrame(vector<Object> objs, float scale, Color3f color);
void plotWireFrame(Object obj, float scale, Color3f color);
void draw(Object obj, Color3f color);
void draw(vector<Object> objs, Color3f color);
void draw(vector<Object> objs, float scale, Color3f color);
void draw(Object obj, float scale, Color3f color);



void draw(vector<Vertex> vertices, Color3f color);









#endif