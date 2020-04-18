// Metody.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "method.h"
#include "gauss.h"
#include "gauss_seidel.h"
#include "gauss_jordan.h"
#include "jacobi.h"
#include "generate.h"
#include "readdata.h"
#include "save_results.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

using namespace std;

void printResults(const std::vector<double> &solution, int n)
{
	for (int i = 0; i < n; i++)
	{
		std::cout << solution[i] << " ";
	}
	std::cout << '\n';
}

void checkEquationsByFourMethods(std::string path, OutputData &out, int sizeOfMatrix)
{
	Generate coeff(path);
	bool dataCorrectness = coeff.isDataCorrect();
	
	if(!dataCorrectness)
	{
		std::cerr<<"Amount of data is to small. Please use files with proper amount of data for "<<sizeOfMatrix<< "size matrix.\n";
		return;
	}

	std::vector<std::vector<double>> A = coeff.getCoeff();

	int n = coeff.getSize();
	
	int sum=0;

    	for(int z=0; z < n; ++z)
    	{
		if (A[z][z]=0)
		++sum;
    	}

    	if (sum==10)
    	{
    		std::cerr<<"This system of equations cannot be solved";
    		return;
    	}

	//pobranie parmetrow dla metod iteracyjnych
	InputData param("Macierze\\IterationParmeters.txt");
	param.readParameters();

	std::cout << param.getIteration() << " " << param.getPrecision() << '\n';

	//declare object
	Gauss g;
	GaussJordan gj;
	GaussSeidel gs(param.getIteration(), param.getPrecision());
	Jacobi j(param.getIteration(), param.getPrecision());

	//g.print(A);

	result outputG, outputGJ, outputGS, outputJ;

	outputG = g.calculate(A);
	outputGJ = gj.calculate(A);
	outputGS = gs.calculate(A);
	outputJ = j.calculate(A);

	// Print result
	std::cout << setprecision(16);
	std::cout << "Result:\n";

	printResults(outputG.solution, n);
	printResults(outputGJ.solution, n);
	printResults(outputGS.solution, n);
	printResults(outputJ.solution, n);

	std::cout << "\n\n";

	std::cout << "Calculating takes: " << outputG.time << " seconds.\n";
	std::cout << "Calculating takes: " << outputGJ.time << " seconds.\n";
	std::cout << "Calculating takes: " << outputGS.time << " seconds.\n";
	std::cout << "Calculating takes: " << outputJ.time << " seconds. \n";

	out.writeResultsIntoFile(outputG.time, outputGJ.time, outputGS.time, outputJ.time, sizeOfMatrix);
}

int main()
{

	OutputData out;
	checkEquationsByFourMethods("Macierze\\10x10_random\\", out, 10);
	checkEquationsByFourMethods("Macierze\\100x100_random\\", out, 100);
	checkEquationsByFourMethods("Macierze\\1000x1000_random\\", out, 1000);

	return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
