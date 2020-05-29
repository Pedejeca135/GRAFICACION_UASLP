#pragma once
#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP
#include <stdio.h>
#include <armadillo>

class Transform
{
public:
	Transform();
	arma::dmat T(double tx, double ty, double tz);
	arma::dmat S(double sx, double sy, double sz);
	arma::dmat R(double ax, double ay, double az, double angle);
};

#endif // FACE_HPP