#ifndef JACOBI_H
#define JACOBI_H

#include "method.h"

class Jacobi : public Method
{
private:
	int mIteration;
	double mPrecision;
public:
	Jacobi(int iteration = 1000, double precision = 0.001) : mIteration(iteration), mPrecision(precision) {};
	virtual result calculate(std::vector<std::vector<double>> A) override;
};


#endif

