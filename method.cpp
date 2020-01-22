#include "method.h"
#include <iostream>

void Method::printAugmentedMatrix(std::vector< std::vector<double> > &A)
 {
    int n = A.size();
    for (int i=0; i<n; i++) {
        for (int j=0; j<n+1; j++) {
            std::cout << A[i][j] << "\t";
            if (j == n-1) {
                std::cout << "| ";
            }
        }
        std::cout << "\n";
    }
    std::cout << std::endl;
}

