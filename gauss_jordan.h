#ifndef GAUSS_JORDAN_H
#define GAUSS_JORDAN_H

#include "method.h"

class GaussJordan : public Method
{
public:
	virtual result calculate(std::vector<std::vector<double>> A) override;

};



#endif


