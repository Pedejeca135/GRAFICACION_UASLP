#include <cmath>
#include "Transform.hpp"

#define PI 3.14159265

Transform::Transform() {

}

arma::dmat Transform::T(double tx, double ty, double tz) {
	return(arma::dmat({ {1.0f, 0.0f, 0.0f, tx},
						{0.0f, 1.0f, 0.0f, ty},
						{0.0f, 0.0f, 1.0f, tz},
						{0.0f, 0.0f, 0.0f, 1.0} })
		);
}

arma::dmat Transform::S(double sx, double sy, double sz) {
	return(arma::dmat({ {sx, 0.0f, 0.0f, 0.0f},
						{0.0f, sy, 0.0f, 0.0f},
						{0.0f, 0.0f, sz, 0.0f},
						{0.0f, 0.0f, 0.0f, 1.0} })
		);
}

arma::dmat Transform::R(double ax, double ay, double az, double angle) {
	float ang = angle * PI / 180.0f;
	arma::dmat Rot;

	Rot.eye(4, 4);

	if (ax)
		Rot = arma::dmat({ {1.0f, 0.0f, 0.0f, 0.0f},
						{0.0f, cosf(ang), -sinf(ang), 0.0f},
						{0.0f, sinf(ang), cosf(ang), 0.0f},
						{0.0f, 0.0f, 0.0f, 1.0} });
	if (ay)
		Rot = arma::dmat({ {cosf(ang), 0.0f, sinf(ang), 0.0f},
						{0.0f, 1.0f, 0.0f, 0.0f},
						{-sinf(ang), 0.0, cosf(ang), 0.0f},
						{0.0f, 0.0f, 0.0f, 1.0} });
	if (az)
		Rot = arma::dmat({ {cosf(ang), -sinf(ang), 0.0f, 0.0f},
						{sinf(ang), cosf(ang), 0.0f, 0.0f},
						{0.0f, 0.0f, 1.0f, 0.0f},
						{0.0f, 0.0f, 0.0f, 1.0} });

	return(Rot);
}