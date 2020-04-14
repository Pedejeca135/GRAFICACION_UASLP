#include "UtilComm.hpp"


Timer::Timer() {
	gettimeofday(&t0, 0);
}

void Timer::Restart() {
	gettimeofday(&t0, 0);
}
double Timer::Delta() {
	gettimeofday(&t1, 0);
	double diff = (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;

	return diff;
}

