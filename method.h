#ifndef METHOD_H_INCLUDED
#define METHOD_H_INCLUDED

#include <vector>

struct result
{
    std::vector<double> solution;
    double time;
};


class Method
{
public:
        virtual result calculate(std::vector<std::vector<double>> A) = 0;
        void printAugmentedMatrix(std::vector< std::vector<double> > &A);
};




#endif // METHOD_H_INCLUDED
