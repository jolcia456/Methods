#ifndef READ_DATA_H
#define READ_DATA_H

#include <string>
#include <vector>

class InputData
{
private:
	std::string mPath;
	int mRow;
	int mCol;
	int mIteration;
	double mPrecision;

public:
	InputData(std::string path) : mPath(path) {}
	bool readDataIntoMatrix(std::vector<std::vector<double>>& A);
	bool readParameters();
	int getSize();
	int getIteration();
	double getPrecision();
};


#endif


