#include "gauss_jordan.h"
#include "timer.h"
#include <iostream>


result GaussJordan::calculate(std::vector<std::vector<double>> A)
{

    Timer t;

	int n =  A.size();

    
    for (int i = 0; i < n; i++)
    {
        if (A[i][i] == 0)
        {
            //exchange row
            int k = i + 1;
            int great = i + 1;
            while (k < n)
            {
                if (A[great][i] < A[k][i])
                    great = k;
                k++;
            }
         
            for (int j = 0; j < n + 1; j++)
            {
                double temp;
                temp = A[i][j];
                A[i][j] = A[great][j];
                A[great][j] = temp;
            }
        }
            
        //normalize
        double normal = A[i][i];
        for (int j = 0; j < n + 1; j++)
        {
            A[i][j] /= normal;
        }

        //make below pivot zero
        for (int ii = i + 1; ii < n; ii++)
        {
            double zeroFactor = A[ii][i];
            for (int j = 0; j < n + 1; j++)
            {
                A[ii][j] -= zeroFactor * A[i][j];
            }
        }
    }

    for (int i = n - 1; i > 0; i--)
    {
        //make above pivot zero
        for (int ii = i - 1; ii >= 0; ii--)
        {
            double zeroFactor = A[ii][i];
            for (int j = i; j < n + 1; j++)
            {
                A[ii][j] -= zeroFactor * A[i][j];
            }
        }

    }

    double time = t.elapsed();

    
    result output;
    
    for (int i = 0; i < n; i++)
    {
        output.solution.push_back(A[i][n]);
    }
    output.time = time;
    return output;
    


}

