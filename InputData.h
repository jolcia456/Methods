#ifndef INPUT_DATA_H
#define INPUT_DATA_H

#include <fstream>
#include <string>
#include <vector>

class InputData
{
private:
	std::string mFileName;

public:
	InputData(std::string fileName) : mFileName(fileName) {};
	bool open();
	void readDataIntoMatrix(std::vector<std::vector<double>>& A);
};


#endif


