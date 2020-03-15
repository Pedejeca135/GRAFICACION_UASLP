#ifndef PLOTTER_H
#define PLOTTER_H

#include <Object.hpp>
#include <GLFW/glfw3.h>


    void plotWireFrame(Object obj);
    void plotWireFrame(vector<Object> objs);

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


#endif