#include "gauss_seidel.h"
#include "timer.h"
#include <iomanip>
#include <cmath>


result GaussSeidel::calculate(std::vector<std::vector<double>> A)
{
	Timer t;
    
    int n = A.size();
    
    for (int i = 0; i < n; i++)                    //Pivotisation(partial) to make the equations diagonally dominant
        for (int k = i + 1; k < n; k++)
            if (abs(A[i][i]) < abs(A[k][i]))
                for (int j = 0; j <= n; j++)
                {
                    double temp = A[i][j];
                    A[i][j] = A[k][j];
                    A[k][j] = temp;
                }

    int flag = 0;
    int count = 0;
    std::vector<double> x(n, 0.0);
    double y;

    do                            //Perform iterations to calculate x1,x2,...xn
    {
        for (int i = 0; i < n; i++)                //Loop that calculates x1,x2,...xn
        {
            y = x[i];
            x[i] = A[i][n];
            for (int j = 0; j < n; j++)
            {
                if (j != i)
                    x[i] = x[i] - A[i][j] * x[j];
            }
            x[i] = x[i] / A[i][i];
            if (abs(x[i] - y) <= mPrecision)            //Compare the ne value with the last value eps
                flag++;
        }

        count++;
    } while (flag < n && count < mIteration); //If the values of all the variables don't differ from their previious values with error more than eps then flag must be n and hence stop the loop

 
    
    double time = t.elapsed();

    if (flag < n)
    {
        for (int i = 0; i < n; ++i)
            x[i] = NAN;
    }

    result output;
    output.solution = x;
    output.time = time;

    return output;
}