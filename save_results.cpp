#include "save_results.h"
#include <fstream>
#include <iostream>

bool OutputData::create()
{
    std::ofstream output("Results.csv");

    if (!output)
    {
        // Print an error and exit
        std::cerr << "Uh oh, Sample.dat could not be opened for writing!" << std::endl;
        return false;
    }

    output <<"Size of Matrix"<< ", "
        << "Gauss" << ", "
        << "GaussJordan" << ", "
        << "Gauss-Seidel" << ", "
        << "Jacobi"<< "\n";

    output.close();

    return true;
}

bool OutputData::writeResultsIntoFile(double time1, double time2, double time3, double time4, int sizeOfMatrix)
{
	std::ofstream output("Results.csv", std::ios::out | std::ios::app);

    if (!output)
    {
        // Print an error and exit
        std::cerr << "Uh oh, Sample.dat could not be opened for writing!" << std::endl;
        return false;
    }

    output << sizeOfMatrix << ", "
        << time1 << ", "
        << time2 << ", "
        << time3 << ", "
        << time4 << "\n";

    output.close();

    return true;

}