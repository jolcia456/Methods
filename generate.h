#ifndef GENERATE_H_INCLUDED
#define GENERATE_H_INCLUDED

#include "readdata.h"
#include <cstdlib>
#include <ctime>

class Generate
{
private:
	int mRow;
	int mCol;
	std::vector<std::vector<double>> mCoeff;
	bool mDataCorrectness; //paramter okresla czy danych w plikach jest odpowiednia ilosc

public:
	Generate(int row) : mRow(row), mCol(row + 1)
	{
		std::srand(static_cast<unsigned int>(clock()));

		for (int i = 0; i < mRow; ++i)
		{
			std::vector<double> vRow;
			for (size_t j = 0; j < mCol; ++j)
				vRow.push_back(double(rand() % 101 + 1));

			mCoeff.push_back(vRow);
		}
	}

	Generate()
	{
		mCoeff = { {1,2,3,1},
					{4,5,6,1},
					{1,0,1,1}
		};


		mRow = 3;
		mCol = mRow + 1;
	}


	Generate(std::string path)
	{
		InputData input(path);
		mDataCorrectness = datainput.readDataIntoMatrix(mCoeff);
		mRow = input.getSize();
	}

	std::vector<std::vector<double>>& getCoeff()
	{
		return mCoeff;
	}

	size_t getSize()
	{
		return mRow;
	}
	
	bool isDataCorrect()
	{
		return mDataCorrectness;
	}

};

#endif // GENERATE_H_INCLUDED
