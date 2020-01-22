#ifndef SAVE_RESULTS_H
#define SAVE_RESULTS_H

#include "method.h"
#include <string>

class OutputData
{
    public:
	OutputData() 
	{
		create();
	}
	bool create();
	bool writeResultsIntoFile(double time1, double time2, double time3, double time4, int sizeOfMatrix);

};


#endif
