#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP
#include <stdio.h>
#include <armadillo>

class Transform
{
public:
    Transform();
    arma::fmat T(float tx, float ty, float tz);
    arma::fmat S(float sx, float sy, float sz);
    arma::fmat R(float ax, float ay, float az, float angle);
};

#endif // FACE_HPP



