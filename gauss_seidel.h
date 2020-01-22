#ifndef GAUSS_SEIDEL_H_INLCUDED
#define GAUSS_SEIDEL_H_INCLUDED

#include "method.h"

class GaussSeidel : public Method
{
private:
	int mIteration;
	double mPrecision;
public:
	GaussSeidel(int iteration = 1000, double precision = 0.001) : mIteration(iteration), mPrecision(precision) {};
	virtual result calculate(std::vector<std::vector<double>> A) override;
};

#endif

