#include "readdata.h"
#include <fstream>
#include <sstream>
#include <iostream>

bool InputData::readDataIntoMatrix(std::vector<std::vector<double>>& A)
{

	std::string fullPathA = mPath + "A" +".txt";
	std::cout << fullPathA << '\n';

	std::ifstream inputA(fullPathA);
		
	if (!inputA)
	{
		std::cerr << "File could not be opened for reading";
		return false;
	}
		
	std::string line;
	std::getline(inputA, line);

	int rowA = stoi(line);

	std::getline(inputA, line);
	int colA = std::stoi(line);

	int countRows = 0; //= rowA;
	int countCols = 0; // = colA;

	mRow = rowA;
	mCol = colA + 1;

	
	while (std::getline(inputA, line))
	{
		//std::getline(inputA, line);
		std::stringstream s(line);
		std::vector<double> row;
		++countRows;
			
		std::string element;
		while (std::getline(s, element, ','))
		{
			//std::string element;
			//std::getline(s, element, ',');
			double el = std::stod(element);
			row.push_back(el);
			++countCols;
		}
		if(countCols < colA)
		{ 	
			inputA.close();
			return false;
		}
		countCols = 0;

		row.resize(colA + 1);
		A.push_back(row);
	}

	inputA.close();
	
	if(countRows < rowA)
		return false;

	std::string fullPathB = mPath + 'b' + ".txt";
	std::cout << fullPathB << '\n';

		
	std::ifstream inputB(fullPathB);

	if (!inputB)
	{
		std::cerr << "File could not be opened for reading";
		return false;
	}

	std::string lineB;
	std::getline(inputB, lineB);

	int rowB = stoi(lineB);
	int countRowsB = 0;

	while (std::getline(inputB, lineB))
	{
		//std::getline(inputB, lineB);
		double el = std::stod(lineB);
		A[rowB - countRowsB][rowB] = el;
		++countRowsB;
	}

	inputB.close();
	
	if(countRowsB < rowB)
		return false;
	
	return true;

}

bool InputData::readParameters()
{
	std::ifstream input(mPath);

	if (!input)
	{
		std::cerr << "File could not be opened for reading";
		return false;
	}

	std::string line;
	std::getline(input, line);
	mIteration = std::stoi(line);

	std::getline(input, line);
	mPrecision = std::stod(line);

	input.close();

	return true;
}

int InputData::getSize()
{
	return mRow;
}

int InputData::getIteration()
{
	return mIteration;
}
double InputData::getPrecision()
{
	return mPrecision;
}
