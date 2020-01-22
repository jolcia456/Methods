#ifndef GAUSS_H_INCLUDED
#define GAUSS_H_INCLUDED

#include "method.h"

class Gauss : public Method
{
public:
    virtual result calculate(std::vector<std::vector<double>> A) override;
};


#endif // GAUSS_H_INCLUDED
